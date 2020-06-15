#include "tracc.h"
#include"headf.h"
#include"slf.h"
#include "stdafx.h"
using namespace std;
bool tracc::transferacc(int userh1, Date& date, Array<user_info*>& accounts) {
	user_info* user1 = accounts[userh1];
	string id;
	double amount;
	string desc1;
	int f0 = 0;
	while (1) {
		system("cls");
		cout << "o=================================================o" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|               请输入该账户的ID                  |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;
		cout << "|                                                 |" << endl;;
		cout << "o=================================================o" << endl;
		cin.clear();
		cin >> id;
		if (id == "0")
		{
			return 0;
		}
		int userh2P = check::checkid(id, accounts);
		int userh2 = userh2P - 1;
		if (!userh2P) {
			system("cls");
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|         该账号名不存在，请尝试其他账号名        |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;;
			cout << "o=================================================o" << endl;
			system("pause");
			system("cls");
			continue;
		}
		else if (userh2 == userh1)
		{
			system("cls");
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                你不可以给自己转账               |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;;
			cout << "o=================================================o" << endl;
			system("pause");
			system("cls");
			continue;
		};
		bool famo = 0;
		while (1) {
			system("cls");
			cout << "o=================================================o" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|               请输入要转账的金额                |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;
			cout << "|                                                 |" << endl;;
			cout << "o=================================================o" << endl;
			cin.clear();
			cin >> amount;
			if (amount == 0)
			{
				famo = 1;
				break;
			};
			system("cls");
			if (!(check::checkamount(amount, userh1, accounts)))
			{
				system("cls");
				cout << "o=================================================o" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|     余额不足，或余额非法，请输入正确的金额！    |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;
				cout << "|                                                 |" << endl;;
				cout << "o=================================================o" << endl;
				system("pause");
				system("cls");
				continue;
			};
			int fche = 0;
			while (1) {
				system("cls");
				cout << "o=================================================o" << endl;
				cout << "                                                   " << endl;
				cout << "   向" << accounts[userh2]->getname() << "所属的账号" << accounts[userh2]->getaccount()->getId() << endl;
				cout << "                                                   " << endl;
				cout << "             转入" << amount << "元" << endl;
				cout << "                                                   " << endl;
				cout << "(1)确定      (2)重新填写      (3)放弃并返回主页面  " << endl;
				cout << "o=================================================o" << endl;
				int f1;
				cin.clear();
				cin >> f1;
				system("cls");
				switch (f1)
				{
				case(0):
				{
					fche = 1;
					break;
				}
				case(1):
				{
					user_info* user2 = accounts[userh2];
					user1->getaccount()->withdraw(date, amount, desc1);//将钱取出来
					user2->getaccount()->deposit(date, amount, desc1);//将钱存入
					system("cls");
					cout << "o=================================================o" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                   转账成功                      |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "o=================================================o" << endl;
					slf::savef(date, accounts);
					system("pause");
					system("cls");
					return 0;
				}
				case(2):
				{
					break;
				};
				case(3):
				{
					f0 = 1;
					break;
				};
				default:
					system("cls");
					cout << "o=================================================o" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                 错误的输入                      |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;;
					cout << "o=================================================o" << endl;
					system("pause");
					system("cls");
					continue;
				}
				break;
			};
			if (fche)
			{
				continue;
			};
			break;
		};
		if (famo)
		{
			continue;
		};
		if (f0)
		{
			return 0;
		};
	};
};
