/**
 * @Title: 			Chart.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/10
 * @Version:		V1.0.0	
 */

#ifndef CHART_CHART_H_
#define CHART_CHART_H_

#include "../Attributes/Attribute.h"
#include "../Attributes/ScaleAttribute.h"
#include "../Attributes/CurveAttribute.h"
#include "../Attributes/AxisAttribute.h"
#include "../Axes/ChartAxis.h"
#include "../Curves/ChartCurve.h"
#include "../Panel/ChartPanel.h"


#include <map>


using namespace std;


namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::Chart
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/10
 * @Version:		V1.0.0	
 */

class Chart
{
public:
	/**
	 * @FuncName: Chart(string strTitle, double dXManValue, double dXMinValue, double dXTickValue, double dYMaxValue, double dYMinValue, double dYTickValue)
	 * @Description:
	 * @param strTitle
	 * @param dXManValue
	 * @param dXTickValue
	 * @param dXMinValue
	 * @param dYMaxValue
	 * @param dYMinValue
	 * @param dYTickValue
	 */
	Chart(string strTitle,
			double dXManValue,
			double dXMinValue,
			double dXTickValue,
			double dYMaxValue,
			double dYMinValue,
			double dYTickValue);

	/**
	 *
	 */
	Chart(void);

	/**
	 *
	 */
	virtual ~Chart();

public:
	void UpdateChartPanel(string strPanelTitle);
	void UpdateXScaleAttrs(double dMaxValule, double dMinValue, double dAxisLength);
	void UpdateYScaleAttrs(double dMaxValule, double dMinValue, double dAxisLength);
	void UpdateXAxisAttrs(double dMaxValule, double dMinValue, double dTickValue, double dScaleValue);
	void UpdateYAxisAttrs(double dMaxValule, double dMinValue, double dTickValue, double dScaleValue);
	void AddSerialData(string strSerialTitle, double dXValue, double dYValue);
	void AddSerialData(string strSerialTitle, double* pXValueList, double* pYValueList, int nCount);
	void ClearSerialData(string strSerialTitle);
public:
	void setChartPanel(ChartPanel* pChartPanel);
	void setXScaleAttrs(ScaleAttribute* pXScaleAttrs);
	void setYScaleAttrs(ScaleAttribute* pYScaleAttrs);
	void setXAxis(ChartAxis* pXAxis);
	void setXAxisAttrs(AxisAttribute* pXAxisAttrs);
	void setYAxis(ChartAxis* pYAxis);
	void setYAxisAttrs(AxisAttribute* pYAxisAttrs);
	void setSerials(map<string, ChartCurve*> mpSerials);
	void setSerialAttrs(map<string, Attribute*> mpSerialAttrs);
	ChartPanel* getChartPanel(void);
	ScaleAttribute* getXScaleAttrs(void);
	ScaleAttribute* getYScaleAttrs(void);
	ChartAxis* getXAxis(void);
	AxisAttribute* getXAxisAttrs(void);
	ChartAxis* getYAxis(void);
	AxisAttribute* getYAxisAttrs(void);
	map<string, ChartCurve*> getSerials(void);
	map<string, Attribute*> getSerialAttrs(void);

private:
	/**
	 * @Field : m_pScaleAttrs : ScaleAttribute :
	 */
	ChartPanel* m_pChartPanel;

	/**
	 * @Field : m_pXScaleAttrs : ScaleAttribute :
	 */
	ScaleAttribute* m_pXScaleAttrs;

	/**
	 * @Field : m_pXScaleAttrs : ScaleAttribute :
	 */
	ScaleAttribute* m_pYScaleAttrs;

	/**
	 * @Field : m_pScaleAttrs : ScaleAttribute :
	 */
	AxisAttribute* m_pXAxisAttrs;

	/**
	 * @Field : m_pScaleAttrs : ScaleAttribute :
	 */
	AxisAttribute* m_pYAxisAttrs;

	/**
	 * @Field : m_pScaleAttrs : ScaleAttribute :
	 */
	map<string, Attribute*> m_mpSerialAttrs;

	/**
	 * @Field : m_pScaleAttrs : ScaleAttribute :
	 */
	ChartAxis* m_pXAxis;

	/**
	 * @Field : m_pScaleAttrs : ScaleAttribute :
	 */
	ChartAxis* m_pYAxis;

	/**
	 * @Field : m_pScaleAttrs : ScaleAttribute :
	 */
	map<string, ChartCurve*> m_mpSerials;
};

} /* namespace SuperChart */

#endif /* CHART_CHART_H_ */
