#ifndef KBE_IOCP_POLLER_H
#define KBE_IOCP_POLLER_H

#include "event_poller.h"
#ifndef HAS_IOCP
namespace KBEngine {
namespace Network
{


class IOCPPoller : public EventPoller
{
public:
	IOCPPoller(int expectedSize = 10);
	virtual ~IOCPPoller();

protected:
	virtual bool doRegisterForRead(int fd)
	{
		return this->doRegister(fd, true, true);
	}

	virtual bool doRegisterForWrite(int fd)
	{
		return this->doRegister(fd, false, true);
	}

	virtual bool doDeregisterForRead(int fd)
	{
		return this->doRegister(fd, true, false);
	}

	virtual bool doDeregisterForWrite(int fd)
	{
		return this->doRegister(fd, false, false);
	}

	virtual int processPendingEvents(double maxWait);

	bool doRegister(int fd, bool isRead, bool isRegister);

private:

	int epfd_;
};

}
}
#endif
#endif
