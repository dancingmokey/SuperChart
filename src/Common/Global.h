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
	static uint8 Global::GetAxisPositionByName(string strPosName)
	{
		/** Transform Color Name to Lower case*/
		transform(strPosName.begin(), strPosName.end(), strPosName.begin(), ::tolower/*toupper*/);

		/** Get Line Type Match with given Line Type Name */
		if (strPosName.compare("left") == 0)
		{
			return Axis_Left;
		}
		else if (strPosName.compare("right") == 0)
		{
			return Axis_Right;
		}
		else if (strPosName.compare("top") == 0)
		{
			return Axis_Top;
		}
		else
		{
			return Axis_Bottom;
		}
	}

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
	static uint32 Global::GetColorByName(string strColorName)
	{
		/** Transform Color Name to Lower case*/
		transform(strColorName.begin(), strColorName.end(), strColorName.begin(), ::tolower/*toupper*/);

		/** Get Color Match with given color Name */
		if (strColorName.compare("white") == 0)
		{
			return Color_White;
		}
		else if (strColorName.compare("green") == 0)
		{
			return Color_Green;
		}
		else if (strColorName.compare("blue") == 0)
		{
			return Color_Blue;
		}
		else if (strColorName.compare("red") == 0)
		{
			return Color_Red;
		}
		else if (strColorName.compare("magenta") == 0)
		{
			return Color_Magenta;
		}
		else if (strColorName.compare("lightgray") == 0)
		{
			return Color_Lightgray;
		}
		else if (strColorName.compare("cyan") == 0)
		{
			return Color_Cyan;
		}
		else if (strColorName.compare("gray") == 0)
		{
			return Color_Gray;
		}
		else if (strColorName.compare("darkred") == 0)
		{
			return Color_Darkred;
		}
		else if (strColorName.compare("darkblue") == 0)
		{
			return Color_Darkblue;
		}
		else if (strColorName.compare("darkmagenta") == 0)
		{
			return Color_Darkmagenta;
		}
		else if (strColorName.compare("darkcyan") == 0)
		{
			return Color_Darkcyan;
		}
		else if (strColorName.compare("darkyellow") == 0)
		{
			return Color_Darkyellow;
		}
		else if (strColorName.compare("darkgray") == 0)
		{
			return Color_Darkgray;
		}
		else if (strColorName.compare("yellow") == 0)
		{
			return Color_Yellow;
		}
		else if (strColorName.compare("darkgreen") == 0)
		{
			return Color_Darkgreen;
		}
		else
		{
			return Color_Black;
		}
	}


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
	static uint8 GetLineTypeByName(string strLineName)
	{
		/** Transform Color Name to Lower case*/
		transform(strLineName.begin(), strLineName.end(), strLineName.begin(), ::tolower/*toupper*/);

		/** Get Line Type Match with given Line Type Name */
		if (strLineName.compare("solid") == 0)
		{
			return Line_Solid;
		}
		else if (strLineName.compare("dash") == 0)
		{
			return Line_Dash;
		}
		else if (strLineName.compare("dot") == 0)
		{
			return Line_Dot;
		}
		else if (strLineName.compare("dashdot") == 0)
		{
			return Line_Dashdot;
		}
		else if (strLineName.compare("dashdotdot") == 0)
		{
			return Line_Dashdotdot;
		}
		else
		{
			return Line_Customdash;
		}
	}

};

} /* namespace SuperChart */

#endif /* COMMON_GLOBAL_H_ */
