#include "date.h"
#include "accumulator.h"
#include "account.h"
#include "Array.h"
#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	Date date(2008, 11, 1);			//��ʼ����
	Array<Account*> accounts(0);	//�����˻����飬Ԫ�ظ���Ϊ0
	char cmd;
	do {
		cout << "(a)�����˻� (d)�����ֽ� (w)ȡ���ֽ� (s)��ѯ���û���Ϣ (c)�ı����� (n)������һ���� (e)�˳�" << endl;
		//��ʾ���ں��ܽ��
		date.show();
		cout << "\t�ܽ��: " << Account::getTotal() << "\tָ��> ";

		char type;
		int index, day;
		double amount, credit, rate, fee;
		string id, desc;
		Account* account;

		cin >> cmd;
		switch (cmd) {
		case 'a':	//�����˻�
			printf("%s\n", "�����뿪�����ͣ�����sΪ�����˻�������������ĸΪ�����˻���");
			cin >> type;
			printf("%s\n", "�����뿪����");
			cin >> id;
			if (type == 's') {
				printf("%s\n", "��������˻�������");
				cin >> rate;
				account = new SavingsAccount(date, id, rate);
			}
			else {
				printf("%s\n", "��������˻�������");
				cin >> credit;
				printf("%s\n", "��������˻�������");
				cin >> rate;
				printf("%s\n", "��������˻����շ�");
				cin>> fee;
				account = new CreditAccount(date, id, credit, rate, fee);
			}
			accounts.resize(accounts.getSize() + 1);
			accounts[accounts.getSize() - 1] = account;
			break;
		case 'd':	//�����ֽ�
			printf("%s\n", "��������˻��ı��");
			cin >> index;
			printf("%s\n", "���������Ľ��");
			cin >> amount;
			getline(cin, desc);
			accounts[index]->deposit(date, amount, desc);
			break;
		case 'w':	//ȡ���ֽ�
			printf("%s\n", "��������˻��ı��");
			cin >> index;
			printf("%s\n", "���������Ľ��");
			cin >> amount;
			getline(cin, desc);
			accounts[index]->withdraw(date, amount, desc);
			break;
		case 's':	//��ѯ���˻���Ϣ
			for (int i = 0; i < accounts.getSize(); i++) {
				cout << "[" << i << "] ";
				accounts[i]->show();
				cout << endl;
			}
			break;
		case 'c':	//�ı�����
			printf("%s\n", "����������");
			cin >> day;
			if (day < date.getDay())
				cout << "You cannot specify a previous day";
			else if (day > date.getMaxDay())
				cout << "��Ч������";
			else
				date = Date(date.getYear(), date.getMonth(), day);
			break;
		case 'n':	//�����¸���
			if (date.getMonth() == 12)
				date = Date(date.getYear() + 1, 1, 1);
			else
				date = Date(date.getYear(), date.getMonth() + 1, 1);
			for (int i = 0; i < accounts.getSize(); i++)
				accounts[i]->settle(date);
			break;
		}
		system("pause");
		system("cls");
	} while (cmd != 'e');

	for (int i = 0; i < accounts.getSize(); i++)
		delete accounts[i];

	return 0;
}
