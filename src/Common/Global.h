/**
 * @Title: 			Global.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef COMMON_GLOBAL_H_
#define COMMON_GLOBAL_H_

#include <cctype>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


namespace SuperChart
{

/** */
typedef unsigned char 						uint8;
typedef unsigned short 						uint16;
typedef unsigned int						uint32;


/**
 * @ClassName: 		SuperChart::Global
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */
class Global
{

public:
	/**
	 * @filed : Chart Type
	 */
	static const uint8 Chart_Curve			= 0x01;
	static const uint8 Chart_Pie			= 0x02;
	static const uint8 Chart_Bar			= 0x03;




public:
	/**
	 * @FuncName: Safe_Delete(void* pPointer)
	 * @Description: Safe Delete Pointer
	 * @param pPointer : void* : Pointer
	 */
	static void Safe_Delete(void* pPointer);

public:
	/**
	 * @filed : Axis Position
	 */
	static const string Style_File;

public:
	/**
	 * @filed : Axis Position
	 */
	static const uint8 Axis_Left			= 0x01;
	static const uint8 Axis_Right			= 0x02;
	static const uint8 Axis_Top				= 0x03;
	static const uint8 Axis_Bottom			= 0x04;

public:
	/**
	 *
	 * @param strPosName
	 * @return
	 */
	static uint8 GetAxisPositionByName(string strPosName);

public:
	/**
	 * @filed : Color
	 */
	static const uint32 Color_White 		= 0x000000;
	static const uint32 Color_Green 		= 0x0000ff;
	static const uint32 Color_Blue 			= 0x000080;
	static const uint32 Color_Red 			= 0x008000;
	static const uint32 Color_Magenta 		= 0x008080;
	static const uint32 Color_Lightgray 	= 0x00ff00;
	static const uint32 Color_Cyan 			= 0x00ffff;
	static const uint32 Color_Gray 			= 0x800000;
	static const uint32 Color_Darkred 		= 0x800080;
	static const uint32 Color_Darkblue 		= 0x808000;
	static const uint32 Color_Darkmagenta 	= 0x808080;
	static const uint32 Color_Darkcyan 		= 0xa0a0a4;
	static const uint32 Color_Darkyellow 	= 0xc0c0c0;
	static const uint32 Color_Darkgray 		= 0xff0000;
	static const uint32 Color_Yellow 		= 0xff00ff;
	static const uint32 Color_Darkgreen 	= 0xffff00;
	static const uint32 Color_Black 		= 0xffffff;


public:
	/**
	 *
	 * @param strColorName
	 * @return
	 */
	static uint32 GetColorByName(string strColorName);


public:
	/**
	 * @filed : Types of Line
	 */
	static const uint8 Line_Solid 			= 0x01;
	static const uint8 Line_Dash 			= 0x02;
	static const uint8 Line_Dot 			= 0x03;
	static const uint8 Line_Dashdot 		= 0x04;
	static const uint8 Line_Dashdotdot 		= 0x05;
	static const uint8 Line_Customdash 		= 0x06;

public:
	/**
	 *
	 * @param strLineName
	 * @return
	 */
	static uint8 GetLineTypeByName(string strLineName);

};

} /* namespace SuperChart */

#endif /* COMMON_GLOBAL_H_ */
