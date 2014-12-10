/**
 * @Title: 			ChartCurve.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/10
 * @Version:		V1.0.0	
 */
#ifndef CURVES_CHARTCURVE_H_
#define CURVES_CHARTCURVE_H_

#include "../Elements/ChartElement.h"
#include "../Attributes/Attribute.h"
#include "../Attributes/CurveAttribute.h"
#include "../Attributes/ScaleAttribute.h"

#include <GeoRect.h>
#include <GeoLine.h>
#include <list>

using namespace std;
using namespace Geometry;

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartCurve
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/10
 * @Version:		V1.0.0	
 */
class ChartCurve: public ChartElement
{
public:
	/**
	 * @FuncName: ChartCurve(GeoRect* pBoundRect, AxisAttribute* pAttribute, ChartStyle* pStyle)
	 * @Description: Custom Constructor Function
	 * @param pBoundRect : GeoRect* : Bound Rectangle of Curve
	 * @param pAttribute : AxisAttribute* : Attributes of Curve
	 * @param pChartStyle : ChartStyle* : Styles of Curve
	 */
	ChartCurve(GeoRect* pBoundRect,
			CurveAttribute* pAttribute,
			ChartStyle* pStyle);

	/**
	 * @FuncName: ChartCurve(void)
	 * @Description: Default Constructor Function
	 */
	ChartCurve(void);

	/**
	 * @FuncName: ~ChartCurve(void)
	 * @Description: Default Constructor Function
	 */
	virtual ~ChartCurve(void);


public:
	/**
	 * @FuncName : AddData(double dXValue, double dYValue)
	 * @Description: Add Data into Value List
	 * @param dXValue : double : Horizontal Value
	 * @param dYValue : double : Vertical Value
	 */
	void AddData(double dXValue, double dYValue);

	/**
	 * @FuncName : AddData(double* pXValueList, double* pYValueList, int nCount)
	 * @Description: Add Data into Value List
	 * @param pXValueList : double* : Horizontal Value Array
	 * @param pYValueList : double* : Vertical Value Array
	 * @param nCount : int :  Count of Elements in Value Array
	 */
	void AddData(double* pXValueList, double* pYValueList, int nCount);

	/**
	 * @FuncName : ClearData(void)
	 * @Description: Clear Data into Value List
	 */
	void ClearData(void);

	/**
	 * @FuncName : UpdateCurveLines(void)
	 * @Description: Update Curve Lines
	 * @return list<GeoLine*>
	 */
	list<GeoLine*> UpdateCurveLines(void);

private:
	/**
	 * @Filed : m_ltCurveLines : list<GeoLine*> : Lines of Curve
	 */
	list<GeoLine*> m_ltCurveLines;
};

} /* namespace SuperChart */

#endif /* CURVES_CHARTCURVE_H_ */
