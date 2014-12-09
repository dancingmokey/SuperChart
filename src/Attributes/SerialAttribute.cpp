/**
 * @Title: 			SerialAttribute.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/08
 * @Version:		V1.0.0	
 */

#include "SerialAttribute.h"

namespace SuperChart
{

SerialAttribute::SerialAttribute(string strTitle,
		ScaleAttribute* pXScaleAttrs,
		ScaleAttribute* pYScaleAttrs)
{
	// TODO Auto-generated constructor stub
	m_strTitle = strTitle;
	m_pXScaleAttrs = pXScaleAttrs;
	m_pYScaleAttrs = pYScaleAttrs;
}

SerialAttribute::~SerialAttribute()
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName : ResetAttribute(void)
 * @Description: Reset Attribute
 */
void SerialAttribute::ResetAttribute(void)
{
}

void SerialAttribute::AddData(double dXValue, double dYValue)
{
	m_ltXValues.push_back(dXValue);
	m_ltYValues.push_back(dYValue);
	m_ltXPositions.push_back(this->m_pXScaleAttrs->getPositionViaScale(dXValue));
	m_ltYPositions.push_back(this->m_pYScaleAttrs->getPositionViaScale(dYValue));

	this->ResizeData();
}

void SerialAttribute::AddData(double* pXValueList, double* pYValueList, int nCount)
{
	for (int i = 0; i < nCount; ++i)
	{
		m_ltXValues.push_back(pXValueList[i]);
		m_ltYValues.push_back(pYValueList[i]);
		m_ltXPositions.push_back(this->m_pXScaleAttrs->getPositionViaScale(pXValueList[i]));
		m_ltYPositions.push_back(this->m_pYScaleAttrs->getPositionViaScale(pYValueList[i]));
	}

	this->ResizeData();
}

void SerialAttribute::ResizeData(void)
{
	int nMaxPointPerPage = this->m_pXScaleAttrs->getMaxValue() -
			this->m_pXScaleAttrs->getMinValue();

	if (m_ltXValues.size() > nMaxPointPerPage)
	{
		int nDiff = m_ltXValues.size() - nMaxPointPerPage;

		for (int i = 0; i < nDiff; ++i)
		{
			m_ltXValues.pop_front();
			m_ltYValues.pop_front();
			m_ltYPositions.pop_front();
		}
	}


	m_ltXPositions.clear();
	for (list<double>::iterator it = m_ltXValues.begin();
			it != m_ltXValues.end();
			it++)
	{
		m_ltXPositions.push_back(this->m_pXScaleAttrs->getPositionViaScale(*it));
	}
}

void SerialAttribute::setTitle(const string& strTitle)
{
	m_strTitle = strTitle;
}

const string& SerialAttribute::getTitle(void) const
{
	return m_strTitle;
}

list<int> SerialAttribute::GetXPosition(void)
{
	return m_ltXPositions;
}

list<int> SerialAttribute::GetYPosition(void)
{
	return m_ltYPositions;
}

} /* namespace SuperChart */

