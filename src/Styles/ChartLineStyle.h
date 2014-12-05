/**
 * @Title: 			ChartLineStyle.h
 * @Package 		SuperChart
 * @Description: 	Define Class SuperChart::ChartLineStyle
 * @Author: 		LiuLei
 * @Created on: 	2014/12/05
 * @Version:		V1.0.0	
 */

#ifndef CHARTLINESTYLE_H_
#define CHARTLINESTYLE_H_

#include "../Common/Global.h"
#include "ChartStyle.h"

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartLineStyle
 * @NameSpace: 		SuperChart
 * @Description: 	Chart Line Style Class, include color, size, type
 * @Author: 		LiuLei
 * @Created on: 	2014/12/05
 * @Version:		V1.0.0	
 */
class ChartLineStyle : public ChartStyle
{
public:
	/**
	 * @FuncName : ChartLineStyle(bool bIsVisible, uint32 nLineColor, uint32 nLineWidth, uint8 nLineType)
	 * @Description: Custom Constructor Function
	 * @param bIsVisible : bool : Is Element Visible or Not
	 * @param nLineColor : uint32 : Color Defined in Global::Color
	 * @param nLineWidth : uint32 : Element Size
	 * @param nLineType : uint8 : Type of Line or Font of Text
	 */
	ChartLineStyle(bool bIsVisible, uint32 nLineColor, uint32 nLineWidth, uint8 nLineType);

	/**
	 * @FuncName : ~ChartLineStyle(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~ChartLineStyle(void);
};

} /* namespace SuperChart */

#endif /* CHARTLINESTYLE_H_ */
