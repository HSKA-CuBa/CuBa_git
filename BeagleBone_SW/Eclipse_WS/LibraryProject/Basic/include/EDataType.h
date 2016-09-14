//12.9.16, Michael Meindl
#ifndef EDATATYPE_H
#define EDATATYPE_H

enum class EDataType : UInt8
{
	DEFAULT_IGNORE = 0,
	SENSOR_DATA = 1,
	MOTOR_DATA = 2,
	UNFILTERED_DATA = 3,
	KALMAN_DATA = 4,
	COMPLEMENTARY_DATA = 5
};

#endif
