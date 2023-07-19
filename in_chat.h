#pragma once
#include <string>
#include "user.h"

class in_chat   //Отправка и просмотр сообщений
{
public:
	in_chat(std::vector<user>& _v, int _my_num);   //Ссылка на вектор, номер пользователя
	void s_mes();   //Отправка сообщений
	~in_chat();
private:
	std::vector<user>& v;
	int my_num;
	std::string my_log;
	std::string my_name;
};
