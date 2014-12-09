/**
 * @Title: 			AxisAttribute.cpp
 * @Package 		SuperChart
 * @Description: 	Implement Class SuperChart::AxisAttribute
 * @Author: 		LiuLei
 * @Created on: 	2014/12/05
 * @Version:		V1.0.0	
 */

#include "ScaleAttribute.h"

namespace SuperChart
{

/**
 * @FuncName : AxisAttribute(uint8 nAxisPosition, string strTitle, int nMaxVlue, int nMinValue, double dTickValue)
 * @Description: Custom Constructor Function
 * @param nAxisPosition : uint8 : Axis Position
 * @param strTitle : string : Axis Title
 * @param nMaxVlue : int : Maximum Value of Axis
 * @param nMinValue : int : Minimum Value of Axis
 * @param dTickValue : double : Single Tick Value of Axis
 */
ScaleAttribute::ScaleAttribute(uint8 nAxisPosition,
				string strTitle,
				int nMaxVlue,
				int nMinValue,
				double dTickValue) :
				m_nAxisPosition(Global::Axis_Left),
				m_strTitle(""),
				m_nMaxValue(0),
				m_nMinValue(0),
				m_dAxisLength(0),
				m_dScaleValue(0.0f),
				m_dTickValue(0)
{
	// TODO Auto-generated constructor stub
	m_nAxisPosition = nAxisPosition;
	m_strTitle = strTitle;
	m_nMaxValue = nMaxVlue;
	m_nMinValue = nMinValue;
	m_dTickValue = dTickValue;

	this->ResetAttribute();
}

/**
 * @FuncName: ~ChartAxis(void)
 * @Description: Default Destructor Function
 */
ScaleAttribute::~ScaleAttribute()
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName : ResetAttribute(void)
 * @Description: Reset Attribute
 */
void ScaleAttribute::ResetAttribute(void)
{
	this->ResetScale(m_nMaxValue, m_nMinValue, m_dAxisLength);

	this->ResetTickValues(m_nMaxValue, m_nMinValue, m_dTickValue);
}

/**
 * @FuncName : SetChartScale(int nMaxVlue, int nMinValue, int dAxisLength)
 * @Description: Set Values of Chart Scale
 * @param nMaxValue : int : Maximum Value of Axis
 * @param nMinValue : int : Minimum Value of Axis
 * @param dAxisLength : double : Length of Axis, Used to Calculate Scale Value
 */
void ScaleAttribute::ResetScale(int nMaxValue, int nMinValue, double dAxisLength)
{
	/** Set Class Member Values */
	m_nMaxValue = nMaxValue;
	m_nMinValue = nMinValue;
	m_dAxisLength = dAxisLength;

	/** Calculate Scale Value  */
	CalcScaleValue();
}

/**
 * @FuncName : setScaleValue(void)
 * @Description: Calculate Scale Value
 * @param dScaleValue : double : Scale Value
 */
void ScaleAttribute::CalcScaleValue(void)
{
	/** Axis Length equals 0 means Axis is not exist */
	if (m_dAxisLength == 0.0f)
	{
		m_dScaleValue = 0.0f;
	}
	else /** Calculate Scale Value  */
	{
		m_dScaleValue = ((double)(m_nMaxValue - m_nMinValue)) / m_dAxisLength;
	}
}

/**
 * @FuncName : ResetTickValues(int nMaxValue, int nMinValue, double dAxisLength)
 * @Description: Set Axis Ticks Value
 * @param nMaxValue : int : Maximum Value of Axis
 * @param nMinValue : int : Minimum Value of Axis
 * @param dAxisLength : double : Length of Axis, Used to Calculate Scale Value
 */
void ScaleAttribute::ResetTickValues(int nMaxValue, int nMinValue, double dAxisLength)
{
	/** Set Class Member Values */
	m_nMaxValue = nMaxValue;
	m_nMinValue = nMinValue;
	m_dTickValue = dAxisLength;

	/** Reset List of Tick Values */
	m_ltTickValues.clear();

	/** Tick Value Equals 0 means No Ticks in Axis */
	if (m_dTickValue != 0)
	{
		/** Calculate Ticks Count of Axis */
		int nTickCount = (m_nMaxValue - m_nMinValue) / m_dTickValue + 1;

		/** Calculate Every Single Tick Value */
		for (int i = 0; i < nTickCount; ++i)
		{
			double dValue = (double)m_nMinValue + m_dTickValue * i;
			m_ltTickValues.push_back(dValue);
		}
	}

}

/**
 * @FuncName : getPixCntViaScale(double dValue)
 * @Description: Input Value, Output Position on Axis
 * @param dValue : double : Value
 * @return
 */
int ScaleAttribute::getPositionViaScale(double dValue)
{
	return (int)((dValue - (double)m_nMinValue) / m_dScaleValue);
}

/**
 * @FuncName: setAxisPosition(uint8 nAxisPosition)
 * @Description: Set Axis Position Information
 * @param nAxisPosition : uint8 : Axis Position Information
 */
void ScaleAttribute::setAxisPosition(uint8 nAxisPosition)
{
	m_nAxisPosition = nAxisPosition;
}

/**
 * @FuncName : setTitle(const string& strTitle)
 * @Description: Set Axis Title
 * @param strTitle : string : Title of Axis
 */
void ScaleAttribute::setTitle(const string& strTitle)
{
	m_strTitle = strTitle;
}

/**
 * @FuncName : setMaxValue(int nMaxValue)
 * @Description: Set Maximum Value to nMaxValue
 * @param dScaleValue : int : Scale Value
 */
void ScaleAttribute::setMaxValue(int nMaxValue)
{
	m_nMaxValue = nMaxValue;

	ResetAttribute();
}

/**
 * @FuncName : setMinValue(int nMinValue)
 * @Description: Set Minimum Value to nMinValue
 * @param dScaleValue : int : Minimum Value
 */
void ScaleAttribute::setMinValue(int nMinValue)
{
	m_nMinValue = nMinValue;

	ResetAttribute();
}

/**
 * @FuncName : setAxisLength(int nAxisLength)
 * @Description: Set Axis Length to nAxisLength
	 * @param dAxisLength : double : Axis Length
 */
void ScaleAttribute::setAxisLength(double dAxisLength)
{
	m_dAxisLength = dAxisLength;

	ResetAttribute();
}

/**
 * @FuncName : setTickValue(double dTickValue)
 * @Description: Set Axis Single Tick Value
 * @param nTickValue : double : Single Tick Value
 */
void ScaleAttribute::setTickValue(double dTickValue)
{
	m_dTickValue = dTickValue;

	ResetAttribute();
}

/**
 * @FuncName: getAxisPosition(void)
 * @Description: Get Axis Position Information
 * @return uint8
 */
uint8 ScaleAttribute::getAxisPosition() const
{
	return m_nAxisPosition;
}

/**
 * @FuncName : getTitle(void)
 * @Description: Get Axis Title
 * @return string
 */
const string& ScaleAttribute::getTitle(void) const
{
	return m_strTitle;
}

/**
 * @FuncName : getScaleValue(void)
 * @Description: Get Scale Value
 * @return double
 */
double ScaleAttribute::getScaleValue(void) const
{
	return m_dScaleValue;
}

/**
 * @FuncName : getMaxValue(void)
 * @Description: Get Maximum Value
 * @return int
 */
int ScaleAttribute::getMaxValue(void) const
{
	return m_nMaxValue;
}

/**
 * @FuncName : getMinValue(void)
 * @Description: Get Minimum Value
 * @return int
 */
int ScaleAttribute::getMinValue(void) const
{
	return m_nMinValue;
}

/**
 * @FuncName : getAxisLength(void)
 * @Description: Get Axis Length
 * @return double
 */
double ScaleAttribute::getAxisLength() const
{
	return m_dAxisLength;
}

/**
 * @FuncName : getTickValue(void)
 * @Description: Get Axis Single Tick Value
 * @return double
 */
double ScaleAttribute::getTickValue(void) const
{
	return m_dTickValue;
}

/**
 * @FuncName : getTickValues(void)
 * @Description: Get Axis Ticks Value list
 * @return list<double>
 */
list<double> ScaleAttribute::getTickValues(void)
{
	return m_ltTickValues;
}











} /* namespace SuperChart */
