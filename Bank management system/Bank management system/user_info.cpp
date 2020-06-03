#include "headf.h"
#include "stdafx.h"
using namespace std;
//�û����ݳ�ʼ��
user_info::user_info(string id, string name, int pnum, string password, bool type, Account* account)
{
	this->name = name;
	this->pnum = pnum;
	this->account = account;
	this->password = password;
};
//�����˻�����
user_info* user_info::createaccount( 
	string id,
	string name,  //�û���
	int pnum,  //�ֻ�����
	string password,//����
	bool type,
	Account* account, //�˻���
	Array<user_info*> accounts //�˻��б�
)
{
	user_info* user = new user_info(id,name, pnum, password, type, account);
	return user;
};

//��ȡ�˻���
Account* user_info::getaccount() 
{
	Account* x = this->account;
	return x;
};

//��ȡ�ֻ���
int user_info::getpnum()
{
	int x;
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

//��������
user_info::~user_info() 
{
	delete this->account;
};

//��ȡ�绰����
void user_info::changepnum(int pnum) {
	this->pnum = pnum;
	return;
};

//��ȡ����
void user_info::changepassword(string password) {
	this->password = password;
};

//��ȡ����
void user_info::changename(string name) {
	this->name = name;
};