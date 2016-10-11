/**
 * @file	CFilterSystem.h
 * @author	Michael Meindl
 * @date	10.10.2016
 */
#ifndef CFILTERSYSTEM_H
#define CFILTERSYSTEM_H
#include "TFloatingMean.h"
#include "TKalmanFilter.h"
#include "CComplementaryFilter.h"
#include "CPhi.h"
#include "CPhi__d.h"
#include "CPsi__d.h"

class CFilterSystem
{
public:
	void calculateValues(Float32 phi, Float32 phi__d,
						 Float32 phi__dd, Float32 psi__d);
	const CPhi& getPhiValues() const;
	const CPhi__d& getPhi__dValues() const;
	const CPsi__d& getPsi__dValues() const;
public:
	CFilterSystem();
	CFilterSystem(const CFilterSystem&) = delete;
	CFilterSystem& operator=(const CFilterSystem&) = delete;
	~CFilterSystem() = default;
private:
	CComplementaryFilter mPhiComp;
	TKalmanFilter<ControlConfig::KalmanVarianceSize> mPhiKalman;
	TKalmanFilter<ControlConfig::KalmanVarianceSize> mPhi__dKalman;
	TFloatingMean<4> mPsi__dMean4;
	TFloatingMean<8> mPsi__dMean8;
	TFloatingMean<16> mPsi__dMean16;
	CPhi mPhi;
	CPhi__d mPhi__d;
	CPsi__d mPsi__d;
};

#endif
