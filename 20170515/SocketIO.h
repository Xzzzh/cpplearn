#ifndef __WD_SOCKETIO_H__
#define __WD_SOCKETIO_H__
#include <stdio.h>

namespace wd
{

class SocketIO
{
public:
	SocketIO(size_t sockfd);

	size_t readn(char * buf, size_t count);
	size_t writen(const char * buf, size_t count);
	size_t readline(char * buf, size_t max_len);
private:
	size_t recv_peek(char * buf, size_t count);

private:
	size_t _sockfd;
};

}//end of namespace wd

#endif


