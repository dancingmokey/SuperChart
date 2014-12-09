/**
 * @Title: 			SerialAttribute.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/08
 * @Version:		V1.0.0	
 */

#ifndef ATTRIBUTES_SERIALATTRIBUTE_H_
#define ATTRIBUTES_SERIALATTRIBUTE_H_

#include "Attribute.h"
#include "ScaleAttribute.h"
#include <list>
#include <string>
#include <GeoPoint.h>

using namespace std;
using namespace Geometry;

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::SerialAttribute
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/08
 * @Version:		V1.0.0	
 */
class SerialAttribute: public Attribute
{
public:
	/**
	 *
	 * @param strTitle
	 * @param dScale
	 * @param nMaxValue
	 * @param nMinValue
	 * @param nMaxPointPerPage
	 */
	SerialAttribute(string strTitle,
			ScaleAttribute* pXScaleAttrs,
			ScaleAttribute* pYScaleAttrs);

	/**
	 *
	 */
	virtual ~SerialAttribute();

public:
	/**
	 * @FuncName : ResetAttribute(void)
	 * @Description: Reset Attribute
	 */
	void ResetAttribute(void);

	/**
	 *
	 * @param dData
	 */
	void AddData(double dXValue, double dYValue);

	/**
	 *
	 * @param pDataList
	 * @param nCount
	 */
	void AddData(double* pXValueList, double* pYValueList, int nCount);

	/**
	 *
	 */
	void ResizeData(void);

public:
	/**
	 *
	 * @param strTitle
	 */
	void setTitle(const string& strTitle);

	/**
	 *
	 * @return
	 */
	const string& getTitle(void) const;

	/**
	 *
	 */
	list<int> GetXPosition(void);

	/**
	 *
	 */
	list<int> GetYPosition(void);
private:
	/**
	 * @field : m_strTitle : string : Serial Title
	 */
	string m_strTitle;

	ScaleAttribute* m_pXScaleAttrs;
	ScaleAttribute* m_pYScaleAttrs;

	/**
	 * @field : m_ltData : list<double> : Serial Title
	 */
	list<double> m_ltXValues;
	list<double> m_ltYValues;
	list<int> m_ltXPositions;
	list<int> m_ltYPositions;
};

} /* namespace SuperChart */

#endif /* ATTRIBUTES_SERIALATTRIBUTE_H_ */
