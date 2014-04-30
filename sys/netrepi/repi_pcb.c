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
#include <sys/domain.h>
#include <sys/mbuf.h>
#include <sys/uio.h>
#include <sys/lock.h>
#include <sys/mutex.h>

#include <netrepi/repi.h>
#include <netrepi/repi_pcb.h>

struct repi_pcb *repi_bind_hash;

int
repi_pcb_add(const char *interest, const struct socket *so) {

	uint32_t hash;

	hash = REPI_HASH_BIND_CREATE(interest);

	if(repi_bind_hash[hash % 4096].so == NULL) {
		repi_bind_hash[hash % 4096].so = (struct socket *) so;
		repi_bind_hash[hash % 4096].interest_hash = hash;
		repi_bind_hash[hash % 4096].so->so_pcb = &(repi_bind_hash[hash % 4096]);
	}
	else
		return 1;

	return 0;

}

struct repi_pcb *
repi_pcb_get(const char *interest) {

	uint32_t hash;

	hash = REPI_HASH_BIND_CREATE(interest);

	return &(repi_bind_hash[hash % 4096]);
}

struct repi_pcb *
repi_pcb_get_by_hash(const uint32_t hash) {

	return &(repi_bind_hash[hash % 4096]);
}
