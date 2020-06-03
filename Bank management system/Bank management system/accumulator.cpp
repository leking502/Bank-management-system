#include "headf.h"
#include "stdafx.h"
using namespace std;
//构造函数，date为开始累加的日期，value为初始值
Accumulator::Accumulator(const Date& date, double value)
	: lastDate(date), value(value), sum(0) { }

//获得到日期date的累加结果
double Accumulator::getSum(const Date& date) const {
	return sum + value * (date - lastDate);
}

//在date将数值变更为value
void Accumulator::change(const Date& date, double value) {
	sum = getSum(date);
	lastDate = date;
	this->value = value;
}

//初始化，将日期变为date，数值变为value，累加器清零
void Accumulator::reset(const Date& date, double value) {
	lastDate = date;
	this->value = value;
	sum = 0;
}