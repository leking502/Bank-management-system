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
		cout << "|               ��������˻���ID                  |" << endl;
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
			cout << "|         ���˺��������ڣ��볢�������˺���        |" << endl;
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
			cout << "|                �㲻���Ը��Լ�ת��               |" << endl;
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
			cout << "|               ������Ҫת�˵Ľ��                |" << endl;
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
				cout << "|     ���㣬�����Ƿ�����������ȷ�Ľ�    |" << endl;
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
				cout << "   ��" << accounts[userh2]->getname() << "�������˺�" << accounts[userh2]->getaccount()->getId() << endl;
				cout << "                                                   " << endl;
				cout << "             ת��" << amount << "Ԫ" << endl;
				cout << "                                                   " << endl;
				cout << "(1)ȷ��      (2)������д      (3)������������ҳ��  " << endl;
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
					user1->getaccount()->withdraw(date, amount, desc1);//��Ǯȡ����
					user2->getaccount()->deposit(date, amount, desc1);//��Ǯ����
					system("cls");
					cout << "o=================================================o" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                                                 |" << endl;
					cout << "|                   ת�˳ɹ�                      |" << endl;
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
					cout << "|                 ���������                      |" << endl;
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
