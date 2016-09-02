/* Interrupt Handler
 *
 * Created on: 16.08.2016
 * Author: Alexander Schleicher
 * From Foundation of Michael Meindl
 */
#include "SCommComponent.h"

extern "C"
{
	//Interrupt von der UART
	void USART3_IRQHandler()
	{
		SCommComponent::getInstance().onUSARTIRQ();
	}

}
