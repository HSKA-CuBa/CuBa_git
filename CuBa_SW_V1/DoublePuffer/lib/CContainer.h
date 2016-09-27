/**
 * @file	CContainer.h
 * @author	Michael Meindl
 * @date	25.9.2016
 * @brief	Class definition for a container.
 */
#ifndef CCONTAINER_H
#define CCONTAINER_H
#include "Global.h"

class CContainer
{
public:
	struct CPhiValues
	{
		Float32 mRaw;		/// Phi value from the angle estimation.
		Float32 mComp;		/// Phi value from the complementary filter.
		Float32 mKalman;	/// Phi value from the kalman filter.
	};
	struct CPhi__dValues
	{
		Float32 mRaw;		/// Phi__d value from the gyroscope.
		Float32 mKalman;	/// Phi__d value from the kalmanf filter.
	};
	struct CPsi__dValues
	{
		Float32 mRaw;		/// Psi__d value from the ADC.
		Float32 mMean4;		/// Psi__d value from the floating mean over the last 4 values.
		Float32 mMean8; 	/// Psi__d value from the floating mean over the last 8 values.
		Float32 mMean16;	/// Psi__d value fromt he floating mean over the last 16 values.
	};
public:
	bool setData(CPhiValues& phiValues,
				 CPhi__dValues& phi__dValues,
				 CPsi__dValues& psi__dValues);
	bool getData(CPhiValues& phiValues,
				 CPhi__dValues& phi__dValues,
				 CPsi__dValues& psi__dValues);
public:
	CContainer();
	CContainer(const CContainer&) = delete;
	CContainer& operator=(const CContainer&) = default;
	~CContainer() = default;
private:
	CPhiValues mPhiValues;
	CPhi__dValues mPhi__dValues;
	CPsi__dValues mPsi__dValues;
};
#endif