#include "CMessage.h"

CMessage::CMessage() :	mHeader{EEvent::EV_DEFAULT_IGNORE,
								EDataType::DEFAULT_IGNORE,
								0U},
					    mData{0U}
{

}
CMessage::CMessage(EEvent event,
				   EDataType dataType,
				   CSensorData data) : mHeader{event, dataType, 0U},
						   	   	   	   mData{0U}
{
	mData.mSensorData = data;
}
CMessage::CMessage(EEvent event) : mHeader{event, EDataType::DEFAULT_IGNORE, 0U},
								   mData{0U}
{

}
