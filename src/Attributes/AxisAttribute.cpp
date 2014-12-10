/**
 * @Title: 			AxisAttribute.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/09
 * @Version:		V1.0.0	
 */

#include "AxisAttribute.h"

namespace SuperChart
{

/**
 * @FuncName : AxisAttribute(string strTitle, uint8 nAxisPosition, double dMaxValue, double dMinValue, double dTickValue)
 * @Description: Custom Constructor Function
 * @param strTitle : string : Attribute Title
 * @param nAxisPosition : uint8 : Axis Position
 * @param dMaxValue : double : Maximum Value of Axis
 * @param dMinValue : double : Minimum Value of Axis
 * @param dTickValue : double : Every Single Value of Axis
 */
AxisAttribute::AxisAttribute(string strTitle,
				uint8 nAxisPosition,
				double dMaxValue,
				double dMinValue,
				double dTickValue) :
				m_nAxisPosition(Global::Axis_Top),
				m_dMaxValue(0.0f),
				m_dMinValue(0.0f),
				m_dTickValue(0.0f),
				m_dScaleValue(0.0f)
{
	// TODO Auto-generated constructor stub
	this->setTitle(strTitle);
	this->setAxisPosition(nAxisPosition);
	this->setMaxValue(dMaxValue);
	this->setMinValue(dMinValue);
	this->setTickValue(dTickValue);
	this->setScaleValue(0.0f);
}

/**
 * @FuncName : AxisAttribute(void)
 * @Description: Default Constructor Function
 */
AxisAttribute::AxisAttribute() :
				m_nAxisPosition(Global::Axis_Top),
				m_dMaxValue(0.0f),
				m_dMinValue(0.0f),
				m_dTickValue(0.0f),
				m_dScaleValue(0.0f)
{
	// TODO Auto-generated constructor stub
}

/**
 * @FuncName : ~AxisAttribute(void)
 * @Description: Default Destructor Function
 */
AxisAttribute::~AxisAttribute()
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName : UpdateAttribute(void)
 * @Description: Update Attribute
 */
void AxisAttribute::UpdateAttribute(void)
{
	this->UpdateTickValues(m_dMaxValue, m_dMinValue, m_dTickValue, m_dScaleValue);
}

/**
 * @FuncName : UpdateTickValues(double dMaxValue, double dMinValue, double dTickValue)
 * @Description: Set Axis Ticks Value
 * @param dMaxValue : double : Maximum Value of Axis
 * @param dMinValue : double : Minimum Value of Axis
 * @param dTickValue : double : Length of Axis, Used to Calculate Scale Value
 * @param dScaleValue : double : Scale of Axis
 */
void AxisAttribute::UpdateTickValues(double dMaxValue,
		double dMinValue,
		double dTickValue,
		double dScaleValue)
{
	/** Set Class Member Values */
	m_dMaxValue = dMaxValue;
	m_dMinValue = dMinValue;
	m_dTickValue = dTickValue;
	m_dScaleValue = dScaleValue;

	/** Reset List of Tick Values */
	m_ltTickValues.clear();

	/** Tick Value Equals 0 means No Ticks in Axis */
	if (m_dTickValue != 0)
	{
		/** Calculate Ticks Count of Axis */
		int nTickCount = (int)((m_dMaxValue - m_dMinValue) / m_dTickValue) + 1;

		/** Calculate Every Single Tick Value */
		for (int i = 0; i < nTickCount; ++i)
		{
			double dValue = m_dMinValue + m_dTickValue * (double)(i);
			m_ltTickValues.push_back(dValue);
		}
	}
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
 * @FuncName : setMaxValue(double dMaxValue)
 * @Description: Set Axis Maximum Value
 * @param dMaxValue : double : Axis Maximum Value
 */
void AxisAttribute::setMaxValue(double dMaxValue)
{
	this->m_dMaxValue = dMaxValue;

	this->UpdateAttribute();
}

/**
 * @FuncName : setMinValue(double dMinValue)
 * @Description: Set Axis Minimum Value
 * @param dMinValue : double : Axis Minimum Value
 */
void AxisAttribute::setMinValue(double dMinValue)
{
	this->m_dMinValue = dMinValue;

	this->UpdateAttribute();
}

/**
 * @FuncName : setTickValue(double dTickValue)
 * @Description: Set Axis Single Tick Value
 * @param nTickValue : double : Single Tick Value
 */
void AxisAttribute::setTickValue(double dTickValue)
{
	m_dTickValue = dTickValue;

	this->UpdateAttribute();
}
/**
 * @FuncName : setScaleValue(double dScaleValue)
 * @Description: Set Axis Scale Value
 * @param dScaleValue : double : Axis Scale Value
 */
void AxisAttribute::setScaleValue(double dScaleValue)
{
	m_dScaleValue = dScaleValue;

	this->UpdateAttribute();
}

/**
 * @FuncName: getAxisPosition(void)
 * @Description: Get Axis Position Information
 * @return uint8
 */
uint8 AxisAttribute::getAxisPosition(void) const
{
	return m_nAxisPosition;
}

/**
 * @FuncName : getMaxValue(void)
 * @Description: Get Axis Maximum Value
 * @return double
 */
double AxisAttribute::getMaxValue() const
{
	return m_dMaxValue;
}

/**
 * @FuncName : getMinValue(void)
 * @Description: Get Axis Minimum Value
 * @return double
 */
double AxisAttribute::getMinValue() const
{
	return m_dMinValue;
}

/**
 * @FuncName : getTickValue(void)
 * @Description: Get Axis Single Tick Value
 * @return double
 */
double AxisAttribute::getTickValue(void) const
{
	return m_dTickValue;
}

/**
 * @FuncName : getScaleValue(void)
 * @Description: Get Axis Scale Value
 * @return double
 */
double AxisAttribute::getScaleValue() const
{
	return m_dScaleValue;
}

/**
 * @FuncName : getTickValues(void)
 * @Description: Get Axis Ticks Value list
 * @return list<double>
 */
list<double> AxisAttribute::getTickValues(void)
{
	return m_ltTickValues;
}



} /* namespace SuperChart */
