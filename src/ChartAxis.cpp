/**
 * @Title: 			ChartAxis.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartAxis.h"

namespace SuperChart
{

ChartAxis::ChartAxis(GeoRect* pBoundRect, string strTitle, int nMaxValue, int nMinValue, int nTickValue)
{
	// TODO Auto-generated constructor stub
	int nStartPtX = pBoundRect->getTopLeftPoint()->getX();
	int nStartPtY = (pBoundRect->getBottomRightPoint()->getY()
			+ pBoundRect->getTopLeftPoint()->getY())
			/ 2;
	int nEndPtX = pBoundRect->getBottomRightPoint()->getX();
	int nEndPtY = (pBoundRect->getBottomRightPoint()->getY()
			+ pBoundRect->getTopLeftPoint()->getY())
			/ 2;


	/** Create Axis Line */
	m_pAxisLine = new ChartLine();




	m_pAxisTitle = new ChartText();
}

ChartAxis::ChartAxis()
{
	// TODO Auto-generated constructor stub
	m_pAxisLine = new ChartLine();
	m_pAxisTitle = new ChartText();
}

ChartAxis::~ChartAxis()
{
	// TODO Auto-generated destructor stub
}

} /* namespace SuperChart */
