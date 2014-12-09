/**
 * @Title: 			ChartStyles.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/05
 * @Version:		V1.0.0	
 */

#ifndef STYLES_CHARTSTYLES_H_
#define STYLES_CHARTSTYLES_H_

#include "ChartStyle.h"
#include "../Common/Global.h"
#include "../TinyXml/tinyxml.h"
#include <map>
#include <stdlib.h>

#include <iostream>

using namespace std;

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartStyles
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/05
 * @Version:		V1.0.0	
 */
class ChartStyles
{
public:
	/**
	 * @FuncName : ChartStyles(void)
	 * @Description: Custom Constructor Function
	 */
	ChartStyles(ChartStyles& pChartStyles);

	/**
	 * @FuncName : ChartStyles(void)
	 * @Description: Custom Constructor Function
	 */
	ChartStyles(void);

	/**
	 * @FuncName : ~ChartStyles(void)
	 * @Description: Custom Destructor Function
	 */
	virtual ~ChartStyles(void);


public:
	/**
	 * @FuncName : LoadChartStyles(string strFileName)
	 * @Description: Load Chart Style from File named strFileName
	 * @param strFileName
	 */
	void LoadChartStyles(string strFileName);

	/**
	 * @FuncName : LoadDefaultChartStyles(void)
	 * @Description: Load Default Chart Style when Load From XML File Failed
	 * @param strFileName : string : Style File Path & Name
	 */
	void LoadDefaultChartStyles(void);

	/**
	 * @FuncName : getChartStyles(void)
	 * @Description: Find and return Style from map by Name
	 * @param strFileName : string : Chart Style Name
	 * @return ChartStyle*
	 */
	ChartStyle* getChartStyleByName(string strName);

	/**
	 * @FuncName : getChartStyles(void)
	 * @Description: Get Mapping between String & ChartStyle
	 * @return map<string, ChartStyle*>
	 */
	map<string, ChartStyle*> getChartStyles(void);

private:
	/**
	 * @field : m_mpChartStyles : map<string, ChartStyle*> : Mapping between String & ChartStyle
	 */
	map<string, ChartStyle*> m_mpChartStyles;

};

} /* namespace SuperChart */

#endif /* STYLES_CHARTSTYLES_H_ */
