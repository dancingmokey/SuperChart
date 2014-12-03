/**
 * @Title: 			ChartElement.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartElement.h"

namespace SuperChart
{

ChartElement::ChartElement()
{
	// TODO Auto-generated constructor stub
	m_pBoundRect = new GeoRect();
	m_bIsVisible = false;
}

ChartElement::~ChartElement()
{
	// TODO Auto-generated destructor stub
	if (m_pBoundRect == NULL)
	{
		delete m_pBoundRect;
		m_pBoundRect = NULL;
	}
}

bool ChartElement::isVisible() const
{
	return m_bIsVisible;
}

void ChartElement::setVisible(bool bIsVisible)
{
	m_bIsVisible = bIsVisible;
}

GeoRect* ChartElement::getBoundRect()
{
	return m_pBoundRect;
}

void ChartElement::setBoundRect(GeoRect* pBoundRect)
{
	m_pBoundRect = pBoundRect;
}

} /* namespace Geometry */
