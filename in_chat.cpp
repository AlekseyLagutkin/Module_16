#include<iostream>
#include <string>
#include <vector>
#include "in_chat.h"
#include "user.h"

in_chat::in_chat(std::vector<user>& _v, int _my_num) : v(_v), my_num(_my_num)
{
	//cout << "Конструктор in_chat" << endl;
	my_log = v[my_num].get_login();
	my_name = v[my_num].get_name();
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Логин:" << my_log << std::endl;
	std::cout << "Имя:" << my_name << std::endl;
	//cout << "Номер:" << my_num << endl;
}
void in_chat::s_mes()   //Отправка сообщений
{
	bool log_us;   //Метка поиска логина получателя
	char in;
	int i;
	//vector <user>::iterator it = v.begin();
	std::string login;
	std::string mes;
	while (true)
	{
		v[my_num].show_mes();   //Вывод отправленных и полученных сообщений
		std::cout << "Для отправки сообщения введите 1, для выхода введите 2:" << std::endl;
		std::cin >> in;
		if (in == '1')
		{
			std::cout << "Введите логин пользователя, которому вы хотите отправить сообщение,\n";
			std::cout << "или введите all для отправки всем пользователям:\n";
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
				std::cout << "Введите сообщение:";
				std::cin >> mes;
				v[i].rec_mes(mes, my_log);   //Отправка сообщения получателю
				v[my_num].sent_mes(mes, login);   //Сохранение отправленного сообщения
			}
			else if (login == "all")
			{
				std::cout << "Введите сообщение:";
				std::cin >> mes;
				for (i = 0; i < v.size(); ++i)
				{
					if (i == my_num)
					{
						continue;
					}
					v[i].rec_mes(mes, my_log);   //Отправка сообщения получателям
				}
				v[my_num].sent_mes(mes, "всем");   //Сохранение отправленного сообщения 
			}
			else
			{
				std::cout << "Такого пользователя не существует." << std::endl;
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
	//cout << "Деструктор in_chat" << endl;
}
