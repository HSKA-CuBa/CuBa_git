// ==========================================================================
//  Copyright © 2016  Christian Steiger  -  All rights reserved
// ==========================================================================

#include <iostream>   // cout, cerr
#include <string>     // string, to_string
#include <cstdio>     // fprintf, perror
#include <cstring>    // strlen
#include <cerrno>     // errno
#include <unistd.h>   // open, close, read, write, access, F_OK
#include <fcntl.h>    // O_RDONLY
#include <cstdlib>
#include <string.h>

#include <linux/i2c.h>

#include "CBBBHardware.h"

using namespace std;

// --------------------------------------------------------------------------
//  Internal structure for mpu6050 readout
// --------------------------------------------------------------------------
struct mpu6050_data
{
	Int16 accel_x;
	Int16 accel_y;
	Int16 accel_z;
	Int16 anglvel_x;
	Int16 anglvel_y;
	Int16 anglvel_z;
}
__attribute__((packed));


// --------------------------------------------------------------------------
//  Defines to simplify some of the strings
// --------------------------------------------------------------------------
#define EHRPWM2B "/sys/class/pwm/pwmchip1/pwm1/"

// --------------------------------------------------------------------------
//  Constructor and destructor
// --------------------------------------------------------------------------
CBBBHardware::CBBBHardware()
{
	// TODO: Set variables
}

CBBBHardware::~CBBBHardware(){
}

// --------------------------------------------------------------------------
//  sysfsEcho
//    Simple function that emulates the echo X > /file on the console.
//    Needed to configure the IIO interface for the hardware.
// --------------------------------------------------------------------------
int CBBBHardware::sysfsEcho(const char* file, const char* string)
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


// --------------------------------------------------------------------------
//  initializeGpioPin
//    Configures one of the Gpio pins
// --------------------------------------------------------------------------
int CBBBHardware::initializeGpioPin(UInt8 gpio, UInt8 dir, UInt8 alow)
{

	int ret;

	// TODO: Detect invalid GPIO pin values
	// ...

	// Create the path for the iio-device representing the mpu6050
	string gpioPath = "/sys/class/gpio/gpio" + to_string(gpio);

	// Create a full filename for the attribute 'value'
	string value = gpioPath + "/value";


	// Primitive check if the GPIO interface is up and running...
	ret = access(value.c_str(), F_OK);
	if (ret < 0)
	{
		// ...if not, activate the driver interface for the GPIO pin
		ret = sysfsEcho("/sys/class/gpio/export", to_string(gpio).c_str());
		if (ret < 0)
		{
			cerr << "sysfsEcho to " << "/sys/class/gpio/export"
				<< " failed! ret: " << ret << endl;
			return -1;
		}
	}


	// Create filenames for other needed attributes
	string active_low = gpioPath + "/active_low";
	string direction  = gpioPath + "/direction";

	// Ensure that '0' really means '0' when we switch to output mode
	ret = sysfsEcho(active_low.c_str(), to_string(alow & 0x01).c_str());
	if (ret < 0) {
		cerr << "sysfsEcho to " << active_low
			<< " failed! ret: " << ret << endl;
		return -2;
	}

	// Set gpio pin for output
	ret = sysfsEcho(direction.c_str(), (dir & 0x01) ? "out" : "in");
	if (ret < 0) {
		cerr << "sysfsEcho to " << direction
			<< " failed! ret: " << ret << endl;
		return -3;
	}

	// Set gpio pin to 'low'
	ret = sysfsEcho(value.c_str(), "0");
	if (ret < 0) {
		cerr << "sysfsEcho to " << value
			<< " failed! ret: " << ret << endl;
		return -4;
	}

	return 0;
}

// --------------------------------------------------------------------------
//  initializeHardware
//    Configures the hardware needed for this class.
// --------------------------------------------------------------------------
int CBBBHardware::initializeHardware()
{
	int ret;

	// ------------------------------------------------------------------
	//  Configure GPIO pins for output
	// ------------------------------------------------------------------

	ret = initializeGpioPin(66);
	if (ret < 0) {
		cerr << "initializeGpioPin 66 failed! ret: " << ret << endl;
		return -1;
	}

	ret = initializeGpioPin(67);
	if (ret < 0) {
		cerr << "initializeGpioPin 67 failed! ret: " << ret << endl;
		return -1;
	}


	// ------------------------------------------------------------------
	//  Configure ADC for buffered continuous readout
	// ------------------------------------------------------------------

	// A little voodoo to make things more readable
	#define ADCDIR "/sys/bus/iio/devices/iio:device0/"

	// Disable buffered readout (so we can configure the buffer)
	ret = sysfsEcho(ADCDIR "buffer/enable", "0");
	if (ret < 0) {
		fprintf(stderr, "Echo to enable failed! ret: %d\n", ret);
		return -9;
	}

	// Enable the first channel for the buffered readout
	ret = sysfsEcho(ADCDIR "scan_elements/in_voltage0_en", "1");
	if (ret < 0) {
		fprintf(stderr, "Echo to in_voltage0_en failed! ret: %d\n", ret);
		return -10;
	}

	// Enable buffered readout
	ret = sysfsEcho(ADCDIR "buffer/enable", "1");
	if (ret < 0) {
		fprintf(stderr, "Echo to enable failed! ret: %d\n", ret);
		return -11;
	}

	// Undo our little voodoo
	#undef ADCDIR

	// Try to open the buffer we enabled above
	int fd;
	fd = open("/dev/iio:device0", O_RDONLY);
	if (fd < 0) {
		perror("open");
		return -12;
	}

	// Copy the file descriptor
	mAdcFd = fd;


	// ------------------------------------------------------------------
	//  Configure MPU6050 for buffered continuous readout
	// ------------------------------------------------------------------

	uint8_t bitfield = CMpu6050::ACCEL_X | CMpu6050::ACCEL_Y | CMpu6050::ANGLVEL_Z;

	ret = mpu6050[0].initialize(1, bitfield); // iio:device1, i2c 0x68
	if (ret < 0) {
		cerr << "mpu6050[0].initialize failed! ret: " << ret << endl;
		return -12;
	}

	ret = mpu6050[1].initialize(2, bitfield); // iio:device2, i2c 0x69
	if (ret < 0) {
		cerr << "mpu6050[0].initialize failed! ret: " << ret << endl;
		return -12;
	}


	// ------------------------------------------------------------------
	//  Configure PWM
	// ------------------------------------------------------------------

	// Check if the interface for EHRPWM2B is up and running...
	ret = access(EHRPWM2B "period", F_OK);
	if (ret < 0)
	{
		// ...if not, activate the driver interface for EHRPWM2B
		ret = sysfsEcho("/sys/class/pwm/pwmchip1/export", "1");
		if (ret < 0) {
			fprintf(stderr, "Echo to 'export' failed! ret: %d\n", ret);
			return -13;
		}
	}

	// Disable the PWM generator, just to be on the safe side
	ret = sysfsEcho(EHRPWM2B "enable", "0");
	if (ret < 0) {
		fprintf(stderr, "Echo to 'enable' failed! ret: %d\n", ret);
		return -14;
	}

	// Set polarity to 'normal' (again to be on the safe side)
	ret = sysfsEcho(EHRPWM2B "polarity", "normal");
	if (ret < 0) {
		fprintf(stderr, "Echo to 'polarity' failed! ret: %d\n", ret);
		return -15;
	}

	// Set PWM frequency to 50Hz (period of 20ms, written in nanoseconds)
	ret = sysfsEcho(EHRPWM2B "period", "20000000");
	if (ret < 0) {
		fprintf(stderr, "Echo to 'period' failed! ret: %d\n", ret);
		return -16;
	}

	// Set PWM duty cycle to 0%
	ret = sysfsEcho(EHRPWM2B "duty_cycle", "0");
	if (ret < 0) {
		fprintf(stderr, "Echo to 'duty_cycle' failed! ret: %d\n", ret);
		return -17;
	}

	// Enable the PWM generator
	ret = sysfsEcho(EHRPWM2B "enable", "1");
	if (ret < 0) {
		fprintf(stderr, "Echo to 'enable' failed! ret: %d\n", ret);
		return -18;
	}

	return 0;
}

// --------------------------------------------------------------------------
//  fetchValues
//    Fetches all needed values from the hardware in one go.
//    Neccessary since buffered read won't allow us to fetch single values.
// --------------------------------------------------------------------------
int CBBBHardware::fetchValues()
{
	int ret;
	UInt16 psi;

	// Read from the ADC buffer
	ret = read(mAdcFd, &psi, sizeof(UInt16));
	if ((ret < 0) || (ret < (int)sizeof(UInt16)))
	{
		perror("read");
		return -1;
	}

	// Copy the ADC values
	mPsi = psi;


	// Read from mpu6050 at Address 0x68
	ret = mpu6050[0].readValues();
	if (ret < 0)
	{
		cerr << "mpu6050[0].readValues() failed! ret: " << ret << endl;
		return -2;
	}

	// Read from mpu6050 at Address 0x69
	ret = mpu6050[1].readValues();
	if (ret < 0)
	{
		cerr << "mpu6050[1].readValues() failed! ret: " << ret << endl;
		return -3;
	}

	return 0;
}


Int16 CBBBHardware::getX1__dd_raw()
{
	return mpu6050[0].getAccelX();
}


Int16 CBBBHardware::getX2__dd_raw()
{
	return mpu6050[1].getAccelX();
}


Int16 CBBBHardware::getY1__dd_raw()
{
	return mpu6050[0].getAccelY();
}


Int16 CBBBHardware::getY2__dd_raw()
{
	return mpu6050[1].getAccelY();
}


Int16 CBBBHardware::getPhi1__d_raw()
{
	return mpu6050[0].getAnglVelZ();
}


Int16 CBBBHardware::getPhi2__d_raw()
{
	return mpu6050[1].getAnglVelZ();
}


UInt16 CBBBHardware::getPsi__d_raw()
{
	return mPsi;
}


void CBBBHardware::openBrake()
{
	// Set PWM duty cycle to 9.5% (value for open brake)
	int ret;
	ret = sysfsEcho(EHRPWM2B "duty_cycle", "1900000");
	if (ret < 0) {
		fprintf(stderr, "Echo to 'enable' failed! ret: %d\n", ret);
	}
}
//20000000

void CBBBHardware::closeBrake()
{
	//TODO PWM für Servo
	// Set PWM duty cycle to 7.3% (value for closed brake)

}

void CBBBHardware::enableMotor()
{
	this->setTorque(0.0F);
	// Set gpio pin 66 to 0
	int ret;
	ret = sysfsEcho("/sys/class/gpio/gpio66/value", "1");
	if (ret < 0) {
		fprintf(stderr, "Echo to 'value' failed! ret: %d\n", ret);
	}
}


void CBBBHardware::disableMotor()
{
	// Set gpio pin 66 to 0
	int ret;
	ret = sysfsEcho("/sys/class/gpio/gpio66/value", "0");
	if (ret < 0) {
		fprintf(stderr, "Echo to 'value' failed! ret: %d\n", ret);
	}
}


void CBBBHardware::setTorque(float torque)
{
	const char* value = "1";
	if (torque >= 0.0f) { value = "0"; }

	// Set GPIO67
	int ret;
	ret = sysfsEcho("/sys/class/gpio/gpio67/value", value);
	if (ret < 0) {
		fprintf(stderr, "Echo to 'value' failed! ret: %d\n", ret);
	}
	// Set PWM-DC
	torque = torque > 0.0F ? torque : -1.0F * torque;
	float period = 20000000.0F;
	int dc = static_cast<int>(period*(torque*11.258F+0.1F));
	std::string dcString = std::to_string(dc);
	ret = sysfsEcho(EHRPWM2B "duty_cycle", dcString.c_str());
	if (ret < 0) {
		fprintf(stderr, "Echo to 'enable' failed! ret: %d\n", ret);
	}
	return;
}


