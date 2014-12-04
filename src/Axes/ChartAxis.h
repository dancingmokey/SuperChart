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

#include "ChartScale.h"

#include <GeoRect.h>
#include <GeoPoint.h>

#include <list>
#include <sstream>

using namespace std;

namespace SuperChart
{

/**Chart
 * @ClassName: 		SuperChart::ChartAxis
 * @NameSpace: 		SuperCha	rt
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
	 * @param strTitle : string : Title of Axis
	 * @param pAxisStyle : ChartStyle* : Style of Axis
	 * @param bIsVisible : bool : Is Axis Visible or Not
	 * @param nMaxValue : int : Max Value of Axis
	 * @param nMinValue : int : Min Value of Axis
	 * @param nTickValue : int : Enery Single Value of Axis Tick
	 */
	ChartAxis(uint8 nAxisPosition,
			GeoRect* pBoundRect,
			string strTitle,
			ChartStyle* pAxisStyle,
			int nMaxValue,
			int nMinValue,
			int nTickValue);

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
	 * @FuncName: CreateAxisTitle(GeoRect* pBoundRect, ChartStyle* pTextStyle, string strTitle)
	 * @Description: Create Axis Title
	 * @param pBoundRect : GeoRect* : Bound Rectangle of Axis Line
	 * @param pTextStyle : ChartStyle* : Style of Axis Title Text
	 * @param strTitle : string : Title of Axis
	 */
	void CreateAxisTitle(GeoRect* pBoundRect, ChartStyle* pTextStyle, string strTitle);

	/**
	 * @FuncName: CreateAxisLine(GeoRect* pBoundRect, ChartStyle* pLineStyle)
	 * @Description: Create Axis Line
	 * @param pBoundRect : GeoRect* : Bound Rectangle of Axis Area
	 * @param pLineStyle : ChartStyle* : Style of Axis Line
	 */
	void CreateAxisLine(GeoRect* pBoundRect, ChartStyle* pLineStyle);

	/**
	 * @FuncName: CreateAxisScale(int nMaxValue, int nMinValue)
	 * @Description: Create Axis Scale
	 * @param nMaxValue : int : Maximum Value of Axis
	 * @param nMinValue : int : Minimum Value of Axis
	 */
	void CreateAxisScale(int nMaxValue, int nMinValue);

	/**
	 * @FuncName: CreateAxisOthers(int nMaxValue, int nMinValue, int nTickValue, ChartStyle* pAxisStyle)
	 * @Description: Create Axis Other Element, Include Grids, Ticks, Labels
	 * @param nMaxValue : int : Maximum value of Axis
	 * @param nMinValue : int : Minimum value of Axis
	 * @param nTickValue : int : Every single tick value of Axis
	 * @param pAxisStyle : ChartStyle* : Chart Style instance
	 */
	void CreateAxisOthers(int nMaxValue, int nMinValue, int nTickValue, ChartStyle* pAxisStyle);

public:
	/**
	 * @FuncName: getAxisPosition(void)
	 * @Description: Get Axis Position Information
	 * @return uint8
	 */
	uint8 getAxisPosition(void) const;

	/**
	 * @FuncName: setAxisPosition(uint8 nAxisPosition)
	 * @Description: Set Axis Position Information
	 * @param nAxisPosition : uint8 : Axis Position Information
	 */
	void setAxisPosition(uint8 nAxisPosition);

private:
	/**
	 * @field : m_nAxisPosition : uint8 : Axis Position Information
	 */
	uint8 m_nAxisPosition;

	/**
	 * @field : m_pAxisLine : ChartLine* : Line of Axis
	 */
	int m_nAxisLength;

	/**
	 * @field : m_pAxisLine : ChartLine* : Line of Axis
	 */
	ChartLine* m_pAxisLine;

	/**
	 * @field : m_pAxisScale : ChartScale* : Scale of Axis
	 */
	ChartScale* m_pAxisScale;

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



//	void CreateAxisTicks();
//    void CreateAxisLeftTick(int nStartPosX, int nStartPosY, int nTickLength, ChartStyle* pTickStyle);
//    void CreateAxisRightTick(int nStartPosX, int nStartPosY, int nTickLength, ChartStyle* pTickStyle);
//    void CreateAxisTopTick(int nStartPosX, int nStartPosY, int nTickLength, ChartStyle* pTickStyle);
//    void CreateAxisBottomTick(int nStartPosX, int nStartPosY, int nTickLength, ChartStyle* pTickStyle);
//
//
//    void CreateAxisLeftGrid();
//    void CreateAxisRightGrid();
//    void CreateAxisTopGrid();
//    void CreateAxisBottomGrid();
//    void CreateAxisLeftLabel();
//    void CreateAxisRightLabel();
//    void CreateAxisTopLabel();
//    void CreateAxisBottomLabel();






