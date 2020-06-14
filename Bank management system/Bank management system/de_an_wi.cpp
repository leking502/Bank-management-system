#include "headf.h"
#include "stdafx.h"
using namespace std;
void  de_an_wi::deposit(int userh,  const Date& date, Array<user_info*> accounts)
{
	double amount;
	string desc;
	while (1) {
		cout << "����Ҫ����" << endl;
		cin.clear();
		cin >> amount;
		system("cls");
		if (amount<=0) 
		{
			cout << "������Ľ��Ϊ��򲻺Ϸ���������" << endl;
			system("pause");
			system("cls");
			continue;
		};
		accounts[userh]->getaccount()->deposit(date, amount, desc);
		cout << "����ɹ�" << endl;
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
		cout << "����Ҫȡ�����" << endl;
		cin.clear();
		cin >> amount;
		system("cls");
		if ((check::checkamount(amount, userh, accounts) < amount) || (amount <= 0)) 
		{
			cout << "������Ľ��Ϊ���С��������㣬������" << endl;
			system("pause");
			system("cls");
			continue;
		};
		accounts[userh]->getaccount()->withdraw(date, amount, desc);
		cout << "ȡ���ɹ�" << endl;
		system("pause");
		system("cls");
		return;
	};
};