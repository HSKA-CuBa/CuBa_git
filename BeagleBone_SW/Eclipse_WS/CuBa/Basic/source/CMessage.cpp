#include "CMessage.h"

CMessage::CMessage() :  mHeader{EEvent::EV_DEFAULT_IGNORE,
								EDataType::DEFAULT_IGNORE,
								0U},
						mData{0U}
{

}
CMessage::CMessage(EEvent event,
				   EDataType dataType,
				   CSensorData& data) : mHeader{event, dataType, 0U},
						   	   	   	   mData{0U}
{
	union
	{
		UInt32 rawData[4];
		CSensorData sensorData = data;
	};
	sensorData = data;
	for(Int32 index = 0; index < 4; index++)
	{
		reinterpret_cast<UInt32*>(mData)[index] = rawData[index];
	}
}
CMessage::CMessage(EEvent event,
				   EDataType datatype,
				   CFilterData& data) : mHeader{event, datatype, 0U},
						   	   	   	   mData{0U}
{
	union
	{
		UInt32 rawData[4];
		CFilterData filterData = data;
	};
	filterData = data;
	for(Int32 index = 0; index < 4; index++)
	{
		reinterpret_cast<UInt32*>(mData)[index] = rawData[index];
	}
}
CMessage::CMessage(EEvent event,
				   EDataType datatype,
				   CMotorData& data) : mHeader{event, datatype, 0U},
						   	   	   	    mData{0U}
{
   union
   {
	   UInt32 rawData[4];
	   CMotorData motorData = data;
   };
   motorData = data;
   for(Int32 index = 0; index < 4; index++)
   {
	   reinterpret_cast<UInt32*>(mData)[index] = rawData[index];
   }
}
CMessage::CMessage(EEvent event) : mHeader{event, EDataType::DEFAULT_IGNORE, 0U},
								   mData{0U}
{

}

constexpr Int32 CMessage::cClassSizeAssertion(size_t classSize)
{
	return (sDataSize == classSize) ? 0 : sRuntimeFallback(classSize);
}
Int32 CMessage::sRuntimeFallback(Int32 x)
{
	return x;
}
static constexpr Int32 sCSensorDataSizeAssertion = CMessage::cClassSizeAssertion(sizeof(CSensorData));
static constexpr Int32 sCFilterDataSizeAssertion = CMessage::cClassSizeAssertion(sizeof(CFilterData));
static constexpr Int32 sCMotorDataSizeAssertion  = CMessage::cClassSizeAssertion(sizeof(CMotorData));
