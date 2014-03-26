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


#ifndef _NETREPI_REPI_H_
#define _NETREPI_REPI_H_

/* Message types */

#define REPITYPE_MSG	0	/* REPI message */
#define	REPITYPE_STATUS	1	/* REPI status message */
#define	REPITYPE_TIME	2	/* Time counter packet */

/* Number of input repi datagrams */
static counter_u64_t repi_input_dgrams_count = NULL;

/* Number of output repi datagrams */
static counter_u64_t repi_output_dgrams_count = NULL;

/* Number of forwarded datagrams */
static counter_u64_t repi_forwarded_dgrams_count = NULL;

/* Generate random MAC address */
static int repi_random_mac_address = 0;

/* Enable/Disable packets forwarding */
static int repi_packets_forwarding_disabled = 0;


struct repi_user_message {
	char 	chat_text[55];	/* Text message from the messaging application */
	char 	chat_id[10];	/* Application user's alias */
	char 	custom_int[8];	/* User's custom interest */
	u_char 	source[ETHER_ADDR_LEN];	/* Source address */
	u_char 	last_hop[ETHER_ADDR_LEN];	/* Address of the last machine the transmit the packet */
	u_char 	htl;	/* Hops to live / TTL */
	u_int	seqno;	/* Packet identifier */
	u_char	prefix[32];	/* Features and interests of the user */
};


struct repi_status_message {
	u_char	err_code;
	u_char	source_addr[ETHER_ADDR_LEN];
	u_char	is_err;
};


struct repi_time_message {
	u_int	time_left;
	u_int	time_arrive;
	u_char	hops;
};

#endif /* !_NETREPI_REPI_H_ */
