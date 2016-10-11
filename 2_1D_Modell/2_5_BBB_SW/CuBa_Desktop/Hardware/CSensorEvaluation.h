/**
 * @file	CSensorEvaluation.h
 * @author	Michael Meindl
 * @date 	13.9.2016
 */
#ifndef CSENSOREVALUATION_H
#define CSENSOREVALUATION_H
#include "Global.h"
#include "CDummyHW.h"
#include "CSensorData.h"

class CSensorEvaluation
{
public:
	const CSensorData& getSensorData() const;
	Float32 getPhi() const;
	Float32 getPhi__d() const;
	Float32 getPhi__dd() const;
	Float32 getPsi__d() const;
	void calculateValues();
public:
	CSensorEvaluation();
	CSensorEvaluation(const CSensorEvaluation&) = delete;
	CSensorEvaluation& operator=(const CSensorEvaluation&) = delete;
	~CSensorEvaluation() = default;
private:
	CDummyHW mHW;
	CSensorData mSensorData;
	Float32 mPhi;
	Float32 mPhi__d;
	Float32 mPhi__dd;
	Float32 mPsi__d;
};

#endif
