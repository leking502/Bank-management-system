#include "date.h"
#include "accumulator.h"
#include "account.h"
#include "Array.h"
#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	Date date(2008, 11, 1);			//起始日期
	Array<Account*> accounts(0);	//创建账户数组，元素个数为0
	char cmd;
	do {
		cout << "(a)增加账户 (d)存入现金 (w)取出现金 (s)查询各用户信息 (c)改变日期 (n)进入下一个月 (e)退出" << endl;
		//显示日期和总金额
		date.show();
		cout << "\t总金额: " << Account::getTotal() << "\t指令> ";

		char type;
		int index, day;
		double amount, credit, rate, fee;
		string id, desc;
		Account* account;

		cin >> cmd;
		switch (cmd) {
		case 'a':	//增加账户
			printf("%s\n", "请输入开户类型（输入s为储蓄账户，输入任意字母为信用账户）");
			cin >> type;
			printf("%s\n", "请输入开户名");
			cin >> id;
			if (type == 's') {
				printf("%s\n", "请输入该账户的利率");
				cin >> rate;
				account = new SavingsAccount(date, id, rate);
			}
			else {
				printf("%s\n", "请输入该账户的信用");
				cin >> credit;
				printf("%s\n", "请输入该账户的利率");
				cin >> rate;
				printf("%s\n", "请输入该账户的收费");
				cin>> fee;
				account = new CreditAccount(date, id, credit, rate, fee);
			}
			accounts.resize(accounts.getSize() + 1);
			accounts[accounts.getSize() - 1] = account;
			break;
		case 'd':	//存入现金
			printf("%s\n", "请输入该账户的编号");
			cin >> index;
			printf("%s\n", "请输入存入的金额");
			cin >> amount;
			getline(cin, desc);
			accounts[index]->deposit(date, amount, desc);
			break;
		case 'w':	//取出现金
			printf("%s\n", "请输入该账户的编号");
			cin >> index;
			printf("%s\n", "请输入存入的金额");
			cin >> amount;
			getline(cin, desc);
			accounts[index]->withdraw(date, amount, desc);
			break;
		case 's':	//查询各账户信息
			for (int i = 0; i < accounts.getSize(); i++) {
				cout << "[" << i << "] ";
				accounts[i]->show();
				cout << endl;
			}
			break;
		case 'c':	//改变日期
			printf("%s\n", "请输入日期");
			cin >> day;
			if (day < date.getDay())
				cout << "You cannot specify a previous day";
			else if (day > date.getMaxDay())
				cout << "无效的日期";
			else
				date = Date(date.getYear(), date.getMonth(), day);
			break;
		case 'n':	//进入下个月
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
