#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\tְ����λ��" << this->getDeptName()
		<< "\t��λְ��" << this->getDeptDuty()
		<< endl;
}

string Manager::getDeptName()
{
	return string("����");
}

string Manager::getDeptDuty()
{
	return string("����ϰ彻��������,�����·��������ͬԱ��");
}

Manager::~Manager()
{

}
