//13.9.16, Michael Meindl
#ifndef CSENSOREVALUATION_H
#define CSENSOREVALUATION_H
#include "Global.h"

class CSensorEvaluation
{
public:
	Float32 getPhi() const;
	Float32 getPhi__d() const;
	Float32 getPhi__dd() const;
	Float32 getPsi__d() const;
	void calculateValues(const Int16 x1_raw__dd,
						 const Int16 x2_raw__dd,
						 const Int16 y1_raw__dd,
						 const Int16 y2_raw__dd,
						 const Int16 phi1_raw__d,
						 const Int16 phi2_raw__d,
						 const UInt16 psi_raw__d);
public:
	CSensorEvaluation();
	CSensorEvaluation(const CSensorEvaluation&) = delete;
	CSensorEvaluation& operator=(const CSensorEvaluation&) = delete;
	~CSensorEvaluation() = default;
private:
	Float32 mPhi;
	Float32 mPhi__d;
	Float32 mPhi__dd;
	Float32 mPsi__d;
};

#endif
