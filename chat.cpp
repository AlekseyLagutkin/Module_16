#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "chek_us.h"
#include "in_chat.h"

int main()
{
	setlocale(LC_ALL, "");
	int sizev = 5;   //������ ������� - ���������� �������������
	int my_num = 0;   //������� ����� ������������
	std::vector<user> v;  //�������� ������� �������������
	
	std::cout << "����� ���������� � ���!\n";
	char in = 0;
	std::string str;
	while (true)
	{
		std::cout << "��� ����� � ��� ������� 1, ��� ����������� ������� 2, ��� ���������� ������ ������� 3:" << std::endl;
		std::cin >> in;
		if (in == '3')
		{
			break;
		}
		if (in == '1')
		{
			chek_us User(v, sizev);
			my_num = User.chek_logpas();   //�������� ������ � ������
			if (my_num >= 0)
			{
				in_chat Uchat(v, my_num);
				Uchat.s_mes();   //�������� ���������
			}

		}
		if (in == '2')
		{
			chek_us User(v, sizev);
			try
			{
				User.chek_in();   //���������� ������ ������������
			}
			catch (const char* except)
			{
				std::cout << "����������: " << except << std::endl;
			}
		}
	}
	return 0;
}