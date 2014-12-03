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

#include "ChartStyles.h"

using namespace std;
using namespace Geometry;
using namespace SuperChart;


int main(int argc, char** argv)
{
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

	ChartStyles::Chart_Text_Style1 = ChartTextStyle(0x01, 0x01, 0x01);

	return 0;
}

