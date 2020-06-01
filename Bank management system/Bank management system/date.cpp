//date.cpp
#include "date.h"
#include "account.h"
#include "Array.h"
#include "accumulator.h"
#include <iostream>
#include <cstdlib>
using namespace std;

namespace {	//namespace使下面的定义只在当前文件中有效
	//存储平年中某个月1日之前有多少天，为便于getMaxDay函数的实现，该数组多出一项
	const int DAYS_BEFORE_MONTH[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
}

//构造函数初始化当前账户时间，并计算元年到现日期的天数totalDays
Date::Date(int year, int month, int day) : year(year), month(month), day(day) {
	if (day <= 0 || day > getMaxDay()) {
		cout << "Invalid date: ";
		show();
		cout << endl;
		exit(1);
	}
	//计算公元元年1月1日到现在的天数：（1）每年365天（闰年多一天），先计算元年到前一年的天数。
	//闰年是：能被4整除但不能被100整除；或能被400整除
	int years = year - 1;
	totalDays = years * 365 + years / 4 - years / 100 + years / 400 //(1)总天数+闰年的数
		+ DAYS_BEFORE_MONTH[month - 1] + day;   //(2)本年初到当前月日的天数
	if (isLeapYear() && month > 2) totalDays++; //(3)本年是润年则二月是29天。故二月后加1
}
//返回当前账户日期月的最大天数
int Date::getMaxDay() const {
	if (isLeapYear() && month == 2)
		return 29;
	else
		return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}
//显示当前账户日期
void Date::show() const {
	cout << getYear() << "-" << getMonth() << "-" << getDay();
}
