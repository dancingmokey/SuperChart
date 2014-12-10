/**
 * @Title: 			ScaleAttribute.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/09
 * @Version:		V1.0.0	
 */

#include "ScaleAttribute.h"

namespace SuperChart
{

ScaleAttribute* ScaleAttribute::pScaleAttrInstance = NULL;

ScaleAttribute* ScaleAttribute::Instance(string strTitle,
				double dMaxValue,
				double dMinValue,
				double dAxisLength)
{
	if (!pScaleAttrInstance)
	{
		pScaleAttrInstance = new ScaleAttribute();
	}
	return pScaleAttrInstance;
}

ScaleAttribute* ScaleAttribute::Instance(void)
{
	if (!pScaleAttrInstance)
	{
		pScaleAttrInstance = new ScaleAttribute();
	}
	return pScaleAttrInstance;
}

/**
 * @FuncName : ScaleAttribute(string strTitle, double dAxisValue, double dAxisLength)
 * @Description: Custom Constructor Function
 * @param strTitle : string : Scale Title
 * @param dAxisValue : double : Value of Axis
 * @param dAxisLength : double : Length of Axis
 */
ScaleAttribute::ScaleAttribute(string strTitle,
				double dMaxValue,
				double dMinValue,
				double dAxisLength) :
				m_dMaxValue(0.0f),
				m_dMinValue(0.0f),
				m_dAxisLength(0.0f),
				m_dScaleValue(0.0f)
{
	// TODO Auto-generated constructor stub
	this->setTitle(strTitle);
	this->setAxisLength(dAxisLength);
	this->setMaxValue(dMaxValue);
	this->setMinValue(dMinValue);
	this->UpdateScale(dMaxValue, dMinValue, dAxisLength);
}

/**
 * @FuncName : ScaleAttribute(void)
 * @Description: Default Constructor Function
 */
ScaleAttribute::ScaleAttribute() :
				Attribute(),
				m_dMaxValue(0.0f),
				m_dMinValue(0.0f),
				m_dAxisLength(0.0f),
				m_dScaleValue(0.0f)
{
	// TODO Auto-generated constructor stub
}

/**
 * @FuncName : ~ScaleAttribute(void)
 * @Description: Default Destructor Function
 */
ScaleAttribute::~ScaleAttribute()
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName : UpdateAttribute(void)
 * @Description: Update Attributes
 */
void ScaleAttribute::UpdateAttribute(void)
{
	this->UpdateScale(m_dMaxValue, m_dMinValue, m_dAxisLength);
}

/**
 * @FuncName : UpdateScale(double dMaxValue, double dMinValue, double dAxisLength)
 * @Description: Set Values of Chart Scale
 * @param dMaxValue : double : Maximum Value of Axis
 * @param dMinValue : double : Minimum Value of Axis
 * @param dAxisLength : int : Length of Axis, Used to Calculate Scale Value
 */
void ScaleAttribute::UpdateScale(double dMaxValue, double dMinValue, double dAxisLength)
{
	/**  */
	m_dMaxValue = dMaxValue;
	m_dMinValue = dMinValue;
	m_dAxisLength = dAxisLength;

	/** Axis Length equals 0 means Axis is not exist */
	if (m_dAxisLength == 0.0f)
	{
		m_dScaleValue = 0.0f;
	}
	else /** Calculate Scale Value  */
	{
		m_dScaleValue = (m_dMaxValue - m_dMinValue) / dAxisLength;
	}
}

/**
 * @FuncName : GetPositionByValue(double dValue)
 * @Description: Input Offset Value Based on MinValue of Axis, Output Position on Axis
 * @param dValue : double : Value
 * @return double
 */
double ScaleAttribute::GetPositionByValue(double dValue)
{
	return ((dValue - m_dMinValue) / m_dScaleValue);
}

/**
 * @FuncName : setAxisLength(double dAxisLength)
 * @Description: Set Axis Length to nAxisLength
 * @param dAxisLength : double : Axis Length
 */
void ScaleAttribute::setAxisLength(double dAxisLength)
{
	this->m_dAxisLength = dAxisLength;

	this->UpdateAttribute();
}

/**
 * @FuncName : setAxisMaxValue(double dMaxValue)
 * @Description: Set Axis Maximum Value
 * @param dMaxValue : double : Axis Maximum Value
 */
void ScaleAttribute::setMaxValue(double dMaxValue)
{
	this->m_dMaxValue = dMaxValue;

	this->UpdateAttribute();
}

/**
 * @FuncName : setMinValue(double dMinValue)
 * @Description: Set Axis Minimum Value
 * @param dMinValue : double : Axis Minimum Value
 */
void ScaleAttribute::setMinValue(double dMinValue)
{
	this->m_dMinValue = dMinValue;

	this->UpdateAttribute();
}

/**
 * @FuncName : setScaleValue(void)
 * @Description: Set Scale Value
 * @param dScaleValue : double : Scale Value
 */
void ScaleAttribute::setScaleValue(double dScaleValue)
{
	m_dScaleValue = dScaleValue;

	this->UpdateAttribute();
}

/**
 * @FuncName : getAxisLength(void)
 * @Description: Get Axis Length Value
 * @return double
 */
double ScaleAttribute::getAxisLength() const
{
	return m_dAxisLength;
}

/**
 * @FuncName : getMaxValue(void)
 * @Description: Get Axis Maximum Value
 * @return double
 */
double ScaleAttribute::getMaxValue() const
{
	return m_dMaxValue;
}

/**
 * @FuncName : getMinValue(void)
 * @Description: Get Axis Minimum Value
 * @return double
 */
double ScaleAttribute::getMinValue() const
{
	return m_dMinValue;
}

/**
 * @FuncName : getScaleValue(void)
 * @Description: Get Scale Value
 * @return double
 */
double ScaleAttribute::getScaleValue() const
{
	return m_dScaleValue;
}

} /* namespace SuperChart */
