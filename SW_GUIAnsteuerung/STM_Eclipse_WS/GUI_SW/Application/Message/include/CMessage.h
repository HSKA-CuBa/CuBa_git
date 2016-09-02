/* Communication with Message
 *
 * Created on: 16.08.2016
 * Author: Alexander Schleicher
 * From Foundation of Michael Meindl
 */

#ifndef INCLUDE_CMESSAGE_H_
#define INCLUDE_CMESSAGE_H_

#include "Global.h"
#include "EComponentID.h"
#include "EControlEvent.h"
#include "EDiagEvent.h"
#include "ECommEvent.h"
#include "EMessageType.h"

class CMessage
{

public:

	CMessage(const CMessage&) = default;
	CMessage& operator=(const CMessage&) = default;


	CMessage(EComponentID sender,
			 EComponentID receiver,
			 EControlEvent controlEvent);

	CMessage(EComponentID sender,
			 EComponentID receiver,
			 EDiagEvent diagEvent);

	CMessage(EComponentID sender,
			 EComponentID receiver,
			 ECommEvent commEvent);


	~CMessage();

	EComponentID getSender() const;
	EComponentID getReceiver() const;
	EMessageType getMessageType() const;
	EControlEvent getControlEvent() const;
	EDiagEvent getDiagEvent() const;
	ECommEvent getCommEvent() const;
	UInt32 getData() const;
	void setData(UInt32 data);
	void setByte(UInt8 byte, UInt8 index);


private:

	EComponentID mSender;
	EComponentID mReceiver;
	EMessageType mType;
	union //Memory optimization
	{
		EControlEvent mControlEvent;
		EDiagEvent mDiagEvent;
		ECommEvent mCommEvent;
	};
	union
	{
		UInt8 mByteArray[4];
		UInt32 mData;
	};

};

#endif
