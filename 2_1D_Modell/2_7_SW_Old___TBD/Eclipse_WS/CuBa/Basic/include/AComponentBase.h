/*! \brief Abstract base class for the components.
 *
 * This class contains two references to queues, which are used for communication between the TCP/IP-server and the control system.
 */
#ifndef ACOMPONENTBASE_H
#define ACOMPONENTBASE_H
#include "Config.h"
#include "TQueue.h"

class AComponentBase
{
public:
	virtual void init() = 0;									///< Brief Abstract method to initialize the comopnent.
	virtual void run_V1_AusgleichsPolynomAccelerometer() = 0;	///< Abstract method to run the first measurement setup.
	virtual void run_V2_OffsetGyroscope() = 0;					///< Abstract method to run the second measurement setup.
	virtual void run_V3_AusgleichsPolynomMotorADC() = 0;		///< Abstract method to run the third measurement setup.
	virtual void run_V4_FilterTest() = 0;						///< Abstract method to test the different filters.
	virtual void run_V5_BestimmungC_psi() = 0;					///< Abstract method to determine C_psi.
	virtual void run_V6_BestimmungC_phi() = 0;					///< Abstract method to determine C_phi.
	virtual void run_V7_RegelungTest() = 0;						///< Abstract method to test and evaluate the control system.
public:
	AComponentBase(TQueue<Config::QueueSize>& rxQueue,			//Queues werden in main im SHM angelegt
				   TQueue<Config::QueueSize>& txQueue,
				   bool initStandby);
	AComponentBase() = delete;
	AComponentBase(const AComponentBase&) = delete;
	AComponentBase& operator=(const AComponentBase&) = delete;
	virtual ~AComponentBase() = default;
protected:
	TQueue<Config::QueueSize>& mRxQueue;
	TQueue<Config::QueueSize>& mTxQueue;		//2 components --> point-to-point-communication
	bool mStandbyState;
	UInt8 mPadding{};
};

#endif
