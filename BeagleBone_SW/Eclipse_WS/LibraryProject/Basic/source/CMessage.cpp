#include "CMessage.h"

CMessage::CMessage() : mData(0.0F)
{

}
float CMessage::getData()
{
	return mData;
}
void CMessage::setData(float data)
{
	mData = data;
}

