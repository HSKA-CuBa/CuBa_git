/**
 * @file EDataType.h
 * @author Michael Meindl
 * @date 24.9.2016
 * @brief Enumeration to represent the different types of data which are stored in messages.
 */
#ifndef EDATATYPE_H
#define EDATATYPE_H
#include "Global.h"

enum class EDataType : UInt8
{
	/**
	 * Default type which is used in standard constructors.
	 */
	DEFAULT_IGNORE = 0,
    /**
     * Datatype to represent the raw sensor values from the accelerometers, gyroscopes and ADC.
     */
    SENSORDATA = 1,
	/**
	 * Datatype to represent a packet which contains the phi values from different filters.
	 */
	PHI = 2,
	/**
	 * Datatype to represent a packet which contains the phi__d values from different filters.
	 */
	PHI__D = 3,
	/**
	 * Datatype to represent a packet which contains the psi__d values from different filters.
	 */
	PSI__D = 4
};

#endif
