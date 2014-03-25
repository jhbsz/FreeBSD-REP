# $FreeBSD: head/usr.sbin/bsdconfig/Makefile 258400 2013-11-20 20:37:21Z dteske $

SUBDIR=	console \
	diskmgmt \
	docsinstall \
	dot \
	examples \
	include \
	includes \
	mouse \
	networking \
	packages \
	password \
	security \
	share \
	startup \
	timezone \
	ttys \
	usermgmt

FILESDIR=	${LIBEXECDIR}/bsdconfig
FILES=		USAGE

SCRIPTS= bsdconfig

MAN= bsdconfig.8

beforeinstall:
	mkdir -p ${DESTDIR}${FILESDIR}
	mkdir -p ${DESTDIR}${SCRIPTSDIR}
	mkdir -p ${DESTDIR}${MANDIR}8

.include <bsd.prog.mk>
