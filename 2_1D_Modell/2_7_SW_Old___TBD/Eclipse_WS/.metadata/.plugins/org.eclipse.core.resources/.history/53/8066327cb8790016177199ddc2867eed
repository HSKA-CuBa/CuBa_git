/*! \brief Abstract base class for the components.
 *
 * This class contains two references to queues, which are used for communication between the TCP/IP-server and the control system.
 */
#ifndef ACOMPONENTBASE_H
#define ACOMPONENTBASE_H
#include "Config.h"
#include "TQueue.h"

class AComponentBase
{
public:
	virtual void init() = 0;	///< Brief Abstract method to initialize the comopnent.
	virtual void run() = 0;		///< Brief Abstract method to run the component. This function should never return.
public:
	AComponentBase(TQueue<Config::QueueSize>& rxQueue,			//Queues werden in main im SHM angelegt
				   TQueue<Config::QueueSize>& txQueue);
	AComponentBase() = delete;
	AComponentBase(const AComponentBase&) = delete;
	AComponentBase& operator=(const AComponentBase&) = delete;
	virtual ~AComponentBase() = default;
protected:
	TQueue<Config::QueueSize>& mRxQueue;
	TQueue<Config::QueueSize>& mTxQueue;		//2 components --> point-to-point-communication
};

#endif
