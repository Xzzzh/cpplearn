#include "Socket.h"
#include "SocketUtil.h"
#include "InetAddress.h"

namespace wd
{

Socket::Socket(int sockfd)
: m_sockfd(sockfd)
{}

Socket::Socket()
: _sockfd(createSockFd())
{}

Socket::~Socket()
{
	::close(_sockfd);
}

void Socket::nonblock()
{
	setNonblock(_sockfd);
}

void Socket::shutdownWrite()
{
	if(::shutdown(_sockfd, SHUT_WR) == -1)
	{
		perror("shutdown write error!");
	}	
}

InetAddress Socket::getPeerAddr(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(sockaddr_in);
	if(::getpeername(sockfd, (struct sockaddr *)&addr, &len) == -1)
	{
		perror("getpeername error");
	}
	return InetAddress(addr);
}

}//end of namespace wd
