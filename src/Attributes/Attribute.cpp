/**
 * @Title: 			Attribute.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/05
 * @Version:		V1.0.0	
 */

#include "Attribute.h"

namespace SuperChart
{

Attribute::Attribute()
{
	// TODO Auto-generated constructor stub

}

Attribute::~Attribute()
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName : setTitle(const string& strTitle)
 * @Description: Set Axis Title
 * @param strTitle : string : Title of Axis
 */
void Attribute::setTitle(const string& strTitle)
{
	m_strTitle = strTitle;
}

/**
 * @FuncName : getTitle(void)
 * @Description: Get Axis Title
 * @return string
 */
const string& Attribute::getTitle(void) const
{
	return m_strTitle;
}

} /* namespace SuperChart */
