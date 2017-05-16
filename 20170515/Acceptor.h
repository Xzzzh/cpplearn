#ifndef __WD_ACCEPTOR_H__
#define __WD_ACCEPTOR_H__

#include "Socket.h"
#include "InetAddress.h"

namespace wd
{

class Acceptor
{
public:
	Acceptor(int listenfd, const InetAddress & addr);

	void ready();
	int accept();

	int fd() const{ return m_listenSock.fd(); }

private:
	void setReuseAddr(bool on);
	void setReusePort(bool on);
	void bind();
	void listen();

private:
	Socket m_listenSock;
	InetAddress m_addr;
};

}//end of namespace wd

#endif
