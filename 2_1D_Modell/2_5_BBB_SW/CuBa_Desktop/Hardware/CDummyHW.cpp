/**
 * @file	CDummyHW.cpp
 * @author	Michael Meindl
 * @date	9.10.2016
 */
#include "CDummyHW.h"
#include <iostream>
using namespace std;

CDummyHW::CDummyHW() : mX1(0), mX2(0), mY1(0), mY2(0),
					   mPhi1(0), mPhi2(0), mPsi(0U)
{

}
Int16 CDummyHW::getX1_raw__dd()
{
	mX1++;
	return mX1;
}
Int16 CDummyHW::getX2_raw__dd()
{
	mX2++;
	return mX2;
}
Int16 CDummyHW::getY1_raw__dd()
{
	mY1++;
	return mY1;
}
Int16 CDummyHW::getY2_raw__dd()
{
	mY2++;
	return mY2;
}
Int16 CDummyHW::getPhi1_raw__d()
{
	mPhi1++;
	return mPhi1;
}
Int16 CDummyHW::getPhi2_raw__d()
{
	mPhi2++;
	return mPhi2;
}
UInt16 CDummyHW::getPsi_raw__d()
{
	mPsi++;
	return mPsi;
}
void CDummyHW::enableMotor()
{
	cout << "[*] Hardware: Enabling Motor" << endl;
}
void CDummyHW::disableMotor()
{
	cout << "[*] Hardware: Disabling Motor" << endl;
}
void CDummyHW::setTorque(Float32 torque)
{
	cout << "[*] Hardware: Setting torque " << torque << endl;
}
