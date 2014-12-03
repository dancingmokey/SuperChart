/**
 * @Title: 			ChartText.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartText.h"

namespace SuperChart
{

/**
 *
 * @param strText
 * @param nFont
 * @param nColor
 * @param nSize
 */
ChartText::ChartText(GeoRect* pBoundRect, string strText, ChartTextStyle vTextStyle)
{
	// TODO Auto-generated constructor stub
	m_strText = strText;
	m_vTextStyle = vTextStyle;
	this->setBoundRect(pBoundRect);
}

/**
 *
 */
ChartText::ChartText()
{
	// TODO Auto-generated constructor stub
	m_strText = "";
//	m_vTextStyle =
}

/**
 *
 */
ChartText::~ChartText()
{
	// TODO Auto-generated destructor stub
}

/**
 *
 * @return
 */
const string& ChartText::getText() const
{
	return m_strText;
}

/**
 *
 * @param strText
 */
void ChartText::setText(const string& strText)
{
	m_strText = strText;
}

/**
 *
 * @return
 */
const ChartTextStyle& ChartText::getTextStyle() const
{
	return m_vTextStyle;
}

/**
 *
 * @param vTextStyle
 */
void ChartText::setTextStyle(const ChartTextStyle& vTextStyle)
{
	m_vTextStyle = vTextStyle;
}

} /* namespace SuperChart */
