/**
 * @Title: 			ChartCurve.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/10
 * @Version:		V1.0.0	
 */
#include "ChartCurve.h"

namespace SuperChart
{
/**
 * @FuncName: ChartCurve(GeoRect* pBoundRect, AxisAttribute* pAttribute, ChartStyle* pStyle)
 * @Description: Custom Constructor Function
 * @param pBoundRect : GeoRect* : Bound Rectangle of Curve
 * @param pAttribute : CurveAttribute* : Attributes of Curve
 * @param pChartStyle : ChartStyle* : Styles of Curve
 */
ChartCurve::ChartCurve(GeoRect* pBoundRect,
				CurveAttribute* pAttribute,
				ChartStyle* pStyle) :
				ChartElement(pBoundRect, dynamic_cast<Attribute*>(pAttribute), pStyle)
{
	/** Initialize Private Class Members */
	this->setBoundRect(pBoundRect);
	this->setAttribute(dynamic_cast<Attribute*>(pAttribute));
	this->setStyle(pStyle);
}

/**
* @FuncName: ChartCurve(void)
* @Description: Default Constructor Function
 */
ChartCurve::ChartCurve(void)
{
	// TODO Auto-generated constructor stub

}

/**
* @FuncName: ~ChartCurve(void)
* @Description: Default Constructor Function
 */
ChartCurve::~ChartCurve(void)
{
	// TODO Auto-generated destructor stub
}
/**
 * @FuncName : AddData(double dXValue, double dYValue)
 * @Description: Add Data into Value List
 * @param dXValue : double : Horizontal Value
 * @param dYValue : double : Vertical Value
 */
void ChartCurve::AddData(double dXValue, double dYValue)
{
	CurveAttribute* pCurveAttr = dynamic_cast<CurveAttribute*>(this->getStyle());
	pCurveAttr->AddData(dXValue, dYValue);
}

/**
 * @FuncName : AddData(double* pXValueList, double* pYValueList, int nCount)
 * @Description: Add Datas into Value List
 * @param pXValueList : double* : Horizontal Value Array
 * @param pYValueList : double* : Vertical Value Array
 * @param nCount : int :  Count of Elements in Value Array
 */
void ChartCurve::AddData(double* pXValueList, double* pYValueList, int nCount)
{
	CurveAttribute* pCurveAttr = dynamic_cast<CurveAttribute*>(this->getStyle());
	pCurveAttr->AddData(pXValueList, pYValueList, nCount);
}

/**
 * @FuncName : ClearData()
 * @Description: Clear Data into Value List
 */
void ChartCurve::ClearData(void)
{
	CurveAttribute* pCurveAttr = dynamic_cast<CurveAttribute*>(this->getStyle());
	pCurveAttr->ClearData();
}

/**
 * @FuncName : UpdateCurveLines(void)
 * @Description: Update Curve Lines
 * @return list<GeoLine*>
 */
list<GeoLine*> ChartCurve::UpdateCurveLines(void)
{
	/** Clear Curve Lines */
	for (list<GeoLine*>::iterator itLine = m_ltCurveLines.begin();
			itLine != m_ltCurveLines.end();
			itLine++)
	{
		Global::Safe_Delete(dynamic_cast<void*>(*itLine));
	}
	m_ltCurveLines.clear();

	/** Get Horizontal & Vertical Data Values */
	ScaleAttribute* pInstance = ScaleAttribute::Instance();
	CurveAttribute* pCurveAttr = dynamic_cast<CurveAttribute*>(this->getStyle());
	list<double> ltHorizontalVals = pCurveAttr->getHorizontalVal();
	list<double> ltVerticalVals = pCurveAttr->getVerticalVal();

	/**    */
	list<double>::iterator itHorizontal = ltHorizontalVals.begin();
	list<double>::iterator itVertical = ltVerticalVals.begin();

	/**   */
	while (true)
	{
		double dXValue1 = pInstance->GetPositionByValue(*itHorizontal);
		double dYValue1 = pInstance->GetPositionByValue(*itVertical);
		if (((itHorizontal++) == ltHorizontalVals.end()) ||
			((itVertical++) == ltVerticalVals.end()))
		{
			break;
		}
		else
		{
			double dXValue2 = pInstance->GetPositionByValue(*itHorizontal);
			double dYValue2 = pInstance->GetPositionByValue(*itVertical);

			m_ltCurveLines.push_back(new GeoLine(dXValue1, dYValue1, dXValue2, dYValue2));
		}
	}

	/** */
	return m_ltCurveLines;
}


} /* namespace SuperChart */
