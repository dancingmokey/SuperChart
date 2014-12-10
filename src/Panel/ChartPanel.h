/**
 * @Title: 			ChartPanel.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTPANEL_H_
#define CHARTPANEL_H_

#include "../Elements/ChartElement.h"
#include "../Elements/ChartText.h"
#include "../Axes/ChartAxis.h"
#include "../Styles/ChartStyle.h"
#include "../Attributes/PanelAttribute.h"

#include <GeoRect.h>


namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartPanel
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */
class ChartPanel : public ChartElement
{
public:
	/**
	 * @FuncName: ChartPanel(GeoRect* pBoundRect, AxisAttribute* pAttribute, ChartStyle* pStyle)
	 * @Description: Custom Constructor Function
	 * @param pBoundRect : GeoRect* : Bound Rectangle of Panel
	 * @param pAttribute : AxisAttribute* : Attributes of Panel
	 * @param pStyle : ChartStyle* : Styles of Panel
	 */
	ChartPanel(GeoRect* pBoundRect,
			Attribute* pAttribute,
			ChartStyle* pStyle);

	/**
	* @FuncName: ChartPanel(void)
	* @Description: Default Constructor Function
	*/
	ChartPanel(void);

	/**
	 * @FuncName: ~ChartPanel(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~ChartPanel(void);

public:
	/**
	 * @FuncName: UpdateAxisTitle(void)
	 * @Description: Update Panel Title
	 */
	void UpdatePanelTitle(void);

public:
	/**
	 * @FuncName: setPanelTitle(ChartText* pPanelTitle)
	 * @Description: Set Panel Title
	 * @param pPanelTitle : ChartText* : Panel Title
	 */
	void setPanelTitle(ChartText* pPanelTitle);

	/**
	 * @FuncName: getPanelTitle(void)
	 * @Description: Get Panel Title
	 * @return ChartText*
	 */
	ChartText* getPanelTitle(void);

private:
	/**
	 * @field : m_pTitle : ChartText* : Title of Panel
	 */
	ChartText* m_pPanelTitle;
};

} /* namespace SuperChart */

#endif /* CHARTPANEL_H_ */
