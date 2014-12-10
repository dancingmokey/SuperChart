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

/**
 * @FuncName: ChartAxis(GeoRect* pBoundRect, string strTitle, int nMaxValue, int nMinValue, int nTickValue)
 * @Description: Custom Constructor Function
 * @param nAxisPosition : uint8 : Position Infomation of Axis
 * @param pBoundRect : GeoRect* : Bound Rectangle of Axis
 * @param pAttribute : AxisAttribute* : Attributes of Axis
 * @param pAxisStyle : ChartStyle* : Style of Axis
 */
ChartAxis::ChartAxis(GeoRect* pBoundRect,
		AxisAttribute* pAttribute,
		ChartStyle* pStyle) :
		ChartElement(pBoundRect, dynamic_cast<Attribute*>(pAttribute), pStyle),
		m_pAxisLine(new ChartLine()),
		m_pAxisTitle(new ChartText())
{
	/** Initialize Private Class Members */
	this->setBoundRect(pBoundRect);
	this->setAttribute(dynamic_cast<Attribute*>(pAttribute));
	this->setStyle(pStyle);

	/** Create Axis Line, Title, Other Elements */
	this->UpdateChartAxis();
}

/**
* @FuncName: ChartAxis(void)
* @Description: Default Constructor Function
*/
ChartAxis::ChartAxis(void) :
		m_pAxisLine(new ChartLine()),
		m_pAxisTitle(new ChartText())
{
	// TODO Auto-generated constructor stub
}

/**
 * @FuncName: ~ChartAxis(void)
 * @Description: Default Destructor Function
 */
ChartAxis::~ChartAxis(void)
{
	// TODO Auto-generated destructor stub
	Global::Safe_Delete(m_pAxisLine);
	Global::Safe_Delete(m_pAxisTitle);
}

/**
 * @FuncName: UpdateChartAxis(void)
 * @Description: Update Chart Axis
 */
void ChartAxis::UpdateChartAxis(void)
{
	/** Create Axis Line */
	this->UpdateAxisLine();

	/** Create Axis Title */
	this->UpdateAxisTitle();

	/** Create Axis Other Elements */
	this->UpdateAxisOtherElements();
}

/**
 * @FuncName: UpdateAxisLine(void)
 * @Description: Update Axis Line
 */
void ChartAxis::UpdateAxisLine(void)
{
	/** Convert Attribute to AxisAttr Type */
	AxisAttribute* pAttribute = dynamic_cast<AxisAttribute*>(getAttribute());
	GeoRect* pBoundRect = this->getBoundRect();

	/** Declare Variables */
	int nTickLength = 20;

	/** Get Bound Rectangle Parameters */
	int nTLPointX = pBoundRect->getTopLeftPoint()->getX();
	int nTLPointY = pBoundRect->getTopLeftPoint()->getY();
	int nRBPointX = pBoundRect->getBottomRightPoint()->getX();
	int nRBPointY = pBoundRect->getBottomRightPoint()->getY();

	/** Calculate Axis Length & GeoLine base on Axis Position  */
	switch (pAttribute->getAxisPosition())
	{
	case Global::Axis_Top:
	{
		m_pAxisLine->setStartPoint(nTLPointX, nTLPointY + nTickLength);
		m_pAxisLine->setEndPoint(nRBPointX, nTLPointY + nTickLength);
		break;
	}
	case Global::Axis_Bottom:
	{
		m_pAxisLine->setStartPoint(nTLPointX, nRBPointY - nTickLength);
		m_pAxisLine->setEndPoint(nRBPointX, nRBPointY - nTickLength);
		break;
	}
	case Global::Axis_Left:
	{
		m_pAxisLine->setStartPoint(nTLPointX + nTickLength, nRBPointY);
		m_pAxisLine->setEndPoint(nTLPointX + nTickLength, nTLPointY);
		break;
	}
	case Global::Axis_Right:
	{
		m_pAxisLine->setStartPoint(nRBPointX - nTickLength, nRBPointY);
		m_pAxisLine->setEndPoint(nRBPointX - nTickLength, nTLPointY);
		break;
	}
	default:
	{
		m_pAxisLine->setStartPoint(0, 0);
		m_pAxisLine->setEndPoint(0, 0);
		break;
	}
	}

	/** Initialize Axis Line */
	m_pAxisLine->setStyle(new ChartStyle(Global::Style_File, "AxisLine"));

	/** Update Attributes */
	double dAxisLength = m_pAxisLine->getLength();
	ScaleAttribute::Instance()->setAxisLength(dAxisLength);
}

/**
 * @FuncName: UpdateAxisTitle(void)
 * @Description: Update Axis Title
 */
void ChartAxis::UpdateAxisTitle(void)
{
	/** Convert Attribute to AxisAttr Type */
	AxisAttribute* pAttribute = dynamic_cast<AxisAttribute*>(getAttribute());
	GeoRect* pBoundRect = this->getBoundRect();

	/** Declare Variables */
	GeoRect* pTitleRect = NULL;
	int nTitleWidh = 400;
	int nTitleHeight = 100;

	/** Get Bound Rectangle Parameters */
	int nTLPointX = pBoundRect->getTopLeftPoint()->getX();
	int nTLPointY = pBoundRect->getTopLeftPoint()->getY();
	int nRBPointX = pBoundRect->getBottomRightPoint()->getX();
	int nRBPointY = pBoundRect->getBottomRightPoint()->getY();

	/** Calculate Title Position */
	switch (pAttribute->getAxisPosition())
	{
	case Global::Axis_Top:
	{
		pTitleRect = new GeoRect((nTLPointX + nRBPointX - nTitleWidh) / 2,
				nTLPointY - nTitleHeight,
				nTitleWidh,
				nTitleHeight);
		break;
	}
	case Global::Axis_Bottom:
	{
		pTitleRect = new GeoRect((nTLPointX + nRBPointX - nTitleWidh) / 2,
				nRBPointY,
				nTitleWidh,
				nTitleHeight);
		break;
	}
	case Global::Axis_Left:
	{
		pTitleRect = new GeoRect(nTLPointX - nTitleHeight,
				(nTLPointY + nRBPointY - nTitleWidh) / 2,
				nTitleHeight,
				nTitleWidh);
		break;
	}
	case Global::Axis_Right:
	{
		pTitleRect = new GeoRect(nTLPointX + nTitleHeight,
				(nTLPointY + nRBPointY - nTitleWidh) / 2,
				nTitleHeight,
				nTitleWidh);
		break;
	}
	default:
	{
		pTitleRect = new GeoRect();
		break;
	}
	}

	/** Initialize Axis Title */
	m_pAxisTitle->setBoundRect(pBoundRect);
	m_pAxisTitle->setStyle(new ChartStyle(Global::Style_File, "AxisTitle"));
	m_pAxisTitle->setText(pAttribute->getTitle());
}

/**
 * @FuncName: UpdateAxisOtherElements(void)
 * @Description: Update Axis Other Element, Include Grids, Ticks, Labels
 */
void ChartAxis::UpdateAxisOtherElements(void)
{
	/** Clear All List  */
	m_pAxisLabels.clear();
	m_pAxisTicks.clear();
	m_pAxisGrid.clear();

	/** Convert Attribute to AxisAttr Type */
	AxisAttribute* pAttribute = dynamic_cast<AxisAttribute*>(getAttribute());
	GeoRect* pBoundRect = this->getBoundRect();

	/** Declare Geometry Variables */
	int nStartPosX = m_pAxisLine->getStartPoint()->getX();
	int nStartPosY = m_pAxisLine->getStartPoint()->getY();

	/** Declare Geometry Variables */
	list<double> ltTickVals = pAttribute->getTickValues();

	/**   */
	for (list<double>::iterator it = ltTickVals.begin();
			it != ltTickVals.end();
			++it)
	{
		/** Calculate Parameters */
		double nValue = *it;
		double dOffsite = ScaleAttribute::Instance()->GetPositionByValue(nValue);

		/** Create Single Tick */
		UpdateSingleTick(pAttribute->getAxisPosition(),
				nStartPosX,
				nStartPosY,
				dOffsite,
				new ChartStyle(Global::Style_File, "AxisTick"));

		/** Create Single Grid */
		UpdateSingleGrid(pAttribute->getAxisPosition(),
				nStartPosX,
				nStartPosY,
				dOffsite,
				new ChartStyle(Global::Style_File, "AxisGrid"));

		/** Create Single Label */
		UpdateSingleLabel(pAttribute->getAxisPosition(),
				nValue,
				nStartPosX,
				nStartPosY,
				dOffsite,
				new ChartStyle(Global::Style_File, "AxisLabel"));
	}
}

/**
 * @FuncName: UpdateSingleTick(uint8 nAxisPos, int nStartPosX, int nStartPosY, double dOffset, ChartStyle* pTickStyle)
 * @Description: Update Single Tick in Axis
 * @param nAxisPos : uint8 : Axis Position
 * @param nStartPosX : int : X Coordinate of Axis Start Position
 * @param nStartPosY : int : Y Coordinate of Axis Start Position
 * @param dOffset : double : Offset of Y Axis from Axis Start Position
 * @param pTickStyle : ChartStyle* : Tick Style
 */
void ChartAxis::UpdateSingleTick(uint8 nAxisPos, int nStartPosX, int nStartPosY, double dOffset, ChartStyle* pTickStyle)
{
	/** Declare Variables */
	int nTickLength = 20;
	GeoLine* pTickLine = NULL;

	/** Calculate Tick Line & Grid Line & Label Rectangle */
	switch (nAxisPos)
	{
	case Global::Axis_Top:
	{
		/** Create a Single Tick Line */
		pTickLine = new GeoLine(nStartPosX + dOffset,
				nStartPosY,
				nStartPosX + dOffset,
				nStartPosY - nTickLength);
		break;
	}
	case Global::Axis_Bottom:
	{
		/** Create a Single Tick Line */
		pTickLine = new GeoLine(nStartPosX + dOffset,
				nStartPosY,
				nStartPosX + dOffset,
				nStartPosY + nTickLength);
		break;
	}
	case Global::Axis_Left:
	{
		/** Create a Single Tick Line */
		pTickLine = new GeoLine(nStartPosX,
				nStartPosY - dOffset,
				nStartPosX - nTickLength,
				nStartPosY - dOffset);
		break;
	}
	case Global::Axis_Right:
	{
		/** Create a Single Tick Line */
		pTickLine = new GeoLine(nStartPosX,
				nStartPosY - dOffset,
				nStartPosX + nTickLength,
				nStartPosY - dOffset);
		break;
	}
	default:
	{
		/** Create a Single Tick Line */
		pTickLine = new GeoLine();
		break;
	}
	}

	/** Storage New Tick */
	m_pAxisTicks.push_back(new ChartLine(pTickLine, pTickStyle));
}

/**
 * @FuncName: UpdateSingleGrid(uint8 nAxisPos, int nStartPosX, int nStartPosY, double dOffset, ChartStyle* pTickStyle)
 * @Description: Update Single Grid in Axis
 * @param nAxisPos : uint8 : Axis Position
 * @param nStartPosX : int : X Coordinate of Axis Start Position
 * @param nStartPosY : int : Y Coordinate of Axis Start Position
 * @param dOffset : int : Offset of Y Axis from Axis Start Position
 * @param pGridStyle : ChartStyle* : Grid Style
 */
void ChartAxis::UpdateSingleGrid(uint8 nAxisPos, int nStartPosX, int nStartPosY, double dOffset, ChartStyle* pGridStyle)
{
	/** Declare Variables */
	GeoLine* pGridLine = NULL;

	/** Declare Geometry Variables */
	int nTop = this->getBoundRect()->getTopLeftPoint()->getY();
	int nBottom = this->getBoundRect()->getBottomRightPoint()->getY();
	int nLeft = this->getBoundRect()->getTopLeftPoint()->getX();
	int nRight = this->getBoundRect()->getBottomRightPoint()->getX();

	/** Calculate Grid Line */
	switch (nAxisPos)
	{
	case Global::Axis_Top:
	{
		/** Create a Single Grid Line */
		pGridLine = new GeoLine(nStartPosX + dOffset,
				nStartPosY,
				nStartPosX + dOffset,
				nBottom);
		break;
	}
	case Global::Axis_Bottom:
	{
		/** Create a Single Grid Line */
		pGridLine = new GeoLine(nStartPosX + dOffset,
				nStartPosY,
				nStartPosX + dOffset,
				nTop);
		break;
	}
	case Global::Axis_Left:
	{
		/** Create a Single Grid Line */
		pGridLine = new GeoLine(nStartPosX,
				nStartPosY - dOffset,
				nRight,
				nStartPosY - dOffset);
		break;
	}
	case Global::Axis_Right:
	{
		/** Create a Single Grid Line */
		pGridLine = new GeoLine(nStartPosX,
				nStartPosY - dOffset,
				nLeft,
				nStartPosY - dOffset);
		break;
	}
	default:
	{
		/** Create a Single Grid Line */
		pGridLine = new GeoLine();
		break;
	}
	}


	/** Storage New Tick */
	m_pAxisGrid.push_back(new ChartLine(pGridLine, pGridStyle));
}

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
void ChartAxis::UpdateSingleLabel(uint8 nAxisPos, int nCurrValue, int nStartPosX, int nStartPosY, double dOffset, ChartStyle* pLabelStyle)
{
	/** Declare Variables */
	int nRectWidth = 60;
	int nRectHeight = 30;
	int nTickLength = 20;
	GeoRect* pLabelRect = NULL;

	/** Calculate Label Rectangle */
	switch (nAxisPos)
	{
	case Global::Axis_Top:
	{
		/** Create a Single Label Rectangle */
		pLabelRect = new GeoRect(nStartPosX + dOffset - nRectWidth / 2,
				nStartPosY - nRectHeight - nTickLength,
				nRectWidth,
				nRectHeight);
		break;
	}
	case Global::Axis_Bottom:
	{
		/** Create a Single Label Rectangle */
		pLabelRect = new GeoRect(nStartPosX + dOffset - nRectWidth / 2,
				nStartPosY + nTickLength,
				nRectWidth,
				nRectHeight);
		break;
	}
	case Global::Axis_Left:
	{
		/** Create a Single Label Rectangle */
		pLabelRect = new GeoRect(nStartPosX - nRectWidth - nTickLength,
				nStartPosY - dOffset - nRectHeight / 2,
				nRectWidth,
				nRectHeight);
		break;
	}
	case Global::Axis_Right:
	{
		/** Create a Single Label Rectangle */
		pLabelRect = new GeoRect(nStartPosX + nTickLength,
				nStartPosY - dOffset - nRectHeight / 2,
				nRectWidth,
				nRectHeight);
		break;
	}
	default:
	{
		/** Create a Single Label Rectangle */
		pLabelRect = new GeoRect();
		break;
	}
	}

	/** */
	stringstream strStream;
	strStream << nCurrValue;
	string strTickLabel = strStream.str();
	strStream.clear();

	/** Storage New Tick */
	m_pAxisLabels.push_back(new ChartText(pLabelRect, pLabelStyle, strTickLabel));
}


} /* namespace SuperChart */
