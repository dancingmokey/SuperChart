/**
 * @Title: 			ChartLineStyle.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTLINESTYLE_H_
#define CHARTLINESTYLE_H_

#include "../Common/Global.h"

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartLineStyle
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

class ChartLineStyle
{
public:
	ChartLineStyle(uint32 nLineColor, uint32 nLineWidth, uint8 nLineType);
	ChartLineStyle();
	virtual ~ChartLineStyle();
public:
	void setChartLineStyle(uint32 nLineColor, uint32 nLineWidth, uint8 nLineType);
	uint32 getLineColor() const;
	void setLineColor(uint32 nLineColor);
	uint8 getLineType() const;
	void setLineType(uint8 nLineType);
	uint32 getLineWidth() const;
	void setLineWidth(uint32 nLineWidth);

private:
	uint32 m_nLineColor;
	uint32 m_nLineWidth;
	uint8 m_nLineType;
};

} /* namespace SuperChart */

#endif /* CHARTLINESTYLE_H_ */
