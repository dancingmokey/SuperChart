/**
 * @Title: 			ChartText.h
 * @Package 		SuperChart
 * @Description: 	Define Class SuperChart::ChartText
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTTEXT_H_
#define CHARTTEXT_H_

#include <string>
#include <GeoRect.h>
#include "../Common/Global.h"
#include "ChartElement.h"
#include "../Styles/ChartStyle.h"

using namespace std;

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartText
 * @NameSpace: 		SuperChart
 * @Description: 	Class Described Methods and Attributes of Chart Text
 * @Parent:			ChartElement
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */
class ChartText : public ChartElement
{
public:
	/**
	 * @FuncName: ChartText(GeoRect* pBoundRect, string strText, ChartStyle* pStyle, bool bIsVisible)
	 * @Description: Custom Constructor Function
	 * @param pBoundRect : GeoRect* : Text Bound Rectangle
	 * @param pStyle : ChartStyle* : Text Style
	 * @param strText : string : Text String
	 */
	ChartText(GeoRect* pBoundRect, ChartStyle* pStyle, string strText);

	/**
	 * @FuncName: ChartText(void)
	 * @Description: Default Constructor Function
	 */
	ChartText(void);

	/**
	 * @FuncName: ~ChartText(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~ChartText(void);

public:
	/**
	 * @FuncName: setText(const string& strText)
	 * @Description: Set Text String
	 * @param strText : string : Text String
	 */
	void setText(const string& strText);

	/**
	 * @FuncName: getText(void)
	 * @Description: Get Text String
	 * @return string
	 */
	const string& getText(void) const;

private:
	/**
	 * @Field : m_strText : Text Content
	 */
	string m_strText;
};

} /* namespace SuperChart */

#endif /* CHARTTEXT_H_ */
