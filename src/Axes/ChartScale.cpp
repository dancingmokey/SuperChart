/**
 * @Title: 			ChartScale.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

#include "ChartScale.h"

namespace SuperChart
{

/**
 * @FuncName : ChartScale(int nMaxVlue, int nMinValue, int nAxisPixCnt)
 * @Description: Custom Constructor Function
 * @param nMaxValue : int : Maximum Value of Axis
 * @param nMinValue : int : Minimum Value of Axis
 * @param nAxisLength : int : Length of Axis, Used to Calculate Scale Value
 */
ChartScale::ChartScale(int nMaxValue, int nMinValue, int nAxisLength)
{
	/** Set Class Member Values */
	m_nMaxValue = nMaxValue;
	m_nMinValue = nMinValue;
	m_nAxisLength = nAxisLength;

	/** Calculate Scale Value  */
	RefreshChartScale();
}

/**
 * @FuncName: ChartElement(void)
 * @Description: Default Copy Constructor Function
 */
ChartScale::ChartScale(ChartScale& vChartScale)
{
	/** Set Class Member Values */
	m_nMaxValue = vChartScale.getMaxValue();
	m_nMinValue = vChartScale.getMinValue();
	m_nAxisLength = vChartScale.getAxisLength();

	/** Calculate Scale Value  */
	RefreshChartScale();
}

/**
 * @FuncName: ChartElement(void)
 * @Description: Default Constructor Function
 */
ChartScale::ChartScale(void)
{
	// TODO Auto-generated constructor stub
	m_nMaxValue = 0;
	m_nMinValue = 0;
	m_nAxisLength = 0;
	m_dScaleValue = 0.0f;
}

/**
 * @FuncName: ~ChartElement(void)
 * @Description: Default Destructor Function
 */
ChartScale::~ChartScale(void)
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName : RefreshChartScale(void)
 * @Description: Refresh Chart Scale
 */
void ChartScale::RefreshChartScale(void)
{
	this->SetChartScale(m_nMaxValue, m_nMinValue, m_nAxisLength);
}

/**
 * @FuncName : SetChartScale(int nMaxVlue, int nMinValue, int nAxisPixCnt)
 * @Description: Set Values of Chart Scale
 * @param nMaxValue : int : Maximum Value of Axis
 * @param nMinValue : int : Minimum Value of Axis
 * @param nAxisLength : int : Length of Axis, Used to Calculate Scale Value
 */
void ChartScale::SetChartScale(int nMaxValue, int nMinValue, int nAxisLength)
{
	/** Set Class Member Values */
	m_nMaxValue = nMaxValue;
	m_nMinValue = nMinValue;
	m_nAxisLength = nAxisLength;

	/** Calculate Scale Value  */
	m_dScaleValue = ((double)(m_nMaxValue - m_nMinValue)) / ((double)(m_nAxisLength));
}

/**
 * @FuncName : setMaxValue(int nMaxValue)
 * @Description: Set Maximum Value to nMaxValue
 * @param dScaleValue : int : Scale Value
 */
void ChartScale::setMaxValue(int nMaxValue)
{
	m_nMaxValue = nMaxValue;

	RefreshChartScale();
}

/**
 * @FuncName : setMinValue(int nMinValue)
 * @Description: Set Minimum Value to nMinValue
 * @param dScaleValue : int : Minimum Value
 */
void ChartScale::setMinValue(int nMinValue)
{
	m_nMinValue = nMinValue;

	RefreshChartScale();
}

/**
 * @FuncName : setAxisLength(int nAxisLength)
 * @Description: Set Axis Length to nAxisLength
 * @param nAxisLength : int : Axis Length
 */
void ChartScale::setAxisLength(int nAxisLength)
{
	m_nAxisLength = nAxisLength;

	RefreshChartScale();
}

/**
 * @FuncName : getPixCntViaScale(int nAxisPixelCount)
 * @Description: Input Value, Output Position on Axis
 * @param nValue : int : Value
 * @return
 */
int ChartScale::getPixCntViaScale(int nValue)
{
	return (int)(((double)(nValue)) / m_dScaleValue);
}

/**
 * @FuncName : getScaleValue(void)
 * @Description: Get Scale Value
 * @return double
 */
double ChartScale::getScaleValue(void) const
{
	return m_dScaleValue;
}

/**
 * @FuncName : getMaxValue(void)
 * @Description: Get Maximum Value
 * @return int
 */
int ChartScale::getMaxValue(void) const
{
	return m_nMaxValue;
}

/**
 * @FuncName : getMinValue(void)
 * @Description: Get Minimum Value
 * @return int
 */
int ChartScale::getMinValue(void) const
{
	return m_nMinValue;
}

/**
 * @FuncName : getAxisLength(void)
 * @Description: Get Axis Length
 * @return int
 */
int ChartScale::getAxisLength() const
{
	return m_nAxisLength;
}

} /* namespace SuperChart */
