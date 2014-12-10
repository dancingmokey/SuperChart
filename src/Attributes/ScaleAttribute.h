/**
 * @Title: 			ScaleAttribute.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/09
 * @Version:		V1.0.0	
 */

#ifndef ATTRIBUTES_SCALEATTRIBUTE_H_
#define ATTRIBUTES_SCALEATTRIBUTE_H_

#include "../Attributes/Attribute.h"

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ScaleAttribute
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/09
 * @Version:		V1.0.0	
 */
class ScaleAttribute : public Attribute
{
public:
	/**
	 * @FuncName : Instance(string strTitle, double dMaxValue, double dMinValue, double dAxisLength)
	 * @Description: Get ScaleAttribute Instance
	 * @param strTitle : string : Scale Title
	 * @param dAxisValue : double : Value of Axis
	 * @param dAxisLength : double : Length of Axis
	 * @return
	 */
	static ScaleAttribute* Instance(string strTitle,
			double dMaxValue,
			double dMinValue,
			double dAxisLength);

	/**
	 * @FuncName : Instance(string strTitle, double dMaxValue, double dMinValue, double dAxisLength)
	 * @Description: Get ScaleAttribute Instance
	 */
	static ScaleAttribute* Instance(void);

	/**
	 * @FuncName : ~ScaleAttribute(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~ScaleAttribute(void);


private:
	/**
	 * @FuncName : ScaleAttribute(string strTitle, double dMaxValue, double dMinValue, double dAxisLength)
	 * @Description: Custom Constructor Function
	 * @param strTitle : string : Scale Title
	 * @param dAxisValue : double : Value of Axis
	 * @param dAxisLength : double : Length of Axis
	 */
	ScaleAttribute(string strTitle,
			double dMaxValue,
			double dMinValue,
			double dAxisLength);

	/**
	 * @FuncName : ScaleAttribute(void)
	 * @Description: Default Constructor Function
	 */
	ScaleAttribute(void);

	/**
	 * @field pScaleAttrInstance : ScaleAttribute* : Maximum Value of Axis
	 */
	static ScaleAttribute* pScaleAttrInstance;

public:
	/**
	 * @FuncName : UpdateAttribute(void)
	 * @Description: Update Attributes
	 */
	virtual void UpdateAttribute(void);

	/**
	 * @FuncName : UpdateScale(double dMaxValue, double dMinValue, double dAxisLength)
	 * @Description: Set Values of Chart Scale
	 * @param dMaxValue : double : Maximum Value of Axis
	 * @param dMinValue : double : Minimum Value of Axis
	 * @param dAxisLength : int : Length of Axis, Used to Calculate Scale Value
	 */
	void UpdateScale(double dMaxValue, double dMinValue, double dAxisLength);

	/**
	 * @FuncName : GetPositionByValue(double dValue)
	 * @Description: Input Value, Output Position on Axis
	 * @param dValue : double : Value
	 * @return double
	 */
	double GetPositionByValue(double dValue);

public:
	/**
	 * @FuncName : setAxisLength(double dAxisLength)
	 * @Description: Set Axis Length to nAxisLength
	 * @param dAxisLength : double : Axis Length
	 */
	void setAxisLength(double dAxisLength);

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
	 * @FuncName : setScaleValue(void)
	 * @Description: Set Scale Value
	 * @param dScaleValue : double : Scale Value
	 */
	void setScaleValue(double dScaleValue);

	/**
	 * @FuncName : getAxisLength(void)
	 * @Description: Get Axis Length Value
	 * @return double
	 */
	double getAxisLength() const;

	/**
	 * @FuncName : getMaxValue(void)
	 * @Description: Get Axis Maximum Value
	 * @return double
	 */
	double getMaxValue(void) const;

	/**
	 * @FuncName : getMinValue(void)
	 * @Description: Get Axis Minimum Value
	 * @return double
	 */
	double getMinValue(void) const;

	/**
	 * @FuncName : getScaleValue(void)
	 * @Description: Get Scale Value
	 * @return double
	 */
	double getScaleValue() const;

private:
	/**
	 * @field m_nMaxValue : double : Maximum Value of Axis
	 */
	double m_dMaxValue;

	/**
	 * @field m_nMaxValue : double : Minimum Value of Axis
	 */
	double m_dMinValue;

	/**
	 * @Field m_dAxisLength : double : Length of Axis
	 */
	double m_dAxisLength;

	/**
	 * @Field m_dScaleValue : double : Scale Value of Axis
	 */
	double m_dScaleValue;
};

} /* namespace SuperChart */

#endif /* ATTRIBUTES_SCALEATTRIBUTE_H_ */
