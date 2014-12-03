/**
 * @Title: 			ChartLine.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartLine.h"

namespace SuperChart
{

ChartLine::ChartLine()
{
	// TODO Auto-generated constructor stub
}

ChartLine::~ChartLine()
{
	// TODO Auto-generated destructor stub
}

const ChartLineStyle& ChartLine::getLineStyle() const
{
	return m_vLineStyle;
}

void ChartLine::setLineStyle(const ChartLineStyle& vLineStyle)
{
	m_vLineStyle = vLineStyle;
}

} /* namespace SuperChart */
