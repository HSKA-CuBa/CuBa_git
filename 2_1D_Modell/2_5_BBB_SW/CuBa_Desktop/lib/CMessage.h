/**
 * @file	CMessage.h
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#ifndef CMESSAGE_H
#define CMESSAGE_H
#include "Global.h"
#include "EEvent.h"

class CMessage
{
public:
	EEvent getEvent() const;
	Float32 getTorque() const;
public:
	CMessage();
	CMessage(EEvent event);
	CMessage(const CMessage&) = default;
	CMessage& operator=(const CMessage&) = default;
	~CMessage() = default;
private:
	static constexpr Int32 sDataSize = 20;
	EEvent mEvent;
	UInt8 mData[sDataSize];
};

#endif
