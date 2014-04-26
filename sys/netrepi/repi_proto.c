/*-
 * Copyright (c) 2014 Danilo Egea Gondolfo <danilo@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */


#include <sys/cdefs.h>
__FBSDID("$FreeBSD:$");

#include <sys/param.h>
#include <sys/kernel.h>
#include <sys/libkern.h>
#include <sys/socket.h>
#include <sys/socketvar.h>
#include <sys/systm.h>
#include <sys/types.h>
#include <sys/protosw.h>
#include <sys/counter.h>
#include <sys/domain.h>

#include <netrepi/repi.h>

static void pr_init_test() {
    printf("REPI pr_init running\n");
}

extern struct pr_usrreqs repi_usrreqs;
extern struct domain repidomain;

struct protosw repisw[] = {
{
	.pr_type =		SOCK_DGRAM,
	.pr_domain =	&repidomain,
	.pr_protocol =	REPIPROTO_REPI,
	.pr_flags =		PR_ATOMIC|PR_ADDR,
	.pr_input =		NULL,
	.pr_ctlinput =	NULL,
	.pr_ctloutput =	NULL,
	.pr_init =		pr_init_test,
#ifdef VIMAGE
	.pr_destroy =	NULL,
#endif
	.pr_usrreqs =	&repi_usrreqs,
}

};

struct domain repidomain = {
	.dom_family =			AF_REPI,
	.dom_name =				"repi",
	.dom_protosw =			repisw,
	.dom_protoswNPROTOSW =	&repisw[sizeof(repisw)/sizeof(repisw[0])],
#ifdef VIMAGE
	.dom_rtdetach =			NULL,
#endif
	.dom_rtoffset =			32,
	.dom_maxrtkey =			sizeof(struct repi_header),
	.dom_ifattach =			NULL,
	.dom_ifdetach =			NULL
};

DOMAIN_SET(repi);
