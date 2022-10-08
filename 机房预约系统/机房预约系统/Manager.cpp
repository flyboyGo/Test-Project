#include "Manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器
	this->InitVector();
}

Manager::~Manager()
{

}

void Manager::openMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加教师" << endl;

	string fileName; //操作的文件名
	string tip; //提示id号
	string errTip; //错误提示

	ofstream ofs; //文件操作对象

	int select = 0;
	cin >> select; //接收用户的选项

	if (select == 1)
	{
		//添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errTip = "学号重复，请重新输入!";
	}
	else if (select == 2)
	{
		//添加教师
		fileName = TEACHER_FILE;
		tip = "请输入职工号：";
		errTip = "职工号重复，请重新输入!";
	}

	//利用追加的方式 写文件
	ofs.open(fileName, ios::out | ios::app);

	int id; //学号或职工号
	string name; //姓名
	string pwd; //密码

	cout << tip << endl;
	//检测id是否重复
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errTip << endl;
		}
		else
		{
			break;
		}
	}


	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功!" << endl;

	system("pause");
	system("cls");

	//关闭文件
	ofs.close();

	//重新初始化容器
	this->InitVector();

}

void printStudent(Student &stu)
{
	cout << "学号：" << stu.m_Id << " 姓名：" << stu.m_Name << " 密码：" << stu.m_Pwd << endl;
}

void printTeacher(Teacher& tea)
{
	cout << "职工号：" << tea.m_EmpId << " 姓名：" << tea.m_Name << " 密码：" << tea.m_Pwd << endl;
}

void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下： " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下： " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");

}

void Manager::showRomm()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
	{
		cout << "机房编号：" << it->m_CompNum << " 机房容量：" << it->m_CompNum << endl;
	}

	system("pause");
	system("cls");
}

void Manager::clearAllOrder()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}

void Manager::InitVector()
{
	//清空容器
	this->vStu.clear();
	this->vTea.clear();
	this->vComp.clear();


	//读取文件信息 学生 教师 机房
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "学生文件读取失败!" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生的数量为：" << this->vStu.size() << endl;
	ifs.close();

	

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "教师文件读取失败!" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师数量为：" << this->vTea.size() << endl;
	ifs.close();



	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "机房文件读取失败!" << endl;
		return;
	}
	ComputerRoom comp;
	while (ifs >> comp.m_CompId && ifs >> comp.m_CompNum)
	{
		vComp.push_back(comp);
	}
	cout << "当前机房数量为：" << this->vComp.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else if (type == 2)
	{
		//检测教师
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}

	return false;
}
 