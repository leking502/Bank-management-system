#include "menu.h"
#include "headf.h"
#include "stdafx.h"
using namespace std;
//用户主页面
void menu::usermenu() 
{
	int f;
	while (1) {
		cout << "◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈" << endl;
		cout << "▣                  1.查看账户信息                 ▣" << endl;
		cout << "▣                  2.取款                         ▣" << endl;
		cout << "▣                  3.存款                         ▣" << endl;
		cout << "▣                  4.修改密码                     ▣" << endl;
		cout << "▣                  5.转账                         ▣" << endl;
		cout << "▣                  6.返回上一菜单                 ▣" << endl;
		cout << "◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈" << endl;
		cin.clear();
		cin >> f;
		switch (f)
		{
		case(1): {/*查看账户信息*/}
		case(2): {/*取款 */}
		case(3): {/*存款 */}
		case(4): {/*修改密码*/}
		case(5): {/*转账*/}
		case(6): {/*返回上一菜单*/}
		default:
			cout << "无效的输入" << endl;
			system("pause");
			system("cls");
			continue;
		};
	};
};
//登录界面
void menu::sginmenu()
{
	int f;
	while (1) {
		cout << "请输入相应的操作序号进行操作 " << endl;
		cout << "◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓" << endl;
		cout << "◑                                                ◐" << endl;
		cout << "◑                  1.开户                        ◐" << endl;
		cout << "◑                  2.账号登录                    ◐" << endl;
		cout << "◑                  3.账户撤销                    ◐" << endl;
		cout << "◑                  4.退出系统                    ◐" << endl;
		cout << "◑                                                ◐" << endl;
		cout << "◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓" << endl;
		cin.clear();
		cin >> f;
		switch (f)
		{
		case(1): {/*开户*/}
		case(2): {/*账号登录*/}
		case(3): {/*账户撤销*/}
		case(4): {/*退出系统*/}
		default:
			cout << "无效的输入" << endl;
			system("pause");
			system("cls");
			continue;
		};

	};
};
//离开界面
void menu::leavemenu() {
	cout << "◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓" << endl;
	cout << "◑                                                ◐" << endl;
	cout << "◑                                                ◐" << endl;
	cout << "◑      感谢您对本银行的支持，欢迎下次光临！      ◐" << endl;
	cout << "◑                                                ◐" << endl;
	cout << "◑                                                ◐" << endl;
	cout << "◑                                                ◐" << endl;
	cout << "◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓◓" << endl;
};
//空白框
void menu::blankmenu() {
	cout << "◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈" << endl;
	cout << "▣                                                ▣" << endl;
	cout << "▣                                                ▣" << endl;
	cout << "▣                                                ▣" << endl;
	cout << "▣                                                ▣" << endl;
	cout << "▣                                                ▣" << endl;
	cout << "▣                                                ▣" << endl;
	cout << "◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈" << endl;
};