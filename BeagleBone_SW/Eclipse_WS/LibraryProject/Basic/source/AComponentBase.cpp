#include "AComponentBase.h"

AComponentBase::AComponentBase(TQueue<Config::QueueSize>& rxQueue,
							   TQueue<Config::QueueSize>& txQueue) :
							   	   mRxQueue(rxQueue),
								   mTxQueue(txQueue)
{

}
