// ==========================================================================
//  Copyright © 2016  Christian Steiger  -  All rights reserved
// ==========================================================================

#ifndef CMPU6050_H
#define CMPU6050_H

#include <cstdint>

class CMpu6050
{
public:
	CMpu6050();
	~CMpu6050();

	enum values_bitfield
	{
		ACCEL_X     = 0x01,
		ACCEL_Y     = 0x02,
		ACCEL_Z     = 0x04,
		ACCEL_ALL   = ACCEL_X | ACCEL_Y | ACCEL_Z,
		ANGLVEL_X   = 0x08,
		ANGLVEL_Y   = 0x10,
		ANGLVEL_Z   = 0x20,
		ANGLVEL_ALL = ANGLVEL_X | ANGLVEL_Y | ANGLVEL_Z,
		ALL         = ACCEL_ALL | ANGLVEL_ALL,
	};

	int initialize(uint8_t iio, uint8_t read_bitfield = ALL);

	int readValues(uint8_t read_bitfield = ALL);

	int16_t getAccelX();
	int16_t getAccelY();
	int16_t getAccelZ();
	int16_t getAnglVelX();
	int16_t getAnglVelY();
	int16_t getAnglVelZ();


private:
	int echo(const char* file, const char* string);
	int read_int32(int fd, int32_t* value);

	uint8_t mReadBitfield;

	int16_t mAccelX;
	int16_t mAccelY;
	int16_t mAccelZ;
	int16_t mAnglVelX;
	int16_t mAnglVelY;
	int16_t mAnglVelZ;

	int mAccelXFd;
	int mAccelYFd;
	int mAccelZFd;
	int mAnglVelXFd;
	int mAnglVelYFd;
	int mAnglVelZFd;
};

#endif
