#include "tracc.h"
#include"headf.h"
using namespace std;
bool tracc::transferacc(user_info user1, user_info user2, const Date& date, Array<user_info*> accounts) {
	Account* userp1 = user1.getaccount();
	Account* userp2 = user2.getaccount();
	string id;
	double amount;
	string desc1;
	while (1) {
		printf("%s\n", "��������˻��ı��");
		cin.clear();
		cin >> id;
		if (check::checkid(id, accounts)) {
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
			if ((amount > user1.getaccount()->getTotal()) || (amount < 0))
			{
				printf("%s\n", "���㣬��������ȷ�Ľ�");
				system("pause");
				system("cls");
				continue;
			};
			cout << "(0)ȷ��" << "(1)������д" << "(2)������������ҳ��" << endl;
		};
		userp1->withdraw(date, amount, desc1);//��Ǯȡ����
		userp2->deposit(date, amount, desc1);//��Ǯ����
		cout << "ת�˳ɹ�" << endl;
	};
};
