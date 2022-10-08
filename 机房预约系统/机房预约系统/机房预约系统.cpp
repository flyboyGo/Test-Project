#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

using namespace std;

//学生子菜单
void studentMenu(Identity* student)
{
	while (true)
	{
		//学生菜单
		student->openMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showOrder();
		}
		else if (select == 3) //查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else if(select == 0) //注销登录
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			system("pause");
			system("cls");
		}
	}
}

//教师子菜单
void teacherMenu(Identity* teacher)
{
	while (true)
	{
		//教师菜单
		teacher->openMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//进入管理员的子菜单界面
void managerMenu(Identity * manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->openMenu();

		//将父类指针 转为子类指针 调用子类里面的其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接收用户的选项
		cin >> select;

		if (select == 1) //添加账号
		{
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			man->showRomm();
		}
		else if (select == 4)//清空预约
		{
			man->clearAllOrder();
		}
		else if(select == 0) //注销登录
		{
			delete manager;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			system("pause");
			system("cls");
		}
	}
}

//登录接口全局函数
//参数1 操作文件名  参数2 操作身份类型
void LoginIn(string fileName, int type)
{
	//父类指针指向父类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接收用户输入的信息
	int id = 0;
	string name;
	string pwd;

	//判断用户的身份
	if (type == 1) 
	{
		//学生
		cout << "输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		//教师
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		//从文件中读取的学生信息
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息作对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证信息通过" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//进入学生子菜单界面
				person = new Student(id,name,pwd);
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		//从文件中读取的教师信息
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息作对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师身份信息验证通过" << endl;
				system("pause");
				system("cls");

				//进入教师子菜单界面
				person = new Teacher(id, name, pwd);
				teacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		//从文件中读取的管理员信息
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息作对比
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员身份信息验证通过" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//进入管理员的子菜单界面
				managerMenu(person);

				return;
			}
		}
	}

	cout << "登录身份验证失败" << endl;
	system("pause");
	system("cls");
	return;
}

int main(int argc, char* argv[])
{
	int select = 0;

	while (true)
	{

		cout << "======================  欢迎来到机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.教    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择

		switch (select)
		{
		case 1:  //学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");

	return 0;
}