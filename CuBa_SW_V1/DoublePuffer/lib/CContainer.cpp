/**
 * @file 	CContainer.cpp
 * @author	Michael Meindl
 * @date	25.9.2016
 * @brief	Class definitions for CContainer.
 */
#include "CContainer.h"


bool CContainer::setData(CPhiValues& phiValues,
						 CPhi__dValues& phi__dValues,
						 CPsi__dValues& psi__dValues)
{
	mPhiValues 		= phiValues;
	mPhi__dValues	= phi__dValues;
	mPsi__dValues	= psi__dValues;
	return true;
}
bool CContainer::getData(CPhiValues& phiValues,
			 	 	 	 CPhi__dValues& phi__dValues,
						 CPsi__dValues& psi__dValues)
{
	phiValues		= mPhiValues;
	phi__dValues	= mPhi__dValues;
	psi__dValues	= mPsi__dValues;
	return true;
}
CContainer::CContainer() : mPhiValues{0.0F, 0.0F, 0.0F},
						   mPhi__dValues{0.0F, 0.0F},
						   mPsi__dValues{0.0F, 0.0F,0.0F, 0.0F}
{

}
