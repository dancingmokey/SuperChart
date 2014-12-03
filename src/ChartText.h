/**
 * @Title: 			ChartText.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTTEXT_H_
#define CHARTTEXT_H_

#include <string>
#include "Global.h"
#include "ChartElement.h"
#include "ChartTextStyle.h"

using namespace std;

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartText
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

class ChartText : public ChartElement
{
public:
	ChartText(GeoRect* pBoundRect, string strText, ChartTextStyle vTextStyle);
	ChartText();
	virtual ~ChartText();
public:
	const string& getText() const;
	void setText(const string& strText);
	const ChartTextStyle& getTextStyle() const;
	void setTextStyle(const ChartTextStyle& vTextStyle);

private:
	/**
	 * @Field : m_strText : Text Content
	 */
	string m_strText;
	/**
	 * @Field :  : Text Content
	 */
	ChartTextStyle m_vTextStyle;
};

} /* namespace SuperChart */

#endif /* CHARTTEXT_H_ */
