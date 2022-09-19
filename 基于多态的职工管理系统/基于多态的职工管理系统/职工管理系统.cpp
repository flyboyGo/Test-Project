#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "workerManager.h"

using namespace std;

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main(int argc, char* argv[])
{

	//实例化管理者对象
	WorkerManager wm = WorkerManager();

	//用户的选项
	int choice = 0;

	while (true)
	{
		//菜单函数
		wm.showMenu();

		cout << "请输入你的选项：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //退出系统
			wm.exitSystem();
			break;
		case 1: //增加职工
			wm.addEmp();
			break;
		case 2: //显示职工
			wm.showEmp();
			break;
		case 3: //删除职工
			wm.delEmp();
			break;
		case 4: //修改职工
			wm.modEmp();
			break;
		case 5: //查找职工
			wm.findEmp();
			break;
		case 6: //排序职工
			wm.sortEmp();
			break;
		case 7: //清空文档
			wm.cleatEmp();
			break;
		default:
			system("cls"); //清屏函数
			break;
		}
	}
	return 0;
}