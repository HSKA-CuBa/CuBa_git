/* Base class for Components
 *
 * Created on: 16.08.2016
 * Author: Alexander Schleicher
 * From Foundation of Michael Meindl
 */

#ifndef INCLUDE_ACOMPONENTBASE_H_
#define INCLUDE_ACOMPONENTBASE_H_

#include "CMessage.h"
#include "Global.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "EComponentID.h"

//class CMessage;		//XXX in use?

class AComponentBase
{
public:
	AComponentBase(EComponentID id);
	AComponentBase(const AComponentBase&) = delete;
	AComponentBase& operator=(const AComponentBase&) = delete;
	virtual ~AComponentBase();

	void run();
	virtual bool dispatch(const CMessage& msg) = 0;

protected:
	xQueueHandle mQueue;
	EComponentID mID;

	friend class SProxy;

};


#endif
