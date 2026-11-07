/*

  Definitions for winsock 1.1
  
  Portions Copyright (c) 1980, 1983, 1988, 1993
  The Regents of the University of California.  All rights reserved.

  Portions Copyright (c) 1993 by Digital Equipment Corporation.
 */

#ifndef _WINSOCK_H
#define _WINSOCK_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#define _GNU_H_WINDOWS32_SOCKETS

#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_
#endif

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined ( _BSDTYPES_DEFINED )
/* also defined in gmon.h and in cygwin's sys/types */
typedef unsigned char	u_char;
typedef unsigned short	u_short;
typedef unsigned int	u_int;
typedef unsigned long	u_long;
#define _BSDTYPES_DEFINED
#endif /* !defined  _BSDTYPES_DEFINED */
typedef u_int	SOCKET;
#ifndef FD_SETSIZE
#define FD_SETSIZE	64
#endif

/* shutdown() how types */
#define SD_RECEIVE      0x00
#define SD_SEND         0x01
#define SD_BOTH         0x02

#ifndef _SYS_TYPES_FD_SET
/* fd_set may have be defined by the newlib <sys/types.h>
 * if  __USE_W32_SOCKETS not defined.
 */
#ifdef fd_set
#undef fd_set
#endif
typedef struct fd_set {
	u_int   fd_count;
	SOCKET  fd_array[FD_SETSIZE];
} fd_set;
/**
 * Tests whether a socket is in an fd_set.
 *
 * The implementation behind the FD_ISSET macro: use FD_ISSET instead.
 *
 * @param fd The socket.
 * @param set The set, e.g. as returned by select.
 * @return Nonzero if fd is in the set, otherwise 0.
 */
int PASCAL __WSAFDIsSet(SOCKET fd,fd_set*set);
#ifndef FD_CLR
#define FD_CLR(fd,set) do { u_int __i;\
for (__i = 0; __i < ((fd_set *)(set))->fd_count ; __i++) {\
	if (((fd_set *)(set))->fd_array[__i] == (fd)) {\
	while (__i < ((fd_set *)(set))->fd_count-1) {\
		((fd_set*)(set))->fd_array[__i] = ((fd_set*)(set))->fd_array[__i+1];\
		__i++;\
	}\
	((fd_set*)(set))->fd_count--;\
	break;\
	}\
}\
} while (0)
#endif
#ifndef FD_SET
#define FD_SET(fd, set) do { \
    if (((fd_set *)(set))->fd_count < FD_SETSIZE) \
	((fd_set *)(set))->fd_array[((fd_set *)(set))->fd_count++]=(fd);\
}while (0)
#endif
#ifndef FD_ZERO
#define FD_ZERO(set) (((fd_set *)(set))->fd_count=0)
#endif
#ifndef FD_ISSET
#define FD_ISSET(fd, set) __WSAFDIsSet((SOCKET)(fd), (fd_set *)(set))
#endif
#elif !defined(USE_SYS_TYPES_FD_SET)
#warning "fd_set and associated macros have been defined in sys/types.  \
    This can cause runtime problems with W32 sockets" 
#endif /* ndef _SYS_TYPES_FD_SET */

#if !(defined (__INSIDE_CYGWIN__) || defined (__INSIDE_MSYS__))
#ifndef _TIMEVAL_DEFINED /* also in sys/time.h */
#define _TIMEVAL_DEFINED
struct timeval {
	long    tv_sec;
	long    tv_usec;
};
#define timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#define timercmp(tvp, uvp, cmp) \
	(((tvp)->tv_sec != (uvp)->tv_sec) ? \
	((tvp)->tv_sec cmp (uvp)->tv_sec) : \
	((tvp)->tv_usec cmp (uvp)->tv_usec))
#define timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#endif /* _TIMEVAL_DEFINED */
struct  hostent {
	char	*h_name;
	char	**h_aliases;
	short	h_addrtype;
	short	h_length;
	char	**h_addr_list;
#define h_addr h_addr_list[0]
};
struct linger {
	u_short l_onoff;
	u_short l_linger;
};
#endif /* ! (__INSIDE_CYGWIN__ || __INSIDE_MSYS__) */
#ifdef _WIN32_WCE
#define IOCPARM_MASK	0x7ff
#else
#define IOCPARM_MASK	0x7f
#endif
#define IOC_VOID	0x20000000
#define IOC_OUT	0x40000000
#define IOC_IN	0x80000000
#define IOC_INOUT	(IOC_IN|IOC_OUT)

#if !(defined (__INSIDE_CYGWIN__) || defined (__INSIDE_MSYS__))
#define _IO(x,y)	(IOC_VOID|((x)<<8)|(y))
#define _IOR(x,y,t)	(IOC_OUT|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))
#define _IOW(x,y,t)	(IOC_IN|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))
#define FIONBIO	_IOW('f', 126, u_long)
#endif /* ! (__INSIDE_CYGWIN__ || __INSIDE_MSYS__) */

#define FIONREAD	_IOR('f', 127, u_long)
#define FIOASYNC	_IOW('f', 125, u_long)
#define SIOCSHIWAT	_IOW('s',  0, u_long)
#define SIOCGHIWAT	_IOR('s',  1, u_long)
#define SIOCSLOWAT	_IOW('s',  2, u_long)
#define SIOCGLOWAT	_IOR('s',  3, u_long)
#define SIOCATMARK	_IOR('s',  7, u_long)

#if !(defined (__INSIDE_CYGWIN__) || defined (__INSIDE_MSYS__))
struct netent {
	char	* n_name;
	char	**n_aliases;
	short	n_addrtype;
	u_long n_net;
};
struct  servent {
	char	*s_name;
	char	**s_aliases;
	short	s_port;
	char	*s_proto;
};
struct  protoent {
	char	*p_name;
	char	**p_aliases;
	short	p_proto;
};
#endif /* ! (__INSIDE_CYGWIN__ || __INSIDE_MSYS__) */

#define IPPROTO_IP	0
#define IPPROTO_ICMP	1
#define IPPROTO_IGMP 2
#ifdef _WIN32_WCE
#define IPPROTO_GGP 2
#else
#define IPPROTO_GGP 3
#endif
#define IPPROTO_TCP	6
#define IPPROTO_PUP	12
#define IPPROTO_UDP	17
#define IPPROTO_IDP	22
#define IPPROTO_ND	77
#define	IPPROTO_RM	113
#define IPPROTO_RAW	255
#define IPPROTO_MAX	256

#define BTHPROTO_RFCOMM	3

#define IPPORT_ECHO	7
#define IPPORT_DISCARD	9
#define IPPORT_SYSTAT	11
#define IPPORT_DAYTIME  13
#define IPPORT_NETSTAT  15
#define IPPORT_FTP      21
#define IPPORT_TELNET   23
#define IPPORT_SMTP     25
#define IPPORT_TIMESERVER 37
#define IPPORT_NAMESERVER 42
#define IPPORT_WHOIS	43
#define IPPORT_MTP	57
#define IPPORT_TFTP	69
#define IPPORT_RJE	77
#define IPPORT_FINGER	79
#define IPPORT_TTYLINK	87
#define IPPORT_SUPDUP	95
#define IPPORT_EXECSERVER	512
#define IPPORT_LOGINSERVER	513
#define IPPORT_CMDSERVER	514
#define IPPORT_EFSSERVER	520
#define IPPORT_BIFFUDP	512
#define IPPORT_WHOSERVER	513
#define IPPORT_ROUTESERVER	520
#define IPPORT_RESERVED	1024
#define IMPLINK_IP	155
#define IMPLINK_LOWEXPER	156
#define IMPLINK_HIGHEXPER       158
struct in_addr {
	union {
		struct { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
		struct { u_short s_w1,s_w2; } S_un_w;
		u_long S_addr;
	} S_un;
#define s_addr  S_un.S_addr
#define s_host  S_un.S_un_b.s_b2
#define s_net   S_un.S_un_b.s_b1
#define s_imp   S_un.S_un_w.s_w2
#define s_impno S_un.S_un_b.s_b4
#define s_lh    S_un.S_un_b.s_b3
};
#define IN_CLASSA(i)	(((long)(i)&0x80000000) == 0)
#define IN_CLASSA_NET	0xff000000
#define IN_CLASSA_NSHIFT	24
#define IN_CLASSA_HOST	0x00ffffff
#define IN_CLASSA_MAX	128
#define IN_CLASSB(i)	(((long)(i)&0xc0000000)==0x80000000)
#define IN_CLASSB_NET	   0xffff0000
#define IN_CLASSB_NSHIFT	16
#define IN_CLASSB_HOST	  0x0000ffff
#define IN_CLASSB_MAX	   65536
#define IN_CLASSC(i)	(((long)(i)&0xe0000000)==0xc0000000)
#define IN_CLASSC_NET	   0xffffff00
#define IN_CLASSC_NSHIFT	8
#define IN_CLASSC_HOST	  0xff
#define INADDR_ANY	      (u_long)0
#define INADDR_LOOPBACK	 0x7f000001
#define INADDR_BROADCAST	(u_long)0xffffffff
#define INADDR_NONE	0xffffffff
struct sockaddr_in {
	short	sin_family;
	u_short	sin_port;
	struct	in_addr sin_addr;
	char	sin_zero[8];
};
#define WSADESCRIPTION_LEN	256
#define WSASYS_STATUS_LEN	128
/**
 * This structure is used to store Windows Sockets initialization data
 * returned by a call to WSAStartup. It contains data about the Winsock.dll
 * implementation.
 *
 * WSAStartup assigns the following values to the members of the WSADATA
 * structure:
 *
 * WSADATA member Assigned value wVersion wVersionRequested parameter value
 * wHighVersion wVersionRequested parameter value szDescription NULL string
 * szSystemStatus NULL string iMaxSockets 20 iMaxUdpDg 0 lpVendorInfo NULL
 */
typedef struct WSAData {
	/**
	 * Version of the Windows Sockets specification that the
	 * Windows Sockets DLL expects the caller to use. The high-order
	 * word specifies the minor version (revision) number; and the
	 * low-order word specifies the major version number.
	 */
	WORD	wVersion;
	/**
	 * Highest version of the Windows Sockets
	 * specification that this DLL can support, usually the same as
	 * wVersion.
	 */
	WORD	wHighVersion;
	/**
	 * Null-terminated string into which the Windows
	 * Sockets DLL copies a description of the Windows Sockets
	 * implementation, including vendor identification. The text-up to
	 * 256 characters in length-can contain any characters, but vendors
	 * are cautioned against including control and formatting
	 * characters. Typically, an application uses this description in a
	 * status message.
	 */
	char	szDescription[WSADESCRIPTION_LEN+1];
	/**
	 * Null-terminated string into which the Windows
	 * Sockets DLL copies relevant status or configuration data. The
	 * Windows Sockets DLL should use this member only if the data might
	 * be useful to the user or support staff; it should not be
	 * considered as an extension of the szDescription member.
	 */
	char	szSystemStatus[WSASYS_STATUS_LEN+1];
	/**
	 * Maximum number of sockets which a single process can
	 * potentially open. A Windows Sockets implementation can provide a
	 * global pool of sockets for allocation to any process;
	 * alternatively it can allocate per-process resources for sockets.
	 * The number can well reflect the way in which the Windows Sockets
	 * DLL or the networking software was configured. Application
	 * writers can use this number as a crude indication of whether the
	 * Windows Sockets implementation is usable by the application. For
	 * example, an X Windows server might check iMaxSockets when first
	 * started: if it is less than 8, the application would display an
	 * error message instructing the user to reconfigure the networking
	 * software. (This is a situation in which the szSystemStatus text
	 * might be used.) Obviously there is no guarantee that a particular
	 * application can actually allocate iMaxSockets sockets, since
	 * there can be other Windows Sockets applications in use.
	 */
	unsigned short	iMaxSockets;
	/**
	 * Size, in bytes, of the largest User Datagram Protocol
	 * (UDP) datagram that can be sent or received by a Windows Sockets
	 * application. If the implementation imposes no limit, iMaxUdpDg is
	 * zero. In many implementations of Berkeley sockets, there is an
	 * implicit limit of 8192 bytes on UDP datagrams, which are
	 * fragmented if necessary. A Windows Sockets implementation can
	 * impose a limit based, for instance, on the allocation of fragment
	 * reassembly buffers. The minimum value of iMaxUdpDg for a
	 * compliant Windows Sockets implementation is 512. Note that
	 * regardless of the value of iMaxUdpDg, it is inadvisable to
	 * attempt to send a broadcast datagram which is larger than the
	 * Maximum Transmission Unit (MTU) for the network. The Windows
	 * Sockets API does not provide a mechanism to discover the MTU, but
	 * it must be no less than 512 bytes.
	 */
	unsigned short	iMaxUdpDg;
	/**
	 * Long pointer to a vendor-specific data structure.
	 * The definition of this structure (if supplied) is beyond the
	 * scope of the Windows Sockets specification.
	 */
	char * 	lpVendorInfo;
} WSADATA;
typedef WSADATA *LPWSADATA;

#if !(defined (__INSIDE_CYGWIN__) || defined (__INSIDE_MSYS__))
#define IP_OPTIONS	1
#define SO_DEBUG	1
#define SO_ACCEPTCONN	2
#define SO_REUSEADDR	4
#define SO_KEEPALIVE	8
#define SO_DONTROUTE	16
#define SO_BROADCAST	32
#define SO_USELOOPBACK	64
#define SO_LINGER	128
#define SO_OOBINLINE	256
#define SO_DONTLINGER	(u_int)(~SO_LINGER)
#define SO_SNDBUF	0x1001
#define SO_RCVBUF	0x1002
#define SO_SNDLOWAT	0x1003
#define SO_RCVLOWAT	0x1004
#define SO_SNDTIMEO	0x1005
#define SO_RCVTIMEO	0x1006
#define SO_ERROR	0x1007
#define SO_TYPE	0x1008
#endif /* ! (__INSIDE_CYGWIN__ || __INSIDE_MSYS__) */
/*
 * Note that the next 5 IP defines are specific to WinSock 1.1 (wsock32.dll).
 * They will cause errors or unexpected results if used with the
 * (gs)etsockopts exported from the WinSock 2 lib, ws2_32.dll. Refer ws2tcpip.h.
 */         
#define IP_MULTICAST_IF	2
#define IP_MULTICAST_TTL	3
#define IP_MULTICAST_LOOP	4
#define IP_ADD_MEMBERSHIP	5
#define IP_DROP_MEMBERSHIP  6

#define IP_DEFAULT_MULTICAST_TTL   1
#define IP_DEFAULT_MULTICAST_LOOP  1
#define IP_MAX_MEMBERSHIPS	 20
struct ip_mreq {
	struct in_addr imr_multiaddr;
	struct in_addr imr_interface;
};
#define INVALID_SOCKET (SOCKET)(~0)
#define SOCKET_ERROR	(-1)
#define SOCK_STREAM	1
#define SOCK_DGRAM	2
#define SOCK_RAW	3
#define SOCK_RDM	4
#define SOCK_SEQPACKET	5
#define TCP_NODELAY	0x0001
#define AF_UNSPEC	0
#define AF_UNIX	1
#define AF_INET	2
#define AF_IMPLINK	3
#define AF_PUP	4
#define AF_CHAOS	5
#define AF_IPX	6
#define AF_NS	6
#define AF_ISO	7
#define AF_OSI	AF_ISO
#define AF_ECMA	8
#define AF_DATAKIT	9
#define AF_CCITT	10
#define AF_SNA	11
#define AF_DECnet	12
#define AF_DLI	13
#define AF_LAT	14
#define AF_HYLINK	15
#define AF_APPLETALK	16
#define AF_NETBIOS	17
#define AF_VOICEVIEW	18
#define	AF_FIREFOX	19
#define	AF_UNKNOWN1	20
#define	AF_BAN	21
#define AF_ATM	22
#define AF_INET6	23
#ifdef _WIN32_WCE
#define AF_IRDA     22
#else
#define AF_IRDA     26
#endif
#define	AF_BTH	32
#define	AF_BT	32
#if !(defined (__INSIDE_CYGWIN__) || defined (__INSIDE_MSYS__))
#ifdef _WIN32_WCE
#if GRIMACE_CE == 1
#define AF_MAX	23
#else
#define AF_MAX	24
#endif
#else
#define AF_MAX	33
#endif
struct sockaddr {
	u_short sa_family;
	char	sa_data[14];
};
#endif /* ! (__INSIDE_CYGWIN__ || __INSIDE_MSYS__) */

struct sockproto {
	u_short sp_family;
	u_short sp_protocol;
};
#define PF_UNSPEC	AF_UNSPEC
#define PF_UNIX	AF_UNIX
#define PF_INET	AF_INET
#define PF_IMPLINK	AF_IMPLINK
#define PF_PUP	AF_PUP
#define PF_CHAOS	AF_CHAOS
#define PF_NS	AF_NS
#define PF_IPX	AF_IPX
#define PF_ISO	AF_ISO
#define PF_OSI	AF_OSI
#define PF_ECMA	AF_ECMA
#define PF_DATAKIT	AF_DATAKIT
#define PF_CCITT	AF_CCITT
#define PF_SNA	AF_SNA
#define PF_DECnet	AF_DECnet
#define PF_DLI	AF_DLI
#define PF_LAT	AF_LAT
#define PF_HYLINK	AF_HYLINK
#define PF_APPLETALK	AF_APPLETALK
#define PF_VOICEVIEW	AF_VOICEVIEW
#define PF_FIREFOX	AF_FIREFOX
#define PF_UNKNOWN1	AF_UNKNOWN1
#define PF_BAN	AF_BAN
#define PF_ATM	AF_ATM
#define PF_INET6	AF_INET6
#define PF_IRDA	AF_IRDA
#define	PF_BTH	AF_BTH
#define PF_MAX	AF_MAX
#define SOL_SOCKET	0xffff
#define SOMAXCONN	5
#if !(defined (__INSIDE_CYGWIN__) || defined (__INSIDE_MSYS__))
#define MSG_OOB	1
#define MSG_PEEK	2
#define MSG_DONTROUTE	4
#endif  /* ! (__INSIDE_CYGWIN__ || __INSIDE_MSYS__) */
#define MSG_MAXIOVLEN	16
#define MSG_PARTIAL	0x8000
#define MAXGETHOSTSTRUCT	1024
#define FD_READ	1
#define FD_WRITE	2
#define FD_OOB	4
#define FD_ACCEPT	8
#define FD_CONNECT	16
#define FD_CLOSE	32
#ifndef WSABASEERR
#define WSABASEERR	10000
#define WSAEINTR	(WSABASEERR+4)
#define WSAEBADF	(WSABASEERR+9)
#define WSAEACCES	(WSABASEERR+13)
#define WSAEFAULT	(WSABASEERR+14)
#define WSAEINVAL	(WSABASEERR+22)
#define WSAEMFILE	(WSABASEERR+24)
#define WSAEWOULDBLOCK	(WSABASEERR+35)
#define WSAEINPROGRESS	(WSABASEERR+36)
#define WSAEALREADY	(WSABASEERR+37)
#define WSAENOTSOCK	(WSABASEERR+38)
#define WSAEDESTADDRREQ	(WSABASEERR+39)
#define WSAEMSGSIZE	(WSABASEERR+40)
#define WSAEPROTOTYPE	(WSABASEERR+41)
#define WSAENOPROTOOPT	(WSABASEERR+42)
#define WSAEPROTONOSUPPORT	(WSABASEERR+43)
#define WSAESOCKTNOSUPPORT	(WSABASEERR+44)
#define WSAEOPNOTSUPP	(WSABASEERR+45)
#define WSAEPFNOSUPPORT	(WSABASEERR+46)
#define WSAEAFNOSUPPORT	(WSABASEERR+47)
#define WSAEADDRINUSE	(WSABASEERR+48)
#define WSAEADDRNOTAVAIL	(WSABASEERR+49)
#define WSAENETDOWN	(WSABASEERR+50)
#define WSAENETUNREACH	(WSABASEERR+51)
#define WSAENETRESET	(WSABASEERR+52)
#define WSAECONNABORTED	(WSABASEERR+53)
#define WSAECONNRESET	(WSABASEERR+54)
#define WSAENOBUFS	(WSABASEERR+55)
#define WSAEISCONN	(WSABASEERR+56)
#define WSAENOTCONN	(WSABASEERR+57)
#define WSAESHUTDOWN	(WSABASEERR+58)
#define WSAETOOMANYREFS	(WSABASEERR+59)
#define WSAETIMEDOUT	(WSABASEERR+60)
#define WSAECONNREFUSED	(WSABASEERR+61)
#define WSAELOOP	(WSABASEERR+62)
#define WSAENAMETOOLONG	(WSABASEERR+63)
#define WSAEHOSTDOWN	(WSABASEERR+64)
#define WSAEHOSTUNREACH	(WSABASEERR+65)
#define WSAENOTEMPTY	(WSABASEERR+66)
#define WSAEPROCLIM	(WSABASEERR+67)
#define WSAEUSERS	(WSABASEERR+68)
#define WSAEDQUOT	(WSABASEERR+69)
#define WSAESTALE	(WSABASEERR+70)
#define WSAEREMOTE	(WSABASEERR+71)
#define WSAEDISCON	(WSABASEERR+101)
#define WSASYSNOTREADY	(WSABASEERR+91)
#define WSAVERNOTSUPPORTED	(WSABASEERR+92)
#define WSANOTINITIALISED	(WSABASEERR+93)
#define WSAHOST_NOT_FOUND	(WSABASEERR+1001)
#define WSATRY_AGAIN	(WSABASEERR+1002)
#define WSANO_RECOVERY	(WSABASEERR+1003)
#define WSANO_DATA	(WSABASEERR+1004)
#endif /* !WSABASEERR */

#define WSANO_ADDRESS	WSANO_DATA
#if !(defined (__INSIDE_CYGWIN__) || defined (__INSIDE_MSYS__))
#define h_errno WSAGetLastError()
#define HOST_NOT_FOUND	WSAHOST_NOT_FOUND
#define TRY_AGAIN	WSATRY_AGAIN
#define NO_RECOVERY	WSANO_RECOVERY
#define NO_DATA	WSANO_DATA
#define NO_ADDRESS	WSANO_ADDRESS
#endif /* ! (__INSIDE_CYGWIN__ || __INSIDE_MSYS__) */
/**
 * Accepts a pending connection on a listening socket.
 *
 * Returns a new connected socket; the listening socket stays open. Blocks
 * until a connection arrives unless the socket is nonblocking.
 *
 * @param s Socket that has been bound and put in listen mode.
 * @param addr Receives the peer's address, or NULL. Must be NULL for
 *        IrDA sockets.
 * @param addrlen In: size of addr in bytes. Out: size of the address
 *        stored. NULL if addr is NULL, and for IrDA sockets.
 * @return The new socket, or INVALID_SOCKET on failure (see
 *         WSAGetLastError; WSAEWOULDBLOCK if nonblocking with nothing
 *         pending). Windows CE never returns WSAEINTR.
 */
SOCKET PASCAL accept(SOCKET s,struct sockaddr*addr,int*addrlen);
/**
 * Assigns a local address and port to a socket.
 *
 * Call before listen, or before recvfrom on an unconnected datagram
 * socket. With INADDR_ANY any local interface is used; with port 0 the
 * stack picks a free port in the range 1024 to 5000 (see getsockname).
 * For IrDA sockets, include af_irda.h and pass a SOCKADDR_IRDA; there is
 * no INADDR_ANY equivalent, and IrDA clients don't call bind.
 *
 * @param s Unbound socket.
 * @param addr Local address, e.g. a SOCKADDR_IN cast to struct sockaddr *.
 * @param namelen Size of addr in bytes.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError, e.g.
 *        WSAEADDRINUSE).
 */
int PASCAL bind(SOCKET s,const struct sockaddr*addr,int namelen);
/**
 * Closes a socket and frees its descriptor.
 *
 * By default, returns at once and sends any queued data in the
 * background. With SO_LINGER and a zero timeout, it resets the connection
 * and discards unsent data; with a nonzero timeout it blocks until the
 * data is sent or the timeout expires (WSAEWOULDBLOCK if the socket is
 * nonblocking).
 *
 * @param s The socket.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError). Windows CE
 *         never returns WSAEINTR.
 */
int PASCAL closesocket(SOCKET s);
/**
 * Connects a socket to a remote address.
 *
 * For a stream socket, opens the connection. For a datagram socket, sets
 * the default destination for send and recv. Binds an unbound socket
 * automatically. On a nonblocking socket it fails with WSAEWOULDBLOCK
 * and completes in the background: select for writability to see when.
 * For IrDA, find a device with the IRLMP_ENUMDEVICES socket option and
 * pass a SOCKADDR_IRDA.
 *
 * @param s Unconnected socket.
 * @param name Remote address, e.g. a SOCKADDR_IN.
 * @param namelen Size of name in bytes.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError, e.g.
 *         WSAECONNREFUSED, WSAETIMEDOUT). Windows CE never returns
 *         WSAEINTR.
 */
int PASCAL connect(SOCKET s,const struct sockaddr*name,int namelen);
/**
 * Gets or sets a socket's I/O mode.
 *
 * @param s The socket.
 * @param cmd FIONBIO (set nonblocking if *argp is nonzero, blocking if 0;
 *        sockets start blocking), FIONREAD (*argp receives the bytes a
 *        single recv can read, or the size of the next datagram) or
 *        SIOCATMARK (*argp receives TRUE if no out-of-band data is waiting;
 *        SOCK_STREAM with SO_OOBINLINE only).
 * @param argp Argument for cmd, in and/or out.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError).
 */
int PASCAL ioctlsocket(SOCKET s,long cmd,u_long *argp);
/**
 * Returns the remote address of a connected socket.
 *
 * @param s Connected socket.
 * @param name Receives the peer address.
 * @param namelen In: size of name in bytes. Out: size of the address
 *        stored.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError; WSAENOTCONN
 *         if not connected).
 */
int PASCAL getpeername(SOCKET s,struct sockaddr*name,int*namelen);
/**
 * Returns the local address of a socket.
 *
 * Useful after bind with port 0, or after connect without bind. A socket
 * bound to INADDR_ANY may not report its IP address until it is connected.
 *
 * @param s Bound or connected socket.
 * @param name Receives the local address.
 * @param namelen In: size of name in bytes. Out: size of the address
 *        stored.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError; WSAEINVAL if
 *         not bound).
 */
int PASCAL getsockname(SOCKET s,struct sockaddr*name,int*namelen);
/**
 * Reads a socket option.
 *
 * Returns the default if the option was never set. Not supported:
 * SO_RCVLOWAT, SO_RCVTIMEO, SO_SNDLOWAT, SO_SNDTIMEO, IP_OPTIONS and
 * TCP_MAXSEG. For IrDA, include af_irda.h: IRLMP_ENUMDEVICES lists
 * devices in range (a DEVICELIST; if the buffer is too small, optlen
 * receives the size needed), IRLMP_IAS_QUERY reads an IAS attribute and
 * IRLMP_SEND_PDU_LEN gives the largest send in IRLMP_IRLPT_MODE. Of the
 * SOL_SOCKET options, IrDA supports only SO_LINGER and SO_DONTLINGER.
 *
 * @param s The socket.
 * @param level SOL_SOCKET, IPPROTO_TCP (for TCP_NODELAY) or SOL_IRLMP.
 * @param optname Option, e.g. SO_ACCEPTCONN, SO_BROADCAST, SO_DEBUG,
 *        SO_DONTLINGER, SO_DONTROUTE, SO_ERROR (reads and clears),
 *        SO_KEEPALIVE, SO_LINGER, SO_OOBINLINE, SO_RCVBUF, SO_REUSEADDR,
 *        SO_SNDBUF, SO_TYPE or TCP_NODELAY.
 * @param optval Receives the value: a struct linger for SO_LINGER, an
 *        int or BOOL for most others.
 * @param optlen In: size of optval in bytes. Out: size of the value.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError;
 *         WSAENOPROTOOPT for an unsupported option).
 */
int PASCAL getsockopt(SOCKET s,int level,int optname,char*optval,int*optlen);
/**
 * Parses a dotted IPv4 address string.
 *
 * Accepts a.b.c.d, and the BSD forms a.b.c, a.b and a, where the last part
 * fills the remaining bytes.
 *
 * @param cp The address string, e.g. "192.168.0.1".
 * @return The address in network byte order, suitable for
 *         sin_addr.s_addr, or INADDR_NONE if the string is invalid. Note
 *         INADDR_NONE is also the value of "255.255.255.255".
 */
unsigned long PASCAL inet_addr(const char*cp);
/**
 * Formats an IPv4 address as a dotted string.
 *
 * The string is in a per-thread Winsock buffer, valid until the next
 * Winsock call on the thread: copy it if you need to keep it.
 *
 * @param in The address.
 * @return The string, e.g. "192.168.0.1", or NULL on failure.
 */
DECLARE_STDCALL_P(char *) inet_ntoa(struct in_addr in);
/**
 * Puts a bound stream socket into listening mode.
 *
 * Accept the connections with accept. Connections arriving when the queue
 * is full are refused.
 *
 * @param s Bound, unconnected SOCK_STREAM socket.
 * @param backlog Maximum queue of pending connections. Silently clamped
 *        to 1 to 5, or to 2 for IrDA sockets.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError).
 */
int PASCAL listen(SOCKET s,int backlog);
/**
 * Receives data from a connected socket.
 *
 * Blocks until data arrives unless the socket is nonblocking
 * (WSAEWOULDBLOCK). A stream socket returns what is available, up to len.
 * A datagram larger than buf is truncated, the rest is lost, and the call
 * fails with WSAEMSGSIZE.
 *
 * @param s Connected socket.
 * @param buf Receives the data.
 * @param len Size of buf in bytes.
 * @param flags 0, or MSG_PEEK (leave the data queued) and/or MSG_OOB.
 * @return Bytes received, 0 if the peer closed the connection gracefully,
 *         or SOCKET_ERROR (see WSAGetLastError, e.g. WSAECONNRESET).
 */
int PASCAL recv(SOCKET s,char*buf,int len,int flags);
/**
 * Receives a datagram and the address it came from.
 *
 * Blocks until data arrives unless the socket is nonblocking
 * (WSAEWOULDBLOCK). A datagram larger than buf is truncated, the rest is
 * lost, and the call fails with WSAEMSGSIZE. On stream sockets it works
 * like recv and from is ignored.
 *
 * @param s Bound socket.
 * @param buf Receives the data.
 * @param len Size of buf in bytes.
 * @param flags 0, or MSG_PEEK (leave the data queued) and/or MSG_OOB.
 * @param from Receives the sender's address, or NULL.
 * @param fromlen In: size of from in bytes. Out: size of the address
 *        stored. NULL if from is NULL.
 * @return Bytes received, 0 if the peer closed a stream connection, or
 *         SOCKET_ERROR (see WSAGetLastError).
 */
int PASCAL recvfrom(SOCKET s,char*buf,int len,int flags,struct sockaddr*from,int*fromlen);
/**
 * Sends data on a connected socket.
 *
 * Success means the data was queued, not delivered. Blocks while there is
 * no buffer space unless the socket is nonblocking (WSAEWOULDBLOCK).
 * A nonblocking stream socket may send fewer bytes than requested. A
 * datagram too large for the protocol fails with WSAEMSGSIZE and nothing
 * is sent. For IrDA sockets, include af_irda.h.
 *
 * @param s Connected socket.
 * @param buf The data.
 * @param len Length of the data in bytes.
 * @param flags 0, or MSG_DONTROUTE (may be ignored) and/or MSG_OOB
 *        (SOCK_STREAM only).
 * @return Bytes sent, which may be less than len, or SOCKET_ERROR (see
 *         WSAGetLastError).
 */
int PASCAL send(SOCKET s,const char*buf,int len,int flags);
/**
 * Sends a datagram to a given address.
 *
 * Success means the data was queued, not delivered. On stream sockets,
 * to and tolen are ignored and it works like send. To broadcast, enable
 * SO_BROADCAST and send to INADDR_BROADCAST; keep broadcasts under 512
 * bytes of data. A datagram too large for the protocol fails with
 * WSAEMSGSIZE and nothing is sent.
 *
 * @param s The socket.
 * @param buf The data.
 * @param len Length of the data in bytes.
 * @param flags 0, or MSG_DONTROUTE (may be ignored) and/or MSG_OOB
 *        (SOCK_STREAM only).
 * @param to Destination address, e.g. a SOCKADDR_IN.
 * @param tolen Size of to in bytes.
 * @return Bytes sent, which may be less than len, or SOCKET_ERROR (see
 *         WSAGetLastError).
 */
int PASCAL sendto(SOCKET s,const char*buf,int len,int flags,const struct sockaddr*to,int tolen);
/**
 * Sets a socket option.
 *
 * For BOOL options, optval points to an int: nonzero to enable, 0 to
 * disable. SO_REUSEADDR only takes effect if set before bind. Not
 * supported: SO_RCVLOWAT, SO_SNDLOWAT and SO_SNDTIMEO; Windows CE 1.0 and
 * 2.0 also don't support SO_ACCEPTCONN, SO_ERROR, SO_TYPE, SO_RCVTIMEO or
 * IP_OPTIONS, and Windows CE 2.0 doesn't support SO_RCVBUF
 * (WSAEOPNOTSUPP). From Windows CE 2.0, SO_SECURE at SOL_SOCKET with a
 * DWORD set to SO_SEC_SSL, before connecting, uses SSL (WSAEISCONN if
 * already connected). Windows CE 3.0 supports IP_MULTICAST_TTL,
 * IP_MULTICAST_IF, IP_ADD_MEMBERSHIP and IP_DROP_MEMBERSHIP at
 * IPPROTO_IP. For IrDA, include af_irda.h: at SOL_IRLMP, IRLMP_IAS_SET
 * sets a local IAS attribute, IRLMP_IRLPT_MODE (nonzero int) enables IrLPT
 * printing mode, and IRLMP_RAW_MODE selects unreliable IrLMP instead of
 * TinyTP and must be set straight after socket, before other Winsock
 * calls. Of the SOL_SOCKET options, IrDA supports only SO_LINGER.
 *
 * @param s The socket.
 * @param level SOL_SOCKET, IPPROTO_TCP (for TCP_NODELAY only), IPPROTO_IP
 *        or SOL_IRLMP.
 * @param optname Option, e.g. SO_BROADCAST, SO_DEBUG, SO_DONTLINGER,
 *        SO_DONTROUTE, SO_KEEPALIVE, SO_LINGER, SO_OOBINLINE,
 *        SO_REUSEADDR, SO_SNDBUF or TCP_NODELAY (disables Nagle).
 * @param optval The value: a struct linger for SO_LINGER (l_onoff,
 *        l_linger in seconds), a DWORD for SO_SECURE, an option-specific
 *        structure, otherwise usually an int.
 * @param optlen Size of optval in bytes.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError;
 *        WSAENOPROTOOPT for an unsupported option).
 */
int PASCAL setsockopt(SOCKET s,int level,int optname,const char*optval,int optlen);
/**
 * Stops sends, receives or both on a socket.
 *
 * Doesn't close the socket or free its resources: call closesocket after.
 * Doesn't block, whatever SO_LINGER says. Don't reuse the socket after
 * shutdown.
 *
 * @param s The socket.
 * @param how 0 (SD_RECEIVE) to stop receiving, 1 (SD_SEND) to stop sending
 *        (TCP sends a FIN), or 2 (SD_BOTH) for both.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError).
 */
int PASCAL shutdown(SOCKET s,int how);
/**
 * Creates a socket.
 *
 * Call WSAStartup first. Close with closesocket.
 *
 * @param af Address family: AF_INET (PF_INET), or AF_IRDA for infrared
 *        (include af_irda.h).
 * @param type SOCK_STREAM (TCP) or SOCK_DGRAM (UDP). IrDA supports only
 *        SOCK_STREAM.
 * @param protocol 0 for the default for af and type. Must be 0 for IrDA.
 * @return The new socket, or INVALID_SOCKET on failure (see
 *         WSAGetLastError; WSAEBADF for IrDA if the shared serial port is
 *         busy).
 */
SOCKET PASCAL socket(int af,int type,int protocol);
/**
 * Looks up a host by its IP address.
 *
 * The result belongs to Winsock, one per thread: don't modify or free it,
 * and copy what you need before the next Winsock call.
 *
 * @param addr The address, in network byte order (e.g. a struct in_addr
 *        cast to const char *).
 * @param len Length of addr: 4.
 * @param type Address family: PF_INET (AF_INET).
 * @return The host entry, or NULL on failure (see WSAGetLastError, e.g.
 *         WSAHOST_NOT_FOUND).
 */
DECLARE_STDCALL_P(struct hostent *) gethostbyaddr(const char*addr,int len,int type);
/**
 * Looks up a host by name.
 *
 * The result belongs to Winsock, one per thread: don't modify or free it,
 * and copy what you need before the next Winsock call. Dotted IP strings
 * aren't resolved: use inet_addr instead. Lookups by a host name in
 * Japanese characters fail on the Japanese version of Windows CE.
 *
 * @param name Host name.
 * @return The host entry, or NULL on failure (see WSAGetLastError, e.g.
 *         WSAHOST_NOT_FOUND).
 */
DECLARE_STDCALL_P(struct hostent *) gethostbyname(const char*name);
/**
 * Looks up a service by port and protocol.
 *
 * The result belongs to Winsock: don't modify or free it, and copy what
 * you need before the next Winsock call.
 *
 * @param port Port number, in network byte order.
 * @param proto Protocol name, e.g. "tcp", or NULL to match any.
 * @return The service entry, or NULL on failure (see WSAGetLastError).
 *
 * @note Windows CE 1.0 only.
 */
DECLARE_STDCALL_P(struct servent *) getservbyport(int port,const char*proto);
/**
 * Looks up a service's port by name and protocol.
 *
 * The result belongs to Winsock: don't modify or free it, and copy what
 * you need before the next Winsock call. s_port is in network byte order.
 *
 * @param name Service name, e.g. "http".
 * @param proto Protocol name, e.g. "tcp", or NULL to match any.
 * @return The service entry, or NULL on failure (see WSAGetLastError).
 *
 * @note Windows CE 1.0 only.
 */
DECLARE_STDCALL_P(struct servent *) getservbyname(const char*name,const char*proto);
/**
 * Looks up a protocol by number.
 *
 * The result belongs to Winsock: don't modify or free it, and copy what
 * you need before the next Winsock call.
 *
 * @param number Protocol number in host byte order, e.g. IPPROTO_TCP.
 * @return The protocol entry, or NULL on failure (see WSAGetLastError).
 *
 * @note Windows CE 1.0 only.
 */
DECLARE_STDCALL_P(struct protoent *) getprotobynumber(int number);
/**
 * Looks up a protocol by name.
 *
 * The result belongs to Winsock: don't modify or free it, and copy what
 * you need before the next Winsock call.
 *
 * @param name Protocol name, e.g. "tcp" or "udp".
 * @return The protocol entry, or NULL on failure (see WSAGetLastError).
 *
 * @note Windows CE 1.0 only.
 */
DECLARE_STDCALL_P(struct protoent *) getprotobyname(const char*name);
/**
 * Initializes Winsock and negotiates the supported socket API version.
 *
 * Call this before other Winsock functions, and call WSACleanup once for
 * every successful startup. Windows CE reports version 1.1. If the
 * version in lpWSAData->wVersion is unacceptable, call WSACleanup. On
 * failure, the return value itself is the error code; don't call
 * WSAGetLastError.
 *
 * @param wVersionRequested Highest Winsock version the caller can use,
 *        e.g. MAKEWORD(1, 1): major version in the low byte, minor in the
 *        high byte.
 * @param lpWSAData Receives details of the Winsock implementation.
 * @return 0 on success, or WSASYSNOTREADY, WSAVERNOTSUPPORTED,
 *        WSAEINPROGRESS, WSAEPROCLIM or WSAEFAULT.
 *
 * @note Windows CE 3.0 only.
 */
int PASCAL WSAStartup(WORD wVersionRequested,LPWSADATA lpWSAData);
/**
 * Balances a successful WSAStartup call and releases Winsock resources.
 *
 * Windows CE provides this function for compatibility. Call once for
 * every successful WSAStartup; only the final call for the task releases
 * the implementation state, and earlier ones just decrement a count. Open
 * sockets are reset and freed as if closed with closesocket, and pending
 * data can be lost: to make sure it is sent, shut down the connection with
 * shutdown and wait for it to close before calling closesocket and
 * WSACleanup. In a multithreaded process this ends Winsock for all
 * threads.
 *
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError).
 *
 * @note Windows CE 3.0 only.
 */
int PASCAL WSACleanup(void);
#ifdef _WIN32_WCE
#define WSASetLastError SetLastError
#define WSAGetLastError GetLastError
#else
/**
 * This function sets the error value that can be retrieved through the
 * WSAGetLastError function.
 *
 * The WSASetLastError function allows an application to set the error
 * value to be returned by a subsequent WSAGetLastError call for the
 * current thread. Note that any subsequent Windows Sockets routine called
 * by the application will override the error value as set by this routine.
 *
 * The error value set by WSASetLastError is different from the error value
 * reset by calling the function getsockopt with SO_ERROR.
 *
 * @param iError [in] Integer that specifies the error value to be returned
 *        by a subsequent WSAGetLastError call.
 * @return None.
 */
void PASCAL WSASetLastError(int iError);
/**
 * This function retrieves the error status for the last Windows Socket
 * operation that failed.
 *
 * The WSAGetLastError function returns the last network error that
 * occurred. When a particular Windows Sockets function indicates that an
 * error has occurred, this function should be called to retrieve the
 * appropriate error value. This error value can be different from the
 * error value obtained from getsockopt SO_ERROR, which is socket-specific
 * since WSAGetLastError is for all thread-specific sockets.
 *
 * A successful function call, or a call to WSAGetLastError, does not reset
 * the error value. To reset the error value, use the WSASetLastError
 * function call with iError set to zero. A getsockopt SO_ERROR also resets
 * the error value to zero.
 *
 * @return The return value indicates the error value for this thread's
 *        last Windows Sockets operation that failed.
 */
int PASCAL WSAGetLastError(void);
#endif
BOOL PASCAL WSAIsBlocking(void);
int PASCAL WSAUnhookBlockingHook(void);
FARPROC PASCAL WSASetBlockingHook(FARPROC);
int PASCAL WSACancelBlockingCall(void);
HANDLE PASCAL WSAAsyncGetServByName(HWND,u_int,const char*,const char*,char*,int);
HANDLE PASCAL WSAAsyncGetServByPort(HWND,u_int,int,const char*,char*,int);
HANDLE PASCAL WSAAsyncGetProtoByName(HWND,u_int,const char*,char*,int);
HANDLE PASCAL WSAAsyncGetProtoByNumber(HWND,u_int,int,char*,int);
HANDLE PASCAL WSAAsyncGetHostByName(HWND,u_int,const char*,char*,int);
HANDLE PASCAL WSAAsyncGetHostByAddr(HWND,u_int,const char*,int,int,char*,int);
int PASCAL WSACancelAsyncRequest(HANDLE);
int PASCAL WSAAsyncSelect(SOCKET,HWND,u_int,long);
#if !(defined (__INSIDE_CYGWIN__) || defined (__INSIDE_MSYS__))
/**
 * Converts a 32-bit value from host to network (big-endian) byte order.
 *
 * @param hostlong Value in host byte order.
 * @return The value in network byte order.
 */
u_long PASCAL htonl(u_long hostlong);
/**
 * Converts a 32-bit value from network (big-endian) to host byte order.
 *
 * @param netlong Value in network byte order.
 * @return The value in host byte order.
 */
u_long PASCAL ntohl(u_long netlong);
/**
 * Converts a 16-bit value from host to network (big-endian) byte order.
 *
 * @param hostshort Value in host byte order.
 * @return The value in network byte order.
 */
u_short PASCAL htons(u_short hostshort);
/**
 * Converts a 16-bit value from network (big-endian) to host byte order.
 *
 * @param netshort Value in network byte order.
 * @return The value in host byte order.
 */
u_short PASCAL ntohs(u_short netshort);
/**
 * Waits until one or more sockets are readable, writable or have an
 * error.
 *
 * Each set is updated in place to hold only the sockets that are ready.
 * Build sets with FD_ZERO and FD_SET and test them with FD_ISSET. An
 * fd_set holds up to FD_SETSIZE (64 by default) sockets. Readable covers
 * a pending connection on a listening socket and a closed connection
 * (recv returns 0). Writable covers completion of a nonblocking connect;
 * a failed connect shows in exceptfds.
 *
 * @param nfds Ignored. Pass 0.
 * @param readfds Sockets to check for readability, or NULL.
 * @param writefds Sockets to check for writability, or NULL.
 * @param exceptfds Sockets to check for errors and out-of-band data, or
 *        NULL.
 * @param timeout Maximum wait, NULL to wait indefinitely, or {0, 0} to
 *        poll.
 * @return The number of ready sockets, 0 on timeout, or SOCKET_ERROR (see
 *         WSAGetLastError).
 */
int PASCAL select(int nfds,fd_set*readfds,fd_set*writefds,fd_set*exceptfds,const struct timeval*timeout);
/**
 * Returns the local host name.
 *
 * The name may be a plain name or fully qualified, but always resolves
 * with gethostbyname.
 *
 * @param name Receives the null-terminated host name.
 * @param namelen Size of name in bytes.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError; WSAEFAULT if
 *         the buffer is too small).
 */
int PASCAL gethostname(char*name,int namelen);
#endif /* ! (__INSIDE_CYGWIN__ || __INSIDE_MSYS__) */

#define WSAMAKEASYNCREPLY(b,e)	MAKELONG(b,e)
#define WSAMAKESELECTREPLY(e,error)	MAKELONG(e,error)
#define WSAGETASYNCBUFLEN(l)	LOWORD(l)
#define WSAGETASYNCERROR(l)	HIWORD(l)
#define WSAGETSELECTEVENT(l)	LOWORD(l)
#define WSAGETSELECTERROR(l)	HIWORD(l)

typedef struct sockaddr SOCKADDR;
typedef struct sockaddr *PSOCKADDR;
typedef struct sockaddr *LPSOCKADDR;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr_in *PSOCKADDR_IN;
typedef struct sockaddr_in *LPSOCKADDR_IN;
typedef struct linger LINGER;
typedef struct linger *PLINGER;
typedef struct linger *LPLINGER;
typedef struct in_addr IN_ADDR;
typedef struct in_addr *PIN_ADDR;
typedef struct in_addr *LPIN_ADDR;
typedef struct fd_set FD_SET;
typedef struct fd_set *PFD_SET;
typedef struct fd_set *LPFD_SET;
typedef struct hostent HOSTENT;
typedef struct hostent *PHOSTENT;
typedef struct hostent *LPHOSTENT;
typedef struct servent SERVENT;
typedef struct servent *PSERVENT;
typedef struct servent *LPSERVENT;
typedef struct protoent PROTOENT;
typedef struct protoent *PPROTOENT;
typedef struct protoent *LPPROTOENT;
typedef struct timeval TIMEVAL;
typedef struct timeval *PTIMEVAL;
typedef struct timeval *LPTIMEVAL;

#ifdef __cplusplus
}
#endif
/*
 * Recent MSDN docs indicate that the MS-specific extensions exported from
 * mswsock.dll (AcceptEx, TransmitFile. WSARecEx and GetAcceptExSockaddrs) are
 * declared in mswsock.h. These extensions are not supported on W9x or WinCE.
 * However, code using WinSock 1.1 API may expect the declarations and
 * associated defines to be in this header. Thus we include mswsock.h here.
 *
 * When linking against the WinSock 1.1 lib, wsock32.dll, the mswsock functions
 * are automatically routed to mswsock.dll (on platforms with support).
 * The WinSock 2 lib, ws2_32.dll, does not contain any references to
 * the mswsock extensions. 
 */

#include <mswsock.h>

#endif
