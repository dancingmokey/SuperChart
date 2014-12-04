/**
 * @Title: 			ChartPanel.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTPANEL_H_
#define CHARTPANEL_H_

#include "../Elements/ChartText.h"
#include "../Axes/ChartAxis.h"
#include "../Styles/ChartStyles.h"

#include <GeoRect.h>


namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartPanel
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

class ChartPanel
{
public:
	ChartPanel(GeoRect* pBoundRect, string strTitle, string strXAxisTitle, string strYAxisTitle, int nMinValue, int nMaxValue, int nTickValue, ChartStyles vChartStyles);
	ChartPanel();
	virtual ~ChartPanel();


public:
	//
	bool CreateChartPanel(GeoRect* pBoundRect, string strTitle, string strXAxisTitle, string strYAxisTitle, int nMinValue, int nMaxValue, int nTickValue, ChartStyles vChartStyles);

private:
	//
	bool CreateTitle(GeoRect* pBoundRect, string strTitle, ChartStyles vChartStyles);
	//
	bool CreateAxes(GeoRect* pBoundRect, string strXAxisTitle, string strYAxisTitle, int nMinValue, int nMaxValue, int nTickValue, ChartStyles vChartStyles);
	//
	bool CreateGrids(GeoRect* pBoundRect, ChartStyles vChartStyles);
	//
	bool CreateSerials(GeoRect* pBoundRect, ChartStyles vChartStyles);

private:
	/**
	 * @field : m_pTitle :
	 */
	ChartText* m_pTitle;
	/**
	 * @field : m_pTitle :
	 */
	ChartAxis* m_pXAxis;
	/**
	 * @field : m_pTitle :
	 */
	ChartAxis* m_pYAxis;
};

} /* namespace SuperChart */

#endif /* CHARTPANEL_H_ */
