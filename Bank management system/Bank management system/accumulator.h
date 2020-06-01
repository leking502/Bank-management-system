//accumulator.h
#include "stdafx.h"
class Date;
class Accumulator {	//将某个数值按日累加
private:
	Date lastDate;	//上次变更数值的时期
	double value;	//数值的当前值
	double sum;		//数值按日累加之和
public:
	//构造函数，date为开始累加的日期，value为初始值
	Accumulator(const Date& date, double value);
	
	//获得到日期date的累加结果
	double getSum(const Date& date) const;

	//在date将数值变更为value
	void change(const Date& date, double value);

	//初始化，将日期变为date，数值变为value，累加器清零
	void reset(const Date& date, double value);
};
