/**
 * @Title: 			Global.cpp
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/10
 * @Version:		V1.0.0	
 */

#include "Global.h"


namespace SuperChart
{

const string Global::Style_File = "style.xml";

/**
 * @FuncName: Safe_Delete(void* pPointer)
 * @Description: Safe Delete Pointer
 * @param pPointer : void* : Pointer
 */
void Global::Safe_Delete(void* pPointer)
{
	if (pPointer != NULL)
	{
		delete pPointer;
		pPointer = NULL;
	}
}

/**
 *
 * @param strPosName
 * @return
 */
uint8 Global::GetAxisPositionByName(string strPosName)
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

/**
 *
 * @param strLineName
 * @return
 */
uint8 Global::GetLineTypeByName(string strLineName)
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

/**
 *
 * @param strColorName
 * @return
 */
uint32 Global::GetColorByName(string strColorName)
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

}

