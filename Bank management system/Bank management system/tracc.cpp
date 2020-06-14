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
		printf("%s\n", "请输入该账户的编号");
		cin.clear();
		cin >> id;
		int userh2P = check::checkid(id, accounts);
		if (!userh2P) {
			cout << "该账号名不存在，请尝试其他账号名" << endl;
			system("pause");
			system("cls");
			continue;
		};
		cout << "(0)确定" << "(1)重新填写" << "(2)放弃并返回主页面" << endl;
		while (1) {
			printf("%s\n", "要转账的金额");
			cin.clear();
			cin >> amount;
			system("cls");
			if (!(check::checkamount(userh1,amount,accounts)))
			{
				printf("%s\n", "余额不足，或余额非法，请输入正确的金额！");
				system("pause");
				system("cls");
				continue;
			};
			while (1) {
				cout << "(0)确定" << "(1)重新填写" << "(2)放弃并返回主页面" << endl;
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
					user1->getaccount()->withdraw(date, amount, desc1);//将钱取出来
					user2->getaccount()->deposit(date, amount, desc1);//将钱存入
					cout << "转账成功" << endl;
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
					cout << "错误的输入" << endl;
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
