/**
 * @Title: 			ChartAxis.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTAXIS_H_
#define CHARTAXIS_H_

#include "ChartElement.h"
#include "ChartLine.h"
#include "ChartTick.h"

#include <GeoRect.h>
#include <GeoPoint.h>

#include <list>

using namespace std;

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartAxis
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

class ChartAxis: public ChartElement
{
public:
	ChartAxis(GeoRect* pBoundRect, string strTitle, int nMaxValue, int nMinValue, int nTickValue);
	ChartAxis();
	virtual ~ChartAxis();


private:
	int m_nMaxValue;
	int m_nMinValue;
	int m_nTickValue;

private:
	ChartLine* m_pAxisLine;
	ChartText* m_pAxisTitle;
	list<ChartTick*> m_pAxisTicks;
	list<ChartLine*> m_pAxisGrid;


};

} /* namespace SuperChart */

#endif /* CHARTAXIS_H_ */
