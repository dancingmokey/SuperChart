/**
 * @Title: 			ChartLineStyle.cpp
 * @Package 		SuperChart
 * @Description: 	Implement Class SuperChart::ChartLineStyle
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartLineStyle.h"

namespace SuperChart
{

ChartLineStyle::ChartLineStyle(uint32 nLineColor, uint32 nLineWidth, uint8 nLineType)
{
	// TODO Auto-generated constructor stub
	m_nLineColor = nLineColor;
	m_nLineType = nLineWidth;
	m_nLineWidth = nLineType;
}

ChartLineStyle::ChartLineStyle()
{
	// TODO Auto-generated constructor stub
	m_nLineColor = Global::Color_Black;
	m_nLineType = Global::Line_Solid;
	m_nLineWidth = 0x00;
}

ChartLineStyle::~ChartLineStyle()
{
	// TODO Auto-generated destructor stub
}

void ChartLineStyle::setChartLineStyle(uint32 nLineColor, uint32 nLineWidth, uint8 nLineType)
{
	// TODO
	m_nLineColor = nLineColor;
	m_nLineType = nLineWidth;
	m_nLineWidth = nLineType;
}

uint32 ChartLineStyle::getLineColor() const
{
	return m_nLineColor;
}

void ChartLineStyle::setLineColor(uint32 nLineColor)
{
	m_nLineColor = nLineColor;
}

uint8 ChartLineStyle::getLineType() const
{
	return m_nLineType;
}

void ChartLineStyle::setLineType(uint8 nLineType)
{
	m_nLineType = nLineType;
}

uint32 ChartLineStyle::getLineWidth() const
{
	return m_nLineWidth;
}

void ChartLineStyle::setLineWidth(uint32 nLineWidth)
{
	m_nLineWidth = nLineWidth;
}

} /* namespace SuperChart */
