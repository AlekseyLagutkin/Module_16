#include <iostream>
#include <string>
#include "user.h"

//using namespace std;

user::user()
{
	//cout << "����������� user" << endl;
}
void user::set_login(std::string log)
{
	login = log;
}
void user::set_pasw(std::string pas)
{
	pasw = pas;
}
void user::set_name(std::string nam)
{
	name = nam;
}

//void user::sent_mes(string s_mes, string r_user)   //�������� ���������
//{
//	sent_2 = sent_1;
//	to_2 = to_1;
//	sent_1 = s_mes;
//	to_1 = r_user;
//}

void user::sent_mes(std::string s_mes, std::string r_user)   //�������� ���������
{
	if (sm.size() >= sz)
	{
		sm.pop_front();
	}
	user::s_mes new_sm{ s_mes, r_user };
	sm.push_back(new_sm);
}

//void user::rec_mes(string r_mes, string s_user)   //��������� ���������
//{
//	rec_2 = rec_1;
//	from_2 = from_1;
//	rec_1 = r_mes;
//	from_1 = s_user;
//}

void user::rec_mes(std::string r_mes, std::string s_user)   //��������� ���������
{
	if (rm.size() >= sz)
	{
		rm.pop_front();
	}
	user::r_mes new_sm{ r_mes, s_user };
	rm.push_back(new_sm);
}


std::string user::get_login()  //��������� ������
{
	return login;
}
std::string user::get_pasw()  //��������� ������
{
	return pasw;
}
std::string user::get_name()  //��������� �����
{
	return name;
}
//void user::show_mes()   //����� ���������
//{
//	cout << endl << "�������� ���������:" << endl;
//	if (rec_1 != "")
//	{
//		cout << rec_1 << "   ��   " << from_1 << endl;
//	}
//	if (rec_2 != "")
//	{
//		cout << rec_2 << "   ��   " << from_2 << endl;
//	}
//	cout << "������������ ���������:" << endl;
//	if (sent_1 != "")
//	{
//		cout << sent_1 << "   ����   " << to_1 << endl;
//	}
//	if (sent_2 != "")
//	{
//		cout << sent_2 << "   ����   " << to_2 << endl;
//	}
//	cout << endl;
//}

void user::show_mes()   //����� ���������
{
	std::cout << "�������� ���������:" << std::endl;
	for (int i = 0; i < rm.size(); ++i)
	{
		std::cout << rm[i].rec << "   ��   " << rm[i].from << std::endl;
	}
	std::cout << "������������ ���������:" << std::endl;
	for (int i = 0; i < sm.size(); ++i)
	{
		std::cout << sm[i].sent << "   ����   " << sm[i].to << std::endl;
	}
}

user::~user()
{
	//cout << "���������� user" << endl;
}
