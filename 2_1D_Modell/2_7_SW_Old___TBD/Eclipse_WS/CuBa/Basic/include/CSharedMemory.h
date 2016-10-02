//12.9.16, Michael Meindl
#ifndef CSHAREDMEMORY_H
#define CSHAREDMEMORY_H
#include "Global.h"
#include "Config.h"
#include "TQueue.h"

class CSharedMemory
{
public:
	TQueue<Config::QueueSize>* createQueue();
public:
	CSharedMemory();
	CSharedMemory(const CSharedMemory&) = delete;
	CSharedMemory& operator=(const CSharedMemory&) = delete;
	~CSharedMemory();
private:
	static constexpr size_t sSize = Config::SHMSize;
	Int32 mSHMFD;
	Int8* mStartAddr;
	Int8* mCurrentAddr;
};

#endif
