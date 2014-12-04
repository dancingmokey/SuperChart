/**
 * @Title: 			ChartStyle.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

#ifndef STYLES_CHARTSTYLE_H_
#define STYLES_CHARTSTYLE_H_

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartStyle
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

class ChartStyle
{
public:
	ChartStyle();
	virtual ~ChartStyle();

public:
	/**
	 * @FuncName: setVisible(bool bIsVisible)
	 * @Description: Set Element Visible or Not
	 * @param bIsVisible : bool : Visible Attibute Value
	 */
	void setVisible(bool bIsVisible);

	/**
	 * @FuncName: isVisible(void)
	 * @Description: Get Element is Visible or Not
	 * @return bool
	 */
	bool isVisible(void) const;

private:
	/**
	 * @Field : m_bIsVisible : Is Element Visible
	 */
	bool m_bIsVisible;
};

} /* namespace SuperChart */

#endif /* STYLES_CHARTSTYLE_H_ */
