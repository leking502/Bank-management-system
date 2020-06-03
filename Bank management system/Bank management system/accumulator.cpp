#include "headf.h"
#include "stdafx.h"
using namespace std;
//���캯����dateΪ��ʼ�ۼӵ����ڣ�valueΪ��ʼֵ
Accumulator::Accumulator(const Date& date, double value)
	: lastDate(date), value(value), sum(0) { }

//��õ�����date���ۼӽ��
double Accumulator::getSum(const Date& date) const {
	return sum + value * (date - lastDate);
}

//��date����ֵ���Ϊvalue
void Accumulator::change(const Date& date, double value) {
	sum = getSum(date);
	lastDate = date;
	this->value = value;
}

//��ʼ���������ڱ�Ϊdate����ֵ��Ϊvalue���ۼ�������
void Accumulator::reset(const Date& date, double value) {
	lastDate = date;
	this->value = value;
	sum = 0;
}