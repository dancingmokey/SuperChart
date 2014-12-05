/**
 * @Title: 			ChartPanel.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartPanel.h"

namespace SuperChart
{
/**
 *
 * @param pBoundRect
 * @param strTitle
 * @param pTitleStyle
 * @param nXAxisPosition
 * @param strXAxisTitle
 * @param nXAxisMaxVal
 * @param nXAxisMinVal
 * @param nXAxisTickVal
 * @param pXAxisStyles
 * @param nYAxisPosition
 * @param strYAxisTitle
 * @param nYAxisMaxVal
 * @param nYAxisMinVal
 * @param nYAxisTickVal
 * @param pYAxisStyles
 */
ChartPanel::ChartPanel(GeoRect* pBoundRect,
		AxisAttribute* pXAxisAttrs,
		AxisAttribute* pYAxisAttrs,
		ChartStyle* pChartStyle)
{
	m_pTitle = new ChartText(pBoundRect, pChartStyle, "Super Chart");

	m_pXAxis = new ChartAxis(pBoundRect,
			pXAxisAttrs,
			pChartStyle);
	m_pYAxis = new ChartAxis(pBoundRect,
			pYAxisAttrs,
			pChartStyle);

}

ChartPanel::~ChartPanel()
{
	// TODO Auto-generated destructor stub
}

/**
 *
 * @param pBoundRect
 * @param nAxisPosition
 * @param strAxisTitle
 * @param nMaxValue
 * @param nMinValue
 * @param nTickValue
 * @param pAxisStyle
 * @return
 */
ChartAxis*  CreateAxis(GeoRect* pBoundRect,
		uint8 nAxisPosition,
		string strAxisTitle,
		int nMaxValue,
		int nMinValue,
		int nTickValue,
		ChartStyle* pAxisStyle)
{


//	return new ChartAxis(nAxisPosition,
//			pBoundRect,
//			strAxisTitle,
//			pAxisStyle,
//			nMaxValue,
//			nMinValue,
//			nTickValue);
	return NULL;
}









} /* namespace SuperChart */
