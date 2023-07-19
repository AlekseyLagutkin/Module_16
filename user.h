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
	void sent_mes(std::string s_mes, std::string r_user);   //�������� ���������
	void rec_mes(std::string r_mes, std::string s_user);   //����� ���������
	std::string get_login();
	std::string get_pasw();
	std::string get_name();
	void show_mes();   //����� ������������ � �������� ���������
	std::string qw;
	~user();
private:
	std::string login;
	std::string pasw;
	std::string name;
	int sz = 3;   //���������� ����������� ���������
	struct s_mes   //������������ ���������
	{
		std::string sent;   //���������
		std::string to;   //����
	};
	struct r_mes   //�������� ���������
	{
		std::string rec;   //���������
		std::string from;   //�� ����
	};
	std::deque<s_mes> sm;   //��������� ������������ ���������
	std::deque<r_mes> rm;   //��������� �������� ���������

	//string sent_1;   //������������ ��������� 1
	//string sent_2;   //������������ ��������� 2
	//string to_1;     //���� ���������� ��������� 1
	//string to_2;     //���� ���������� ��������� 2
	//string rec_1;    //�������� ��������� 1
	//string rec_2;    //�������� ��������� 2
	//string from_1;   //�� ���� ������� ��������� 1
	//string from_2;   //�� ���� ������� ��������� 2
};
