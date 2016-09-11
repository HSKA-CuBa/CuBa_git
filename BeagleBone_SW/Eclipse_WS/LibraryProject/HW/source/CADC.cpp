//8.9.2016, Michael Meindl
//Method-Definitions to control the ADC0
#include "CADC.h"
#include <unistd.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fcntl.h>
#include <iostream>

#define ADC0_PATH "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"

float CADC::getADCValue()
{	Int32 number;
	mFileStream.open(ADC0_PATH, std::fstream::in);
	mFileStream >> number;
	mFileStream.close();
	return static_cast<float>(number);
}

CADC::CADC() : mFile(-1)
{

}
CADC::~CADC()
{
}
