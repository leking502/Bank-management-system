#include"headf.h"
#include "stdafx.h"
using namespace std;
bool tracc::transferacc(int userh1, const Date& date, Array<user_info*> accounts) {
	user_info* user1 = accounts[userh1];
	string id;
	double amount;
	string desc1;
	int f0 = 0;
	while (1) {
		printf("%s\n", "��������˻��ı��");
		cin.clear();
		cin >> id;
		int userh2P = check::checkid(id, accounts);
		if (!userh2P) {
			cout << "���˺��������ڣ��볢�������˺���" << endl;
			system("pause");
			system("cls");
			continue;
		};
		cout << "(0)ȷ��" << "(1)������д" << "(2)������������ҳ��" << endl;
		while (1) {
			printf("%s\n", "Ҫת�˵Ľ��");
			cin.clear();
			cin >> amount;
			system("cls");
			if (!(check::checkamount(userh1,amount,accounts)))
			{
				printf("%s\n", "���㣬�����Ƿ�����������ȷ�Ľ�");
				system("pause");
				system("cls");
				continue;
			};
			while (1) {
				cout << "(0)ȷ��" << "(1)������д" << "(2)������������ҳ��" << endl;
				int f1;
				cin.clear();
				cin >> f1;
				system("cls");
				switch (f1)
				{
				case(0): 
				{
					int userh2 = userh2P - 1;
					user_info* user2 = accounts[userh2];
					user1->getaccount()->withdraw(date, amount, desc1);//��Ǯȡ����
					user2->getaccount()->deposit(date, amount, desc1);//��Ǯ����
					cout << "ת�˳ɹ�" << endl;
					system("pause");
					system("cls");
					return 0;
				}
				case(1):
				{
					break;
				};
				case(2):
				{
					f0 = 1;
					break;
				};
				default:
					cout << "���������" << endl;
					system("pause");
					system("cls");
					continue;
				}
				break;
			};
			break;
		};
		if (f0) 
		{
			return 0;
		};
	};
};
