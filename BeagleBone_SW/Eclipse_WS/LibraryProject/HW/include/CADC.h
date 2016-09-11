//8.9.16, Michael Meindl
//Class-Definition to control the ADC0
#ifndef CADC_H
#define CADC_H
#include "Global.h"
#include <iostream>
#include <fstream>

class CADC
{
public:
	float getADCValue();
public:
	CADC();
	CADC(const CADC&) = delete;
	CADC& operator=(const CADC&) = delete;
	~CADC();
private:
	std::fstream mFileStream;
	Int32 mFile;
};

#endif
