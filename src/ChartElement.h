/**
 * @Title: 			ChartElement.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTELEMENT_H_
#define CHARTELEMENT_H_

#include <stdlib.h>
#include <GeoRect.h>

using namespace Geometry;

namespace SuperChart
{

/**
 * @ClassName: 		Geometry::ChartElement
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

class ChartElement
{
public:
	ChartElement();
	virtual ~ChartElement();
	bool isVisible() const;
	void setVisible(bool bIsVisible);
	GeoRect* getBoundRect();
	void setBoundRect(GeoRect* pBoundRect);

private:
	/**
	 * @Field : m_pBoundRect : Bound Rectangle
	 */
	GeoRect* m_pBoundRect;
	/**
	 * @Field : m_bIsVisible : Is Element Visible
	 */
	bool m_bIsVisible;

};

} /* namespace Geometry */

#endif /* CHARTELEMENT_H_ */
