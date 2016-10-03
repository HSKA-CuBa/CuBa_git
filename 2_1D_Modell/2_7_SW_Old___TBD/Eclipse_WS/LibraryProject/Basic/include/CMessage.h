//12.9.16, Michal Meindl
#ifndef CMESSAGE_H
#define CMESSAGE_H
#include "Global.h"
#include "EEvent.h"
#include "EDataType.h"
#include "CSensorData.h"
#include "CFilterData.h"
#include "CMotorData.h"

///	Container-Class to pass Data between processes
class CMessage
{
public:
	struct Header
	{
	public:
		EEvent mEvent;
		EDataType mDataType;
		UInt8 mReservered[2];
	};
public:
	CMessage();
	CMessage(EEvent event);
	CMessage(EEvent event, EDataType datatype, CSensorData data);
	CMessage(const CMessage&) = delete;
	CMessage& operator=(const CMessage&) = default;
	~CMessage() = default;
public:
	Header mHeader;
	UInt8 mData[16];
};

#endif