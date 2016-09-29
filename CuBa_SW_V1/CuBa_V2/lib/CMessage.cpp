/**
 * @file CMessage.cpp
 * @author Michael Meindl
 * @date 25.9.2016
 * @brief Method definitions for CMessage.
 */
#include "CMessage.h"
#include <iostream>

CMessage::CMessage() : mHeader{EEvent::EV_DEFAULT_IGNORE,
							   EDataType::DEFAULT_IGNORE,
							   ECommand::CMD_DONT_CARE,
							   0U},
					   mData{0U}
{

}
CMessage::CMessage(EEvent event) : mHeader{event,
										   EDataType::DEFAULT_IGNORE,
										   ECommand::CMD_DONT_CARE, 0U},
								   mData{0U}
{

}
CMessage::CMessage(const CSensorData& data) : mHeader{EEvent::EV_TRANSMIT_DATA,
													  EDataType::SENSORDATA,
													   ECommand::CMD_DONT_CARE, 0U},
											  mData{0U}
{
	*reinterpret_cast<CSensorData*>(mData) = data;
}
CMessage::CMessage(const CPhi& phi) : mHeader{EEvent::EV_TRANSMIT_DATA,
											  EDataType::PHI,
											  ECommand::CMD_DONT_CARE, 0U},
									  mData{0U}
{
	*reinterpret_cast<CPhi*>(mData) = phi;
}
CMessage::CMessage(const CPhi__d& phi__d) : mHeader{EEvent::EV_TRANSMIT_DATA,
													EDataType::PHI__D,
													ECommand::CMD_DONT_CARE, 0U},
											mData{0U}
{
	*reinterpret_cast<CPhi__d*>(mData) = phi__d;
}
CMessage::CMessage(const CPsi__d& psi__d) : mHeader{EEvent::EV_TRANSMIT_DATA,
													EDataType::PSI__D,
													ECommand::CMD_DONT_CARE, 0U},
											mData{0U}
{
	*reinterpret_cast<CPsi__d*>(mData) = psi__d;
}
Float32 CMessage::getTorque()
{
	return *reinterpret_cast<Float32*>(mData);
}
EFilter CMessage::getFilter()
{
	return *reinterpret_cast<EFilter*>(mData);
}
Float32 CMessage::getOffset()
{
	return *reinterpret_cast<Float32*>(mData);
}
EEvent CMessage::getEvent()
{
	return mHeader.mEvent;
}
EDataType CMessage::getDataType()
{
	return mHeader.mDataType;
}
ECommand CMessage::getCommand()
{
	return mHeader.mCommand;
}
