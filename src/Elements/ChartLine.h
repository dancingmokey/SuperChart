/**
 * @Title: 			ChartLine.h
 * @Package 		SuperChart
 * @Description: 	Define Class SuperChart::ChartLine
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTLINE_H_
#define CHARTLINE_H_

#include "ChartElement.h"
#include "../Common/Global.h"

#include <GeoLine.h>

using namespace Geometry;

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartLine
 * @NameSpace: 		SuperChart
 * @Description: 	Describe Method and Attributes of Class ChartLine
 * @Parent:			GeoLine & ChartElement
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */
class ChartLine: public Geometry::GeoLine, public ChartElement
{
public:
	/**
	 * @FuncName: ChartLine(GeoLine* pLine, ChartStyle* pStyle)
	 * @Description: Custom Constructor Function
	 * @param pLine : GeoLine* : Chart Line Instance
	 * @param pStyle : ChartStyle* : Style of Chart Line
	 */
	ChartLine(GeoLine* pLine, ChartStyle* pStyle);

	/**
	 * @FuncName: ChartLine(void)
	 * @Description: Default Constructor Function
	 */
	ChartLine(void);

	/**
	 * @FuncName: ~ChartElement(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~ChartLine();
};

} /* namespace SuperChart */

#endif /* CHARTLINE_H_ */
