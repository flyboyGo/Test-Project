#pragma once
#include <iostream>
#include "Identity.h"
#include <map>
#include <fstream>
#include "Order.h"
#include <vector>

using namespace std;

class Teacher : public Identity
{
public:
	//职工号
	int m_EmpId;

	//预约记录容器

public:
	Teacher();

	Teacher(int id, string name, string pwd);

	~Teacher();

	//菜单界面
	virtual void openMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

};

