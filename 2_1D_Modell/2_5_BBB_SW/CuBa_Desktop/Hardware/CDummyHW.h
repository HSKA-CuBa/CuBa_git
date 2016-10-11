/**
 * @file	DummyHW.h
 * @author	Michael Meindl
 * @date	9.10.2016
 */
#ifndef DUMMYHW_H
#define DUMMYHW_H
#include "Global.h"

class CDummyHW
{
public:
	Int16 getX1_raw__dd();
	Int16 getX2_raw__dd();
	Int16 getY1_raw__dd();
	Int16 getY2_raw__dd();
	Int16 getPhi1_raw__d();
	Int16 getPhi2_raw__d();
	UInt16 getPsi_raw__d();
	void enableMotor();
	void disableMotor();
	void setTorque(Float32 torque);
public:
	CDummyHW();
	CDummyHW(const CDummyHW&) = delete;
	CDummyHW& operator=(const CDummyHW&) = delete;
	~CDummyHW() = default;
private:
	Int16 mX1;
	Int16 mX2;
	Int16 mY1;
	Int16 mY2;
	Int16 mPhi1;
	Int16 mPhi2;
	UInt16 mPsi;
};

#endif
