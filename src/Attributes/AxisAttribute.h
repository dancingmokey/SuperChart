/**
 * @Title: 			AxisAttribute.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/09
 * @Version:		V1.0.0	
 */

#ifndef ATTRIBUTES_AXISATTRIBUTE_H_
#define ATTRIBUTES_AXISATTRIBUTE_H_

#include "../Common/Global.h"
#include "../Attributes/Attribute.h"

#include <list>

using namespace std;

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::AxisAttribute
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/09
 * @Version:		V1.0.0	
 */
class AxisAttribute : public Attribute
{
public:
	/**
	 * @FuncName : AxisAttribute(string strTitle, uint8 nAxisPosition, double dMaxValue, double dMinValue, double dTickValue)
	 * @Description: Custom Constructor Function
	 * @param strTitle : string : Attribute Title
	 * @param nAxisPosition : uint8 : Axis Position
	 * @param dMaxValue : double : Maximum Value of Axis
	 * @param dMinValue : double : Minimum Value of Axis
	 * @param dTickValue : double : Every Single Value of Axis
	 */
	AxisAttribute(string strTitle,
			uint8 nAxisPosition,
			double dMaxValue,
			double dMinValue,
			double dTickValue);

	/**
	 * @FuncName : AxisAttribute(void)
	 * @Description: Default Constructor Function
	 */
	AxisAttribute(void);

	/**
	 * @FuncName : ~AxisAttribute(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~AxisAttribute(void);

public:
	/**
	 * @FuncName : UpdateAttribute(void)
	 * @Description: Update Attributes
	 */
	virtual void UpdateAttribute(void);

	/**
	 * @FuncName : UpdateTickValues(double dMaxValue, double dMinValue, double dTickValue)
	 * @Description: Set Axis Ticks Value
	 * @param dMaxValue : double : Maximum Value of Axis
	 * @param dMinValue : double : Minimum Value of Axis
	 * @param dTickValue : double : Length of Axis, Used to Calculate Scale Value
	 */
	void UpdateTickValues(double dMaxValue,
			double dMinValue,
			double dTickValue,
			double dScaleValue);

public:
	/**
	 * @FuncName: setAxisPosition(uint8 nAxisPosition)
	 * @Description: Set Axis Position Information
	 * @param nAxisPosition : uint8 : Axis Position Information
	 */
	void setAxisPosition(uint8 nAxisPosition);

	/**
	 * @FuncName : setMaxValue(double dMaxValue)
	 * @Description: Set Axis Maximum Value
	 * @param dMaxValue : double : Axis Maximum Value
	 */
	void setMaxValue(double dMaxValue);

	/**
	 * @FuncName : setMinValue(double dMinValue)
	 * @Description: Set Axis Minimum Value
	 * @param dMinValue : double : Axis Minimum Value
	 */
	void setMinValue(double dMinValue);

	/**
	 * @FuncName : setTickValue(double dTickValue)
	 * @Description: Set Axis Single Tick Value
	 * @param nTickValue : double : Single Tick Value
	 */
	void setTickValue(double dTickValue);

	/**
	 * @FuncName : setScaleValue(double dScaleValue)
	 * @Description: Set Axis Scale Value
	 * @param dScaleValue : double : Axis Scale Value
	 */
	void setScaleValue(double dScaleValue);

	/**
	 * @FuncName: getAxisPosition(void)
	 * @Description: Get Axis Position Information
	 * @return uint8
	 */
	uint8 getAxisPosition(void) const;

	/**
	 * @FuncName : getMaxValue(void)
	 * @Description: Get Maximum Value
	 * @return double
	 */
	double getMaxValue(void) const;

	/**
	 * @FuncName : getMinValue(void)
	 * @Description: Get Minimum Value
	 * @return double
	 */
	double getMinValue(void) const;

	/**
	 * @FuncName : getTickValue(void)
	 * @Description: Get Axis Single Tick Value
	 * @return double
	 */
	double getTickValue(void) const;

	/**
	 * @FuncName : getScaleValue(void)
	 * @Description: Get Axis Scale Value
	 * @return double
	 */
	double getScaleValue() const;

	/**
	 * @FuncName : getTickValues(void)
	 * @Description: Get Axis Ticks Value list
	 * @return list<double>
	 */
	list<double> getTickValues(void);

private:
	/**
	 * @field : m_nAxisPosition : uint8 : Axis Position Information
	 */
	uint8 m_nAxisPosition;

	/**
	 * @field m_dMaxValue : double : Maximum Value of Axis
	 */
	double m_dMaxValue;

	/**
	 * @field m_dMinValue : double : Minimum Value of Axis
	 */
	double m_dMinValue;

	/**
	 * @field m_nTickValue : double : Value of Every Single Tick in Axis
	 */
	double m_dTickValue;

	/**
	 * @field m_dScaleValue : double : Scale Value in Axis
	 */
	double m_dScaleValue;

	/**
	 * @field m_ltTickValues : list<double> : Tick Value List of Axis
	 */
	list<double> m_ltTickValues;
};

} /* namespace SuperChart */

#endif /* ATTRIBUTES_AXISATTRIBUTE_H_ */
