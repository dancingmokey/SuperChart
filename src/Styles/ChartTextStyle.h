/**
 * @Title: 			ChartTextStyle.h
 * @Package 		SuperChart
 * @Description: 	Define Class SuperChart::ChartTextStyle
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

#ifndef CHARTTEXTSTYLE_H_
#define CHARTTEXTSTYLE_H_

#include "../Common/Global.h"
#include "ChartStyle.h"

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartTextStyle
 * @NameSpace: 		SuperChart
 * @Description: 	Chart Text Style Class, include color, size, type
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */
class ChartTextStyle : public ChartStyle
{
public:
	/**
	 * @FuncName : ChartTextStyle(bool bIsVisible, uint32 nTextColor, uint32 nTextSize, uint32 nTextFont)
	 * @Description: Custom Constructor Function
	 * @param bIsVisible : bool : Is Element Visible or Not
	 * @param nTextColor : uint32 : Color Defined in Global::Color
	 * @param nTextSize : uint32 : Element Size
	 * @param nTextFont : uint8 : Font of Text
	 */
	ChartTextStyle(bool bIsVisible, uint32 nTextColor, uint32 nTextSize, uint32 nTextFont);

	/**
	 * @FuncName : ~ChartTextStyle(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~ChartTextStyle();
};

} /* namespace SuperChart */

#endif /* CHARTTEXTSTYLE_H_ */
