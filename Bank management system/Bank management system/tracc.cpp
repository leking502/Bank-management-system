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
		printf("%s\n", "请输入该账户的编号");
		cin.clear();
		cin >> id;
		if (check::checkid(id, accounts)) {
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
			if ((amount > user1.getaccount()->getTotal()) || (amount < 0))
			{
				printf("%s\n", "余额不足，请输入正确的金额！");
				system("pause");
				system("cls");
				continue;
			};
			cout << "(0)确定" << "(1)重新填写" << "(2)放弃并返回主页面" << endl;
		};
		userp1->withdraw(date, amount, desc1);//将钱取出来
		userp2->deposit(date, amount, desc1);//将钱存入
		cout << "转账成功" << endl;
	};
};
