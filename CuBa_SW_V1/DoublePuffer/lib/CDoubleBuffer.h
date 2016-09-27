/**
 * @file	CDoubleBuffer.h
 * @author	Michael Meindl
 * @date	25.9.2016
 * @brief	Class definition for a double puffer.
 */
#ifndef CDOUBLEBUFFER_H
#define CDOUBLEBUFFER_H
#include "CContainer.h"
#include "CBinarySemaphore.h"

/**
 * Class holding two containers.
 */
class CDoubleBuffer
{
public:
	bool setData(bool waitForever,
				 CContainer::CPhiValues& phiValues,
				 CContainer::CPhi__dValues& phi__dValues,
				 CContainer::CPsi__dValues& psi__dValues);
	bool getData(bool waitForever,
				 CContainer::CPhiValues& phiValues,
				 CContainer::CPhi__dValues& phi__dValues,
				 CContainer::CPsi__dValues& psi__dValues);
public:
	CDoubleBuffer();
	CDoubleBuffer(const CDoubleBuffer&) = delete;
	CDoubleBuffer& operator=(const CDoubleBuffer&) = delete;
	~CDoubleBuffer() = default;
private:
	CContainer mReadContainer;
	CContainer mWriteContainer;
	CBinarySemaphore mReadSem;			/// Signals whether data can be read.
	CBinarySemaphore mSwitchSem;		/// Signals whether data can be switched from the write to read container.
};

#endif