/**
 * @Title: 			AxisAttribute.cpp
 * @Package 		SuperChart
 * @Description: 	Implement Class SuperChart::AxisAttribute
 * @Author: 		LiuLei
 * @Created on: 	2014/12/05
 * @Version:		V1.0.0	
 */

#include "AxisAttribute.h"

namespace SuperChart
{

/**
 * @FuncName : AxisAttribute(int nMaxVlue, int nMinValue, int nAxisPixCnt)
 * @Description: Custom Constructor Function
 * @param nAxisPosition : uint8 : Axis Position
 * @param strTitle : string : Axis Title
 * @param nMaxVlue : int : Maximum Value of Axis
 * @param nMinValue : int : Minimum Value of Axis
 * @param nTickValue : int : Single Tick Value of Axis
 */
AxisAttribute::AxisAttribute(uint8 nAxisPosition,
				string strTitle,
				int nMaxVlue,
				int nMinValue,
				int nTickValue) :
				m_nAxisPosition(Global::Axis_Left),
				m_strTitle(""),
				m_nMaxValue(0),
				m_nMinValue(0),
				m_nAxisLength(0),
				m_dScaleValue(0.0f),
				m_nTickValue(0)
{
	// TODO Auto-generated constructor stub
	m_nAxisPosition = nAxisPosition;
	m_strTitle = strTitle;
	m_nMaxValue = nMaxVlue;
	m_nMinValue = nMinValue;
	m_nTickValue = nTickValue;

	this->ResetAttribute();
}

/**
 * @FuncName: ~ChartAxis(void)
 * @Description: Default Destructor Function
 */
AxisAttribute::~AxisAttribute()
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName : ResetAttribute(void)
 * @Description: Reset Attribute
 */
void AxisAttribute::ResetAttribute(void)
{
	this->ResetScale(m_nMaxValue, m_nMinValue, m_nAxisLength);

	this->ResetTickValues(m_nMaxValue, m_nMinValue, m_nTickValue);
}

/**
 * @FuncName : SetChartScale(int nMaxVlue, int nMinValue, int nAxisPixCnt)
 * @Description: Set Values of Chart Scale
 * @param nMaxValue : int : Maximum Value of Axis
 * @param nMinValue : int : Minimum Value of Axis
 * @param nAxisLength : int : Length of Axis, Used to Calculate Scale Value
 */
void AxisAttribute::ResetScale(int nMaxValue, int nMinValue, int nAxisLength)
{
	/** Set Class Member Values */
	m_nMaxValue = nMaxValue;
	m_nMinValue = nMinValue;
	m_nAxisLength = nAxisLength;

	/** Calculate Scale Value  */
	if (m_nAxisLength == 0)
	{
		m_dScaleValue = 0.0f;
	}
	else
	{
		m_dScaleValue = ((double)(m_nMaxValue - m_nMinValue)) / ((double)(m_nAxisLength));
	}
}

/**
 * @FuncName : setScaleValue(void)
 * @Description: Calculate Scale Value
 * @param dScaleValue : double : Scale Value
 */
void AxisAttribute::setScaleValue(void)
{
	/** Axis Length equals 0 means Axis is not exist */
	if (m_nAxisLength == 0)
	{
		m_dScaleValue = 0.0f;
	}
	else /** Calculate Scale Value  */
	{
		m_dScaleValue = ((double)(m_nMaxValue - m_nMinValue)) / ((double)(m_nAxisLength));
	}
}

/**
	 * @FuncName : ResetTickValues(int nMaxValue, int nMinValue, int nTickValue)
	 * @Description: Set Axis Ticks Value
	 * @param nMaxValue : int : Maximum Value of Axis
	 * @param nMinValue : int : Minimum Value of Axis
	 * @param nTickValue : int : Every Single Tick Value in Axis
 */
void AxisAttribute::ResetTickValues(int nMaxValue, int nMinValue, int nTickValue)
{
	/** Set Class Member Values */
	m_nMaxValue = nMaxValue;
	m_nMinValue = nMinValue;
	m_nTickValue = nTickValue;

	/** Reset List of Tick Values */
	m_ltTickValues.clear();

	/** Tick Value Equals 0 means No Ticks in Axis */
	if (m_nTickValue != 0)
	{
		/** Calculate Ticks Count of Axis */
		int nTickCount = (m_nMaxValue - m_nMinValue) / m_nTickValue + 1;

		/** Calculate Every Single Tick Value */
		for (int i = 0; i < nTickCount; ++i)
		{
			int nValue = m_nMinValue + m_nTickValue * i;
			m_ltTickValues.push_back(nValue);
		}
	}

}

/**
 * @FuncName : getPixCntViaScale(int nAxisPixelCount)
 * @Description: Input Value, Output Position on Axis
 * @param nValue : int : Value
 * @return
 */
int AxisAttribute::getPositionViaScale(int nValue)
{
	return (int)(((double)(nValue - m_nMinValue)) / m_dScaleValue);
}

/**
 * @FuncName: setAxisPosition(uint8 nAxisPosition)
 * @Description: Set Axis Position Information
 * @param nAxisPosition : uint8 : Axis Position Information
 */
void AxisAttribute::setAxisPosition(uint8 nAxisPosition)
{
	m_nAxisPosition = nAxisPosition;
}

/**
 * @FuncName : setTitle(const string& strTitle)
 * @Description: Set Axis Title
 * @param strTitle : string : Title of Axis
 */
void AxisAttribute::setTitle(const string& strTitle)
{
	m_strTitle = strTitle;
}

/**
 * @FuncName : setMaxValue(int nMaxValue)
 * @Description: Set Maximum Value to nMaxValue
 * @param dScaleValue : int : Scale Value
 */
void AxisAttribute::setMaxValue(int nMaxValue)
{
	m_nMaxValue = nMaxValue;

	ResetAttribute();
}

/**
 * @FuncName : setMinValue(int nMinValue)
 * @Description: Set Minimum Value to nMinValue
 * @param dScaleValue : int : Minimum Value
 */
void AxisAttribute::setMinValue(int nMinValue)
{
	m_nMinValue = nMinValue;

	ResetAttribute();
}

/**
 * @FuncName : setAxisLength(int nAxisLength)
 * @Description: Set Axis Length to nAxisLength
 * @param nAxisLength : int : Axis Length
 */
void AxisAttribute::setAxisLength(int nAxisLength)
{
	m_nAxisLength = nAxisLength;

	ResetAttribute();
}

/**
 * @FuncName : setTickValue(int nTickValue)
 * @Description: Set Axis Single Tick Value
 * @param nTickValue : int : Single Tick Value
 */
void AxisAttribute::setTickValue(int nTickValue)
{
	m_nTickValue = nTickValue;

	ResetAttribute();
}

/**
 * @FuncName: getAxisPosition(void)
 * @Description: Get Axis Position Information
 * @return uint8
 */
uint8 AxisAttribute::getAxisPosition() const
{
	return m_nAxisPosition;
}

/**
 * @FuncName : getTitle(void)
 * @Description: Get Axis Title
 * @return string
 */
const string& AxisAttribute::getTitle(void) const
{
	return m_strTitle;
}

/**
 * @FuncName : getScaleValue(void)
 * @Description: Get Scale Value
 * @return double
 */
double AxisAttribute::getScaleValue(void) const
{
	return m_dScaleValue;
}

/**
 * @FuncName : getMaxValue(void)
 * @Description: Get Maximum Value
 * @return int
 */
int AxisAttribute::getMaxValue(void) const
{
	return m_nMaxValue;
}

/**
 * @FuncName : getMinValue(void)
 * @Description: Get Minimum Value
 * @return int
 */
int AxisAttribute::getMinValue(void) const
{
	return m_nMinValue;
}

/**
 * @FuncName : getAxisLength(void)
 * @Description: Get Axis Length
 * @return int
 */
int AxisAttribute::getAxisLength() const
{
	return m_nAxisLength;
}

/**
 * @FuncName : getTickValue(void)
 * @Description: Get Axis Single Tick Value
 * @return int
 */
int AxisAttribute::getTickValue(void) const
{
	return m_nTickValue;
}

/**
 * @FuncName : getTickValues(void)
 * @Description: Get Axis Ticks Value list
 * @return list<int>
 */
list<int> AxisAttribute::getTickValues(void)
{
	return m_ltTickValues;
}











} /* namespace SuperChart */
