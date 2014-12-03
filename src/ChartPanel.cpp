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

ChartPanel::ChartPanel()
{
	// TODO Auto-generated constructor stub
	m_pTitle = NULL;
	m_pXAxis = NULL;
	m_pYAxis = NULL;
}

ChartPanel::~ChartPanel()
{
	// TODO Auto-generated destructor stub
}

bool ChartPanel::CreateChartPanel(GeoRect* pBoundRect,
		string strTitle,
		string strXAxisTitle,
		string strYAxisTitle,
		int nMinValue,
		int nMaxValue,
		int nTickValue,
		ChartStyles vChartStyles)
{
	/** Declare Variables */
	int nRectWidth = pBoundRect->getSize()->getWidth();
	int nRectHeight = pBoundRect->getSize()->getHeight();
	int nXCorrdinate;
	int nYCorrdinate;
	int nTargetWidth;
	int nTargetHeight;

	/** Create Title Bound Rectangle */
	nXCorrdinate = nRectWidth / 2 - 80;
	nYCorrdinate = 0;
	nTargetWidth = 160;
	nTargetHeight = 120;
	GeoRect* pTitleRect = new GeoRect(new GeoPoint(nXCorrdinate, nYCorrdinate), new GeoSize(nTargetWidth, nTargetHeight));
	m_pTitle = new ChartText(pTitleRect, strTitle, vChartStyles.Chart_Text_Style);

	/** Create X Axis Bound Rectangle */
	nXCorrdinate = 40;
	nYCorrdinate = nRectHeight - 40;
	nTargetWidth = nRectWidth - 40;
	nTargetHeight = 40;
	GeoRect* pXAxisRect = new GeoRect(new GeoPoint(nXCorrdinate, nYCorrdinate), new GeoSize(nTargetWidth, nTargetHeight));
	m_pXAxis = new ChartAxis();

	/** Create Y Axis Bound Rectangle */
	nXCorrdinate = 0;
	nYCorrdinate = 0;
	nTargetWidth = 40;
	nTargetHeight = nRectHeight - 40;
	GeoRect* pYAxisRect = new GeoRect(new GeoPoint(nXCorrdinate, nYCorrdinate), new GeoSize(nTargetWidth, nTargetHeight));
	m_pYAxis = new ChartAxis();

	/** Create Grids Bound Rectangle */
	nXCorrdinate = 40;
	nYCorrdinate = 0;
	nTargetWidth = nRectWidth - 40;
	nTargetHeight = nRectHeight - 40;
	GeoRect* pGridRect = new GeoRect(new GeoPoint(nXCorrdinate, nYCorrdinate), new GeoSize(nTargetWidth, nTargetHeight));

	/** Create Serials */


	ChartStyles::Chart_Text_Style1 = vChartStyles.Chart_Text_Style1;



	m_pTitle = new ChartText(new GeoRect(), strTitle, vChartStyles.Chart_Text_Style);


	/**  */
	return false;
}












} /* namespace SuperChart */
