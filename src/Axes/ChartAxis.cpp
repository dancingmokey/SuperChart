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
 * @param strTitle : string : Title of Axis
 * @param nMaxValue : int : Max Value of Axis
 * @param nMinValue : int : Min Value of Axis
 * @param nTickValue : int : Enery Single Value of Axis Tick
 */
ChartAxis::ChartAxis(uint8 nAxisPosition,
		GeoRect* pBoundRect,
		string strTitle,
		ChartStyle* pAxisStyle,
		int nMaxValue,
		int nMinValue,
		int nTickValue) :
		ChartElement(pBoundRect, pAxisStyle),
		m_nAxisPosition(Global::Axis_Left),
		m_nAxisLength(0),
		m_pAxisLine(NULL),
		m_pAxisTitle(NULL),
		m_pAxisScale(NULL)
{
	/** Initialize Private Class Members */
	this->setAxisPosition(nAxisPosition);
	this->setBoundRect(pBoundRect);

	/** Create Axis Title */
	this->CreateAxisTitle(pBoundRect, pAxisStyle, strTitle);

	/** Create Axis Line */
	this->CreateAxisLine(pBoundRect, pAxisStyle);

	/** Create Axis Other Elements */
	this->CreateAxisOthers(nMaxValue, nMinValue, nTickValue, pAxisStyle);
}

/**
* @FuncName: ChartAxis(void)
* @Description: Default Constructor Function
*/
ChartAxis::ChartAxis()
{
	// TODO Auto-generated constructor stub
	m_nAxisPosition = Global::Axis_Left;
	m_pAxisLine = new ChartLine();
	m_pAxisTitle = new ChartText();
	m_pAxisScale = new ChartScale();
	m_nAxisLength = 0;
}

/**
 * @FuncName: ~ChartAxis(void)
 * @Description: Default Destructor Function
 */
ChartAxis::~ChartAxis()
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName: CreateAxisTitle(ChartTextStyle vTextStyle)
 * @Description: Create Axis Title
 * @param pBoundRect : GeoRect* : Bound Rectangle of Axis Line
 * @param pTextStyle : ChartStyle* : Style of Axis Title Text
 * @param strTitle : string : Title of Axis
 */
void ChartAxis::CreateAxisTitle(GeoRect* pBoundRect, ChartStyle* pTextStyle, string strTitle)
{
	/** Initialize Axis Title */
	m_pAxisTitle = new ChartText(pBoundRect, pTextStyle, strTitle);
}

/**
 * @FuncName: CreateAxisLine(GeoRect* pBoundRect, ChartStyle* pLineStyle)
 * @Description: Create Axis Line
 * @param pBoundRect : GeoRect* : Bound Rectangle of Axis Area
 * @param pLineStyle : ChartStyle* : Style of Axis Line
 */
void ChartAxis::CreateAxisLine(GeoRect* pBoundRect, ChartStyle* pLineStyle)
{
	/** Get Bound Rectangle Parameters */
	GeoLine* pAxisLine = NULL;
	int nTLPointX = pBoundRect->getTopLeftPoint()->getX();
	int nTLPointY = pBoundRect->getTopLeftPoint()->getY();
	int nRBPointX = pBoundRect->getBottomRightPoint()->getX();
	int nRBPointY = pBoundRect->getBottomRightPoint()->getY();

	/** Calculate Axis Length & GeoLine base on Axis Position  */
	switch (m_nAxisPosition)
	{
	case Global::Axis_Top:
	{
		m_nAxisLength = nRBPointX - nTLPointX;
		pAxisLine = new GeoLine(nTLPointX, nTLPointY, nRBPointX, nTLPointY);
		break;
	}
	case Global::Axis_Bottom:
	{
		m_nAxisLength = nRBPointX - nTLPointX;
		pAxisLine = new GeoLine(nTLPointX, nRBPointY, nRBPointX, nRBPointY);
		break;
	}
	case Global::Axis_Left:
	{
		m_nAxisLength = nRBPointY - nTLPointY;
		pAxisLine = new GeoLine(nTLPointX, nRBPointY, nTLPointX, nTLPointY);
		break;
	}
	case Global::Axis_Right:
	{
		m_nAxisLength = nRBPointY - nTLPointY;
		pAxisLine = new GeoLine(nRBPointX, nRBPointY, nRBPointY, nTLPointY);
		break;
	}
	default:
	{
		m_nAxisLength = 1;
		pAxisLine = new GeoLine();
		break;
	}
	}

	/** Initialize Axis Line */
	m_pAxisLine = new ChartLine(pAxisLine, pLineStyle);
}

/**
 * @FuncName: CreateAxisScale(int nMaxValue, int nMinValue)
 * @Description: Create Axis Scale
 * @param nMaxValue : int : Maximum Value of Axis
 * @param nMinValue : int : Minimum Value of Axis
 */
void ChartAxis::CreateAxisScale(int nMaxValue, int nMinValue)
{
	/** Initialize Axis Title */
	this->m_pAxisScale = new ChartScale(nMaxValue, nMinValue, m_nAxisLength);
}

/**
 * @FuncName: CreateAxisOthers(int nMaxValue, int nMinValue, int nTickValue, ChartStyle* pAxisStyle)
 * @Description: Create Axis Other Element, Include Grids, Ticks, Labels
 * @param nMaxValue : int : Maximum value of Axis
 * @param nMinValue : int : Minimum value of Axis
 * @param nTickValue : int : Every single tick value of Axis
 * @param pAxisStyle : ChartStyle* : Chart Style instance
 */
void ChartAxis::CreateAxisOthers(int nMaxValue, int nMinValue, int nTickValue, ChartStyle* pAxisStyle)
{
	/** Declare Geometry Variables */
	int nStartPosX = m_pAxisLine->getStartPoint()->getX();
	int nStartPosY = m_pAxisLine->getStartPoint()->getY();
	int nTop = this->getBoundRect()->getTopLeftPoint()->getY();
	int nBottom = this->getBoundRect()->getBottomRightPoint()->getY();
	int nLeft = this->getBoundRect()->getTopLeftPoint()->getX();
	int nRight = this->getBoundRect()->getBottomRightPoint()->getX();

	/** Calculate Count of All The Ticks */
	int nTicksCount = (nMaxValue - nMinValue) / nTickValue + 1;

	/**  */
	stringstream strStream;
	for (int i = 0; i < nTicksCount; ++i)
	{
		/** Calculate Parameters */
		int nCurrValue = nMinValue + i * nTickValue;
		int nCurrPosition = m_pAxisScale->getPixCntViaScale(nCurrValue);

		/** Generate Tick Label */
		strStream << nCurrValue;
		string strTickLabel = strStream.str();
		strStream.clear();

		/** Calculate Tick Line & Grid Line & Label Rectangle */
		GeoLine* pTickLine = new GeoLine();
		GeoLine* pGridLine = new GeoLine();
		GeoRect* pLabelRect = new GeoRect();
		switch (m_nAxisPosition)
		{
		case Global::Axis_Top:
		{
			/** Create a Single Tick Line */
			pTickLine->setStartPoint(nStartPosX + nCurrPosition, nStartPosY);
			pTickLine->setEndPoint(nStartPosX + nCurrPosition, nStartPosY - 20);

			/** Create a Single Grid Line */
			pGridLine->setStartPoint(nStartPosX + nCurrPosition, nStartPosY);
			pGridLine->setStartPoint(nStartPosX + nCurrPosition, nBottom);

			/** Create a Single Label */
			pLabelRect->setTopLeftPoint(nStartPosX + nCurrPosition - 30,
					nStartPosY - 80);
			pLabelRect->setSize(60, 60);

			break;
		}
		case Global::Axis_Bottom:
		{
			/** Create a Single Tick Line */
			pTickLine->setStartPoint(nStartPosX + nCurrPosition, nStartPosY);
			pTickLine->setEndPoint(nStartPosX + nCurrPosition, nStartPosY + 20);

			/** Create a Single Grid Line */
			pGridLine->setStartPoint(nStartPosX + nCurrPosition, nStartPosY);
			pGridLine->setStartPoint(nStartPosX + nCurrPosition, nTop);

			/** Create a Single Label */
			pLabelRect->setTopLeftPoint(nStartPosX + nCurrPosition - 30,
					nStartPosY + 20);
			pLabelRect->setSize(60, 60);

			break;
		}
		case Global::Axis_Left:
		{
			/** Create a Single Tick Line */
			pTickLine->setStartPoint(nStartPosX, nStartPosY - nCurrPosition);
			pTickLine->setEndPoint(nStartPosX - 20, nStartPosY - nCurrPosition);

			/** Create a Single Grid Line */
			pGridLine->setStartPoint(nStartPosX, nStartPosY - nCurrPosition);
			pGridLine->setEndPoint(nStartPosX, nRight);

			/** Create a Single Label */
			pLabelRect->setTopLeftPoint(nStartPosX - 80,
					nStartPosY - nCurrPosition - 30);
			pLabelRect->setSize(60, 60);

			break;
		}
		case Global::Axis_Right:
		{
			/** Create a Single Tick Line */
			pTickLine->setStartPoint(nStartPosX, nStartPosY - nCurrPosition);
			pTickLine->setEndPoint(nStartPosX + 20, nStartPosY - nCurrPosition);

			/** Create a Single Grid Line */
			pTickLine->setStartPoint(nStartPosX, nStartPosY - nCurrPosition);
			pTickLine->setEndPoint(nStartPosX, nLeft);

			/** Create a Single Label */
			pLabelRect->setTopLeftPoint(nStartPosX + 20,
					nStartPosY - nCurrPosition - 30);
			pLabelRect->setSize(60, 60);

			break;
		}
		default:
		{
			break;
		}
		}

		/** Storage New Tick */
		m_pAxisTicks.push_back(new ChartLine(pTickLine, pAxisStyle));

		/** Storage New Tick */
		m_pAxisGrid.push_back(new ChartLine(pGridLine, pAxisStyle));

		/** Storage New Tick */
		m_pAxisLabels.push_back(new ChartText(pLabelRect, pAxisStyle, strTickLabel));
	}
}

/**
 * @FuncName: getAxisPosition(void)
 * @Description: Get Axis Position Information
 * @return uint8
 */
uint8 ChartAxis::getAxisPosition() const
{
	return m_nAxisPosition;
}

/**
 * @FuncName: setAxisPosition(uint8 nAxisPosition)
 * @Description: Set Axis Position Information
 * @param nAxisPosition : uint8 : Axis Position Information
 */
void ChartAxis::setAxisPosition(uint8 nAxisPosition)
{
	m_nAxisPosition = nAxisPosition;
}

} /* namespace SuperChart */
