/**
 * @Title: 			ChartStyles.h
 * @Package 		SuperChart
 * @Description: 	Define Class SuperChart::ChartStyles
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTSTYLES_H_
#define CHARTSTYLES_H_

#include "ChartTextStyle.h"
#include "ChartLineStyle.h"

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartStyles
 * @NameSpace: 		SuperChart
 * @Description: 	Describe Attributes in Class SuperChart::ChartStyles
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */
class ChartStyles
{
public:
	ChartStyles(ChartStyles& vChartStyles);
	ChartStyles();
	virtual ~ChartStyles();

public:
	 static ChartTextStyle Chart_Text_Style1;
	 ChartTextStyle Chart_Text_Style;
	 ChartLineStyle Axis_Line_Style;
	 ChartTextStyle Axis_Text_Style;
	 ChartLineStyle Grid_Line_Style;
	 ChartLineStyle Tick_Line_Style;
	 ChartTextStyle Tick_Text_Style;
	 ChartLineStyle Serial_Line_Style;
	 ChartLineStyle Serial_Text_Style;
};

} /* namespace SuperChart */

#endif /* CHARTSTYLES_H_ */
