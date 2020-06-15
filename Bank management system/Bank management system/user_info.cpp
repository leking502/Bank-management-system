#include "headf.h"
#include "stdafx.h"
using namespace std;
//用户数据初始化
user_info::user_info(string id, string name, long long pnum, string password, int type, Account* account)
{
	this->name = name;
	this->pnum = pnum;
	this->account = account;
	this->password = password;
	this->type = type;
};
//创建账户函数
user_info* user_info::createaccount(
	string id,
	string name,  //用户名
	long long pnum,  //手机号码
	string password,//密码
	int type,
	Account* account, //账户类
	Array<user_info*> accounts //账户列表
)
{
	user_info* user = new user_info(id, name, pnum, password, type, account);
	return user;
};

//获取账户类
Account* user_info::getaccount()
{
	Account* x = this->account;
	return x;
};

//获取手机号
long long user_info::getpnum()
{
	long long x;
	x = this->pnum;
	return x;
};

//获取姓名
string user_info::getname()
{
	string x;
	x = this->name;
	return x;
};

//获取密码
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
//析构函数
user_info::~user_info()
{
	delete this->account;
};

//更改电话号码
void user_info::changepnum(long long pnum) {
	this->pnum = pnum;
	return;
};

//更改密码
void user_info::changepassword(string password) {
	this->password = password;
};

//更改姓名
void user_info::changename(string name) {
	this->name = name;
};