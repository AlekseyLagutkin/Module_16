#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "chek_us.h"
#include "in_chat.h"

int main()
{
	setlocale(LC_ALL, "");
	int sizev = 5;   //Размер вектора - количество пользователей
	int my_num = 0;   //Текущий номер пользователя
	std::vector<user> v;  //Создание вектора пользователей
	
	std::cout << "Добро пожаловать в чат!\n";
	char in = 0;
	std::string str;
	while (true)
	{
		std::cout << "Для входа в чат введите 1, для регистрации введите 2, для завершения работы введите 3:" << std::endl;
		std::cin >> in;
		if (in == '3')
		{
			break;
		}
		if (in == '1')
		{
			chek_us User(v, sizev);
			my_num = User.chek_logpas();   //Проверка логина и пароля
			if (my_num >= 0)
			{
				in_chat Uchat(v, my_num);
				Uchat.s_mes();   //Отправка сообщений
			}

		}
		if (in == '2')
		{
			chek_us User(v, sizev);
			try
			{
				User.chek_in();   //Добавление нового пользователя
			}
			catch (const char* except)
			{
				std::cout << "Исключение: " << except << std::endl;
			}
		}
	}
	return 0;
}