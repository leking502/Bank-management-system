#include "headf.h"
#include "stdafx.h"
#include "slf.h"
using namespace std;
int main() {

	system("mode con: cols=52 lines=20");
	Date date(2008, 11, 1);			//��ʼ����
	Array<user_info*> accounts(0);	//�����˻����飬Ԫ�ظ���Ϊ0
	Array<Account*> acco(0);
	slf::loadf(date, accounts);
	acco.getsize();
	menu::sginmenu(date, accounts);
	slf::savef(date, accounts);
}
