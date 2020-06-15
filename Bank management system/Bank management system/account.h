//account.h
#include "stdafx.h"
class Date;
class Accumulator;
class Account { //账户类，抽象类
private:
	std::string id;	//帐号
	static double total; //静态数据成员，所有账户的总金额
protected:
	double balance;//余额
	//供派生类调用的构造函数，id为账户：新账户生成的日期和账户号
	Account(const Date& date, const std::string& id);
	//记录一笔帐，date为日期，amount为金额，desc为说明
	void record(const Date& date, double amount, const std::string& desc);
	//报告错误信息
	void error(const std::string& msg) const;
public:
	std::string getId()  { return id; } //获得账号
	double getBalance() const { return balance; }   //获得账户金额
	static double getTotal() { return total; }      //静态成员函数，返回总金额
	//存入现金，date为日期，amount为金额，desc为款项说明，纯虚函数
	virtual void deposit(const Date& date, double amount, const std::string& desc) = 0;
	//取出现金，date为日期，amount为金额，desc为款项说明，纯虚函数
	virtual void withdraw(const Date& date, double amount, const std::string& desc) = 0;
	//结算（计算利息、年费等），每月结算一次，date为结算日期，纯虚函数
	virtual void settle(const Date& date) = 0;
	//显示账户信息
	virtual void show() const;
	virtual void setbal(double amount) 
	{
		this->balance = amount;
	};
};

class SavingsAccount : public Account { //储蓄账户类,派生类
private:
	Accumulator* acc;//辅助计算利息的累加器
	double rate;		//存款的年利率
public:
	//构造函数:日期，账号，存款利率
	SavingsAccount(const Date& date, const std::string& id, double rate);
	double getRate() const { return rate; } //获得存款利率
	virtual void deposit(const Date& date, double amount, const std::string& desc);//存款
	virtual void withdraw(const Date& date, double amount, const std::string& desc);//取款
	virtual void settle(const Date& date);//结算
};

class CreditAccount : public Account { //信用账户类
private:
	Accumulator* acc;	//辅助计算利息的累加器
	double credit;		//信用额度
	double rate;		//欠款的日利率
	double fee;			//信用卡年费

	double getDebt() const {	//获得欠款额
		double balance = getBalance();
		return (balance < 0 ? balance : 0);
	}
public:
	//构造函数
	CreditAccount(const Date& date, const std::string& id, double credit, double rate, double fee);
	double getCredit() const { return credit; }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	double getAvailableCredit() const {	//获得可用信用
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
