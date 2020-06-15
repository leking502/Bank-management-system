//account.h
#include "stdafx.h"
class Date;
class Accumulator;
class Account { //�˻��࣬������
private:
	std::string id;	//�ʺ�
	static double total; //��̬���ݳ�Ա�������˻����ܽ��
protected:
	double balance;//���
	//����������õĹ��캯����idΪ�˻������˻����ɵ����ں��˻���
	Account(const Date& date, const std::string& id);
	//��¼һ���ʣ�dateΪ���ڣ�amountΪ��descΪ˵��
	void record(const Date& date, double amount, const std::string& desc);
	//���������Ϣ
	void error(const std::string& msg) const;
public:
	std::string getId()  { return id; } //����˺�
	double getBalance() const { return balance; }   //����˻����
	static double getTotal() { return total; }      //��̬��Ա�����������ܽ��
	//�����ֽ�dateΪ���ڣ�amountΪ��descΪ����˵�������麯��
	virtual void deposit(const Date& date, double amount, const std::string& desc) = 0;
	//ȡ���ֽ�dateΪ���ڣ�amountΪ��descΪ����˵�������麯��
	virtual void withdraw(const Date& date, double amount, const std::string& desc) = 0;
	//���㣨������Ϣ����ѵȣ���ÿ�½���һ�Σ�dateΪ�������ڣ����麯��
	virtual void settle(const Date& date) = 0;
	//��ʾ�˻���Ϣ
	virtual void show() const;
	virtual void setbal(double amount) 
	{
		this->balance = amount;
	};
};

class SavingsAccount : public Account { //�����˻���,������
private:
	Accumulator* acc;//����������Ϣ���ۼ���
	double rate;		//����������
public:
	//���캯��:���ڣ��˺ţ��������
	SavingsAccount(const Date& date, const std::string& id, double rate);
	double getRate() const { return rate; } //��ô������
	virtual void deposit(const Date& date, double amount, const std::string& desc);//���
	virtual void withdraw(const Date& date, double amount, const std::string& desc);//ȡ��
	virtual void settle(const Date& date);//����
};

class CreditAccount : public Account { //�����˻���
private:
	Accumulator* acc;	//����������Ϣ���ۼ���
	double credit;		//���ö��
	double rate;		//Ƿ���������
	double fee;			//���ÿ����

	double getDebt() const {	//���Ƿ���
		double balance = getBalance();
		return (balance < 0 ? balance : 0);
	}
public:
	//���캯��
	CreditAccount(const Date& date, const std::string& id, double credit, double rate, double fee);
	double getCredit() const { return credit; }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	double getAvailableCredit() const {	//��ÿ�������
		if (getBalance() < 0)
			return credit + getBalance();
		else
			return credit;
	}
	virtual void deposit(const Date& date, double amount, const std::string& desc);
	virtual void withdraw(const Date& date, double amount, const std::string& desc);
	virtual void settle(const Date& date);
	virtual void show() const;
};
