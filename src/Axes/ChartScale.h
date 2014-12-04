/**
 * @Title: 			ChartScale.h
 * @Package 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

#ifndef AXES_CHARTSCALE_H_
#define AXES_CHARTSCALE_H_

namespace SuperChart
{

/**
 * @ClassName: 		SuperChart::ChartScale
 * @NameSpace: 		SuperChart
 * @Description: 	TODO 
 * @Author: 		LiuLei
 * @Created on: 	2014/12/04
 * @Version:		V1.0.0	
 */

class ChartScale
{
public:
	/**
	 * @FuncName : ChartScale(int nMaxVlue, int nMinValue, int nAxisPixCnt)
	 * @Description: Custom Constructor Function
	 * @param nMaxVlue : int : Maximum Value of Axis
	 * @param nMinValue : int : Minimum Value of Axis
	 * @param nAxisLength : int : Length of Axis, Used to Calculate Scale Value
	 */
	ChartScale(int nMaxVlue, int nMinValue, int nAxisLength);

	/**
	 * @FuncName: ChartElement(void)
	 * @Description: Default Copy Constructor Function
	 */
	ChartScale(ChartScale& vChartScale);

	/**
	 * @FuncName: ChartElement(void)
	 * @Description: Default Constructor Function
	 */
	ChartScale(void);

	/**
	 * @FuncName: ~ChartElement(void)
	 * @Description: Default Destructor Function
	 */
	virtual ~ChartScale(void);

public:
	/**
	 * @FuncName : RefreshChartScale(void)
	 * @Description: Refresh Chart Scale
	 */
	void RefreshChartScale(void);

	/**
	 * @FuncName : SetChartScale(int nMaxVlue, int nMinValue, int nAxisPixCnt)
	 * @Description: Set Values of Chart Scale
	 * @param nMaxValue : int : Maximum Value of Axis
	 * @param nMinValue : int : Minimum Value of Axis
	 * @param nAxisLength : int : Length of Axis, Used to Calculate Scale Value
	 */
	void SetChartScale(int nMaxValue, int nMinValue, int nAxisLength);

	/**
	 * @FuncName : setScaleValue(double dScaleValue)
	 * @Description: Set Scale Value
	 * @param dScaleValue : double : Scale Value
	 */
	void setScaleValue(double dScaleValue);

	/**
	 * @FuncName : setMaxValue(int nMaxValue)
	 * @Description: Set Maximum Value to nMaxValue
	 * @param dScaleValue : int : Scale Value
	 */
	void setMaxValue(int nMaxValue);

	/**
	 * @FuncName : setMinValue(int nMinValue)
	 * @Description: Set Minimum Value to nMinValue
	 * @param dScaleValue : int : Minimum Value
	 */
	void setMinValue(int nMinValue);

	/**
	 * @FuncName : setAxisLength(int nAxisLength)
	 * @Description: Set Axis Length to nAxisLength
	 * @param nAxisLength : int : Axis Length
	 */
	void setAxisLength(int nAxisLength);

	/**
	 * @FuncName : getPixCntViaScale(int nAxisPixelCount)
	 * @Description: Input Value, Output Position on Axis
	 * @param nValue : int : Value
	 * @return
	 */
	int getPixCntViaScale(int nValue);

	/**
	 * @FuncName : getScaleValue(void)
	 * @Description: Get Scale Value
	 * @return double
	 */
	double getScaleValue(void) const;

	/**
	 * @FuncName : getMaxValue(void)
	 * @Description: Get Maximum Value
	 * @return int
	 */
	int getMaxValue(void) const;

	/**
	 * @FuncName : getMinValue(void)
	 * @Description: Get Minimum Value
	 * @return int
	 */
	int getMinValue(void) const;

	/**
	 * @FuncName : getAxisLength(void)
	 * @Description: Get Axis Length Value
	 * @return int
	 */
	int getAxisLength() const;

private:
	/**
	 * @field m_nMaxValue : int : Maximum Value of Axis
	 */
	int m_nMaxValue;

	/**
	 * @field m_nMaxValue : int : Minimum Value of Axis
	 */
	int m_nMinValue;

	/**
	 * @field m_nAxisLength : int : Length of Axis
	 */
	int m_nAxisLength;

	/**
	 * @field m_dScaleValue : double : Scale Value of Axis
	 */
	double m_dScaleValue;
};

} /* namespace SuperChart */

#endif /* AXES_CHARTSCALE_H_ */
