#include "Acceptor.h"
#include "SocketUtil.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
Acceptor::Acceptor(int listenfd, const InetAddress & addr)
: m_listenSock(listenfd)
, m_addr(addr)
{}

void Acceptor::ready()
{
	setReuseAddr(true);
	setReusePort(true);
	bind();
	listen();
}

int Acceptor::accept()
{
	int peerfd = ::accept(m_listenSock.fd(), NULL, NULL);
	if(-1 == peerfd)
	{
		perror("accept error");
	}	
	return peerfd;
}

void Acceptor::setReuseAddr(bool flag)
{
	int on = (flag ? 1 : 0);
	if(::setsockopt(m_listenSock.fd(),
				SOL_SOCKET,
				SO_REUSEADDR,
				&on,
				static_cast<socklen_t>(sizeof(on))) == -1)
	{
		perror("setsockopt reuseaddr error");
		::close(m_listenSock.fd());
		exit(EXIT_FAILURE);
	}
}

void Acceptor::setReusePort(bool flag)
{
#ifdef SO_REUSEPORT
	int on = (flag ? 1 : 0);
	if(setsockopt(m_listenSock.fd(),
				SOL_SOCKET,
				SO_REUSEPORT,
				&on,
				static_cast<socklen_t>(sizeof(on))) == -1)
	{
		perror("setsockopt reuseport error");
		::close(m_listenSock.fd());
		exit(EXIT_FAILURE);
	}
#else
	if(flag)
	{
		fprintf(stderr, "SO_REUSEPORT is not supported!\n");
	}
#endif
}

void Acceptor::bind()
{
	if(-1 == ::bind(m_listenSock.fd(),\
				static_cast<const struct sockaddr *> m_addr.getSockAddrPtr(),\
				sizeof(InetAddress)))
	{
		perror("bind error");
		::close(_listenSock.fd());
		exit(EXIT_FAILURE);
	}
}

void Acceptor::listen()
{
	if(-1 == ::listen(m_listenSock.fd(), 10))
	{
		perror("listen error");
		::close(m_listenSock.fd());
		exit(EXIT_FAILURE);
	}	
}

}//end of namespace wd
