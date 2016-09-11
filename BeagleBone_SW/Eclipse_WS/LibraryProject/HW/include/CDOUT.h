//7.9.2016, Michael Meindl
//Class-Declaration to run a GPIO as digital output
#ifndef CDOUT_H
#define CDOUT_H
#include "Global.h"
#include <string>

class CDOUT
{
public:
	void setPinState(bool state);
public:
	CDOUT(std::string pinNumber);
	CDOUT() = delete;
	CDOUT(const CDOUT&) = delete;
	CDOUT& operator=(const CDOUT&) = delete;
	~CDOUT();
private:
	Int32 mFile;
	std::string mPin;
};

#endif
