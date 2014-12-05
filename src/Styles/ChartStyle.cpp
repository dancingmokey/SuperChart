/**
 * @Title: 			ChartStyle.cpp
 * @Package 		SuperChart
 * @Description: 	Implement Class SuperChart::ChartStyle
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

#include "ChartStyle.h"

namespace SuperChart
{

/**
 * @FuncName : ChartStyle(bool bIsVisible, uint32 nColor, uint32 nSize, uint8 nType)
 * @Description: Custom Constructor Function
 * @param bIsVisible : bool : Is Element Visible or Not
 * @param nColor : uint32 : Color Defined in Global::Color
 * @param nSize : uint32 : Element Size
 * @param nType : uint8 : Type of Line or Font of Text
 */
ChartStyle::ChartStyle(bool bIsVisible, uint32 nColor, uint32 nSize, uint8 nType)
{
	// TODO Auto-generated constructor stub
	m_bIsVisible = bIsVisible;
	m_nColor = nColor;
	m_nSize = nSize;
	m_nType = nType;
}

/**
 * @FuncName : ChartStyle(void)
 * @Description: Default Constructor Function
 */
ChartStyle::ChartStyle(void)
{
	// TODO Auto-generated constructor stub
	m_bIsVisible = false;
	m_nColor = Global::Color_Black;
	m_nSize = 0x00;
	m_nType = 0x00;
}

/**
 * @FuncName : ChartStyle(void)
 * @Description: Default Destructor Function
 */
ChartStyle::~ChartStyle(void)
{
	// TODO Auto-generated destructor stub
}

/**
 * @FuncName: setVisible(bool bIsVisible)
 * @Description: Set Element Visible or Not
 * @param bIsVisible : bool : Visible Attibute Value
 */
void ChartStyle::setVisible(bool bIsVisible)
{
	m_bIsVisible = bIsVisible;
}

/**
 * @FuncName: setColor(uint32 nColor)
 * @Description: Set Element Color
 * @param nColor : uint32 : Color of Line or Text
 */
void ChartStyle::setColor(uint32 nColor)
{
	m_nColor = nColor;
}

/**
 * @FuncName: setSize(uint32 nSize)
 * @Description: Set Element Size
 * @param nSize : uint32 : Width of Line or Font Size of Text
 */
void ChartStyle::setSize(uint32 nSize)
{
	m_nSize = nSize;
}

/**
 * @FuncName: setType(uint32 nType)
 * @Description: Set Element Type
 * @param nType : uint32 : Font of Text or Type of Line
 */
void ChartStyle::setType(uint32 nType)
{
	m_nType = nType;
}

/**
 * @FuncName: isVisible(void)
 * @Description: Get Element is Visible or Not
 * @return bool
 */
bool ChartStyle::isVisible(void) const
{
	return m_bIsVisible;
}

/**
 * @FuncName: getColor(void)
 * @Description: Get Element Color
 * @return uint32
 */
uint32 ChartStyle::getColor() const
{
	return m_nColor;
}

/**
 * @FuncName: getSize(void)
 * @Description: Get Element Size
 * @return uint32
 */
uint32 ChartStyle::getSize() const
{
	return m_nSize;
}

/**
 * @FuncName: getType(void)
 * @Description: Get Element Type
 * @return uint32
 */
uint32 ChartStyle::getType() const
{
	return m_nType;
}

} /* namespace SuperChart */
