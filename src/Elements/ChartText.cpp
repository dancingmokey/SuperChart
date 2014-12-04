/**
 * @Title: 			ChartText.cpp
 * @Package 		SuperChart
 * @Description: 	Implement Class SuperChart::ChartText
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartText.h"

namespace SuperChart
{

/**
 * @FuncName: ChartText(GeoRect* pBoundRect, string strText, ChartStyle* pStyle, bool bIsVisible)
 * @Description: Custom Constructor Function
 * @param pBoundRect : GeoRect* : Text Bound Rectangle
 * @param pStyle : ChartStyle* : Text Style
 * @param strText : string : Text String
 */
ChartText::ChartText(GeoRect* pBoundRect,
		ChartStyle* pStyle,
		string strText) :
		ChartElement(pBoundRect, pStyle)
{
	// TODO Auto-generated constructor stub
	m_strText = strText;
}

/**
 * @FuncName: ChartText(void)
 * @Description: Default Constructor Function
 */
ChartText::ChartText(void) :
		ChartElement()
{
	// TODO Auto-generated constructor stub
	m_strText = "";
}

/**
 * @FuncName: ~ChartText(void)
 * @Description: Default Destructor Function
 */
ChartText::~ChartText()
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName: setText(const string& strText)
 * @Description: Set Text String
 * @param strText : string : Text String
 */
void ChartText::setText(const string& strText)
{
	m_strText = strText;
}


/**
 * @FuncName: getText(void)
 * @Description: Get Text String
 * @return string
 */
const string& ChartText::getText() const
{
	return m_strText;
}
} /* namespace SuperChart */
