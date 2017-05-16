#ifndef __WD_EPOLLPOLLER_H__
#define __WD_EPOLLPOLLER_H__

#include "Noncopyable.h"
#include "TcpConnection.h"
#include "MutexLock.h"

#include <sys/epoll.h>
#include <vector>
#include <map>
#include <functional>

namespace wd
{

class Acceptor;
class EpollPoller : Noncopyable
{
public:
	typedef TcpConnection::TcpConnectionCallback EpollCallback;
	typedef std::function<void()> Functor;

	EpollPoller(Acceptor & acceptor);
	~EpollPoller();
	
	void loop();
	void unloop();
	void runInLoop(const Functor & cb);
	void doPendingFunctors();

	void wakeup();
	void handleRead();

	void setConnectionCallback(EpollCallback cb);
	void setMessageCallback(EpollCallback cb);
	void setCloseCallback(EpollCallback cb);

private:
	void waitEpollfd();
	void handleConnection();
	void handleMessage(int peerfd);
private:
	Acceptor & m_acceptor;
	int m_epollfd;
	int m_listenfd;
	int m_wakeupfd;
	bool m_isLooping;

	MutexLock m_mutex;
	std::vector<Functor> m_pendingFunctors;

	typedef std::vector<struct epoll_event> EventList;
	EventList m_eventsList;

	typedef std::map<int, TcpConnectionPtr> ConnectionMap;
	ConnectionMap m_connMap;

	EpollCallback m_onConnectionCb;
	EpollCallback m_onMessageCb;
	EpollCallback m_onCloseCb;
};

}//end of namespace wd

#endif
