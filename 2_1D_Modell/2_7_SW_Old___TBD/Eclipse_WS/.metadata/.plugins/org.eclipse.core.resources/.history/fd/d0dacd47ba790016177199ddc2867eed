// ==========================================================================
//  Copyright © 2016  Christian Steiger  -  All rights reserved
// ==========================================================================

#ifndef BBB_AIN_H_
#define BBB_AIN_H_

#include <stdint.h>

#define BBB_AIN_PATH "/sys/bus/iio/devices/iio:device0/"
#define BBB_AIN_FILE "in_voltage%u_raw"

enum AIN
{
	AIN0 = 0,
	AIN1,
	AIN2,
	AIN3,
	AIN4,
	AIN5,
	AIN6,
	AIN_MAX
};

// Data structure for the bbb_ain_* functions
struct bbb_ain
{
	    int fd;
	uint8_t channel;
};

int bbb_ain_open(struct bbb_ain* ain, uint8_t channel);
int bbb_ain_read(struct bbb_ain* ain, uint16_t* value);
int bbb_ain_close(struct bbb_ain* ain);

#endif /* GPIO_H_ */
