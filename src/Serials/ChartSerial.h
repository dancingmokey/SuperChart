/**
 * @Title: 			ChartSerial.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

#ifndef CHARTSERIAL_H_
#define CHARTSERIAL_H_

#include "../Elements/ChartElement.h"
#include "../Styles/ChartStyles.h"
#include "../Attributes/SerialAttribute.h"

#include <GeoLine.h>

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartSerial
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/02
 * @Version:		V1.0.0	
 */

class ChartSerial: public ChartElement
{
public:
	/**
	 *
	 * @param pBoundRect
	 * @param pSerialAttrs
	 * @param pChartStyles
	 */
	ChartSerial(GeoRect* pBoundRect,
			SerialAttribute* pSerialAttrs,
			ChartStyles* pChartStyles);

	/**
	 *
	 */
	virtual ~ChartSerial(void);

public:
	list<GeoLine*> GetSerialLine(void);

private:

	ChartStyles* m_pChartStyles;

	/**
	 * @field : m_ltLine : GeoLine* : Serial Title
	 */
	list<GeoLine*> m_ltLines;
};

} /* namespace SuperChart */

#endif /* CHARTSERIAL_H_ */
