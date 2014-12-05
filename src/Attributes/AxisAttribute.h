/**
 * @Title: 			AxisAttribute.h
 * @Package 		SuperChart
 * @Description: 	Define Class SuperChart::AxisAttribute
 * @Author: 		LiuLei
 * @Created on: 	2014/12/05
 * @Version:		V1.0.0	
 */

#ifndef AXES_AXISATTRIBUTE_H_
#define AXES_AXISATTRIBUTE_H_

#include "Attribute.h"
#include "../Common/Global.h"
#include <string>
#include <list>

using namespace std;

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::AxisAttribute
 * @NameSpace: 		SuperChart
 * @Description: 	Class Described Methods and Attributes of AxisAttribute
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */
class AxisAttribute: public Attribute
{
public:
	/**
	 * @FuncName : AxisAttribute(int nMaxVlue, int nMinValue, int nAxisLength)
	 * @Description: Custom Constructor Function
	 * @param nAxisPosition : uint8 : Axis Position
	 * @param strTitle : string : Axis Title
	 * @param nMaxVlue : int : Maximum Value of Axis
	 * @param nMinValue : int : Minimum Value of Axis
	 * @param nTickValue : int : Single Tick Value of Axis
	 */
	AxisAttribute(uint8 nAxisPosition,
			string strTitle,
			int nMaxVlue,
			int nMinValue,
			int nTickValue);

	/**
	 * @FuncName: ~ChartAxis(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~AxisAttribute(void);

public:
	/**
	 * @FuncName : ResetAttribute(void)
	 * @Description: Reset Attribute
	 */
	void ResetAttribute(void);

	/**
	 * @FuncName : SetChartScale(int nMaxVlue, int nMinValue, int nAxisPixCnt)
	 * @Description: Set Values of Chart Scale
	 * @param nMaxValue : int : Maximum Value of Axis
	 * @param nMinValue : int : Minimum Value of Axis
	 * @param nAxisLength : int : Length of Axis, Used to Calculate Scale Value
	 */
	void ResetScale(int nMaxValue, int nMinValue, int nAxisLength);

	/**
	 * @FuncName : ResetTickValues(int nMaxValue, int nMinValue, int nTickValue)
	 * @Description: Set Axis Ticks Value
	 * @param nMaxValue : int : Maximum Value of Axis
	 * @param nMinValue : int : Minimum Value of Axis
	 * @param nTickValue : int : Every Single Tick Value in Axis
	 */
	void ResetTickValues(int nMaxValue, int nMinValue, int nTickValue);

	/**
	 * @FuncName : getPixCntViaScale(int nAxisPixelCount)
	 * @Description: Input Value, Output Position on Axis
	 * @param nValue : int : Value
	 * @return
	 */
	int getPositionViaScale(int nValue);



public:

	/**
	 * @FuncName: setAxisPosition(uint8 nAxisPosition)
	 * @Description: Set Axis Position Information
	 * @param nAxisPosition : uint8 : Axis Position Information
	 */
	void setAxisPosition(uint8 nAxisPosition);


	/**
	 * @FuncName : setTitle(const string& strTitle)
	 * @Description: Set Axis Title
	 * @param strTitle : string : Title of Axis
	 */
	void setTitle(const string& strTitle);

	/**
	 * @FuncName : setScaleValue(void)
	 * @Description: Calculate Scale Value
	 * @param dScaleValue : double : Scale Value
	 */
	void setScaleValue(void);

	/**
	 * @FuncName : setMaxValue(int nMaxValue)
	 * @Description: Set Maximum Value to nMaxValue
	 * @param dScaleValue : int : Scale Value
	 */
	void setMaxValue(int nMaxValue);

	/**
	 * @FuncName : setMinValue(int nMinValue)
	 * @Description: Set Minimum Value to nMinValue
	 * @param dScaleValue : int : Minimum Value
	 */
	void setMinValue(int nMinValue);

	/**
	 * @FuncName : setAxisLength(int nAxisLength)
	 * @Description: Set Axis Length to nAxisLength
	 * @param nAxisLength : int : Axis Length
	 */
	void setAxisLength(int nAxisLength);

	/**
	 * @FuncName : setTickValue(int nTickValue)
	 * @Description: Set Axis Single Tick Value
	 * @param nTickValue : int : Single Tick Value
	 */
	void setTickValue(int nTickValue);

	/**
	 * @FuncName: getAxisPosition(void)
	 * @Description: Get Axis Position Information
	 * @return uint8
	 */
	uint8 getAxisPosition(void) const;

	/**
	 * @FuncName : getTitle(void)
	 * @Description: Get Axis Title
	 * @return string
	 */
	const string& getTitle(void) const;

	/**
	 * @FuncName : getScaleValue(void)
	 * @Description: Get Scale Value
	 * @return double
	 */
	double getScaleValue(void) const;

	/**
	 * @FuncName : getMaxValue(void)
	 * @Description: Get Maximum Value
	 * @return int
	 */
	int getMaxValue(void) const;

	/**
	 * @FuncName : getMinValue(void)
	 * @Description: Get Minimum Value
	 * @return int
	 */
	int getMinValue(void) const;

	/**
	 * @FuncName : getAxisLength(void)
	 * @Description: Get Axis Length Value
	 * @return int
	 */
	int getAxisLength() const;

	/**
	 * @FuncName : getTickValue(void)
	 * @Description: Get Axis Single Tick Value
	 * @return int
	 */
	int getTickValue(void) const;

	/**
	 * @FuncName : getTickValues(void)
	 * @Description: Get Axis Ticks Value list
	 * @return list<int>
	 */
	list<int> getTickValues(void);

private:
	/**
	 * @field : m_nAxisPosition : uint8 : Axis Position Information
	 */
	uint8 m_nAxisPosition;

	/**
	 * @field : m_nAxisPosition : uint8 : Axis Position Information
	 */
	string m_strTitle;
	/**
	 * @field m_nMaxValue : int : Maximum Value of Axis
	 */
	int m_nMaxValue;

	/**
	 * @field m_nMaxValue : int : Minimum Value of Axis
	 */
	int m_nMinValue;

	/**
	 * @field m_nAxisLength : int : Length of Axis
	 */
	int m_nAxisLength;

	/**
	 * @field m_dScaleValue : double : Scale Value of Axis
	 */
	double m_dScaleValue;

	/**
	 * @field m_nTickValue : int : Value of Every Single Tick in Axis
	 */
	int m_nTickValue;

	/**
	 * @field m_ltTickValues : list<int> : Tick Value List of Axis
	 */
	list<int> m_ltTickValues;
};

} /* namespace SuperChart */

#endif /* AXES_AXISATTRIBUTE_H_ */