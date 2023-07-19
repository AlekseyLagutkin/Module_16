#pragma once
#include <string>
#include <vector>
#include "user.h"

class chek_us   //����������� � ���� ������������� � ���
{
public:
	chek_us(std::vector<user>& _v, int _sizev);   //������ � ������� �������������, ������������ ������ �������
	int chek_logpas();   //�������� ������ � ������
	int chek_in();   //����������� ������ ������������
	~chek_us();
private:
	std::vector<user>& v;
	int sizev;
	std::string log;
	std::string pas;
	std::string name;
};