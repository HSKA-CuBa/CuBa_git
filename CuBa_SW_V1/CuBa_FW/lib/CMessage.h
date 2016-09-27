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
	struct CHeader
	{
		EEvent mEvent;
		EDataType mDataType;
		UInt8 mReserved[2];
	};
public:
	/**
	 * Method to get the event stored in the message header.
	 * @param[out] event 	Holds the current event.
	 * @return 				Returns false if the event is EV_DEFAULT_IGNORE
	 */
	bool getEvent(EEvent& event);
	/**
	 * Method to get the datatype stored in the message header.
	 * @param[out] datatype Holds the current datatype.
	 * @return				Returns true if the event signals a data message.
	 */
	bool getDataType(EDataType& datatype);
	/**
	 * Method to get the different phi values.
	 * @param[out] time 		 Holds the current time value in seconds.
	 * @param[out] raw	 		 Holds the phi value of the angle estimation.
	 * @param[out] complementary Holds the phi value from the complementary filter.
	 * @param[out] kalman		 Holds the phi value from the kalman filter.
	 * @return 					 Returns true if datatype signals a data message containing phi values.
	 */
	bool getPhiValues(Float32& time,
					  Float32& raw,
					  Float32& complementary,
					  Float32& kalman);
	/**
	 * Method to get the different phi__d values.
	 * @param[out] time			 Holds the current time value in seconds.
	 * @param[out] raw 			 Holds the phi__d value of the gyroscope [rad/sec].
	 * @param[out] kalman		 Holds the phi__d value from the kalman filter.
	 * @return 					 Returns true if the datatype signal a data message containing phi__d values.
	 */
	bool getPhi__dValues(Float32& time,
						 Float32& raw,
						 Float32& kalman);
	/**
	 * Method to get the different psi__d values.
	 * @param[out] time 		 Holds the current time value in seconds.
	 * @param[out] raw			 Holds the psi__d value of the ADC [rad/sec].
	 * @param[out] mean4		 Holds the psi__d value from the floating mean over the last 4 values.
	 * @param[out] mean8		 Holds the psi__d value from the floating mean over the last 8 values.
	 * @param[out] mean16		 Holds the psi__d value from the floating mean over the last 16 values.
	 * @return 					 Returns true if the datatype signals a data message containing psi__d values.
	 */
	bool getPsi__dValues(Float32& time,
						 Float32& raw,
						 Float32& mean4,
						 Float32& mean8,
						 Float32& mean16);
public:
	/**
	 * Required to create create empty messages in the queues.
	 */
	CMessage();
	/**
	 * Constructor to create a message holding phi values.
	 * @param[in] time		Holds the current time value in seconds.
	 * @param[in] raw		Holds the phi value from the angle estimation.
	 * @param[in] comp		Holds the phi value from the complementary filter.
	 * @param[in] kalman	Holds the phi value from the kalman filter.
	 */
	CMessage(const Float32& time,
			 const Float32& raw,
			 const Float32& comp,
			 const Float32& kalman);
	/**
	 * Constructor to create a message holding the phi__d values.
	 * @param[in] time		Holds the current time value in seconds.
	 * @param[in] raw		Holds the phi__d value from the gyroscope.
	 * @param[in] kalman	Holds the phi__d value from the kalman filter.
	 */
	CMessage(const Float32& time,
			 const Float32& raw,
			 const Float32& kalman);
	/**
	 * Constructor to create a message holding the psi__d values.
	 * @param[in] time		Holds the current time value in seconds.
	 * @param[in] raw		Holds the psi__d value from the ADC.
	 * @param[in] mean4		Holds the psi__d value from the floating mean over the last 4 values.
	 * @param[in] mean8		Holds the psi__d value from the floating mean over the last 8 values.
	 * @param[in] mean16	Holds the psi__d value from the floating mean over the last 16 values.
	 */
	CMessage(const Float32& time,
			 const Float32& raw,
			 const Float32& mean4,
			 const Float32& mean8,
			 const Float32& mean16);
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