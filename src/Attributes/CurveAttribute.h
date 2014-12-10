/**
 * @Title: 			CurveAttribute.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/09
 * @Version:		V1.0.0	
 */
#ifndef ATTRIBUTES_CURVEATTRIBUTE_H_
#define ATTRIBUTES_CURVEATTRIBUTE_H_

#include "../Attributes/Attribute.h"
#include <list>

using namespace std;

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::CurveAttribute
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/09
 * @Version:		V1.0.0	
 */
class CurveAttribute : public Attribute
{
public:
	/**
	 * @FuncName : CurveAttribute(int nMaxPointperPage)
	 * @Description: Custom Constructor Function
	 * @param strTitle : string : Attribute Title
	 * @param nMaxPointperPage : int : Maximum Point Count per Page
	 */
	CurveAttribute(string strTitle, int nMaxPointperPage);

	/**
	 * @FuncName : CurveAttribute(void)
	 * @Description: Default Constructor Function
	 */
	CurveAttribute(void);

	/**
	 * @FuncName : ~CurveAttribute(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~CurveAttribute();

public:
	/**
	 * @FuncName : UpdateAttribute(void)
	 * @Description: Update Attribute
	 */
	void UpdateAttribute(void);

	/**
	 * @FuncName : ResizeData(void)
	 * @Description: Resize Data Value List
	 */
	void ResizeData(void);

	/**
	 * @FuncName : AddData(double dXValue, double dYValue)
	 * @Description: Add Data into Value List
	 * @param dXValue : double : Horizontal Value
	 * @param dYValue : double : Vertical Value
	 */
	void AddData(double dXValue, double dYValue);

	/**
	 * @FuncName : AddData(double* pXValueList, double* pYValueList, int nCount)
	 * @Description: Add Data into Value List
	 * @param pXValueList : double* : Horizontal Value Array
	 * @param pYValueList : double* : Vertical Value Array
	 * @param nCount : int :  Count of Elements in Value Array
	 */
	void AddData(double* pXValueList, double* pYValueList, int nCount);

	/**
	 * @FuncName : ClearData()
	 * @Description: Clear Data into Value List
	 */
	void ClearData(void);

public:
	/**
	 * @FuncName : setMaxPointPerPage(int nMaxPointPerPage)
	 * @Description: Set Maximum Point Per Page
	 * @param nMaxPointPerPage : int : Maximum Point Per Page
	 */
	void setMaxPointPerPage(int nMaxPointPerPage);

	/**
	 * @FuncName : getMaxPointPerPage(void)
	 * @Description: Get Maximum Point Per Page
	 * @return int
	 */
	int getMaxPointPerPage(void);

	/**
	 * @FuncName : getHorizontalVal(void)
	 * @Description: Get Horizontal Data Value List
	 * @return list<double>
	 */
	list<double> getHorizontalVal(void);

	/**
	 * @FuncName : getVerticalVal(void)
	 * @Description: Get Vertical Data Value List
	 * @return list<double>
	 */
	list<double> getVerticalVal(void);



private:
	/**
	 * @field m_nMaxPointPerPage : int : Max Point per Page of Axis
	 */
	int m_nMaxPointPerPage;

	/**
	 * @field m_ltHorValues : list<double> : Horizontal Value List of Axis
	 */
	list<double> m_ltHorizontalVal;
	/**
	 * @field m_ltHorValues : list<double> : Vertical Value List of Axis
	 */
	list<double> m_ltVerticalVal;

};

} /* namespace SuperChart */

#endif /* ATTRIBUTES_CURVEATTRIBUTE_H_ */
