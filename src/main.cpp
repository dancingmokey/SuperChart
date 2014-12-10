/**
 * @Title: 			SuperChart.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include <stdlib.h>
#include <iostream>

#include <GeoRect.h>

#include "Chart/Chart.h"

using namespace std;
using namespace Geometry;
using namespace SuperChart;

void print_information(string strPrintTitle, ChartAxis* pAxis)
{
//	cout << "###################" << strPrintTitle << " Area#################################" << endl;
//	cout << "*************Axis Attribute Information**************" << endl;
//	ScaleAttribute* pAxisAttribute = dynamic_cast<ScaleAttribute*>(pAxis->getAttribute());
//
//	cout << "Title = " << pAxisAttribute->getTitle() << endl;
//
//	cout << "Maximum Value = " << pAxisAttribute->getMaxValue() << endl;
//	cout << "Minimum Value = " << pAxisAttribute->getMinValue() << endl;
//	cout << "Scale = " << pAxisAttribute->getScaleValue() << endl;
//	cout << "Tick Value = " << pAxisAttribute->getTickValue() << endl;
//
//	int nTempCnt = 0;
//	list<double> ltTickVals = pAxisAttribute->getTickValues();
//	for (list<double>::iterator it = ltTickVals.begin();
//			it != ltTickVals.end();
//			it++)
//	{
//		cout << "Tick ["
//			 << nTempCnt++
//			 << "] = "
//			 << *it
//			 << " Position = "
//			 << pAxisAttribute->getPositionViaScale(*it)
//			 << endl;
//	}
//
//	cout << "*************Axis Grids Information**************" << endl;
//	nTempCnt = 0;
//	list<ChartLine*> ltGrids = pAxis->m_pAxisGrid;
//	for (list<ChartLine*>::iterator it = ltGrids.begin();
//			it != ltGrids.end();
//			it++)
//	{
//		cout << "Grid ["
//			 << nTempCnt++
//			 << "] StartPoint("
//			 << (*it)->getStartPoint()->getX()
//			 << ","
//			 << (*it)->getStartPoint()->getY()
//			 << ") EndPoint("
//			 << (*it)->getEndPoint()->getX()
//			 << ","
//			 << (*it)->getEndPoint()->getY()
//			 << ") Length = "
//			 << (*it)->getLength()
//			 << endl;
//	}
//
//	cout << "*************Axis Ticks Information**************" << endl;
//	nTempCnt = 0;
//	list<ChartLine*> ltTicks = pAxis->m_pAxisTicks;
//	for (list<ChartLine*>::iterator it = ltTicks.begin();
//			it != ltTicks.end();
//			it++)
//	{
//		cout << "Tick ["
//			 << nTempCnt++
//			 << "] StartPoint("
//			 << (*it)->getStartPoint()->getX()
//			 << ","
//			 << (*it)->getStartPoint()->getY()
//			 << ") EndPoint("
//			 << (*it)->getEndPoint()->getX()
//			 << ","
//			 << (*it)->getEndPoint()->getY()
//			 << ") Length = "
//			 << (*it)->getLength()
//			 << endl;
//	}
//
//	cout << "*************Axis Labels Information**************" << endl;
//	nTempCnt = 0;
//	list<ChartText*> ltLabels = pAxis->m_pAxisLabels;
//	for (list<ChartText*>::iterator it = ltLabels.begin();
//			it != ltLabels.end();
//			it++)
//	{
//		cout << "Label ["
//			 << nTempCnt++
//			 << "] TopLeftPoint("
//			 << (*it)->getBoundRect()->getTopLeftPoint()->getX()
//			 << ","
//			 << (*it)->getBoundRect()->getTopLeftPoint()->getY()
//			 << ") BottomRightPoint("
//			 << (*it)->getBoundRect()->getBottomRightPoint()->getX()
//			 << ","
//			 << (*it)->getBoundRect()->getBottomRightPoint()->getY()
//			 << ") Value = "
//			 << (*it)->getText()
//			 << endl;
//	}
//	cout << "###################" << strPrintTitle << " Area#################################" << endl;
//

}

void AddData(double* pDataList, int nCount)
{
	for (int i = 0; i < nCount; ++i)
	{
		cout << "Double Value [" << i << "] = " << *pDataList << endl;
		pDataList++;
	}
}


int main(int argc, char** argv)
{
	/** */
	Chart* pChart = new Chart("Test Chart",
			1000,
			0,
			50,
			25.5f,
			0.0f,
			0.5);


	cout << "Chart Created!" << endl;


	delete pChart;

	cout << "Chart Destroyed!" << endl;

	return 0;
}

