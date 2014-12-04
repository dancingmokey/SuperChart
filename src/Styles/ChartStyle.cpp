/**
 * @Title: 			ChartStyle.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

#include "ChartStyle.h"

namespace SuperChart
{

ChartStyle::ChartStyle()
{
	// TODO Auto-generated constructor stub
	m_bIsVisible = false;
}

ChartStyle::~ChartStyle()
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName: setVisible(bool bIsVisible)
 * @Description: Set Element Visible or Not
 * @param bIsVisible : bool : Visible Attibute Value
 */
void ChartStyle::setVisible(bool bIsVisible)
{
	m_bIsVisible = bIsVisible;
}

/**
 * @FuncName: isVisible(void)
 * @Description: Get Element is Visible or Not
 * @return bool
 */
bool ChartStyle::isVisible(void) const
{
	return m_bIsVisible;
}

} /* namespace SuperChart */
