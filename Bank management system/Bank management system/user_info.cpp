#include "headf.h"
#include "stdafx.h"
using namespace std;
//�û����ݳ�ʼ��
user_info::user_info(string id, string name, long long pnum, string password, int type, Account* account)
{
	this->name = name;
	this->pnum = pnum;
	this->account = account;
	this->password = password;
	this->type = type;
};
//�����˻�����
user_info* user_info::createaccount(
	string id,
	string name,  //�û���
	long long pnum,  //�ֻ�����
	string password,//����
	int type,
	Account* account, //�˻���
	Array<user_info*> accounts //�˻��б�
)
{
	user_info* user = new user_info(id, name, pnum, password, type, account);
	return user;
};

//��ȡ�˻���
Account* user_info::getaccount()
{
	Account* x = this->account;
	return x;
};

//��ȡ�ֻ���
long long user_info::getpnum()
{
	long long x;
	x = this->pnum;
	return x;
};

//��ȡ����
string user_info::getname()
{
	string x;
	x = this->name;
	return x;
};

//��ȡ����
string user_info::getpassword()
{
	string x;
	x = this->password;
	return x;
};
int user_info::gettype() 
{
	int x;
	x = this->type;
	return x;
};
//��������
user_info::~user_info()
{
	delete this->account;
};

//���ĵ绰����
void user_info::changepnum(long long pnum) {
	this->pnum = pnum;
	return;
};

//��������
void user_info::changepassword(string password) {
	this->password = password;
};

//��������
void user_info::changename(string name) {
	this->name = name;
};