#include "employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Id = did;
}

void Employee::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t职工岗位：" << this->getDeptName()
		<< "\t岗位职责：" << this->getDeptDuty()
		<< endl;
}

string Employee::getDeptName()
{
	return string("普通员工"); //将const char * 转换为 string 也可以有编译器隐式转换
}

string Employee::getDeptDuty()
{
	return string("完成经理交给的任务");
}

Employee::~Employee()
{

}
