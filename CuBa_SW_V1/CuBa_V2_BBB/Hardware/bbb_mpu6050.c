// ==========================================================================
//  Copyright © 2016  Christian Steiger  -  All rights reserved
// ==========================================================================

#define _GNU_SOURCE     // Needed for asprintf

// Headers
#include <stdio.h>      // fprintf, perror, asprintf
#include <stdlib.h>     // strtoul
#include <string.h>     // strchr
#include <unistd.h>     // read, close, lseek
#include <fcntl.h>      // open, SEEK_SET
#include "bbb_mpu6050.h"

#define IIO_PATH "/sys/bus/iio/devices/iio:device"

// --------------------------------------------------------------------------
//  bbb_mpu6050_open
// --------------------------------------------------------------------------
int bbb_mpu6050_open(struct bbb_mpu6050* mpu, uint8_t num)
{
	int ret;

	// Control function parameters
	if (mpu == 0) {
		fprintf(stderr, "Parameter 'mpu' == 0\n");
		return -1;
	}

	// Piece the sysfs-filenames together for the accel values
	char* accel_x = 0;
	ret = asprintf(&accel_x, IIO_PATH "%u/in_accel_x_raw", num);
	if (ret < 0) { fprintf(stderr, "asprintf failed!\n"); ret = -2; goto end; }

	char* accel_y = 0;
	ret = asprintf(&accel_y, IIO_PATH "%u/in_accel_y_raw", num);
	if (ret < 0) { fprintf(stderr, "asprintf failed!\n"); ret = -3; goto end; }

	char* accel_z = 0;
	ret = asprintf(&accel_z, IIO_PATH "%u/in_accel_z_raw", num);
	if (ret < 0) { fprintf(stderr, "asprintf failed!\n"); ret = -4; goto end; }

	char* accel_s = 0;
	ret = asprintf(&accel_s, IIO_PATH "%u/in_accel_scale", num);
	if (ret < 0) { fprintf(stderr, "asprintf failed!\n"); ret = -5; goto end; }


	// Piece the sysfs-filenames together for the anglvel values
	char* anglvel_x = 0;
	ret = asprintf(&anglvel_x, IIO_PATH "%u/in_anglvel_x_raw", num);
	if (ret < 0) { fprintf(stderr, "asprintf failed!\n"); ret = -6; goto end; }

	char* anglvel_y = 0;
	ret = asprintf(&anglvel_y, IIO_PATH "%u/in_anglvel_y_raw", num);
	if (ret < 0) { fprintf(stderr, "asprintf failed!\n"); ret = -7; goto end; }

	char* anglvel_z = 0;
	ret = asprintf(&anglvel_z, IIO_PATH "%u/in_anglvel_z_raw", num);
	if (ret < 0) { fprintf(stderr, "asprintf failed!\n"); ret = -8; goto end; }

	char* anglvel_s = 0;
	ret = asprintf(&anglvel_s, IIO_PATH "%u/in_anglvel_scale", num);
	if (ret < 0) { fprintf(stderr, "asprintf failed!\n"); ret = -9; goto end; }


	// Open the accel entries
	ret = open(accel_x, O_RDONLY);
	if (ret < 0) { perror("open"); ret = -10; goto end; }
	mpu->fd.accel[0] = ret;

	ret = open(accel_y, O_RDONLY);
	if (ret < 0) { perror("open"); ret = -11; goto end; }
	mpu->fd.accel[1] = ret;

	ret = open(accel_z, O_RDONLY);
	if (ret < 0) { perror("open"); ret = -12; goto end; }
	mpu->fd.accel[2] = ret;

	ret = open(accel_s, O_RDONLY);
	if (ret < 0) { perror("open"); ret = -13; goto end; }
	mpu->fd.accel[3] = ret;


	// Open the anglvel entries
	ret = open(anglvel_x, O_RDONLY);
	if (ret < 0) { perror("open"); ret = -14; goto end; }
	mpu->fd.anglvel[0] = ret;

	ret = open(anglvel_y, O_RDONLY);
	if (ret < 0) { perror("open"); ret = -15; goto end; }
	mpu->fd.anglvel[1] = ret;

	ret = open(anglvel_z, O_RDONLY);
	if (ret < 0) { perror("open"); ret = -16; goto end; }
	mpu->fd.anglvel[2] = ret;

	ret = open(anglvel_s, O_RDONLY);
	if (ret < 0) { perror("open"); ret = -17; goto end; }
	mpu->fd.anglvel[3] = ret;


	// Copy iio device number
	mpu->iio_device_num = num;


	// Free asprintf strings, end function
	ret = 0;
end:
	free(accel_x);
	free(accel_y);
	free(accel_z);
	free(accel_s);
	free(anglvel_x);
	free(anglvel_y);
	free(anglvel_z);
	free(anglvel_s);

	return ret;
}


// --------------------------------------------------------------------------
//  bbb_mpu6050_read_entry
// --------------------------------------------------------------------------
static int read_int32(int fd, int32_t* value)
{
	// Control function parameters
	if (fd < 0) {
		fprintf(stderr, "Parameter 'fd' < 0\n");
		return -1;
	}

	if (value == 0) {
		fprintf(stderr, "Parameter 'value' == 0\n");
		return -2;
	}

	int ret;

	// Reset file position to prevent errors
	ret = lseek(fd, 0, SEEK_SET);
	if (ret < 0)
	{
		perror("lseek");
		return -4;
	}

	// Try to read a value from the AIN channel
	char buf[32];
	ret = read(fd, buf, 32);
	if (ret < 0)
	{
		perror("read");
		return -3;
	}

	// Search for a carriage return
	char* end = 0;
	end = strchr(buf, 0xA);
	if (end == 0)
	{
		fprintf(stderr, "Invalid output!\n");
		return -4;
	}

	// Convert the string into an integer
	*value = (int32_t) strtol(buf, &end, 10);

	return 0;
}

// --------------------------------------------------------------------------
//  bbb_mpu6050_read
// --------------------------------------------------------------------------
int bbb_mpu6050_read(struct bbb_mpu6050* mpu, struct bbb_mpu6050_values* val)
{
	// Control function parameters
	if (mpu == 0) {
		fprintf(stderr, "Parameter 'mpu' == 0\n");
		return -1;
	}

	if (val == 0) {
		fprintf(stderr, "Parameter 'val' == 0\n");
		return -2;
	}

	// Read acceleration values
	int i;
	for(i = 0; i < 3; i++)
	{
		read_int32(mpu->fd.accel[i], &val->accel[i]);
	}

	// Read angel velocity values
	for(i = 0; i < 3; i++)
	{
		read_int32(mpu->fd.anglvel[i], &val->anglvel[i]);
	}

	return 0;
}




