/**
 * @Title: 			Chart.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/10
 * @Version:		V1.0.0	
 */

#include "Chart.h"

namespace SuperChart
{

Chart::Chart(string strTitle,
		double dXManValue,
		double dXMinValue,
		double dXTickValue,
		double dYMaxValue,
		double dYMinValue,
		double dYTickValue)
{
	// TODO Auto-generated constructor stub

}

Chart::Chart()
{
	// TODO Auto-generated destructor stub
}

Chart::~Chart()
{
	// TODO Auto-generated destructor stub
}

void Chart::UpdateChartPanel(string strPanelTitle)
{
	m_pChartPanel->getPanelTitle()->setText(strPanelTitle);
}

void Chart::UpdateXScaleAttrs(double dMaxValule, double dMinValue, double dAxisLength)
{
	this->m_pXScaleAttrs->UpdateScale(dMaxValule, dMinValue, m_pXAxis->m_pAxisLine->getLength());
}

void Chart::UpdateYScaleAttrs(double dMaxValule, double dMinValue, double dAxisLength)
{
	this->m_pYScaleAttrs->UpdateScale(dMaxValule, dMinValue, m_pYAxis->m_pAxisLine->getLength());
}

void Chart::UpdateXAxisAttrs(double dMaxValule, double dMinValue, double dTickValue, double dScaleValue)
{
	this->m_pXAxisAttrs->UpdateTickValues(dMaxValule, dMinValue, dTickValue, m_pXScaleAttrs->getScaleValue());
}

void Chart::UpdateYAxisAttrs(double dMaxValule, double dMinValue, double dTickValue, double dScaleValue)
{
	this->m_pYAxisAttrs->UpdateTickValues(dMaxValule, dMinValue, dTickValue, m_pYScaleAttrs->getScaleValue());
}

void Chart::AddSerialData(string strSerialTitle, double dXValue, double dYValue)
{
	map<string, Attribute*>::iterator it = m_mpSerialAttrs.find(strSerialTitle);
	if (it != m_mpSerialAttrs.end())
	{
		Attribute* pAttribute = it->second;
		if (pAttribute != NULL)
		{
			(dynamic_cast<CurveAttribute*>(pAttribute))->AddData(dXValue, dYValue);
		}
	}
}

void Chart::AddSerialData(string strSerialTitle, double* pXValueList, double* pYValueList, int nCount)
{
	map<string, Attribute*>::iterator it = m_mpSerialAttrs.find(strSerialTitle);
	if (it != m_mpSerialAttrs.end())
	{
		Attribute* pAttribute = it->second;
		if (pAttribute != NULL)
		{
			(dynamic_cast<CurveAttribute*>(pAttribute))->AddData(pXValueList, pYValueList, nCount);
		}
	}
}

void Chart::ClearSerialData(string strSerialTitle)
{
	map<string, Attribute*>::iterator it = m_mpSerialAttrs.find(strSerialTitle);
	if (it != m_mpSerialAttrs.end())
	{
		Attribute* pAttribute = it->second;
		if (pAttribute != NULL)
		{
			(dynamic_cast<CurveAttribute*>(pAttribute))->ClearData();
		}
	}
}

void Chart::setChartPanel(ChartPanel* pChartPanel)
{
	m_pChartPanel = pChartPanel;
}

void Chart::setXScaleAttrs(ScaleAttribute* pXScaleAttrs)
{
	m_pXScaleAttrs = pXScaleAttrs;
}

void Chart::setYScaleAttrs(ScaleAttribute* pYScaleAttrs)
{
	m_pYScaleAttrs = pYScaleAttrs;
}

void Chart::setXAxis(ChartAxis* pXAxis)
{
	m_pXAxis = pXAxis;
}

void Chart::setXAxisAttrs(AxisAttribute* pXAxisAttrs)
{
	m_pXAxisAttrs = pXAxisAttrs;
}

void Chart::setYAxis(ChartAxis* pYAxis)
{
	m_pYAxis = pYAxis;
}

void Chart::setYAxisAttrs(AxisAttribute* pYAxisAttrs)
{
	m_pYAxisAttrs = pYAxisAttrs;
}

void Chart::setSerials(map<string, ChartCurve*> mpSerials)
{
	m_mpSerials = mpSerials;
}

void Chart::setSerialAttrs(map<string, Attribute*> mpSerialAttrs)
{
	m_mpSerialAttrs = mpSerialAttrs;
}

ChartPanel* Chart::getChartPanel(void)
{
	return m_pChartPanel;
}

ScaleAttribute* Chart::getXScaleAttrs(void)
{
	return m_pXScaleAttrs;
}

ScaleAttribute* Chart::getYScaleAttrs(void)
{
	return m_pYScaleAttrs;
}

AxisAttribute* Chart::getYAxisAttrs(void)
{
	return m_pYAxisAttrs;
}

ChartAxis* Chart::getYAxis()
{
	return m_pYAxis;
}

AxisAttribute* Chart::getXAxisAttrs(void)
{
	return m_pXAxisAttrs;
}

ChartAxis* Chart::getXAxis()
{
	return m_pXAxis;
}

map<string, ChartCurve*> Chart::getSerials(void)
{
	return m_mpSerials;
}

map<string, Attribute*> Chart::getSerialAttrs(void)
{
	return m_mpSerialAttrs;
}

} /* namespace SuperChart */
