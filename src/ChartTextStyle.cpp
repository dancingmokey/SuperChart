/**
 * @Title: 			ChartTextStyle.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartTextStyle.h"

namespace SuperChart
{

ChartTextStyle::ChartTextStyle(uint32 nTextFont, uint32 nTextColor, uint32 nTextSize)
{
	// TODO Auto-generated constructor stub
	m_nTextColor = nTextColor;
	m_nTextSize = nTextSize;
	m_nTextFont = nTextFont;
}

ChartTextStyle::ChartTextStyle(ChartTextStyle& vChartTextStyle)
{
	// TODO Auto-generated constructor stub
	m_nTextColor = vChartTextStyle.getTextColor();
	m_nTextSize = vChartTextStyle.getTextSize();
	m_nTextFont = vChartTextStyle.getTextFont();
}


ChartTextStyle::ChartTextStyle()
{
	// TODO Auto-generated constructor stub
	m_nTextColor = Global::Color_Black;
	m_nTextSize = 0x00;
	m_nTextFont = 0x00;
}

ChartTextStyle::~ChartTextStyle()
{
	// TODO Auto-generated destructor stub
}

void ChartTextStyle::setTextStyle(uint32 nTextFont, uint32 nTextColor, uint32 nTextSize)
{
	// TODO Auto-generated constructor stub
	m_nTextColor = nTextFont;
	m_nTextSize = nTextColor;
	m_nTextFont = nTextSize;
}

/**
 *
 * @return
 */
uint32 ChartTextStyle::getTextColor() const
{
	return m_nTextColor;
}

/**
 *
 * @param nColor
 */
void ChartTextStyle::setTextColor(uint32 nTextColor)
{
	m_nTextColor = nTextColor;
}

/**
 *
 * @return
 */
uint32 ChartTextStyle::getTextFont() const
{
	return m_nTextFont;
}

/**
 *
 * @param nFont
 */
void ChartTextStyle::setTextFont(uint32 nTextFont)
{
	m_nTextFont = nTextFont;
}

/**
 *
 * @return
 */
uint32 ChartTextStyle::getTextSize() const
{
	return m_nTextSize;
}

/**
 *
 * @param nSize
 */
void ChartTextStyle::setTextSize(uint32 nTextSize)
{
	m_nTextSize = nTextSize;
}

} /* namespace SuperChart */
