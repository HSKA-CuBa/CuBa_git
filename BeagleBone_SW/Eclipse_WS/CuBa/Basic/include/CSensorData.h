//12.9.16, Michael Meindl
#ifndef CSENSORDATA_H
#define CSENSORDATA_H
#include "Global.h"

/// Container-Class to hold the current sensor raw values.
class CSensorData
{
public:
	Float32 getTime() const;
	Int16 getX1_raw__dd() const;
	Int16 getX2_raw__dd() const;
	Int16 getY1_raw__dd() const;
	Int16 getY2_raw__dd() const;
	Int16 getPhi1_raw__d() const;
	Int16 getPhi2_raw__d() const;
public:
	///Constructor to create an instance with valid data.
	CSensorData(Float32 time,
				Int16 x1_raw__dd,
				Int16 y1_raw__dd,
				Int16 phi1_raw__dd,
				Int16 x2_raw__dd,
				Int16 y2_raw__dd,
				Int16 phi2_raw__dd);
	CSensorData(const CSensorData&) = default;
	CSensorData& operator=(const CSensorData&) = default; 	///< Required to copy messages into the queue.
	~CSensorData() = default;
private:
	Float32 mTime;			///< Current time.
	Int16 mX1_raw__dd;		///< Current X1-Acceleration in 2-complement.
	Int16 mY1_raw__dd;		///< Current Y1-Acceleration in 2-complement.
	Int16 mPhi1_raw__d;	///< Current Z1-Angular-Velocity in 2-complement.
	Int16 mX2_raw__dd;		///< Current X2-Acceleration in 2-complement.
	Int16 mY2_raw__dd;		///< Current Y2-Acceleration in 2-complement.
	Int16 mPhi2_raw__d;	///< Current Z2-Angular-Velocity in 2-complement.
};

#endif
