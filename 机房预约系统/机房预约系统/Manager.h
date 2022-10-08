#pragma once
#include<iostream>
#include "Identity.h"
#include <fstream>
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include <vector>
#include <algorithm>
#include "ComputerRoom.h"

using namespace std;

class Manager : public Identity
{
public:
	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	//机房容器
	vector<ComputerRoom> vComp;

public:
	Manager();

	Manager(string name, string pwd);

	~Manager();

	//菜单界面
	virtual void openMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showRomm();

	//清空所有预约信息
	void clearAllOrder();

	//初始化容器
	void InitVector();

	//检测重复(参数1 学号/职工号 参数2 文件类型)
	bool checkRepeat(int id, int type);
};

