/**
 * @Title: 			CurveAttribute.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/09
 * @Version:		V1.0.0	
 */

#include "CurveAttribute.h"

namespace SuperChart
{

/**
 * @FuncName : CurveAttribute(int nMaxPointperPage)
 * @Description: Custom Constructor Function
 * @param strTitle : string : Attribute Title
 * @param nMaxPointperPage : int : Maximum Point Count per Page
 */
CurveAttribute::CurveAttribute(string strTitle,
				int nMaxPointperPage) :
				m_nMaxPointPerPage(0)
{
	// TODO Auto-generated constructor stub
	this->setTitle(strTitle);
	this->setMaxPointPerPage(nMaxPointperPage);
}
/**
 * @FuncName : CurveAttribute(void)
 * @Description: Default Constructor Function
 */
CurveAttribute::CurveAttribute() :
				m_nMaxPointPerPage(0)
{
	// TODO Auto-generated constructor stub
}

/**
 * @FuncName : ~CurveAttribute(void)
 * @Description: Default Destructor Function
 */
CurveAttribute::~CurveAttribute()
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName : UpdateAttribute(void)
 * @Description: Update Attribute
 */
void CurveAttribute::UpdateAttribute(void)
{
	this->ResizeData();
}

/**
 * @FuncName : ResizeData(void)
 * @Description: Resize Data Value List
 */
void CurveAttribute::ResizeData(void)
{
	if (m_ltHorizontalVal.size() > m_nMaxPointPerPage)
	{
		int nDiff = m_ltHorizontalVal.size() - m_nMaxPointPerPage;

		for (int i = 0; i < nDiff; ++i)
		{
			m_ltHorizontalVal.pop_front();
			m_ltVerticalVal.pop_front();
		}
	}
}

/**
 * @FuncName : AddData(double dXValue, double dYValue)
 * @Description: Add Data into Value List
 * @param dXValue : double : Horizontal Value
 * @param dYValue : double : Vertical Value
 */
void CurveAttribute::AddData(double dXValue, double dYValue)
{
	m_ltHorizontalVal.push_back(dXValue);
	m_ltVerticalVal.push_back(dYValue);

	this->ResizeData();
}

/**
 * @FuncName : AddData(double* pXValueList, double* pYValueList, int nCount)
 * @Description: Add Datas into Value List
 * @param pXValueList : double* : Horizontal Value Array
 * @param pYValueList : double* : Vertical Value Array
 * @param nCount : int :  Count of Elements in Value Array
 */
void CurveAttribute::AddData(double* pXValueList, double* pYValueList, int nCount)
{
	for (int i = 0; i < nCount; ++i)
	{
		m_ltHorizontalVal.push_back(pXValueList[i]);
		m_ltVerticalVal.push_back(pYValueList[i]);
	}

	this->ResizeData();
}

/**
 * @FuncName : ClearData()
 * @Description: Clear Data into Value List
 */
void CurveAttribute::ClearData(void)
{
	m_ltHorizontalVal.clear();
	m_ltVerticalVal.clear();
}

/**
 * @FuncName : setMaxPointPerPage(int nMaxPointPerPage)
 * @Description: Set Maximum Point Per Page
 * @param nMaxPointPerPage : int : Maximum Point Per Page
 */
void CurveAttribute::setMaxPointPerPage(int nMaxPointPerPage)
{
	m_nMaxPointPerPage = nMaxPointPerPage;

	ResizeData();
}

/**
 * @FuncName : getMaxPointPerPage(void)
 * @Description: Get Maximum Point Per Page
 * @return int
 */
int CurveAttribute::getMaxPointPerPage(void)
{
	return m_nMaxPointPerPage;
}

/**
 * @FuncName : getHorizontalVal(void)
 * @Description: Get Horizontal Data Value List
 * @return list<double>
 */
list<double> CurveAttribute::getHorizontalVal(void)
{
	return m_ltHorizontalVal;
}

/**
 * @FuncName : getVerticalVal(void)
 * @Description: Get Vertical Data Value List
 * @return list<double>
 */
list<double> CurveAttribute::getVerticalVal(void)
{
	return m_ltVerticalVal;
}

} /* namespace SuperChart */
