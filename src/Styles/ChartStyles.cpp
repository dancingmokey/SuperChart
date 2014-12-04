/**
 * @Title: 			ChartStyles.cpp
 * @Package 		SuperChart
 * @Description: 	Implement Class SuperChart::ChartStyles
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartStyles.h"

namespace SuperChart
{
ChartTextStyle ChartStyles::Chart_Text_Style1 = ChartTextStyle();

ChartStyles::ChartStyles()
{
	// TODO Auto-generated constructor stub
	Chart_Text_Style1 = ChartTextStyle();
//	Axis_Line_Style = ChartLineStyle();
//	Axis_Text_Style = ChartTextStyle();
//	Grid_Line_Style = ChartLineStyle();
//	Tick_Line_Style = ChartLineStyle();
//	Tick_Text_Style = ChartTextStyle();
//	Serial_Line_Style = ChartLineStyle();
//	Serial_Text_Style = ChartLineStyle();
}

ChartStyles::ChartStyles(ChartStyles& vChartStyles)
{
	// TODO Auto-generated constructor stub
//	Axis_Line_Style = vChartStyles.Axis_Line_Style;
//	Axis_Text_Style = vChartStyles.Axis_Text_Style;
//	Grid_Line_Style = vChartStyles.Grid_Line_Style;
//	Tick_Line_Style = vChartStyles.Tick_Line_Style;
//	Tick_Text_Style = vChartStyles.Tick_Text_Style;
//	Serial_Line_Style = vChartStyles.Serial_Line_Style;
//	Serial_Text_Style = vChartStyles.Serial_Text_Style;
}

ChartStyles::~ChartStyles()
{
	// TODO Auto-generated destructor stub
}

} /* namespace SuperChart */
