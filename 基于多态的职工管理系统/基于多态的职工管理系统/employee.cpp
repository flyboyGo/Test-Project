#include "employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Id = did;
}

void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\tְ����λ��" << this->getDeptName()
		<< "\t��λְ��" << this->getDeptDuty()
		<< endl;
}

string Employee::getDeptName()
{
	return string("��ͨԱ��"); //��const char * ת��Ϊ string Ҳ�����б�������ʽת��
}

string Employee::getDeptDuty()
{
	return string("��ɾ�����������");
}

Employee::~Employee()
{

}
