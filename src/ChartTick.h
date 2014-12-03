/**
 * @Title: 			ChartTick.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTTICK_H_
#define CHARTTICK_H_

#include "ChartElement.h"
#include "ChartLine.h"
#include "ChartText.h"

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartTick
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

class ChartTick: public ChartElement
{
public:
	ChartTick();
	virtual ~ChartTick();


private:
	ChartLine* m_pTickLine;
	ChartText* m_pTickText;
};

} /* namespace SuperChart */

#endif /* CHARTTICKS_H_ */
