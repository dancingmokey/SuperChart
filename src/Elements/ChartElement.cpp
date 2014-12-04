/**
 * @Title: 			ChartElement.cpp
 * @Package 		SuperChart
 * @Description: 	Implement Class SuperChart::ChartElement
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartElement.h"

namespace SuperChart
{

/**
 * @FuncName: ChartElement(void)
 * @Description: Custom Constructor Function
 * @param pBoundRect : GeoRect* : Bound Rectangle of Element
 * @param pStyle : ChartStyle* : Style of Element
 */
ChartElement::ChartElement(GeoRect* pBoundRect, ChartStyle* pStyle)
{
	// TODO Auto-generated constructor stub
	m_pBoundRect = pBoundRect;
	m_pStyle = pStyle;
}

/**
 * @FuncName: ChartElement(void)
 * @Description: Default Constructor Function
 */
ChartElement::ChartElement()
{
	// TODO Auto-generated constructor stub
	m_pBoundRect = new GeoRect();
	m_pStyle = new ChartStyle();
}

/**
 * @FuncName: ~ChartElement(void)
 * @Description: Default Destructor Function
 */
ChartElement::~ChartElement()
{
	// TODO Auto-generated destructor stub
	if (m_pBoundRect == NULL)
	{
		delete m_pBoundRect;
		m_pBoundRect = NULL;
	}
	if (m_pStyle == NULL)
	{
		delete m_pStyle;
		m_pStyle = NULL;
	}
}

/**
 * @FuncName: setBoundRect(GeoRect* pBoundRect)
 * @Description: Set Bound Rectangle of Element
 * @param pBoundRect : GeoRect* : Bound Rectangle of Element
 */
void ChartElement::setBoundRect(GeoRect* pBoundRect)
{
	m_pBoundRect = pBoundRect;
}

/**
 * @FuncName: setStyle(ChartStyle* pStyle)
 * @Description: Set Style of Element
 * @param pStyle : ChartStyle* : Style of Element
 */
void ChartElement::setStyle(ChartStyle* pStyle)
{
	m_pStyle = pStyle;
}

/**
 * @FuncName: getBoundRect(void)
 * @Description: Get Bound Rectangle of Element
 * @return GeoRect*
 */
GeoRect* ChartElement::getBoundRect(void)
{
	return m_pBoundRect;
}

/**
 * @FuncName: getStyle(void)
 * @Description: Get Style of Element
 * @return Pointer to ChartStyle Object
 */
ChartStyle* ChartElement::getStyle(void)
{
	return m_pStyle;
}

} /* namespace Geometry */
