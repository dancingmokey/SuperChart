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

/**
 * @FuncName : ChartLineStyle(bool bIsVisible, uint32 nLineColor, uint32 nLineWidth, uint8 nLineType)
 * @Description: Custom Constructor Function
 * @param bIsVisible : bool : Is Element Visible or Not
 * @param nLineColor : uint32 : Color Defined in Global::Color
 * @param nLineWidth : uint32 : Element Size
 * @param nLineType : uint8 : Type of Line or Font of Text
 */
ChartLineStyle::ChartLineStyle(bool bIsVisible,
		uint32 nLineColor,
		uint32 nLineWidth,
		uint8 nLineType) :
		ChartStyle(bIsVisible,
				nLineColor,
				nLineWidth,
				nLineType)
{
	// TODO Auto-generated constructor stub
}

/**
 * @FuncName : ~ChartLineStyle(void)
 * @Description: Default Destructor Function
 */
ChartLineStyle::~ChartLineStyle()
{
	// TODO Auto-generated destructor stub
}

} /* namespace SuperChart */
