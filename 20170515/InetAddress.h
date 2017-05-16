#ifndef __WD_INETADDRESS_H__
#define __WD_INETADDRESS_H__

#include <netinet/in.h>
#include <string>

namespace wd
{

class InetAddress
{
public:
	InetAddress(unsigned short port);
	InetAddress(const std::string ip, unsigned short port);
	InetAddress(const struct sockaddr_in & addr);
	InetAddress(const InetAddress & addr);

	const struct sockaddr_in * getSockAddrPtr() const;
	
	std::string ip() const;

	unsigned short port() const;

private:
	struct sockaddr_in _addr;
};

}//end of namespace wd

#endif
