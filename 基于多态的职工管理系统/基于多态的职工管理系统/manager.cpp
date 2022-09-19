#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t职工岗位：" << this->getDeptName()
		<< "\t岗位职责：" << this->getDeptDuty()
		<< endl;
}

string Manager::getDeptName()
{
	return string("经理");
}

string Manager::getDeptDuty()
{
	return string("完成老板交给的任务,并且下发任务给不同员工");
}

Manager::~Manager()
{

}
