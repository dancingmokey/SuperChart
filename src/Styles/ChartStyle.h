/**
 * @Title: 			ChartStyle.h
 * @Package 		SuperChart
 * @Description: 	Define Class SuperChart::ChartStyle
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

#ifndef STYLES_CHARTSTYLE_H_
#define STYLES_CHARTSTYLE_H_

#include "../Common/Global.h"
#include "../TinyXml/tinyxml.h"

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartStyle
 * @NameSpace: 		SuperChart
 * @Description: 	Chart Style Class, include color, size, type
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */
class ChartStyle
{
public:
	/**
	 * @FuncName : ChartStyle(bool bIsVisible, uint32 nColor, uint32 nSize, uint8 nType)
	 * @Description: Custom Constructor Function
	 * @param bIsVisible : bool : Is Element Visible or Not
	 * @param nColor : uint32 : Color Defined in Global::Color
	 * @param nSize : uint32 : Element Size
	 * @param nType : uint8 : Type of Line or Font of Text
	 */
	ChartStyle(bool bIsVisible, uint32 nColor, uint32 nSize, uint8 nType);

	/**
	 * @FuncName : ChartStylestring strFileName, string strTitle)
	 * @Description: Custom Constructor Function
	 * @param strFileName : string : Style XML File Name
	 * @param strTitle : string : Style XML Tag Name
	 */
	ChartStyle(string strFileName, string strTitle);

	/**
	 * @FuncName : ChartStyle(void)
	 * @Description: Default Constructor Function
	 */
	ChartStyle(void);

	/**
	 * @FuncName : ~ChartStyle(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~ChartStyle(void);

public:
	/**
	 * @FuncName : LoadFromFile strFileName, string strTitle)
	 * @Description: Load Style From XML File
	 * @param strFileName : string : Style XML File Name
	 * @param strTitle : string : Style XML Tag Name
	 */
	void LoadFromFile(string strFileName, string strTitle);

public:
	/**
	 * @FuncName: setVisible(bool bIsVisible)
	 * @Description: Set Element Visible or Not
	 * @param bIsVisible : bool : Visible Attibute Value
	 */
	void setVisible(bool bIsVisible);

	/**
	 * @FuncName: setColor(uint32 nColor)
	 * @Description: Set Element Color
	 * @param nColor : uint32 : Color of Line or Text
	 */
	void setColor(uint32 nColor);

	/**
	 * @FuncName: setSize(uint32 nSize)
	 * @Description: Set Element Size
	 * @param nSize : uint32 : Width of Line or Font Size of Text
	 */
	void setSize(uint32 nSize);

	/**
	 * @FuncName: setType(uint32 nType)
	 * @Description: Set Element Type
	 * @param nType : uint32 : Font of Text or Type of Line
	 */
	void setType(uint32 nType);

	/**
	 * @FuncName: isVisible(void)
	 * @Description: Get Element is Visible or Not
	 * @return bool
	 */
	bool isVisible(void) const;

	/**
	 * @FuncName: getColor(void)
	 * @Description: Get Element Color
	 * @return uint32
	 */
	uint32 getColor(void) const;

	/**
	 * @FuncName: getSize(void)
	 * @Description: Get Element Size
	 * @return uint32
	 */
	uint32 getSize(void) const;

	/**
	 * @FuncName: getType(void)
	 * @Description: Get Element Type
	 * @return uint32
	 */
	uint32 getType(void) const;

private:
	/**
	 * @Field : m_bIsVisible : Is Element Visible
	 */
	bool m_bIsVisible;
	/**
	 * @Field : m_nColor : Color of Line or Text
	 */
	uint32 m_nColor;
	/**
	 * @Field : m_nSize : Width of Line or Font Size of Text
	 */
	uint32 m_nSize;
	/**
	 * @Field : m_nType : Font of Text or Type of Line
	 */
	uint32 m_nType;
};

} /* namespace SuperChart */

#endif /* STYLES_CHARTSTYLE_H_ */
