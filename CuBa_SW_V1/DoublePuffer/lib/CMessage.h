/**
 * @file CMessage.h
 * @author Michael Meindl
 * @date 25.9.2016
 * @brief Class definition for a communication message.
 */
#ifndef CMESSAGE_H
#define CMESSAGE_H
#include "EEvent.h"
#include "EDataType.h"
#include "Global.h"

class CMessage
{
public:
	void setEvent(EEvent event);
	EEvent getEvent();
public:
	CMessage();
	CMessage(const CMessage&) = delete;
	CMessage& operator=(const CMessage&) = default;
	~CMessage() = default;
private:
	EEvent mEvent;
	UInt8 mReserved[3];
};

#endif
