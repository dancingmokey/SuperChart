/**
 * @Title: 			Attribute.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/05
 * @Version:		V1.0.0	
 */

#ifndef ELEMENTS_ATTRIBUTE_H_
#define ELEMENTS_ATTRIBUTE_H_

#include <string>

using namespace std;

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::Attribute
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/05
 * @Version:		V1.0.0	
 */
class Attribute
{
public:
	Attribute();
	virtual ~Attribute();

public:
	/**
	 * @FuncName : UpdateAttribute(void)
	 * @Description: Update Attributes
	 */
	virtual void UpdateAttribute(void) = 0;

public:
	/**
	 * @FuncName : setTitle(const string& strTitle)
	 * @Description: Set Axis Title
	 * @param strTitle : string : Title of Axis
	 */
	void setTitle(const string& strTitle);

	/**
	 * @FuncName : getTitle(void)
	 * @Description: Get Axis Title
	 * @return string
	 */
	const string& getTitle(void) const;



private:
	/**
	 * @field : m_nAxisPosition : uint8 : Axis Position Information
	 */
	string m_strTitle;

};

} /* namespace SuperChart */

#endif /* ELEMENTS_ATTRIBUTE_H_ */
