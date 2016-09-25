/**
 * @file CMessage.cpp
 * @author Michael Meindl
 * @date 25.9.2016
 * @brief Method definitions for CMessage.
 */
#include "CMessage.h"

CMessage::CMessage() : mEvent(EEvent::EV_DEFAULT_IGNORE),
					   mReserved{0U}
{

}
EEvent CMessage::getEvent()
{
	return mEvent;
}
void CMessage::setEvent(EEvent event)
{
	mEvent = event;
}
