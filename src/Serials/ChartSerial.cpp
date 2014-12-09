/**
 * @Title: 			ChartSerial.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartSerial.h"

namespace SuperChart
{

ChartSerial::ChartSerial(GeoRect* pBoundRect,
		SerialAttribute* pAttribute,
		ChartStyles* pChartStyles) :
		ChartElement(pBoundRect,
				dynamic_cast<Attribute*>(pAttribute),
				pChartStyles->getChartStyleByName(pAttribute->getTitle())),
		m_pChartStyles(NULL)
{
	// TODO Auto-generated constructor stub
	this->setBoundRect(pBoundRect);
	this->setAttribute(dynamic_cast<Attribute*>(pAttribute));
	this->setStyle(pChartStyles->getChartStyleByName(pAttribute->getTitle()));
}

ChartSerial::~ChartSerial()
{
	// TODO Auto-generated destructor stub
}

list<GeoLine*> ChartSerial::GetSerialLine(void)
{
	for (list<GeoLine*>::iterator itLine = m_ltLines.begin();
			itLine != m_ltLines.end();
			itLine++)
	{
		GeoLine* pLine = *itLine;
		if (pLine != NULL)
		{
			delete pLine;
			pLine = NULL;
		}
	}
	m_ltLines.clear();

	SerialAttribute* pAttribute = dynamic_cast<SerialAttribute*>(this->getAttribute());
	list<int> ltXPos = pAttribute->GetXPosition();
	list<int> ltYPos = pAttribute->GetYPosition();

	list<int>::iterator itX = ltXPos.begin();
	list<int>::iterator itY = ltYPos.begin();
	while (true)
	{
		int nXValue1 = *itX;
		int nYValue1 = *itY;
		if (((itX++) == ltXPos.end()) ||
			((itY++) == ltYPos.end()))
		{
			break;
		}
		else
		{
			int nXValue2 = *itX;
			int nYValue2 = *itY;

			GeoLine* pNewLine = new GeoLine(nXValue1, nYValue1, nXValue2, nYValue2);
			m_ltLines.push_back(pNewLine);
		}
	}

	return m_ltLines;
}

} /* namespace SuperChart */
