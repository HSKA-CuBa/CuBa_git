/**
 * @file	ECommand.h
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Enumeration to represent the commands.
 */
#ifndef ECOMMAND_H
#define ECOMMAND_H
#include "Global.h"

enum class ECommand : UInt8
{
	/**
	 * Default command used for standard constructors
	 */
	CMD_DONT_CARE = 0,
	CMD_RUN_EXPERIMENT1 = 1,
	CMD_RUN_EXPERIMENT2 = 2,
	CMD_RUN_EXPERIMENT3 = 3,
	CMD_RUN_EXPERIMENT4 = 4,
	CMD_RUN_EXPERIMENT5 = 5,
	CMD_RUN_EXPERIMENT6 = 6
};

#endif
