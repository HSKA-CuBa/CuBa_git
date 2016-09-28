/**
 * @file CMessage.cpp
 * @author Michael Meindl
 * @date 25.9.2016
 * @brief Method definitions for CMessage.
 */
#include "CMessage.h"

bool CMessage::getEvent(EEvent& event)
{
	event = mHeader.mEvent;
	return event != EEvent::EV_DEFAULT_IGNORE;
}
bool CMessage::getDataType(EDataType& datatype)
{
	datatype = mHeader.mDataType;
	return mHeader.mEvent == EEvent::EV_TRANSMIT_DATA;
}
bool CMessage::getPhiValues(Float32& time,
						    Float32& raw,
							Float32& comp,
							Float32& kalman)
{
	bool success = false;
	if(mHeader.mDataType == EDataType::PHI)
	{
		success = true;
		time 	= *reinterpret_cast<Float32*>(mData);
		raw  	= *reinterpret_cast<Float32*>(mData+4);
		comp 	= *reinterpret_cast<Float32*>(mData+8);
		kalman  = *reinterpret_cast<Float32*>(mData+12);
	}
	return success;
}
bool CMessage::getPhi__dValues(Float32& time,
							   Float32& raw,
							   Float32& kalman)
{
	bool success = false;
	if(mHeader.mDataType == EDataType::PHI__D)
	{
		success = true;
		time 	= *reinterpret_cast<Float32*>(mData);
		raw		= *reinterpret_cast<Float32*>(mData+4);
		kalman 	= *reinterpret_cast<Float32*>(mData+8);
	}
	return success;
}
bool CMessage::getPsi__dValues(Float32& time,
							   Float32& raw,
							   Float32& mean4,
							   Float32& mean8,
							   Float32& mean16)
{
	bool success = false;
	if(mHeader.mDataType == EDataType::PSI__D)
	{
		success = true;
		time	= *reinterpret_cast<Float32*>(mData);
		raw 	= *reinterpret_cast<Float32*>(mData+4);
		mean4	= *reinterpret_cast<Float32*>(mData+8);
		mean8	= *reinterpret_cast<Float32*>(mData+12);
		mean16	= *reinterpret_cast<Float32*>(mData+26);
	}
	return success;
}
CMessage::CMessage() : mHeader{EEvent::EV_DEFAULT_IGNORE,
							   EDataType::DEFAULT_IGNORE,
							   0U},
					   mData{0U}
{

}
CMessage::CMessage(const Float32& time,
				   const Float32& raw,
				   const Float32& comp,
				   const Float32& kalman) : mHeader{EEvent::EV_TRANSMIT_DATA,
						   	   	   	   	   	        EDataType::PHI, 0U},
											mData{0U}
{
	*reinterpret_cast<Float32*>(mData) 	  = time;
	*reinterpret_cast<Float32*>(mData+4)  = raw;
	*reinterpret_cast<Float32*>(mData+8)  = comp;
	*reinterpret_cast<Float32*>(mData+12) = kalman;
}
CMessage::CMessage(const Float32& time,
				   const Float32& raw,
				   const Float32& kalman) : mHeader{EEvent::EV_TRANSMIT_DATA,
													EDataType::PHI__D, 0U},
											mData{0U}
{
	*reinterpret_cast<Float32*>(mData) 	  = time;
	*reinterpret_cast<Float32*>(mData+4)  = raw;
	*reinterpret_cast<Float32*>(mData+8)  = kalman;
}
CMessage::CMessage(const Float32& time,
				   const Float32& raw,
				   const Float32& mean4,
				   const Float32& mean8,
				   const Float32& mean16) : mHeader{EEvent::EV_TRANSMIT_DATA,
													EDataType::PSI__D, 0U},
											mData{0U}
{
	*reinterpret_cast<Float32*>(mData)    = time;
	*reinterpret_cast<Float32*>(mData+4)  = raw;
	*reinterpret_cast<Float32*>(mData+8)  = mean4;
	*reinterpret_cast<Float32*>(mData+12) = mean8;
	*reinterpret_cast<Float32*>(mData+16) = mean16;
}
