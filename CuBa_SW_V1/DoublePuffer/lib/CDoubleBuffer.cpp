/**
 * @file 	CDoubleBuffer.cpp
 * @author	Michael Meindl
 * @date	25.9.2016
 * @brief 	Method definitions for CDoublePuffer.
 */
#include "CDoubleBuffer.h"

CDoubleBuffer::CDoubleBuffer() : mReadContainer(),
								 mWriteContainer(),
								 mReadSem(false, true),
								 mSwitchSem(true, true)
{

}
bool CDoubleBuffer::setData(bool waitForever,
							CContainer::CPhiValues& phiValues,
							CContainer::CPhi__dValues& phi__dValues,
							CContainer::CPsi__dValues& psi__dValues)
{
	bool success = false;
	mWriteContainer.setData(phiValues, phi__dValues, psi__dValues);
	if(mSwitchSem.take(waitForever))
	{
		mReadContainer = mWriteContainer;
		success = true;
		mReadSem.give();
	}
	return success;
}
bool CDoubleBuffer::getData(bool waitForever,
						    CContainer::CPhiValues& phiValues,
							CContainer::CPhi__dValues& phi__dValues,
							CContainer::CPsi__dValues& psi__dValues)
{
	bool success = false;
	if(mReadSem.take(waitForever))
	{
		mReadContainer.getData(phiValues, phi__dValues, psi__dValues);
		success = true;
		mSwitchSem.give();
	}
	return success;
}
