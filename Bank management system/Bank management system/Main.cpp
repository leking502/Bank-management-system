#include "headf.h"
#include "stdafx.h"
using namespace std;
int main() {
	system("mode con: cols=52 lines=20");
	Date date(2008, 11, 1);			//��ʼ����
	Array<user_info*> accounts(0);	//�����˻����飬Ԫ�ظ���Ϊ0
	Array<Account*> acco(0);
	acco.getsize();
	menu::sginmenu(date, accounts);
	for (int i = 0; i < accounts.getsize(); i++)
		delete accounts[i];

	return 0;
}
