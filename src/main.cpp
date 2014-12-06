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

#include "Elements/ChartElement.h"
#include "Attributes/Attribute.h"
#include "Attributes/AxisAttribute.h"
#include "Panel/ChartPanel.h"
#include "Styles/ChartStyles.h"
#include "Styles/ChartStyle.h"

using namespace std;
using namespace Geometry;
using namespace SuperChart;

void print_information(string strPrintTitle, ChartAxis* pAxis)
{
	cout << "###################" << strPrintTitle << " Area#################################" << endl;
	cout << "*************Axis Attribute Information**************" << endl;
	AxisAttribute* pAxisAttribute = dynamic_cast<AxisAttribute*>(pAxis->getAttribute());

	cout << "Title = " << pAxisAttribute->getTitle() << endl;

	cout << "Maximum Value = " << pAxisAttribute->getMaxValue() << endl;
	cout << "Minimum Value = " << pAxisAttribute->getMinValue() << endl;
	cout << "Scale = " << pAxisAttribute->getScaleValue() << endl;
	cout << "Tick Value = " << pAxisAttribute->getTickValue() << endl;

	int nTempCnt = 0;
	list<int> ltTickVals = pAxisAttribute->getTickValues();
	for (list<int>::iterator it = ltTickVals.begin();
			it != ltTickVals.end();
			it++)
	{
		cout << "Tick ["
			 << nTempCnt++
			 << "] = "
			 << *it
			 << " Position = "
			 << pAxisAttribute->getPositionViaScale(*it)
			 << endl;
	}

	cout << "*************Axis Grids Information**************" << endl;
	nTempCnt = 0;
	list<ChartLine*> ltGrids = pAxis->m_pAxisGrid;
	for (list<ChartLine*>::iterator it = ltGrids.begin();
			it != ltGrids.end();
			it++)
	{
		cout << "Grid ["
			 << nTempCnt++
			 << "] StartPoint("
			 << (*it)->getStartPoint()->getX()
			 << ","
			 << (*it)->getStartPoint()->getY()
			 << ") EndPoint("
			 << (*it)->getEndPoint()->getX()
			 << ","
			 << (*it)->getEndPoint()->getY()
			 << ") Length = "
			 << (*it)->getLength()
			 << endl;
	}

	cout << "*************Axis Ticks Information**************" << endl;
	nTempCnt = 0;
	list<ChartLine*> ltTicks = pAxis->m_pAxisTicks;
	for (list<ChartLine*>::iterator it = ltTicks.begin();
			it != ltTicks.end();
			it++)
	{
		cout << "Tick ["
			 << nTempCnt++
			 << "] StartPoint("
			 << (*it)->getStartPoint()->getX()
			 << ","
			 << (*it)->getStartPoint()->getY()
			 << ") EndPoint("
			 << (*it)->getEndPoint()->getX()
			 << ","
			 << (*it)->getEndPoint()->getY()
			 << ") Length = "
			 << (*it)->getLength()
			 << endl;
	}

	cout << "*************Axis Labels Information**************" << endl;
	nTempCnt = 0;
	list<ChartText*> ltLabels = pAxis->m_pAxisLabels;
	for (list<ChartText*>::iterator it = ltLabels.begin();
			it != ltLabels.end();
			it++)
	{
		cout << "Label ["
			 << nTempCnt++
			 << "] TopLeftPoint("
			 << (*it)->getBoundRect()->getTopLeftPoint()->getX()
			 << ","
			 << (*it)->getBoundRect()->getTopLeftPoint()->getY()
			 << ") BottomRightPoint("
			 << (*it)->getBoundRect()->getBottomRightPoint()->getX()
			 << ","
			 << (*it)->getBoundRect()->getBottomRightPoint()->getY()
			 << ") Value = "
			 << (*it)->getText()
			 << endl;
	}
	cout << "###################" << strPrintTitle << " Area#################################" << endl;


}


int main(int argc, char** argv)
{
	ChartStyles* pChartStyles = new ChartStyles();
	pChartStyles->LoadChartStyles(string("styles.xml"));

	map<string, ChartStyle*> mpChartStyles = pChartStyles->getChartStyles();
	for (map<string, ChartStyle*>::const_iterator ite = mpChartStyles.begin();
			ite != mpChartStyles.end();
			++ite)
	{
		string strName = ite->first;
		ChartStyle* pChartStyle = ite->second;

		cout << "*************Start**************" << endl;
		cout << "Name = " << strName << endl;
		cout << "Visible = " << ((pChartStyle->isVisible() == true) ? "true" : "false") << endl;
		cout << "Color = " << hex << pChartStyle->getColor() << endl;
		cout << "Type = " << pChartStyle->getType() << endl;
		cout << "Size = " << pChartStyle->getSize() << endl;
		cout << "*************End**************" << endl;

		cout.unsetf(ios::hex);
	}






	GeoRect* pChartRect = new GeoRect(0, 0, 1200, 600);

	AxisAttribute* pXAxisAttrs = new AxisAttribute(Global::Axis_Bottom,
			"Test Child",
			1200,
			0,
			50);

	AxisAttribute* pYAxisAttrs = new AxisAttribute(Global::Axis_Bottom,
			"Test Child",
			600,
			0,
			100);

	ChartPanel* pPanel = new ChartPanel(pChartRect, pXAxisAttrs, pYAxisAttrs, pChartStyles);


	print_information("X Axis", pPanel->m_pXAxis);
	print_information("Y Axis", pPanel->m_pYAxis);

	AxisAttribute* pTempX = dynamic_cast<AxisAttribute*>(pPanel->m_pXAxis->getAttribute());
	pTempX->setMaxValue(1300);
	pTempX->setMinValue(100);
	pPanel->m_pXAxis->ResetChartAxis();
	print_information("X Axis After Modify", pPanel->m_pXAxis);

	AxisAttribute* pTempY = dynamic_cast<AxisAttribute*>(pPanel->m_pYAxis->getAttribute());
	pTempY->setMaxValue(1240);
	pTempY->setMinValue(740);
	pPanel->m_pYAxis->ResetChartAxis();
	print_information("Y Axis After Modify", pPanel->m_pYAxis);








//	Attribute* pParent = new Attribute();
//	AxisAttribute* pChind = new AxisAttribute(Global::Axis_Bottom,
//			"Test Child",
//			1200,
//			0,
//			50);
//
//
//	pParent = dynamic_cast<Attribute*>(pChind);
//
//	AxisAttribute* pTemp = dynamic_cast<AxisAttribute*>(pParent);
//
//	if (pTemp == NULL)
//	{
//		cout << "Temp Pointer is NULL!" << endl;
//	}
//	else
//	{
//		cout << "Title = " << pTemp->getTitle() << endl;
//		cout << "Max Value = " << pTemp->getMaxValue() << endl;
//		cout << "Min Value = " << pTemp->getMinValue() << endl;
//		cout << "Tick Value = " << pTemp->getTickValue() << endl;
//		cout << "Scale = " << pTemp->getScaleValue() << endl;
//
//		pTemp->setAxisLength(120);
//		list<int> ltTickVals = pTemp->getTickValues();
//
//		cout << "Title = " << pTemp->getTitle() << endl;
//		cout << "Max Value = " << pTemp->getMaxValue() << endl;
//		cout << "Min Value = " << pTemp->getMinValue() << endl;
//		cout << "Tick Value = " << pTemp->getTickValue() << endl;
//		cout << "Scale = " << pTemp->getScaleValue() << endl;
//		for (list<int>::iterator it = ltTickVals.begin();
//				it != ltTickVals.end();
//				it++)
//		{
//			cout << "Single Tick = " << *it
//					<< " Position = " << pTemp->getPositionViaScale(*it)
//					<< endl;
//		}
//	}


	/**
	 *
	 * @param pBoundRect
	 * @param strTitle
	 * @param pTitleStyle
	 * @param nXAxisPosition
	 * @param strXAxisTitle
	 * @param nXAxisMaxVal
	 * @param nXAxisMinVal
	 * @param nXAxisTickVal
	 * @param pXAxisStyles
	 * @param nYAxisPosition
	 * @param strYAxisTitle
	 * @param nYAxisMaxVal
	 * @param nYAxisMinVal
	 * @param nYAxisTickVal
	 * @param pYAxisStyles
	 */
//	ChartPanel* pPanel = new ChartPanel(new GeoRect(0, 0, 1200, 600),
//			"Test Chart",
//			NULL,
//			Global::Axis_Bottom,
//			"X-Axis(ms)",
//			12000,
//			0,
//			1000,
//			NULL,
//			Global::Axis_Left,
//			"Y-Axis(ms)",
//			255,
//			0,
//			25,
//			NULL);
//
//
//
//	cout << "**** Chart Attributes ****" << endl;





//	GeoRect* pNewRect = new GeoRect(12, 12, 120, 120);
//
//	cout << "Super Chart Rectangle Width = " << pNewRect->getSize()->getWidth()
//		 <<	" Height = "<<  pNewRect->getSize()->getHeight()
//		 << " Top-Left Point (" << pNewRect->getTopLeftPoint()->getX()
//		 << "," << pNewRect->getTopLeftPoint()->getY()
//		 << ")" << endl;
//
//	pNewRect->setTopLeftPoint(new GeoPoint(23, 45));
//	pNewRect->setSize(new GeoSize(37, 68));
//
//	cout << "Super Chart Rectangle Width = " << pNewRect->getSize()->getWidth()
//		 <<	" Height = "<<  pNewRect->getSize()->getHeight()
//		 << " Top-Left Point (" << pNewRect->getTopLeftPoint()->getX()
//		 << "," << pNewRect->getTopLeftPoint()->getY()
//		 << ")" << endl;
//
//	GeoRect* pNewRect1 = pNewRect;
//
//	cout << "Super Chart Rectangle Width = " << pNewRect1->getSize()->getWidth()
//		 <<	" Height = "<<  pNewRect1->getSize()->getHeight()
//		 << " Top-Left Point (" << pNewRect1->getTopLeftPoint()->getX()
//		 << "," << pNewRect1->getTopLeftPoint()->getY()
//		 << ")" << endl;
//
//	delete pNewRect1;

	return 0;
}

