/**
 * @file	CMessage.cpp
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#include "CMessage.h"

CMessage::CMessage() : mEvent(EEvent::INGORE),
					   mData{0U}
{

}
CMessage::CMessage(EEvent event) : mEvent(event),
								   mData{0U}
{

}
EEvent CMessage::getEvent() const
{
	return mEvent;
}
Float32 CMessage::getTorque() const
{
	return *reinterpret_cast<const Float32*>(mData);
}
