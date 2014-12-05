/**
 * @Title: 			ChartTextStyle.cpp
 * @Package 		SuperChart
 * @Description: 	Implement Class SuperChart::ChartTextStyle
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

#include "ChartTextStyle.h"

namespace SuperChart
{

/**
 * @FuncName : ChartTextStyle(bool bIsVisible, uint32 nTextColor, uint32 nTextSize, uint32 nTextFont)
 * @Description: Custom Constructor Function
 * @param bIsVisible : bool : Is Element Visible or Not
 * @param nTextColor : uint32 : Color Defined in Global::Color
 * @param nTextSize : uint32 : Element Size
 * @param nTextFont : uint8 : Font of Text
 */
ChartTextStyle::ChartTextStyle(bool bIsVisible,
		uint32 nTextColor,
		uint32 nTextSize,
		uint32 nTextFont) :
		ChartStyle(bIsVisible,
				nTextColor,
				nTextSize,
				nTextFont)
{
	// TODO Auto-generated constructor stub
}

/**
 * @FuncName : ~ChartTextStyle(void)
 * @Description: Default Destructor Function
 */
ChartTextStyle::~ChartTextStyle()
{
	// TODO Auto-generated destructor stub
}
} /* namespace SuperChart */
