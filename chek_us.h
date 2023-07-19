#pragma once
#include <string>
#include <vector>
#include "user.h"

class chek_us   //Регистрация и вход пользователей в чат
{
public:
	chek_us(std::vector<user>& _v, int _sizev);   //Вектор с данными пользователей, максимальный размер вектора
	int chek_logpas();   //Проверка логина и пароля
	int chek_in();   //Регистрация нового пользователя
	~chek_us();
private:
	std::vector<user>& v;
	int sizev;
	std::string log;
	std::string pas;
	std::string name;
};