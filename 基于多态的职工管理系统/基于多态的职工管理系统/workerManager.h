#pragma once //防止头文件重复包含
#include <iostream> //包含输出、输入六头文件
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.txt" //文件路径

using namespace std; //使用标准命名空间

class WorkerManager
{
public:

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//文件是否为空的标志
	bool m_FileIsEmpty;
	
	//构造函数
	WorkerManager();

	//菜单函数
	void showMenu();

	//退出函数
	void exitSystem();

	//打印函数
	void showEmp();

	//清空函数
	void cleatEmp();

	//排序函数
	void sortEmp();

	//查找函数
	void findEmp();

	//修改函数
	void modEmp();

	//删除函数
	void delEmp();

	//存在函数 如果存在返回职工所在数组中的位置，不存在返回-1
	int isExit(int id);

	//添加函数
	void addEmp();

	//初始化函数
	void InitEmp();

	//保存函数
	void save();

	//统计函数
	int countEmpNum();

	//寻找最大职工号
	int searchMaxId();

	//析构函数
	~WorkerManager();
};

