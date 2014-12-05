/**
 * @Title: 			ChartLine.cpp
 * @Package 		SuperChart
 * @Description: 	Implement Class SuperChart::ChartLine
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartLine.h"

namespace SuperChart
{

/**
 * @FuncName: ChartLine(GeoRect* pBoundRect, ChartStyle* pStyle)
 * @Description: Custom Constructor Function
 * @param pBoundRect : GeoRect* : Bound Rectangle of Chart Line
 * @param pStyle : ChartStyle* : Style of Chart Line
 */
ChartLine::ChartLine(GeoLine* pLine, ChartStyle* pStyle) :
		GeoLine(*pLine),
		ChartElement(NULL, NULL, pStyle)
{
	// TODO Auto-generated constructor stub
}

/**
 * @FuncName: ChartLine(void)
 * @Description: Default Constructor Function
 */
ChartLine::ChartLine(void) :
		GeoLine(),
		ChartElement()
{
	// TODO Auto-generated constructor stub
}

/**
 * @FuncName: ~ChartElement(void)
 * @Description: Default Destructor Function
 */
ChartLine::~ChartLine(void)
{
	// TODO Auto-generated destructor stub
}

} /* namespace SuperChart */
