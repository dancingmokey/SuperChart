/**
 * @Title: 			ChartAxes.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

#include "ChartAxes.h"

namespace SuperChart
{

ChartAxes::ChartAxes()
{
	// TODO Auto-generated constructor stub
	m_pLeftAxis = new ChartAxis();
	m_pRightAxis = new ChartAxis();
	m_pTopAxis = new ChartAxis();
	m_pBottomAxis = new ChartAxis();
}


ChartAxes::ChartAxes(void)
{
	m_pLeftAxis = new ChartAxis();
	m_pRightAxis = new ChartAxis();
	m_pTopAxis = new ChartAxis();
	m_pBottomAxis = new ChartAxis();
}

ChartAxes::~ChartAxes(void)
{
	// TODO Auto-generated destructor stub
}

} /* namespace SuperChart */
