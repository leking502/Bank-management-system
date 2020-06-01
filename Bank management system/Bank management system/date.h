//date.h
#include "stdafx.h"
class Date {	//日期类
private:
	int year;		//年
	int month;		//月
	int day;		//日
	int totalDays;	//该日期是从公元元年1月1日开始的第几天

public:
	Date(int year, int month, int day);	  //用年、月、日构造日期，并计算元年到现日期的天数totalDays
	int getYear() const { return year; }  //获得当前日期年
	int getMonth() const { return month; }//获得当前日期月
	int getDay() const { return day; }    //获得当前日期日
	int getMaxDay() const;		//获得当月有多少天
	bool isLeapYear() const {	//判断当年是否为闰年
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	void show() const;			//输出当前日期
	//计算两个日期之间差多少天	
	int operator - (const Date& date) const {
		return totalDays - date.totalDays;
	}
};

