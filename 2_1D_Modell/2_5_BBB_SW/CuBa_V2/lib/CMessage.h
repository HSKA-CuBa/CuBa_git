/**
 * @file CMessage.h
 * @author Michael Meindl
 * @date 25.9.2016
 * @brief Class definition for a communication message.
 */
#ifndef CMESSAGE_H
#define CMESSAGE_H
#include "CSensorData.h"
#include "CPhi.h"
#include "CPhi__d.h"
#include "CPsi__d.h"
#include "EEvent.h"
#include "EDataType.h"
#include "ECommand.h"
#include "EFilter.h"
#include "Global.h"

class CMessage
{
public:
	struct CHeader
	{
		EEvent mEvent;
		EDataType mDataType;
		ECommand mCommand;
		UInt8 mReserved[1];
	};
public:
	/**
	 * Method to get the event stored in the message header.
	 * @return 	Holds the current event.
	 */
	EEvent getEvent();
	/**
	 * Method to get the datatype stored in the message header.
	 * @return Holds the current datatype.
	 */
	EDataType getDataType();
	/**
	 * Method to get the command stored in the message header.
	 * @return Holds the current command.
	 */
	ECommand getCommand();
	/**
	 * Method to get the filter stored in the data field.
	 * @return Holds the filter enumeration.
	 */
	EFilter getFilter();
	/**
	 * Method to get the offset-value stored in the data field.
	 * @return Holds the offset value.
	 */
	Float32 getOffset();
	/**
	 * Method to get the torque-value stored in the data field.
	 * @return Holds the torque value.
	 */
	Float32 getTorque();
public:
	/**
	 * Required to create create empty messages in the queues.
	 */
	CMessage();
	/**
	 * Constructor to create a message with a simple event.
	 */
	CMessage(EEvent event);
	/**
	 * Constructor to create a message holding sensor data.
	 */
	CMessage(const CSensorData& data);
	/**
	 * Constructor to create a message holding phi values.
	 */
	CMessage(const CPhi& phi);
	/**
	 * Constructor to create a message holding phi__d values.
	 */
	CMessage(const CPhi__d& phi__d);
	/**
	 * Constructor to create a message holding psi__d values.
	 */
	CMessage(const CPsi__d& psi__d);
	CMessage(const CMessage&) = delete;
	/**
	 * Required to copy messages into the queue.
	 */
	CMessage& operator=(const CMessage&) = default;
	~CMessage() = default;
private:
	static constexpr Int32 sDataSize = 20;
	CHeader mHeader;
	UInt8 mData[sDataSize];
};

#endif
