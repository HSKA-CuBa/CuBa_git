
#include <iostream>   // cerr
#include <cstdio>     // fprintf
#include <cstdlib>    // strtol
#include <string>     // string, to_string
#include <cstring>    // strlen
#include <unistd.h>   // write
#include <fcntl.h>    //

#include "CMpu6050.h"

using namespace std;


// --------------------------------------------------------------------------
//  Constructor & Destructor
// --------------------------------------------------------------------------
CMpu6050::CMpu6050() :
	mReadBitfield(0),
	mAccelX(0),
	mAccelY(0),
	mAccelZ(0),
	mAnglVelX(0),
	mAnglVelY(0),
	mAnglVelZ(0),
	mAccelXFd(0),
	mAccelYFd(0),
	mAccelZFd(0),
	mAnglVelXFd(0),
	mAnglVelYFd(0),
	mAnglVelZFd(0)
{
}

CMpu6050::~CMpu6050()
{
}


// --------------------------------------------------------------------------
//  initialize
//    Initialises the mpu6050 hardware.
// --------------------------------------------------------------------------
int CMpu6050::initialize(uint8_t iio, uint8_t read_bitfield)
{
	int ret;

	// Create the path for the iio-device representing the mpu6050
	string iioPath = "/sys/bus/iio/devices/iio:device" + to_string(iio);

	// Create a full filename for the attribute 'sampling_frequency'
	string sampling_frequency = iioPath + "/sampling_frequency";

	// Primitive check if the interface for the MPU is up and running
	ret = access(sampling_frequency.c_str(), F_OK);
	if (ret < 0)
	{
		perror("access");
		return -1;
	}

	// Create filenames for other needed attributes
	string enable          = iioPath + "/buffer/enable";
	string in_accel_x_en   = iioPath + "/scan_elements/in_accel_x_en";
	string in_accel_y_en   = iioPath + "/scan_elements/in_accel_y_en";
	string in_accel_z_en   = iioPath + "/scan_elements/in_accel_z_en";
	string in_anglvel_x_en = iioPath + "/scan_elements/in_anglvel_x_en";
	string in_anglvel_y_en = iioPath + "/scan_elements/in_anglvel_y_en";
	string in_anglvel_z_en = iioPath + "/scan_elements/in_anglvel_z_en";

	// Disable buffered readout so we can configure everything properly
	ret = echo(enable.c_str(), "0");
	if (ret < 0) {
		cerr << "Echo to " << enable << "failed! ret: " << ret << endl;
		return -2;
	}

	// Configure sampling frequency
	ret = echo(sampling_frequency.c_str(), "500");	// TODO : Sampling rate MPU6050
	if (ret < 0) {
		cerr << "Echo to " << sampling_frequency << "failed! ret: " << ret << endl;
		return -3;
	}


	// ---- Acceleration values ----

	ret = echo(in_accel_x_en.c_str(), (read_bitfield & ACCEL_X) ? "1" : "0");
	if (ret < 0) {
		cerr << "Echo to " << in_accel_x_en << "failed! ret: " << ret << endl;
		return -3;
	}

	ret = echo(in_accel_y_en.c_str(), (read_bitfield & ACCEL_Y) ? "1" : "0");
	if (ret < 0) {
		cerr << "Echo to " << in_accel_y_en << "failed! ret: " << ret << endl;
		return -4;
	}

	ret = echo(in_accel_z_en.c_str(), (read_bitfield & ACCEL_Z) ? "1" : "0");
	if (ret < 0) {
		cerr << "Echo to " << in_accel_z_en << "failed! ret: " << ret << endl;
		return -5;
	}


	// ---- Angle velocity values ----

	ret = echo(in_anglvel_x_en.c_str(), (read_bitfield & ANGLVEL_X) ? "1" : "0");
	if (ret < 0) {
		cerr << "Echo to " << in_anglvel_x_en << "failed! ret: " << ret << endl;
		return -6;
	}

	ret = echo(in_anglvel_y_en.c_str(), (read_bitfield & ANGLVEL_Y) ? "1" : "0");
	if (ret < 0) {
		cerr << "Echo to " << in_anglvel_y_en << "failed! ret: " << ret << endl;
		return -7;
	}

	ret = echo(in_anglvel_z_en.c_str(), (read_bitfield & ANGLVEL_Z) ? "1" : "0");
	if (ret < 0) {
		cerr << "Echo to " << in_anglvel_z_en << "failed! ret: " << ret << endl;
		return -8;
	}


	// Enable buffered readout
	ret = echo(enable.c_str(), "1");
	if (ret < 0) {
		cerr << "Echo to " << enable << "failed! ret: " << ret << endl;
		return -9;
	}


	// ---- Preopen sysfs entries ---------------------------------------

	string in_accel_x_raw   = iioPath + "/in_accel_x_raw";
	string in_accel_y_raw   = iioPath + "/in_accel_y_raw";
	string in_accel_z_raw   = iioPath + "/in_accel_z_raw";
	string in_anglvel_x_raw = iioPath + "/in_anglvel_x_raw";
	string in_anglvel_y_raw = iioPath + "/in_anglvel_y_raw";
	string in_anglvel_z_raw = iioPath + "/in_anglvel_z_raw";

	if (read_bitfield & ACCEL_X)
	{
		ret = open(in_accel_x_raw.c_str(), O_RDONLY);
		if (ret < 0) {
			cerr << "Open " << in_accel_x_raw << " failed! " << endl;
			perror("open");
			return -10;
		}

		mAccelXFd = ret;
	}

	if (read_bitfield & ACCEL_Y)
	{
		ret = open(in_accel_y_raw.c_str(), O_RDONLY);
		if (ret < 0) {
			cerr << "Open " << in_accel_y_raw << " failed! " << endl;
			perror("open");
			return -11;
		}

		mAccelYFd = ret;
	}

	if (read_bitfield & ACCEL_Z)
	{
		ret = open(in_accel_z_raw.c_str(), O_RDONLY);
		if (ret < 0) {
			cerr << "Open " << in_accel_z_raw << " failed! " << endl;
			perror("open");
			return -12;
		}

		mAccelZFd = ret;
	}

	if (read_bitfield & ANGLVEL_X)
	{
		ret = open(in_anglvel_x_raw.c_str(), O_RDONLY);
		if (ret < 0) {
			cerr << "Open " << in_anglvel_x_raw << " failed! " << endl;
			perror("open");
			return -13;
		}

		mAnglVelXFd = ret;
	}

	if (read_bitfield & ANGLVEL_Y)
	{
		ret = open(in_anglvel_y_raw.c_str(), O_RDONLY);
		if (ret < 0) {
			cerr << "Open " << in_anglvel_y_raw << " failed! " << endl;
			perror("open");
			return -14;
		}

		mAnglVelYFd = ret;
	}

	if (read_bitfield & ANGLVEL_Z)
	{
		ret = open(in_anglvel_z_raw.c_str(), O_RDONLY);
		if (ret < 0) {
			cerr << "Open " << in_anglvel_z_raw << " failed! " << endl;
			perror("open");
			return -15;
		}

		mAnglVelZFd = ret;
	}

	// Copy the bitfield values
	mReadBitfield = read_bitfield;

	return 0;
}

// --------------------------------------------------------------------------
//  read_int32
//    Reads and converts a int32 value from a sysfs entry fd.
// --------------------------------------------------------------------------
int CMpu6050::read_int32(int fd, int32_t* value)
{
	// Control function parameters
	if (   fd  < 0) { cerr << "Parameter 'fd' < 0"     << endl; return -1; }
	if (value == 0) { cerr << "Parameter 'value' == 0" << endl; return -2; }

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
//  readValues
//    Read a complete set of values from the device.
// --------------------------------------------------------------------------
int CMpu6050::readValues(uint8_t read_bitfield)
{
	uint8_t bitfield;
	bitfield = (mReadBitfield & read_bitfield);
	if (!bitfield) { return 0; }

	int     ret;
	int32_t value;

	if (bitfield & ACCEL_X)
	{
		ret = read_int32(mAccelXFd, &value);
		if (ret < 0)
		{
			cerr << "Read from AccelX failed! ret: " << ret << endl;
			return -1;
		}

		mAccelX = (int16_t)value;
	}

	if (bitfield & ACCEL_Y)
	{
		ret = read_int32(mAccelYFd, &value);
		if (ret < 0)
		{
			cerr << "Read from AccelY failed! ret: " << ret << endl;
			return -2;
		}

		mAccelY = (int16_t)value;
	}

	if (bitfield & ACCEL_Z)
	{
		ret = read_int32(mAccelZFd, &value);
		if (ret < 0)
		{
			cerr << "Read from AccelZ failed! ret: " << ret << endl;
			return -3;
		}

		mAccelZ = (int16_t)value;
	}

	if (bitfield & ANGLVEL_X)
	{
		ret = read_int32(mAnglVelXFd, &value);
		if (ret < 0)
		{
			cerr << "Read from AnglVelX failed! ret: " << ret << endl;
			return -4;
		}

		mAnglVelX = (int16_t)value;
	}

	if (bitfield & ANGLVEL_Y)
	{
		ret = read_int32(mAnglVelYFd, &value);
		if (ret < 0)
		{
			cerr << "Read from AnglVelY failed! ret: " << ret << endl;
			return -5;
		}

		mAnglVelY = (int16_t)value;
	}

	if (bitfield & ANGLVEL_Z)
	{
		ret = read_int32(mAnglVelZFd, &value);
		if (ret < 0)
		{
			cerr << "Read from AnglVelZ failed! ret: " << ret << endl;
			return -6;
		}

		mAnglVelZ = (int16_t)value;
	}
	return 0;
}

// --------------------------------------------------------------------------
//  Return values fetched by 'readValues'
// --------------------------------------------------------------------------
int16_t CMpu6050::getAccelX() { return mAccelX; }
int16_t CMpu6050::getAccelY() { return mAccelY; }
int16_t CMpu6050::getAccelZ() { return mAccelZ; }
int16_t CMpu6050::getAnglVelX() { return mAnglVelX; }
int16_t CMpu6050::getAnglVelY() { return mAnglVelY; }
int16_t CMpu6050::getAnglVelZ() { return mAnglVelZ; }


// --------------------------------------------------------------------------
//  echo
// --------------------------------------------------------------------------
int CMpu6050::echo(const char* file, const char* string)
{
	// Control function parameters
	if (file == 0 || string == 0) {
		fprintf(stderr, "Invalid parameters.\n");
		return -1;
	}

	// Open the sysfs-entry
	int fd;
	fd = open(file, O_WRONLY);
	if (fd < 0) {
		perror("open");
		return -2;
	}

	// Write into the sysfs entry
	int ret;
	ret = write(fd, string, strlen(string));
	if (ret < 0)
	{
		perror("write");
		return -3;
	}
	else if (ret < (int)strlen(string))
	{
		return -4;
	}

	// Close the sysfs-entry
	close(fd);

	return 0;
}
