#include "headf.h"
#include "stdafx.h"
#include"slf.h"
using namespace std;
void  de_an_wi::deposit(int userh, Date& date, Array<user_info*>& accounts)
{
	double amount;
	string desc;
	while (1) {
		system("cls");
		cout << "o=================================================o" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                    输入要存金额                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;;
		cout << "o=================================================o" << endl;
		cin.clear();
		cin >> amount;
		if (amount == 0)
		{
			return;
		}
		system("cls");
		if (amount <= 0)
		{
			system("cls");
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|        你输入的金额为零或不合法，请重试         |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;;
			cout << "o=================================================o" << endl;
			system("pause");
			system("cls");
			continue;
		};
		accounts[userh]->getaccount()->deposit(date, amount, desc);
		system("cls");
		cout << "o=================================================o" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                     存入成功                    |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;;
		cout << "o=================================================o" << endl;
		slf::savef(date, accounts);
		system("pause");
		system("cls");
		return;
	};
};
void  de_an_wi::withdrawal(int userh, Date& date, Array<user_info*>& accounts)
{
	double amount;
	string desc;
	while (1)
	{
		system("cls");
		cout << "o=================================================o" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                  输入要取出金额                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;;
		cout << "o=================================================o" << endl;
		cin.clear();
		cin >> amount;
		if (amount == 0)
		{
			return;
		}
		system("cls");
		cout << amount << endl;
		if (!check::checkamount(amount, userh, accounts) || (amount <= 0))
		{
			system("cls");
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|    你输入的金额为零或小于零或余额不足，请重试   |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;;
			cout << "o=================================================o" << endl;
			system("pause");
			system("cls");
			continue;
		};
		accounts[userh]->getaccount()->withdraw(date, amount, desc);
		system("cls");
		cout << "o=================================================o" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                   取出成功                      |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;;
		cout << "o=================================================o" << endl;
		system("pause");
		system("cls");
		slf::savef(date, accounts);
		return;
	};
};