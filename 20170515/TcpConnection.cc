#include "TcpConnection.h"
#include "EpollPoller.h"
#include <string.h>
#include <stdio.h>


namespace wd
{
TcpConnection::TcpConnection(int sockfd, EpollPoller * loop)
: m_sockfd(sockfd)
, m_sockIO(sockfd)
, m_localAddr(wd::Socket::getLocalAddr(sockfd))
, m_peerAddr(wd::Socket::getPeerAddr(sockfd))
, m_isShutdownWrite(false)
, m_loop(loop)
{
	m_sockfd.nonblock();
}

TcpConnection::~TcpConnection()
{
	if(!m_isShutdownWrite)
	{
		m_isShutdownWrite = true;
		shutdown();
	}
	printf("~TcpConnection()\n");
}

std::string TcpConnection::receive()
{
	char buf[65536];
	memset(buf, 0, sizeof(buf));
	size_t ret = m_sockIO.readline(buf, sizeof(buf));
	if(0 == ret)
	{
		return std::string();
	}
	else
		return std::string(buf);
}

void TcpConnection::send(const std::string & msg)
{
	m_sockIO.writen(msg.c_str(), msg.size());
}

//针对php服务器
void TcpConnection::sendAndClose(const std::string & msg)
{
	send(msg);
	shutdown();
}

void TcpConnection::shutdown()
{
	if(!m_isShutdownWrite)
		m_sockfd.shutdownWrite();
	m_isShutdownWrite = true;
}

std::string TcpConnection::toString()
{
	char str[100];
	snprintf(str, sizeof(str), "%s:%d -> %s:%d",
			m_localAddr.ip().c_str(),
			m_localAddr.port(),
			m_peerAddr.ip().c_str(),
			m_peerAddr.port());
	return std::string(str);
}

void TcpConnection::setConnectionCallback(TcpConnectionCallback cb)
{
	m_onConnectionCb = cb;
}

void TcpConnection::setMessageCallback(TcpConnectionCallback cb)
{
	m_onMessageCb = cb;
}

void TcpConnection::setCloseCallback(TcpConnectionCallback cb)
{
	m_onCloseCb = cb;
}

void TcpConnection::handleConnectionCallback()
{
	if(m_onConnectionCb)
		m_onConnectionCb(shared_from_this());
}

void TcpConnection::handleMessageCallback()
{
	if(m_onMessageCb)
		m_onMessageCb(shared_from_this());
}

void TcpConnection::handleCloseCallback()
{
	if(m_onCloseCb)
		m_onCloseCb(shared_from_this());
}

}//end of namespace wd
