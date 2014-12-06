/**
 * @Title: 			ChartAxis.h
 * @Package 		SuperChart
 * @Description: 	Define Class SuperChart::ChartAxis
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTAXIS_H_
#define CHARTAXIS_H_

#include "../Elements/ChartElement.h"
#include "../Elements/ChartText.h"
#include "../Elements/ChartLine.h"
#include "../Attributes/AxisAttribute.h"
#include "../Styles/ChartStyles.h"
#include "../Common/Global.h"


#include <GeoRect.h>
#include <GeoPoint.h>

#include <list>
#include <sstream>

using namespace std;

namespace SuperChart
{

/**Chart
 * @ClassName: 		SuperChart::ChartAxis
 * @NameSpace: 		SuperChart
 * @Description: 	Class Described Methods and Attributes of ChartAxis
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */
class ChartAxis: public ChartElement
{
public:
	/**
	 * @FuncName: ChartAxis(GeoRect* pBoundRect, string strTitle, int nMaxValue, int nMinValue, int nTickValue)
	 * @Description: Custom Constructor Function
	 * @param nAxisPosition : uint8 : Position Infomation of Axis
	 * @param pBoundRect : GeoRect* : Bound Rectangle of Axis
	 * @param pAttribute : AxisAttribute* : Attributes of Axis
	 * @param pChartStyles : ChartStyles* : Styles of Chart
	 */
	ChartAxis(GeoRect* pBoundRect,
			AxisAttribute* pAttribute,
			ChartStyles* pChartStyles);

	/**
	* @FuncName: ChartAxis(void)
	* @Description: Default Constructor Function
	 */
	ChartAxis(void);

	/**
	 * @FuncName: ~ChartAxis(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~ChartAxis();

public:
	void ResetChartAxis(void);

	/**
	 * @FuncName: ResetAxisLine(GeoRect* pBoundRect, ChartStyle* pLineStyle)
	 * @Description: Create Axis Line
	 * @param pBoundRect : GeoRect* : Bound Rectangle of Axis Area
	 * @param pLineStyle : ChartStyle* : Style of Axis Line
	 */
	void ResetAxisLine(GeoRect* pBoundRect, ChartStyle* pLineStyle);

	/**
	 * @FuncName: ResetAxisTitle(GeoRect* pBoundRect, ChartStyle* pTextStyle, string strTitle)
	 * @Description: Create Axis Title
	 * @param pBoundRect : GeoRect* : Bound Rectangle of Axis Line
	 * @param pTextStyle : ChartStyle* : Style of Axis Title Text
	 */
	void ResetAxisTitle(GeoRect* pBoundRect, ChartStyle* pTextStyle);

	/**
	 * @FuncName: ResetAxisTitle(int nMaxValue, int nMinValue, int nTickValue, ChartStyle* pAxisStyle)
	 * @Description: Create Axis Other Element, Include Grids, Ticks, Labels
	 * @param pChartStyles : ChartStyles* : Chart Style instance
	 */
	void ResetAxisOtherElements(ChartStyles* pChartStyles);

	/**
	 *
	 * @param nAxisPos
	 * @param nStartPosX
	 * @param nStartPosY
	 * @param nOffset
	 * @param pTickStyle
	 */
	void ResetSingleTick(uint8 nAxisPos, int nStartPosX, int nStartPosY, int nOffset, ChartStyle* pTickStyle);

	/**
	 *
	 * @param nAxisPos
	 * @param nStartPosX
	 * @param nStartPosY
	 * @param nOffset
	 * @param pGridStyle
	 */
	void ResetSingleGrid(uint8 nAxisPos, int nStartPosX, int nStartPosY, int nOffset, ChartStyle* pGridStyle);

	/**
	 *
	 * @param nAxisPos
	 * @param nCurrValue
	 * @param nStartPosX
	 * @param nStartPosY
	 * @param nOffset
	 * @param pLabelStyle
	 */
	void ResetSingleLabel(uint8 nAxisPos, int nCurrValue, int nStartPosX, int nStartPosY, int nOffset, ChartStyle* pLabelStyle);


public:
	/**
	 * @field : m_pAxisLine : ChartLine* : Line of Axis
	 */
	ChartLine* m_pAxisLine;

	/**
	 * @field : m_pAxisTitle : ChartText* : Title of Axis
	 */
	ChartText* m_pAxisTitle;

	ChartStyles* m_pChartStyles;

	/**
	 * @field : m_pAxisTicks : list<ChartTick*> :
	 */
	list<ChartLine*> m_pAxisTicks;

	/**
	 * @field : m_pAxisGrid : list<ChartLine*> :
	 */
	list<ChartLine*> m_pAxisGrid;

	/**
	 * @field : m_pAxisLabels : list<ChartText*> :
	 */
	list<ChartText*> m_pAxisLabels;


};

} /* namespace SuperChart */

#endif /* CHARTAXIS_H_ */

