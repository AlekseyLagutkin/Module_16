#include<iostream>
#include <string>
#include <vector>
#include "in_chat.h"
#include "user.h"

in_chat::in_chat(std::vector<user>& _v, int _my_num) : v(_v), my_num(_my_num)
{
	//cout << "����������� in_chat" << endl;
	my_log = v[my_num].get_login();
	my_name = v[my_num].get_name();
	std::cout << "------------------------------------" << std::endl;
	std::cout << "�����:" << my_log << std::endl;
	std::cout << "���:" << my_name << std::endl;
	//cout << "�����:" << my_num << endl;
}
void in_chat::s_mes()   //�������� ���������
{
	bool log_us;   //����� ������ ������ ����������
	char in;
	int i;
	//vector <user>::iterator it = v.begin();
	std::string login;
	std::string mes;
	while (true)
	{
		v[my_num].show_mes();   //����� ������������ � ���������� ���������
		std::cout << "��� �������� ��������� ������� 1, ��� ������ ������� 2:" << std::endl;
		std::cin >> in;
		if (in == '1')
		{
			std::cout << "������� ����� ������������, �������� �� ������ ��������� ���������,\n";
			std::cout << "��� ������� all ��� �������� ���� �������������:\n";
			std::cin >> login;
			log_us = false;
			for (i = 0; i < v.size(); ++i)
			{
				if (login == v[i].get_login())
				{
					log_us = true;
					break;
				}
			}
			if (log_us == true)
			{
				std::cout << "������� ���������:";
				std::cin >> mes;
				v[i].rec_mes(mes, my_log);   //�������� ��������� ����������
				v[my_num].sent_mes(mes, login);   //���������� ������������� ���������
			}
			else if (login == "all")
			{
				std::cout << "������� ���������:";
				std::cin >> mes;
				for (i = 0; i < v.size(); ++i)
				{
					if (i == my_num)
					{
						continue;
					}
					v[i].rec_mes(mes, my_log);   //�������� ��������� �����������
				}
				v[my_num].sent_mes(mes, "����");   //���������� ������������� ��������� 
			}
			else
			{
				std::cout << "������ ������������ �� ����������." << std::endl;
			}


		}
		if (in == '2')
		{
			break;
		}


	}
}
in_chat::~in_chat()
{
	//cout << "���������� in_chat" << endl;
}
