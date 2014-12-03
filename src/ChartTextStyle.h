/**
 * @Title: 			ChartTextStyle.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTTEXTSTYLE_H_
#define CHARTTEXTSTYLE_H_

#include "Global.h"

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartTextStyle
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

class ChartTextStyle
{
public:
	ChartTextStyle(uint32 nFont, uint32 nColor, uint32 nSize);
	ChartTextStyle(ChartTextStyle& vChartTextStyle);
	ChartTextStyle();
	virtual ~ChartTextStyle();
public:
	void setTextStyle(uint32 nFont, uint32 nColor, uint32 nSize);
	uint32 getTextColor() const;
	void setTextColor(uint32 nColor);
	uint32 getTextFont() const;
	void setTextFont(uint32 nFont);
	uint32 getTextSize() const;
	void setTextSize(uint32 nSize);
private:
	/**
	 * @Field : m_nFont :Test Font
	 */
	uint32 m_nTextFont;
	/**
	 * @Field : m_nSize : Test Size
	 */
	uint32 m_nTextSize;
	/**
	 * @Field : m_nColor : Test Color
	 */
	uint32 m_nTextColor;
};

} /* namespace SuperChart */

#endif /* CHARTTEXTSTYLE_H_ */
