#ifndef CONFIG_H
#define CONFIG_H
#include "Global.h"
#include "FWMemory.h"
#include "TQueue.h"

namespace Config
{
	constexpr Int32 QueueSize 	= 10;
	constexpr char SHM[] 		= "CuBaSHM";
	constexpr size_t SHMSize	= cMakeAlignmentSize(sizeof(TQueue<QueueSize>))*2;
}

#endif
