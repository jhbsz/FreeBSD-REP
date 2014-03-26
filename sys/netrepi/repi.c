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
#include <sys/sysctl.h>
#include <sys/systm.h>
#include <sys/mbuf.h>
#include <sys/types.h>
#include <sys/counter.h>

#include <net/if.h>
#include <net/if_var.h>
#include <net/if_dl.h>
#include <net/ethernet.h>
#include <net/netisr.h>

#include <netrepi/repi.h>

/* sysctls functions handlers */

static int sysctl_repi_input_dgrams_count_handler(SYSCTL_HANDLER_ARGS) {

	int error;
	uint64_t val;

	val = counter_u64_fetch(repi_input_dgrams_count);
	error = SYSCTL_OUT(req, &val, sizeof(val));

	return error;

}

static int sysctl_repi_output_dgrams_count_handler(SYSCTL_HANDLER_ARGS) {

	int error;
	uint64_t val;

	val = counter_u64_fetch(repi_output_dgrams_count);
	error = SYSCTL_OUT(req, &val, sizeof(val));

	return error;

}

static int sysctl_repi_forwarded_dgrams_count_handler(SYSCTL_HANDLER_ARGS) {

	int error;
	uint64_t val;

	val = counter_u64_fetch(repi_forwarded_dgrams_count);
	error = SYSCTL_OUT(req, &val, sizeof(val));

	return error;

}

SYSCTL_NODE(_net, OID_AUTO, repi, CTLFLAG_RD, 0, "REPI Protocol");

SYSCTL_NODE(_net_repi, OID_AUTO, stats, CTLFLAG_RD, 0, "REPI Statistics");
SYSCTL_PROC(_net_repi_stats, OID_AUTO, input_packets, CTLTYPE_ULONG|CTLFLAG_RD, NULL, 0,
		sysctl_repi_input_dgrams_count_handler, "LU", "Number of input packets");
SYSCTL_PROC(_net_repi_stats, OID_AUTO, output_packets, CTLTYPE_ULONG|CTLFLAG_RD, NULL, 0,
		sysctl_repi_output_dgrams_count_handler, "LU", "Number of output packets");
SYSCTL_PROC(_net_repi_stats, OID_AUTO, forwarded_packets, CTLTYPE_ULONG|CTLFLAG_RD, NULL, 0,
		sysctl_repi_forwarded_dgrams_count_handler, "LU", "Number of forwarded packets");

SYSCTL_NODE(_net_repi, OID_AUTO, control, CTLFLAG_RD, 0, "REPI Control");
SYSCTL_INT(_net_repi_control, OID_AUTO, random_mac_address, CTLFLAG_RW, &repi_random_mac_address, 0,
		"Generate random MAC address for packets");
SYSCTL_INT(_net_repi_control, OID_AUTO, disable_forwarding, CTLFLAG_RW, &repi_packets_forwarding_disabled, 0,
		"Disable packets forwarding");

static void
repi_randomize_mac_address(u_char *mac) {

	int i;

	for(i = 0; i < ETHER_ADDR_LEN; i++)
		mac[i] = arc4random() % 256;

}

static int
repi_output(struct ifnet *ifp, struct mbuf *m) {

	struct sockaddr addr;
	struct ether_header *eh;

	addr.sa_family = AF_REPI;
	addr.sa_len = m->m_hdr.mh_len;

	eh = (struct ether_header *) &addr.sa_data;
	eh->ether_type = htons(ETHERTYPE_REPI);
	memcpy(eh->ether_dhost, ifp->if_broadcastaddr, ETHER_ADDR_LEN);

	/* Randomize MAC address? */
	if(repi_random_mac_address)
		repi_randomize_mac_address(eh->ether_shost);
	else
		memcpy(eh->ether_shost, IF_LLADDR(ifp), ETHER_ADDR_LEN);

	/* Update statistics */
	counter_u64_add(repi_output_dgrams_count, 1);

	/* Fly packet, fly! */
	return((*ifp->if_output)(ifp, m, &addr, NULL));

}


static void
repi_input_internal(struct mbuf *m) {

	struct repi_user_message repi_umsg;
	struct ifnet *ifp = m->m_pkthdr.rcvif;
	u_short repi_type;

	printf("Packet input...\n");
	printf("Size: %d\n", m->m_hdr.mh_len);

	memcpy(&repi_type, m->m_hdr.mh_data, 2);
	memcpy(&repi_umsg, m->m_hdr.mh_data + 2, m->m_hdr.mh_len);

	printf("REPI type: %d\n", repi_type);

	if(repi_type == REPITYPE_MSG) {

		repi_umsg.chat_text[54] = '\0';
		repi_umsg.chat_id[9] = '\0';
		repi_umsg.custom_int[7] = '\0';
		repi_umsg.prefix[31] = '\0';
		/*
		printf("message: %s\n", repi_umsg.chat_text);
		printf("chat id: %s\n", repi_umsg.chat_id);
		printf("custom int: %s\n", repi_umsg.custom_int);
		printf("source: %x%x%x%x%x%x\n", 
				repi_umsg.source[0],
				repi_umsg.source[1],
				repi_umsg.source[2],
				repi_umsg.source[3],
				repi_umsg.source[4],
				repi_umsg.source[5]);
		printf("last hop: %x%x%x%x%x%x\n", 
				repi_umsg.last_hop[0],
				repi_umsg.last_hop[1],
				repi_umsg.last_hop[2],
				repi_umsg.last_hop[3],
				repi_umsg.last_hop[4],
				repi_umsg.last_hop[5]);
		printf("HTL: %d\n", repi_umsg.htl); 
		printf("seqno: %d\n", repi_umsg.seqno); 
		printf("prefix: %s\n", repi_umsg.prefix); 
*/
	}

	/* Reply the packet to the other machines? */
	if(!repi_packets_forwarding_disabled) {
		/* Update statistics */
		counter_u64_add(repi_forwarded_dgrams_count, 1);

		/* TODO: Implementar as restricoes para o forwarding */

		repi_output(ifp, m);
	}

	m_free(m);

	/* Update statistics */
	counter_u64_add(repi_input_dgrams_count, 1);

}

static void
repi_nh_input(struct mbuf *m) {

	repi_input_internal(m);

}

static struct netisr_handler repi_nh = {

	.nh_name = "repi",
	.nh_handler = repi_nh_input,
	.nh_proto = NETISR_REPI,
	.nh_policy = NETISR_POLICY_SOURCE,
	.nh_dispatch = NETISR_DISPATCH_DIRECT,

};

static void
repi_init(__unused void *args) {

	printf("REPI Initializing...\n");

	repi_input_dgrams_count = counter_u64_alloc(M_WAITOK);
	repi_output_dgrams_count = counter_u64_alloc(M_WAITOK);
	repi_forwarded_dgrams_count = counter_u64_alloc(M_WAITOK);

	counter_u64_zero(repi_input_dgrams_count);
	counter_u64_zero(repi_output_dgrams_count);
	counter_u64_zero(repi_forwarded_dgrams_count);

	netisr_register(&repi_nh);

}

static void
repi_uninit(void) {

	counter_u64_free(repi_input_dgrams_count);
	counter_u64_free(repi_output_dgrams_count);
	counter_u64_free(repi_forwarded_dgrams_count);

	netisr_unregister(&repi_nh);

}

SYSINIT(repi_init, SI_SUB_PROTO_DOMAIN, SI_ORDER_ANY, repi_init, NULL);
SYSUNINIT(repi_uninit, SI_SUB_PROTO_DOMAIN, SI_ORDER_ANY, repi_uninit, NULL);

