#pragma once
#include <iostream>
#include "Identity.h"
#include <string>
#include <vector>
#include "ComputerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "Order.h"

using namespace std;

class Student : public Identity
{
public:
	//学号
	int m_Id;

	//机房容器
	vector<ComputerRoom> vComp;

public:
	Student();

	Student(int id,string name,string pwd);

	~Student();

	//菜单页面
	virtual void openMenu();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//初始化成员属性
	void initVector();

};

