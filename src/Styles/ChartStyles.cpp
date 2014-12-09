/**
 * @Title: 			ChartStyles.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/05
 * @Version:		V1.0.0	
 */

#include "ChartStyles.h"

namespace SuperChart
{

/**
 * @FuncName : ChartStyles(void)
 * @Description: Custom Constructor Function
 */
ChartStyles::ChartStyles(void)
{
	// TODO Auto-generated constructor stub
}

/**
 * @FuncName : ~ChartStyles(void)
 * @Description: Custom Destructor Function
 */
ChartStyles::~ChartStyles(void)
{
	// TODO Auto-generated destructor stub
	map<string, ChartStyle*>::iterator it = m_mpChartStyles.begin();
	while (it != m_mpChartStyles.end())
	{
		/** Get ChartStyle Pointer on Current Position */
		ChartStyle* pChartStyle = it->second;

		/** Erase Key & Value */
		m_mpChartStyles.erase(it++);

		/** Release Memory Space Safely */
		if (pChartStyle != NULL)
		{
			delete pChartStyle;
			pChartStyle = NULL;
		}
	}
}

/**
 * @FuncName : LoadChartStyles(string strFileName)
 * @Description: Load Chart Style from File named strFileName
 * @param strFileName : string : Style File Path & Name
 */
void ChartStyles::LoadChartStyles(string strFileName)
{
	/** Load From XML File */
	TiXmlDocument vXmlDoc(strFileName.c_str());
	if (vXmlDoc.LoadFile() == true)
	{
		/** parse Styles Node */
		TiXmlElement* pStylesNode = vXmlDoc.RootElement();

		/** Parse Every Style Node */
		for (TiXmlNode* pStyleNode = pStylesNode->FirstChild("Style");
				pStyleNode != NULL;
				pStyleNode = pStylesNode->IterateChildren("Style", pStyleNode))
		{
			/** Parse Name Attributes */
			TiXmlNode* pNameNode = pStyleNode->FirstChild("Name");
			string strName = pNameNode->ToElement()->GetText();

			/** Parse Visible Attributes */
			TiXmlNode* pVisibleNode = pStyleNode->FirstChild("Visible");
			string strVisible = pVisibleNode->ToElement()->GetText();
			bool bIsVisible = ((strVisible == "true") ? true : false);

			/** Parse type Attributes */
			TiXmlNode* pTypeNode = pStyleNode->FirstChild("Type");
			string strType = pTypeNode->ToElement()->GetText();
			uint8 nType = Global::GetLineTypeByName(strType);

			/** Parse size Attributes */
			TiXmlNode* pSizeNode = pStyleNode->FirstChild("Size");
			string strSize = pSizeNode->ToElement()->GetText();
			uint32 nSize = atoi(strSize.c_str());

			/** Parse color Attributes */
			TiXmlNode* pColorNode = pStyleNode->FirstChild("Color");
			string strColor = pColorNode->ToElement()->GetText();
			uint32 nColor = Global::GetColorByName(strColor);

			/** Save Style into Map */
			m_mpChartStyles.insert(
					map<string, ChartStyle*>::value_type(
							strName,
							new ChartStyle(true, nColor, nSize, nType)));
		}
	}
	else /** Load XML File Failed! So Load Default Setting!!! */
	{
		this->LoadDefaultChartStyles();
		cout << "Load XML File Failed " <<  endl;
	}
}

/**
 * @FuncName : LoadDefaultChartStyles(void)
 * @Description: Load Default Chart Style when Load From XML File Failed
 * @param strFileName
 */
void ChartStyles::LoadDefaultChartStyles(void)
{
	/** Load Style of Panel */
	ChartStyle* pPanelStyle = new ChartStyle(true, Global::Color_Green, 2, Global::Line_Solid);
	ChartStyle* pPanelTitleStyle = new ChartStyle(true, Global::Color_Yellow, 35, Global::Line_Solid);

	/** Load Style of Axis Attributes */
	ChartStyle* pAxisLineStyle = new ChartStyle(true, Global::Color_Green, 2, Global::Line_Solid);
	ChartStyle* pAxisTickStyle = new ChartStyle(true, Global::Color_Cyan, 2, Global::Line_Solid);
	ChartStyle* pAxisGridStyle = new ChartStyle(true, Global::Color_White, 1, Global::Line_Dashdotdot);
	ChartStyle* pAxisTitleStyle = new ChartStyle(true, Global::Color_Yellow, 25, Global::Line_Solid);
	ChartStyle* pAxisLabelStyle = new ChartStyle(true, Global::Color_Darkyellow, 15, Global::Line_Solid);

	/** Save All Style into Map */
	m_mpChartStyles.insert(map<string, ChartStyle*>::value_type("Panel", pPanelStyle));
	m_mpChartStyles.insert(map<string, ChartStyle*>::value_type("PanelTitle", pPanelTitleStyle));
	m_mpChartStyles.insert(map<string, ChartStyle*>::value_type("AxisLine", pAxisLineStyle));
	m_mpChartStyles.insert(map<string, ChartStyle*>::value_type("AxisTick", pAxisTickStyle));
	m_mpChartStyles.insert(map<string, ChartStyle*>::value_type("AxisGrid", pAxisGridStyle));
	m_mpChartStyles.insert(map<string, ChartStyle*>::value_type("AxisTitle", pAxisTitleStyle));
	m_mpChartStyles.insert(map<string, ChartStyle*>::value_type("AxisLabel", pAxisLabelStyle));
}

/**
 * @FuncName : getChartStyles(void)
 * @Description: Find and return Style from map by Name
 * @param strFileName : string : Chart Style Name
 * @return ChartStyle*
 */
ChartStyle* ChartStyles::getChartStyleByName(string strName)
{
	map<string, ChartStyle*>::const_iterator ite = m_mpChartStyles.find(strName);
	if (ite != m_mpChartStyles.end())
	{
		return ite->second;
	}
	else
	{
		return NULL;
	}
}

/**
 * @FuncName : getChartStyles(void)
 * @Description: Get Mapping between String & ChartStyle
 * @return map<string, ChartStyle*>
 */
map<string, ChartStyle*> ChartStyles::getChartStyles(void)
{
	return m_mpChartStyles;
}

} /* namespace SuperChart */
