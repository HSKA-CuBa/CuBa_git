/*Control component
 *
 * Created on: 16.08.2016
 * Author: Alexander Schleicher
 * From Foundation of Michael Meindl
 */

#ifndef INCLUDE_SCONTROLCOMPONENT_H_
#define INCLUDE_SCONTROLCOMPONENT_H_

#include "CMessage.h"
#include "AComponentBase.h"
#include "CControlFSM.h"


class SControlComponent : public AComponentBase
{
public:
	static SControlComponent& getInstance();
	SControlComponent(const SControlComponent&) = delete;
	SControlComponent& operator=(const SControlComponent&) = delete;
	~SControlComponent() override = default;

	bool dispatch(const CMessage& msg) override;

private:
	SControlComponent();
	static SControlComponent* sInstance;
	CControlFSM mFSM;
};


#endif
