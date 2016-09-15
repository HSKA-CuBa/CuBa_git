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
#include "bbb_ain.h"

// --------------------------------------------------------------------------
//  bbb_ain_open
// --------------------------------------------------------------------------
int bbb_ain_open(struct bbb_ain* ain, uint8_t channel)
{
	int ret;

	// Control function parameters
	if (ain == 0) {
		fprintf(stderr, "Parameter 'ain' == 0\n");
		return -1;
	}

	if (channel >= AIN_MAX) {
		fprintf(stderr, "Parameter 'channel' too big\n");
		return -2;
	}


	// Piece the sysfs-filename for the AIN-channel together
	char* ain_file;
	ret = asprintf(
		&ain_file,
		BBB_AIN_PATH BBB_AIN_FILE,
		channel
	);
	if (ret < 0) {
		fprintf(stderr, "asprintf failed!\n");
		return -3;
	}

	// Open the sysfs-entry
	ret = open(ain_file, O_RDONLY);
	if (ret < 0) {
		perror("open");
		return -4;
	}


	// Copy values into structure
	ain->fd      = ret;
	ain->channel = channel;

	return 0;

}


// --------------------------------------------------------------------------
//  bbb_ain_open
// --------------------------------------------------------------------------
int bbb_ain_read(struct bbb_ain* ain, uint16_t* value)
{
	// Control function parameters
	if (ain == 0) {
		fprintf(stderr, "Parameter 'ain' == 0\n");
		return -1;
	}

	if (value == 0) {
		fprintf(stderr, "Parameter 'value' == 0\n");
		return -2;
	}

	int ret;

	// The file
	ret = lseek(ain->fd, 0, SEEK_SET);
	if (ret < 0)
	{
		perror("lseek");
		return -4;
	}

	// Try to read a value from the AIN channel
	char buf[16];
	ret = read(ain->fd, buf, 16);
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
	*value = (uint16_t) strtoul(buf, &end, 10);

	return 0;
}


// --------------------------------------------------------------------------
//  bbb_ain_open
// --------------------------------------------------------------------------
int bbb_ain_close(struct bbb_ain* ain)
{
	// Close the file and invalidate the file-descriptor
	close(ain->fd);
	ain->fd = -1;

	return 0;
}

