#pragma once
#include <string>
#include "user.h"

class in_chat   //�������� � �������� ���������
{
public:
	in_chat(std::vector<user>& _v, int _my_num);   //������ �� ������, ����� ������������
	void s_mes();   //�������� ���������
	~in_chat();
private:
	std::vector<user>& v;
	int my_num;
	std::string my_log;
	std::string my_name;
};
