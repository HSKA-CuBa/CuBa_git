#ifndef FWMEMORY_H
#define FWMEMORY_H
#include "Global.h"

constexpr size_t cMakeAlignmentSize(size_t size)
{
	return ((size + sizeof(Int32) - 1) / sizeof(Int32)) * sizeof(Int32);
}

#endif
