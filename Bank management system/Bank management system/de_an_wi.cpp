#include "headf.h"
#include "stdafx.h"
using namespace std;
void  de_an_wi::deposit(int userh,  const Date& date, Array<user_info*> accounts)
{
	double amount;
	string desc;
	while (1) {
		cout << "输入要存金额" << endl;
		cin.clear();
		cin >> amount;
		system("cls");
		if (amount<=0) 
		{
			cout << "你输入的金额为零或不合法，请重试" << endl;
			system("pause");
			system("cls");
			continue;
		};
		accounts[userh]->getaccount()->deposit(date, amount, desc);
		cout << "存入成功" << endl;
		system("pause");
		system("cls");
		return;
	};
};
void  de_an_wi::withdrawal(int userh, const Date& date, Array<user_info*> accounts)
{
	double amount;
	string desc;
	while (1) 
	{
		cout << "输入要取出金额" << endl;
		cin.clear();
		cin >> amount;
		system("cls");
		if ((check::checkamount(amount, userh, accounts) < amount) || (amount <= 0)) 
		{
			cout << "你输入的金额为零或小于零或余额不足，请重试" << endl;
			system("pause");
			system("cls");
			continue;
		};
		accounts[userh]->getaccount()->withdraw(date, amount, desc);
		cout << "取出成功" << endl;
		system("pause");
		system("cls");
		return;
	};
};