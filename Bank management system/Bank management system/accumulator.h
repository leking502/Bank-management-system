//accumulator.h
#include "stdafx.h"
class Date;
class Accumulator {	//��ĳ����ֵ�����ۼ�
private:
	Date lastDate;	//�ϴα����ֵ��ʱ��
	double value;	//��ֵ�ĵ�ǰֵ
	double sum;		//��ֵ�����ۼ�֮��
public:
	//���캯����dateΪ��ʼ�ۼӵ����ڣ�valueΪ��ʼֵ
	Accumulator(const Date& date, double value);

	//��õ�����date���ۼӽ��
	double getSum(const Date& date) const;

	//��date����ֵ���Ϊvalue
	void change(const Date& date, double value);

	//��ʼ���������ڱ�Ϊdate����ֵ��Ϊvalue���ۼ�������
	void reset(const Date& date, double value);
};
