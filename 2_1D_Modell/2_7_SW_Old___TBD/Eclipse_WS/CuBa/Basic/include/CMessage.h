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
	CMessage(EEvent event, EDataType datatype, CSensorData& data);
	CMessage(EEvent event, EDataType datatype, CFilterData& data);
	CMessage(EEvent event, EDataType datatype, CMotorData& data);
	CMessage(const CMessage&) = default;
	CMessage& operator=(const CMessage&) = default;
	~CMessage() = default;
public:
	static constexpr Int32 sDataSize = 16;
	Header mHeader;
	UInt8 mData[sDataSize];
public:
	//Methods to assert at compile time that the sizes of the Data-Class are the same as the data field of a message
	static constexpr Int32 cClassSizeAssertion(size_t classSize);
	static Int32 sRuntimeFallback(Int32 x);
};

#endif
