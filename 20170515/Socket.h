#ifndef __WD_SOCKET_H__
#define __WD_SOCKET_H__

#include "Noncopyable.h"

namespace wd
{

class InetAddress;
class Socket : Noncopyable
{
public:
	Socket();
	Socket(size_t Sockfd);
	~Socket();

	void shutdownWrite();
	int fd() const { return _sockfd; }

	void nonblock();

	static InetAddress getLocalAddr(size_t sockfd);
	static InetAddress getPeerAddr(size_t sockfd);
private:
	size_t _sockfd;
};

}//end of namespace wd

#endif
