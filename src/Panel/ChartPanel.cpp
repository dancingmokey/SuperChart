/**
 * @Title: 			ChartPanel.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#include "ChartPanel.h"

namespace SuperChart
{

/**
 * @FuncName: ChartPanel(GeoRect* pBoundRect, AxisAttribute* pAttribute, ChartStyle* pStyle)
 * @Description: Custom Constructor Function
 * @param pBoundRect : GeoRect* : Bound Rectangle of Panel
 * @param pAttribute : AxisAttribute* : Attributes of Panel
 * @param pStyle : ChartStyle* : Styles of Panel
 */
ChartPanel::ChartPanel(GeoRect* pBoundRect,
		Attribute* pAttribute,
		ChartStyle* pStyle) :
		ChartElement(pBoundRect, dynamic_cast<Attribute*>(pAttribute), pStyle),
		m_pPanelTitle(new ChartText())
{
	/** Initialize Private Class Members */
	this->setBoundRect(pBoundRect);
	this->setAttribute(dynamic_cast<Attribute*>(pAttribute));
	this->setStyle(pStyle);

	/** Update Panel Title */
	this->UpdatePanelTitle();
}

/**
 * @FuncName: ChartPanel(void)
 * @Description: Default Constructor Function
 */
ChartPanel::ChartPanel(void) :
		m_pPanelTitle(new ChartText())
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName: ~ChartPanel(void)
 * @Description: Default Destructor Function
 */
ChartPanel::~ChartPanel(void)
{
	/** Release Old Title if Necessary */
	Global::Safe_Delete(m_pPanelTitle);
}

/**
 * @FuncName: UpdateAxisTitle(void)
 * @Description: Update Panel Title
 */
void ChartPanel::UpdatePanelTitle(void)
{
	/** Convert Attribute to AxisAttr Type */
	PanelAttribute* pAttribute = dynamic_cast<PanelAttribute*>(getAttribute());
	GeoRect* pBoundRect = this->getBoundRect();

	/** Create PanelTitle */
	m_pPanelTitle->setText(pAttribute->getTitle());
}

/**
 * @FuncName: setPanelTitle(ChartText* pPanelTitle)
 * @Description: Set Panel Title
 * @param pPanelTitle : ChartText* : Panel Title
 */
void ChartPanel::setPanelTitle(ChartText* pPanelTitle)
{
	m_pPanelTitle = pPanelTitle;
}

/**
 * @FuncName: getPanelTitle(void)
 * @Description: Get Panel Title
 * @return ChartText*
 */
ChartText* ChartPanel::getPanelTitle(void)
{
	return m_pPanelTitle;
}

} /* namespace SuperChart */




