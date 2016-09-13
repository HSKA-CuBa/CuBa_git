#include "AComponentBase.h"

AComponentBase::AComponentBase(TQueue<Config::QueueSize>& rxQueue,
							   TQueue<Config::QueueSize>& txQueue,
							   bool initStandby) :
							   	   mRxQueue(rxQueue),
								   mTxQueue(txQueue),
								   mStandbyState(initStandby)
{

}
