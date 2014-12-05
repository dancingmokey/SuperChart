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
		ChartStyle* pAxisStyle) :
		ChartElement(pBoundRect, dynamic_cast<Attribute*>(pAttribute), pAxisStyle),
		m_pAxisLine(NULL),
		m_pAxisTitle(NULL)
{
	/** Initialize Private Class Members */
	this->setBoundRect(pBoundRect);
	this->setAttribute(dynamic_cast<Attribute*>(pAttribute));
	this->setStyle(pAxisStyle);

	/** Create Axis Line */
	this->ResetAxisLine(pBoundRect, pAxisStyle);

	/** Update Attribute */

	/** Create Axis Title */
	this->ResetAxisTitle(pBoundRect, pAxisStyle);

	/** Create Axis Other Elements */
	this->ResetAxisOtherElements(pAxisStyle);
}

/**
* @FuncName: ChartAxis(void)
* @Description: Default Constructor Function
*/
ChartAxis::ChartAxis(void)
{
	// TODO Auto-generated constructor stub
	m_pAxisLine = new ChartLine();
	m_pAxisTitle = new ChartText();
}

/**
 * @FuncName: ~ChartAxis(void)
 * @Description: Default Destructor Function
 */
ChartAxis::~ChartAxis()
{
	// TODO Auto-generated destructor stub
}

void ChartAxis::ResetChartAxis(void)
{
	/** Create Axis Line */
	this->ResetAxisLine(this->getBoundRect(), this->getStyle());

	/** Update Attribute */

	/** Create Axis Title */
	this->ResetAxisTitle(this->getBoundRect(), this->getStyle());

	/** Create Axis Other Elements */
	this->ResetAxisOtherElements(this->getStyle());
}

/**
 * @FuncName: CreateAxisLine(GeoRect* pBoundRect, ChartStyle* pLineStyle)
 * @Description: Create Axis Line
 * @param pBoundRect : GeoRect* : Bound Rectangle of Axis Area
 * @param pLineStyle : ChartStyle* : Style of Axis Line
 */
void ChartAxis::ResetAxisLine(GeoRect* pBoundRect, ChartStyle* pLineStyle)
{
	/** Convert Attribute to AxisAttr Type */
	AxisAttribute* pAttribute = dynamic_cast<AxisAttribute*>(getAttribute());

	/** Declare Variables */
	int nTickLength = 20;
	GeoLine* pAxisLine = NULL;

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
		pAxisLine = new GeoLine(nTLPointX, nTLPointY + nTickLength, nRBPointX, nTLPointY + nTickLength);
		break;
	}
	case Global::Axis_Bottom:
	{
		pAxisLine = new GeoLine(nTLPointX, nRBPointY - nTickLength, nRBPointX, nRBPointY - nTickLength);
		break;
	}
	case Global::Axis_Left:
	{
		pAxisLine = new GeoLine(nTLPointX + nTickLength, nRBPointY, nTLPointX + nTickLength, nTLPointY);
		break;
	}
	case Global::Axis_Right:
	{
		pAxisLine = new GeoLine(nRBPointX - nTickLength, nRBPointY, nRBPointX - nTickLength, nTLPointY);
		break;
	}
	default:
	{
		pAxisLine = new GeoLine();
		break;
	}
	}

	/** Initialize Axis Line */
	m_pAxisLine = new ChartLine(pAxisLine, pLineStyle);

	/** Update Attributes */
	pAttribute->setAxisLength(m_pAxisLine->getLength());
}

/**
 * @FuncName: CreateAxisTitle(ChartTextStyle vTextStyle)
 * @Description: Create Axis Title
 * @param pBoundRect : GeoRect* : Bound Rectangle of Axis Line
 * @param pTextStyle : ChartStyle* : Style of Axis Title Text
 */
void ChartAxis::ResetAxisTitle(GeoRect* pBoundRect, ChartStyle* pTextStyle)
{
	/** Convert Attribute to AxisAttr Type */
	AxisAttribute* pAttribute = dynamic_cast<AxisAttribute*>(getAttribute());

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
	m_pAxisTitle = new ChartText(pBoundRect, pTextStyle, pAttribute->getTitle());
}

/**
 * @FuncName: CreateAxisOthers(int nMaxValue, int nMinValue, int nTickValue, ChartStyle* pAxisStyle)
 * @Description: Create Axis Other Element, Include Grids, Ticks, Labels
 * @param nMaxValue : int : Maximum value of Axis
 * @param nMinValue : int : Minimum value of Axis
 * @param nTickValue : int : Every single tick value of Axis
 * @param pAxisStyle : ChartStyle* : Chart Style instance
 */
void ChartAxis::ResetAxisOtherElements(ChartStyle* pAxisStyle)
{
	/**  */
	m_pAxisLabels.clear();
	m_pAxisTicks.clear();
	m_pAxisGrid.clear();

	/** Convert Attribute to AxisAttr Type */
	AxisAttribute* pAttribute = dynamic_cast<AxisAttribute*>(getAttribute());

	/** Declare Geometry Variables */
	int nStartPosX = m_pAxisLine->getStartPoint()->getX();
	int nStartPosY = m_pAxisLine->getStartPoint()->getY();

	/** Declare Geometry Variables */
	list<int> ltTickVals = pAttribute->getTickValues();

	/**   */
	for (list<int>::iterator it = ltTickVals.begin();
			it != ltTickVals.end();
			++it)
	{
		/** Calculate Parameters */
		int nValue = *it;
		int nOffsite = pAttribute->getPositionViaScale(nValue);

		/** Create Single Tick */
		ResetSingleTick(pAttribute->getAxisPosition(),
				nStartPosX,
				nStartPosY,
				nOffsite,
				pAxisStyle);

		/** Create Single Grid */
		ResetSingleGrid(pAttribute->getAxisPosition(),
				nStartPosX,
				nStartPosY,
				nOffsite,
				pAxisStyle);

		/** Create Single Label */
		ResetSingleLabel(pAttribute->getAxisPosition(),
				nValue,
				nStartPosX,
				nStartPosY,
				nOffsite,
				pAxisStyle);
	}
}


void ChartAxis::ResetSingleTick(uint8 nAxisPos, int nStartPosX, int nStartPosY, int nOffset, ChartStyle* pTickStyle)
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
		pTickLine = new GeoLine(nStartPosX + nOffset,
				nStartPosY,
				nStartPosX + nOffset,
				nStartPosY - nTickLength);
		break;
	}
	case Global::Axis_Bottom:
	{
		/** Create a Single Tick Line */
		pTickLine = new GeoLine(nStartPosX + nOffset,
				nStartPosY,
				nStartPosX + nOffset,
				nStartPosY + nTickLength);
		break;
	}
	case Global::Axis_Left:
	{
		/** Create a Single Tick Line */
		pTickLine = new GeoLine(nStartPosX,
				nStartPosY - nOffset,
				nStartPosX - nTickLength,
				nStartPosY - nOffset);
		break;
	}
	case Global::Axis_Right:
	{
		/** Create a Single Tick Line */
		pTickLine = new GeoLine(nStartPosX,
				nStartPosY - nOffset,
				nStartPosX + nTickLength,
				nStartPosY - nOffset);
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

void ChartAxis::ResetSingleGrid(uint8 nAxisPos, int nStartPosX, int nStartPosY, int nOffset, ChartStyle* pGridStyle)
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
		pGridLine = new GeoLine(nStartPosX + nOffset,
				nStartPosY,
				nStartPosX + nOffset,
				nBottom);
		break;
	}
	case Global::Axis_Bottom:
	{
		/** Create a Single Grid Line */
		pGridLine = new GeoLine(nStartPosX + nOffset,
				nStartPosY,
				nStartPosX + nOffset,
				nTop);
		break;
	}
	case Global::Axis_Left:
	{
		/** Create a Single Grid Line */
		pGridLine = new GeoLine(nStartPosX,
				nStartPosY - nOffset,
				nRight,
				nStartPosY - nOffset);
		break;
	}
	case Global::Axis_Right:
	{
		/** Create a Single Grid Line */
		pGridLine = new GeoLine(nStartPosX,
				nStartPosY - nOffset,
				nLeft,
				nStartPosY - nOffset);
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

void ChartAxis::ResetSingleLabel(uint8 nAxisPos, int nCurrValue, int nStartPosX, int nStartPosY, int nOffset, ChartStyle* pLabelStyle)
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
		pLabelRect = new GeoRect(nStartPosX + nOffset - nRectWidth / 2,
				nStartPosY - nRectHeight - nTickLength,
				nRectWidth,
				nRectHeight);
		break;
	}
	case Global::Axis_Bottom:
	{
		/** Create a Single Label Rectangle */
		pLabelRect = new GeoRect(nStartPosX + nOffset - nRectWidth / 2,
				nStartPosY + nTickLength,
				nRectWidth,
				nRectHeight);
		break;
	}
	case Global::Axis_Left:
	{
		/** Create a Single Label Rectangle */
		pLabelRect = new GeoRect(nStartPosX - nRectWidth - nTickLength,
				nStartPosY - nOffset - nRectHeight / 2,
				nRectWidth,
				nRectHeight);
		break;
	}
	case Global::Axis_Right:
	{
		/** Create a Single Label Rectangle */
		pLabelRect = new GeoRect(nStartPosX + nTickLength,
				nStartPosY - nOffset - nRectHeight / 2,
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
