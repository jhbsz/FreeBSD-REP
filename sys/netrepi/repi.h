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

#include <net/if.h>
#include <net/ethernet.h>
#include <netrepi/types.h>

#include <sys/hash.h>

#ifdef _KERNEL

#include <sys/counter.h>

/* Message types */

#define REPITYPE_MSG	0	/* REPI message */
#define	REPITYPE_STATUS	1	/* REPI status message */
#define	REPITYPE_TIME	2	/* Time counter packet */

/* TODO: colocar essas variaveis todas em repi.c */

struct repi_stats {
	counter_u64_t repi_input_dgrams_count;		/* Number of input repi datagrams */
	counter_u64_t repi_output_dgrams_count;		/* Number of output repi datagrams */
	counter_u64_t repi_forwarded_dgrams_count;	/* Number of forwarded datagrams */
	counter_u64_t repi_input_bytes_count;		/* Total #bytes received */
	counter_u64_t repi_output_bytes_count;		/* Total #bytes sent */
	counter_u64_t repi_forwarded_bytes_count;	/* Total #bytes forwarded */
};


/* Generate random MAC address */
static int repi_random_mac_address = 0;

/* Enable/Disable packets forwarding */
static int repi_packets_forwarding_disabled = 0;

/* TODO: deve ser local e colocada aqui com export */
static int repi_hash_size = 4096;
static int repi_hash_seed = 0;

extern struct ifnet *repi_ifnet;


/* Macros to work with repi hash */

#define REPI_HASH_PACKET_CREATE(hdr) \
	jenkins_hash32(&(hdr->seq_number), \
			sizeof(hdr->seq_number), repi_hash_seed)

#define REPI_HASH_BIND_CREATE(interest) \
	hash32_strn(interest, \
			strlen(interest), repi_hash_seed)

#define	REPI_HASH_MOD(hash)	(hash % repi_hash_size)
		

/* Functions */
int
repi_output(struct ifnet *ifp, struct mbuf *m);

#endif // _KERNEL

#define	REPI_MAX_INTEREST_LEN	253

#define REPI_PREFIX_LENGTH	8 /* In fields */
#define REPI_FIELD_LENGTH	3 /* In bits */
#define REPI_MASK_FIELD(size, nField, field, length) \
	(((1 << length) - 1) << (field * (size / nField)))

#define REPIPROTO_REPI		1

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


struct repi_header {
	uint8_t			version:4,		/* Protocol version */
					hide_flag:1,	/* Hide the interest */
					crypto:1,		/* Interest and data is encrypted? */
					other_flags:2;	/* Don't used yet */
	uint8_t			ttl;			/* Time to live (hop counter) */
	uint16_t		hlen;			/* Header Length */
	uint32_t		seq_number;		/* Sequence number */
	prefix_addr_t	prefix_dst;		/* Destination prefix */
	prefix_addr_t	prefix_src;		/* Source prefix */
	uint64_t		timestamp;		/* Timestamp when the packet was sent */
	uint32_t		interest;		/* Application interest hash */
};

struct repi_addr {
	prefix_addr_t *prefix_buf;
	struct ifreq ifreq;
};

struct sockaddr_repi {
	uint8_t 	repi_len;
	sa_family_t	repi_family;
	char 		interest[253];	/* TODO: mudar para repi_interest */
};


#endif /* !_NETREPI_REPI_H_ */
