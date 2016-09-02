/* Communication with Message
 *
 * Created on: 16.08.2016
 * Author: Alexander Schleicher
 * From Foundation of Michael Meindl
 */
#include "Global.h"
#include "CMessage.h"


	CMessage::CMessage(EComponentID sender,
			 EComponentID receiver,
			 EControlEvent controlEvent)
	{
		mSender = sender;
		mReceiver = receiver;
		mType = (EMessageType::CONTROL_MSG);
		mControlEvent = controlEvent;
	}

	CMessage::CMessage(EComponentID sender,
			 EComponentID receiver,
			 EDiagEvent diagEvent)
	{
		mSender = sender;
		mReceiver = receiver;
		mType = (EMessageType::DIAG_MSG);
		mDiagEvent = diagEvent;
	}

	CMessage::CMessage(EComponentID sender,
			 EComponentID receiver,
			 ECommEvent commEvent)
	{
		mSender = sender;
		mReceiver = receiver;
		mType = (EMessageType::COMM_MSG);
		mCommEvent = commEvent;
	}

	CMessage::~CMessage(){}

	EComponentID CMessage::getSender() const
	{
		return mSender;
	}

	EComponentID CMessage::getReceiver() const
	{
		return mReceiver;
	}

	EMessageType CMessage::getMessageType() const
	{
		return mType;
	}

	EControlEvent CMessage::getControlEvent() const
	{
		return mControlEvent;
	}

	EDiagEvent CMessage::getDiagEvent() const
	{
		return mDiagEvent;
	}

	ECommEvent CMessage::getCommEvent() const
	{
		return mCommEvent;
	}

	UInt32 CMessage::getData() const
	{
		return mData;
	}

	void CMessage::setData(UInt32 data)
	{
		mData = data;
	}

	void CMessage::setByte(UInt8 byte, UInt8 index)
	{
		if(index < 8U)
		{
			mByteArray[index] = byte;
		}
	}
