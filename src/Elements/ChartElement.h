/**
 * @Title: 			ChartElement.h
 * @Package 		SuperChart
 * @Description: 	Define Class SuperChart::ChartElement
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */
#ifndef CHARTELEMENT_H_
#define CHARTELEMENT_H_

#include <stdlib.h>
#include <GeoRect.h>

#include "../Styles/ChartStyle.h"
#include "../Attributes/Attribute.h"

using namespace Geometry;

namespace SuperChart
{

/**
 * @ClassName: 		Geometry::ChartElement
 * @NameSpace: 		SuperChart
 * @Description: 	Base Abstract Class of All Elements in Chart
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */
class ChartElement
{
public:
	/**
	 * @FuncName: ChartElement(void)
	 * @Description: Custom Constructor Function
	 * @param pBoundRect : GeoRect* : Bound Rectangle of Element
	 * @param pAttribute : Attribute* : Attribute of Element
	 * @param pStyle : ChartStyle* : Style of Element
	 */
	ChartElement(GeoRect* pBoundRect, Attribute* pAttribute, ChartStyle* pStyle);

	/**
	 * @FuncName: ChartElement(void)
	 * @Description: Default Constructor Function
	 */
	ChartElement(void);

	/**
	 * @FuncName: ~ChartElement(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~ChartElement(void);

public:

	/**
	 * @FuncName: setBoundRect(GeoRect* pBoundRect)
	 * @Description: Set Bound Rectangle of Element
	 * @param pBoundRect : GeoRect* : Bound Rectangle of Element
	 */
	void setBoundRect(GeoRect* pBoundRect);

	/**
	 * @FuncName: setStyle(ChartStyle* pStyle)
	 * @Description: Set Style of Element
	 * @param pStyle : ChartStyle* : Style of Element
	 */
	void setStyle(ChartStyle* pStyle);

	/**
	 * @FuncName: setAttribute(void)
	 * @Description: Set Attribute of Element
	 * @param pAttribute : Attribute* : Attribute of Element
	 */
	void setAttribute(Attribute* pAttribute);

	/**
	 * @FuncName: getBoundRect(void)
	 * @Description: Get Bound Rectangle of Element
	 * @return Pointer to GeoRect Object
	 */
	GeoRect* getBoundRect(void);

	/**
	 * @FuncName: getStyle(void)
	 * @Description: Get Style of Element
	 * @return Pointer to ChartStyle Object
	 */
	ChartStyle* getStyle(void);

	/**
	 * @FuncName: getAttribute(void)
	 * @Description: Get Attribute of Element
	 * @return
	 */
	Attribute* getAttribute(void);

private:
	/**
	 * @Field : m_pBoundRect : Bound Rectangle of Element
	 */
	GeoRect* m_pBoundRect;

	/**
	 * @Field : m_bIsVisible : Is Element Visible or Not
	 */
	ChartStyle* m_pStyle;

	/**
	 * @Field : m_pAttribute : Attribute of Element
	 */
	Attribute* m_pAttribute;
};

} /* namespace Geometry */

#endif /* CHARTELEMENT_H_ */
