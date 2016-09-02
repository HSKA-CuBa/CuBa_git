/* Proxy - Distribute the Messages
 *
 * Created on: 16.08.2016
 * Author: Alexander Schleicher
 * From Foundation of Michael Meindl
 */

#ifndef INCLUDE_SPROXY_H_
#define INCLUDE_SPROXY_H_

#include "Global.h"
#include "CMessage.h"
#include "SCommComponent.h"
#include "SControlComponent.h"
#include "EState.h"

class SProxy
{
public:
	static SProxy& getInstance();
	SProxy(const SProxy&) = delete;
	SProxy& operator=(const SProxy&) = delete;
	~SProxy() = default;

	void startControl(EComponentID sender);
	void stopControl(EComponentID sender);
	void setJumpFlag(EComponentID sender, UInt8 jumpFlag);
	void setBalanceFlag(EComponentID sender, UInt8 balanceFlag);
	void setTransmitFlag(EComponentID sender, UInt8 transmitFlag);
	void setJumpVelocity(EComponentID sender);
	void getLogData(EComponentID sender);
	void jump(EComponentID sender);
	void commMessageReceived(EComponentID sender);
	void usartSynchroCheck(EComponentID sender);
	void timerCallback();
	void transmitPhiK(EComponentID sender, UInt16 phiK);
	void transmitPhiK_d(EComponentID sender, UInt16 phiK_d);
	void transmitPhiK_dd(EComponentID sender, UInt16 phiK_dd);
	void transmitPhiR_d(EComponentID sender, UInt16 phiR_d);
	void transmitBrakeState(EComponentID sender, UInt8 brakeState);
	void transmitStateEntry(EComponentID sender, EState state);
	void transmitUnhandeldEvent(EComponentID sender, EControlEvent event);
	void transmitVelocity(EComponentID sender, float velocity);
	void transmitAngle(EComponentID sender, float angle);

private:
	SProxy();

	static SProxy* sInstance;
	static bool sCreated;
	SControlComponent& mControlComp;
	SCommComponent& mCommComp;
};


#endif
