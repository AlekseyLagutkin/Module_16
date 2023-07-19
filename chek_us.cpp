#include <iostream>
#include <string>
#include <vector>
#include "chek_us.h"
#include "user.h"

chek_us::chek_us(std::vector<user>& _v, int _sizev): v(_v), sizev(_sizev)
{
	//cout << "����������� chek_us" << endl;
}
int chek_us::chek_logpas()   //���� ������������
{
	std::cout << "������� �����:";
	std::cin >> log;
	bool login = false;
	bool pasw = false;
	int i;
	std::vector<user>::iterator it = v.begin();
	for (i = 0; i < v.size(); ++i)
	{
		if (log == (it + i)->get_login())   //�������� ������
		{
			login = true;
			std::cout << "������� ������:";
			std::cin >> pas;
			if (pas == (it + i)->get_pasw())   //�������� ������
			{
				pasw = true;
				break;
			}
			else
			{
				std::cout << "�������� ������" << std::endl;
				break;
			}
		}
	}
	if (login && pasw && true)
	{
		std::cout << "���� ��������\n" << std::endl;
		return i;
	}
	if (login == false)
	{
		std::cout << "�������� �����" << std::endl;
	}
	return -1;
}
int chek_us::chek_in()   //����������� ������ ������������
{
	if (v.size() >= sizev)   //�������� �� ������������ �������������� ������� 
	{
		throw "��������, ��� ��������.\n";
	}
	else
	{
		bool login = true;
		std::string pas2;
		user newus;
		std::cout << "������� �����:" << std::endl;
		std::cin >> log;
		std::vector<user>::iterator it = v.begin();
		for (int i = 0; i < v.size(); ++i)
		{
			if (log == (it + i)->get_login())
			{
				login = false;
				std::cout << "����� ��� �����" << std::endl;
				break;
			}
		}
		if (login == true)
		{
			std::cout << "������� ���� ���:";
			std::cin >> name;
			std::cout << "������� ������:";
			std::cin >> pas;
			std::cout << "����������� ������:";
			std::cin >> pas2;
			if (pas2 == pas)
			{
				newus.set_login(log);
				newus.set_name(name);
				newus.set_pasw(pas);
				v.push_back(newus);
				std::cout << "����������� ������ �������!" << std::endl;
			}
			else
			{
				std::cout << "�������� ������, ����������� ��������." << std::endl;
			}
		}
	}
	return v.size();
}
chek_us::~chek_us()
{
	//cout << "���������� chek_us" << endl;
}
