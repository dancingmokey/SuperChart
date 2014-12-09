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
	ChartPanel(GeoRect* pBoundRect,
			ScaleAttribute* pXAxisAttrs,
			ScaleAttribute* pYAxisAttrs,
			ChartStyles* pChartStyles);
	virtual ~ChartPanel(void);

private:
	/**
	 *
	 * @param pBoundRect
	 * @param strTitle
	 * @param pTitleStyle
	 * @return
	 */
	ChartText* CreateTitle(GeoRect* pBoundRect,
			string strTitle, ChartStyle* pTitleStyle);
	/**
	 *
	 * @param pBoundRect
	 * @param nAxisPosition
	 * @param strAxisTitle
	 * @param nMaxValue
	 * @param nMinValue
	 * @param nTickValue
	 * @param pAxisStyle
	 */
	ChartAxis*  CreateAxis(GeoRect* pBoundRect,
			uint8 nAxisPosition,
			string strAxisTitle,
			int nMaxValue,
			int nMinValue,
			int nTickValue,
			ChartStyle* pAxisStyle);
	//
//	bool CreateSerials(GeoRect* pBoundRect, ChartStyles vChartStyles);

public:
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
