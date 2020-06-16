#include "headf.h"
#include "stdafx.h"
#include "slf.h"
using namespace std;
int main() {

	system("mode con: cols=52 lines=20");
	Date date(2008, 11, 1);			//起始日期
	Array<user_info*> accounts(0);	//创建账户数组，元素个数为0
	Array<Account*> acco(0);
	slf::loadf(date, accounts);
	acco.getsize();
	menu::sginmenu(date, accounts);
	slf::savef(date, accounts);
}
