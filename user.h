#pragma once
#include <string>
#include <deque>

//using namespace std;

class user {
public:
	user();
	void set_login(std::string log);
	void set_pasw(std::string pas);
	void set_name(std::string nam);
	void sent_mes(std::string s_mes, std::string r_user);   //Отправка сообщения
	void rec_mes(std::string r_mes, std::string s_user);   //Прием сообщения
	std::string get_login();
	std::string get_pasw();
	std::string get_name();
	void show_mes();   //Вывод отправленных и входящих сообщений
	std::string qw;
	~user();
private:
	std::string login;
	std::string pasw;
	std::string name;
	int sz = 3;   //Количество сохраняемых сообщений
	struct s_mes   //Отправленные сообщения
	{
		std::string sent;   //Сообщение
		std::string to;   //Кому
	};
	struct r_mes   //Принятые сообщения
	{
		std::string rec;   //Сообщение
		std::string from;   //От кого
	};
	std::deque<s_mes> sm;   //Хранилище отправленных сообщений
	std::deque<r_mes> rm;   //Хранилище принятых сообщений

	//string sent_1;   //Отправленное сообщение 1
	//string sent_2;   //Отправленное сообщение 2
	//string to_1;     //Кому отправлено сообщение 1
	//string to_2;     //Кому отправлено сообщение 2
	//string rec_1;    //Принятое сообщение 1
	//string rec_2;    //Принятое сообщение 2
	//string from_1;   //От кого принято сообщение 1
	//string from_2;   //От кого принято сообщение 2
};
