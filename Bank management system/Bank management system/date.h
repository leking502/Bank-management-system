//date.h
#include "stdafx.h"
class Date {	//������
private:
	int year;		//��
	int month;		//��
	int day;		//��
	int totalDays;	//�������Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ���

public:
	Date(int year, int month, int day);	  //���ꡢ�¡��չ������ڣ�������Ԫ�굽�����ڵ�����totalDays
	int getYear() const { return year; }  //��õ�ǰ������
	int getMonth() const { return month; }//��õ�ǰ������
	int getDay() const { return day; }    //��õ�ǰ������
	int getMaxDay() const;		//��õ����ж�����
	bool isLeapYear() const {	//�жϵ����Ƿ�Ϊ����
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	void show() const;			//�����ǰ����
	//������������֮��������	
	int operator - (const Date& date) const {
		return totalDays - date.totalDays;
	}
};

