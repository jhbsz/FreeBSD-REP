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
#include <sys/counter.h>
#include <sys/mbuf.h>
#include <sys/uio.h>
#include <sys/lock.h>
#include <sys/mutex.h>

#include <netrepi/repi.h>
#include <netrepi/repi_pcb.h>

static int repi_attach(struct socket *so, int proto, struct thread *td) {
	printf("REPI attaching\n");
	return 0;
}

static void repi_detach(struct socket *so) {

	struct repi_pcb *pcb = (struct repi_pcb *) so->so_pcb;

	pcb->so = NULL;
	pcb->interest_hash = 0;

	printf("REPI detaching\n");
}

/* TODO: Criar uma tabela relacionando o bind com o pid do processo 
 * Usar o campo so_pcb da struct socket
 */
static int repi_bind(struct socket *so, struct sockaddr *nam, struct thread *td) {

	struct sockaddr_repi *sr;
	struct repi_pcb *pcb;
	uint32_t hash;

	sr = (struct sockaddr_repi *) nam;

	hash = REPI_HASH_BIND_CREATE(sr->interest);

	printf("%s -> %u\n", sr->interest, hash);

	repi_pcb_add(sr->interest, so);

	pcb = repi_pcb_get(sr->interest);
	printf("hash no pcb: %u\n", pcb->interest_hash);

	printf("REPI binding - %s\n", sr->interest);
	return 0;
}

static int repi_sosend(struct socket *so, struct sockaddr *addr, struct uio *uio, struct mbuf *top,
		struct mbuf *control, int flags, struct thread *td) {

	struct mbuf *m;
	uint32_t *interest;

	m = m_uiotombuf(uio, M_WAITOK, 0, max_hdr,
			(M_PKTHDR | ((flags & MSG_EOR) ? M_EOR : 0)));

	printf("REPI send %d - %s\n", m->m_hdr.mh_len, m->m_hdr.mh_data);

	/* Appending the interest hash as a second header */
	M_PREPEND(m, sizeof(uint32_t), M_NOWAIT);

	interest = mtod(m, uint32_t *);
	*interest = ((struct repi_pcb *)so->so_pcb)->interest_hash;

	return(repi_output(NULL /* ifp */, m));

}

static int repi_soreceive(struct socket *so, struct sockaddr **paddr, struct uio *uio, struct mbuf **mp0,
		struct mbuf **controlp, int *flagsp) {

	printf("so_rcv: %d\n", so->so_rcv.sb_cc);

	SOCKBUF_LOCK(&so->so_rcv);
	printf("sbwait waiting\n");
	sbwait(&(so->so_rcv));
	SOCKBUF_UNLOCK(&so->so_rcv);

	uiomove("away!", 5, uio);

	printf("REPI receive\n");

	return 0;
}

struct pr_usrreqs repi_usrreqs = {
	.pru_abort =        NULL,
	.pru_attach =       repi_attach,        /* Executado no momento da criacao do socket sys/kern/uipc_socket.c:409 */
	.pru_bind =         repi_bind,
	.pru_connect =      NULL,
	.pru_control =      NULL,
	.pru_detach =       repi_detach,
	.pru_disconnect =   NULL,
	.pru_peeraddr =     NULL,
	.pru_send =         NULL,
	.pru_soreceive =    repi_soreceive,
	.pru_sosend =       repi_sosend,
	.pru_shutdown =     NULL,
	.pru_sockaddr =     NULL,
	.pru_sosetlabel =   NULL,
	.pru_close  =       NULL,
};

