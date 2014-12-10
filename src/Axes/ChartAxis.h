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
#include "../Attributes/ScaleAttribute.h"
#include "../Attributes/AxisAttribute.h"
#include "../Common/Global.h"

#include <GeoRect.h>
#include <GeoPoint.h>

#include <list>
#include <sstream>

using namespace std;
using namespace Geometry;

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
	* @FuncName: ChartAxis(GeoRect* pBoundRect, AxisAttribute* pAttribute, ChartStyle* pStyle)
	* @Description: Custom Constructor Function
	* @param pBoundRect : GeoRect* : Bound Rectangle of Axis
	* @param pAttribute : AxisAttribute* : Attributes of Axis
	* @param pChartStyle : ChartStyles* : Styles of Chart
	*/
	ChartAxis(GeoRect* pBoundRect,
			AxisAttribute* pAttribute,
			ChartStyle* pStyle);

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
	/**
	 * @FuncName: UpdateChartAxis(void)
	 * @Description: Update Chart Axis
	 */
	void UpdateChartAxis(void);

	/**
	 * @FuncName: UpdateAxisLine(void)
	 * @Description: Update Axis Line
	 */
	void UpdateAxisLine(void);

	/**
	 * @FuncName: UpdateAxisTitle(void)
	 * @Description: Update Axis Title
	 */
	void UpdateAxisTitle(void);

	/**
	 * @FuncName: UpdateAxisOtherElements(void)
	 * @Description: Update Axis Other Element, Include Grids, Ticks, Labels
	 */
	void UpdateAxisOtherElements(void);

	/**
	 * @FuncName: UpdateSingleTick(uint8 nAxisPos, int nStartPosX, int nStartPosY, double dOffset, ChartStyle* pTickStyle)
	 * @Description: Update Single Tick in Axis
	 * @param nAxisPos : uint8 : Axis Position
	 * @param nStartPosX : int : X Coordinate of Axis Start Position
	 * @param nStartPosY : int : Y Coordinate of Axis Start Position
	 * @param dOffset : double : Offset of Y Axis from Axis Start Position
	 * @param pTickStyle : ChartStyle* : Tick Style
	 */
	void UpdateSingleTick(uint8 nAxisPos, int nStartPosX, int nStartPosY, double dOffset, ChartStyle* pTickStyle);

	/**
	 * @FuncName: UpdateSingleGrid(uint8 nAxisPos, int nStartPosX, int nStartPosY, double dOffset, ChartStyle* pTickStyle)
	 * @Description: Update Single Grid in Axis
	 * @param nAxisPos : uint8 : Axis Position
	 * @param nStartPosX : int : X Coordinate of Axis Start Position
	 * @param nStartPosY : int : Y Coordinate of Axis Start Position
	 * @param dOffset : int : Offset of Y Axis from Axis Start Position
	 * @param pGridStyle : ChartStyle* : Grid Style
	 */
	void UpdateSingleGrid(uint8 nAxisPos, int nStartPosX, int nStartPosY, double dOffset, ChartStyle* pGridStyle);

	/**
	 * @FuncName: UpdateSingleLabel(uint8 nAxisPos, int nCurrValue, int nStartPosX, int nStartPosY, double dOffset, ChartStyle* pTickStyle)
	 * @Description: Update Single Label in Axis
	 * @param nAxisPos : uint8 : Axis Position
	 * @param nCurrValue : int : Current Value of Label on Axis
	 * @param nStartPosX : int : X Coordinate of Axis Start Position
	 * @param nStartPosY : int : Y Coordinate of Axis Start Position
	 * @param dOffset : int : Offset of Y Axis from Axis Start Position
	 * @param pLabelStyle : ChartStyle* : Label Style
	 */
	void UpdateSingleLabel(uint8 nAxisPos, int nCurrValue, int nStartPosX, int nStartPosY, double dOffset, ChartStyle* pLabelStyle);


public:
	/**
	 * @field : m_pAxisLine : ChartLine* : Line of Axis
	 */
	ChartLine* m_pAxisLine;

	/**
	 * @field : m_pAxisTitle : ChartText* : Title of Axis
	 */
	ChartText* m_pAxisTitle;

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

