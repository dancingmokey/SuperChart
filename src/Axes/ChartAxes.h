/**
 * @Title: 			ChartAxes.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

#ifndef AXES_CHARTAXES_H_
#define AXES_CHARTAXES_H_

#include "ChartAxis.h"

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartAxes
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

class ChartAxes
{
public:
	ChartAxes();
	virtual ~ChartAxes();



public:
	/**
	 *  @field : m_pLeftAxis : ChartAxis* : Left Axis
	 */
	ChartAxis* m_pLeftAxis;

	/**
	 *  @field : m_pRightAxis : ChartAxis* : Right Axis
	 */
	ChartAxis* m_pRightAxis;

	/**
	 *  @field : m_pTopAxis : ChartAxis* : Top Axis
	 */
	ChartAxis* m_pTopAxis;

	/**
	 *  @field : m_pBottomAxis : ChartAxis* : Bottom Axis
	 */
	ChartAxis* m_pBottomAxis;
};

} /* namespace SuperChart */

#endif /* AXES_CHARTAXES_H_ */
