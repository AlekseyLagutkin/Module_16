#include <iostream>
#include <string>
#include <vector>
#include "chek_us.h"
#include "user.h"

chek_us::chek_us(std::vector<user>& _v, int _sizev): v(_v), sizev(_sizev)
{
	//cout << "Конструктор chek_us" << endl;
}
int chek_us::chek_logpas()   //Вход пользователя
{
	std::cout << "Введите логин:";
	std::cin >> log;
	bool login = false;
	bool pasw = false;
	int i;
	std::vector<user>::iterator it = v.begin();
	for (i = 0; i < v.size(); ++i)
	{
		if (log == (it + i)->get_login())   //Проверка логина
		{
			login = true;
			std::cout << "Введите пароль:";
			std::cin >> pas;
			if (pas == (it + i)->get_pasw())   //Проверка пароля
			{
				pasw = true;
				break;
			}
			else
			{
				std::cout << "Неверный пароль" << std::endl;
				break;
			}
		}
	}
	if (login && pasw && true)
	{
		std::cout << "Вход выполнен\n" << std::endl;
		return i;
	}
	if (login == false)
	{
		std::cout << "Неверный логин" << std::endl;
	}
	return -1;
}
int chek_us::chek_in()   //Регистрация нового пользователя
{
	if (v.size() >= sizev)   //Проверка на переполнение установленного размера 
	{
		throw "Извините, чат заполнен.\n";
	}
	else
	{
		bool login = true;
		std::string pas2;
		user newus;
		std::cout << "Введите логин:" << std::endl;
		std::cin >> log;
		std::vector<user>::iterator it = v.begin();
		for (int i = 0; i < v.size(); ++i)
		{
			if (log == (it + i)->get_login())
			{
				login = false;
				std::cout << "Логин уже занят" << std::endl;
				break;
			}
		}
		if (login == true)
		{
			std::cout << "Введите ваше имя:";
			std::cin >> name;
			std::cout << "Введите пароль:";
			std::cin >> pas;
			std::cout << "Подтвердите пароль:";
			std::cin >> pas2;
			if (pas2 == pas)
			{
				newus.set_login(log);
				newus.set_name(name);
				newus.set_pasw(pas);
				v.push_back(newus);
				std::cout << "Регистрация прошла успешно!" << std::endl;
			}
			else
			{
				std::cout << "Неверный пароль, регистрация прервана." << std::endl;
			}
		}
	}
	return v.size();
}
chek_us::~chek_us()
{
	//cout << "Деструктор chek_us" << endl;
}
