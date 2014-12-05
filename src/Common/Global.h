/**
 * @Title: 			Global.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <string>
#include <sstream>

using namespace std;

namespace SuperChart
{

/** */
typedef unsigned char 						uint8;
typedef unsigned int						uint32;

/** */
//template <typename T>

/**
 * @ClassName: 		Geometry::Global
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
	 *
	 * @param value
	 * @return
	 */
	template <typename T>
	string ConvertToString(T value)
	{
		stringstream ss;
		ss << value;
		return ss.str();
	}


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
	 * @filed : Style of Chart
	 */
	static const uint8 Style_Mode1 			= 0x01;
	static const uint8 Style_Mode2 			= 0x02;
	static const uint8 Style_Mode3 			= 0x03;
	static const uint8 Style_Mode4 			= 0x04;
	static const uint8 Style_Mode5 			= 0x05;
	static const uint8 Style_Mode6 			= 0x06;
	static const uint8 Style_Mode7 			= 0x07;
	static const uint8 Style_Mode8 			= 0x08;

};

} /* namespace Geometry */

#endif /* GLOBAL_H_ */
