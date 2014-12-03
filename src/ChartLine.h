/**
 * @Title: 			ChartLine.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTLINE_H_
#define CHARTLINE_H_

#include "ChartElement.h"
#include "ChartLineStyle.h"
#include "Global.h"

#include <GeoLine.h>

using namespace Geometry;

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartLine
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

class ChartLine: public Geometry::GeoLine, public ChartElement
{
public:
	ChartLine(ChartLineStyle vLineStyle);
	ChartLine();
	virtual ~ChartLine();
public:
	const ChartLineStyle& getLineStyle() const;
	void setLineStyle(const ChartLineStyle& vLineStyle);

private:
	ChartLineStyle m_vLineStyle;
};

} /* namespace SuperChart */

#endif /* CHARTLINE_H_ */
