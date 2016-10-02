// ==========================================================================
//  Copyright © 2016  Christian Steiger  -  All rights reserved
// ==========================================================================

#ifndef BBB_MPU6050_H_
#define BBB_MPU6050_H_

#include <stdint.h>

// Data structure for the bbb_mpu6050_* functions
struct bbb_mpu6050
{
	// File descriptors
	struct
	{
		int accel[4];   // x y z s
		int anglvel[4]; // x y z s
	} fd;

	uint8_t iio_device_num;
};

struct bbb_mpu6050_values
{
	int accel[3];
	int anglvel[3];
};

int bbb_mpu6050_open(struct bbb_mpu6050* mpu, uint8_t iio_device_num);
int bbb_mpu6050_read(struct bbb_mpu6050* mpu, struct bbb_mpu6050_values* val);
int bbb_mpu6050_close(struct bbb_mpu6050* mpu);

#endif /* GPIO_H_ */
