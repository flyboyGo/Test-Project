#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //读文件

	//1、文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在!" << endl; //测试输出
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	else
	{
		char ch;
		ifs >> ch;
		//2、文件存在 数据为空
		if (ifs.eof())
		{
			//文件为空
			cout << "文件为空" << endl;
			//初始化属性
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
			ifs.close();
			return;
		}
		//3、文件存在 数据不为空
		else
		{
			int num = this->countEmpNum();
			cout << "职工人数为：" << num << endl;
			this->m_EmpNum = num;
			this->m_FileIsEmpty = false;
			//开辟空间
			this->m_EmpArray = new Worker * [this->m_EmpNum];
			//将文件中的数据，存到数组中
			this->InitEmp();

			//for (int i = 0; i < this->m_EmpNum; i++)
			//{
			//	cout << "职工编号：" << this->m_EmpArray[i]->m_Id
			//		<< " 姓名：" << this->m_EmpArray[i]->m_Name
			//		<< " 部门编号：" << this->m_EmpArray[i]->m_DeptId
			//		<< endl;
			//}
		}
	}
}

void WorkerManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0); //退出程序
}

void WorkerManager::showEmp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty == true)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::cleatEmp()
{
	cout << "确认清空文件："
		<< " 1、确定 "
		<< " 2、返回 "
		<< endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc); //删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::sortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序的方式 "
			<< " 1、按照职工升序 "
			<< " 2、按照职工降序 "
			<< endl;
		
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i; //声明最小值 或者 最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else if(select == 2) //降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "输入错误" << endl;
				}
			}

			//交换数据
			if (i != minOrMax)
			{
				Worker* tmp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = tmp;
			}
		}
	}
	cout << "排序成功" << endl;

	//保存数据到文件中
	this->save();
	this->showEmp();
}

void WorkerManager::findEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式："
			<< " 1、按职工编号查找 "
			<< " 2、按职工姓名查找 "
			<< endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按照编号查找
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = this->isExit(id);
			if (ret != -1)
			{
				//找到职工
				cout << "查找成功,该员工的信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if(select == 2)
		{
			//按照姓名查找
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			//是否查到的标识
			bool flag = false; //默认未查早到

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					flag = true;
					cout << "查找成功,该职工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::modEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入需要修改的职工编号：" << endl;
		int id;
		cin >> id;

		int ret = this->isExit(id);
		if (ret != -1)
		{
			//查早到编号
			//保存原先的职工编号
			int id = this->m_EmpArray[ret]->m_Id;
			//释放原先指向的空间内容
			delete this->m_EmpArray[ret];

			string name;
			int dSelect = 0;
			
			cout << "请输入新的姓名：" << endl;
			cin >> name;

			cout << "请输入新的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;

			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				cout << "输入错误" << endl;
				break;
			}

			//更新数据 到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功" << endl;

			//保存数据到文件中
			this->save();
		}
		else
		{
			cout << "查无此人,修改失败" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::delEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除的职工编号" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExit(id);

		if (index != -1) //职工存在，并且需要删除index位置上的职工信息
		{
			//数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新数组中记录个数
			this->m_EmpNum--;
			//同步更新数据到文件中
			this->save();
			//更新文件是否为空的标识符
			if (this->countEmpNum() == 0)
			{
				this->m_FileIsEmpty = true;
			}
			else
			{
				this->m_FileIsEmpty = false;
			}

			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败,未找到该职工" << endl;
		}
	}
	//按任意键 清空
	system("pause");
	system("cls");
}

int WorkerManager::isExit(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::addEmp()
{
	cout << "请输入添加职工人数：" << endl;
	int addNum = 0;//保存用户输入的人数   
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加新空间的大小
		int newSize = this->m_EmpNum + addNum; //新空间人数

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间数据,拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id; //职工编号
			string name; //职工姓名
			int dSelect; //部门选择

			//cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			//cin >> id;
			id = this->searchMaxId() + 1;

			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "输入错误!" << endl;
				break;
			}

			//将创建职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有的空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新职工不为空的标志
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;

		//成功添加后 保存数据到文件中
		this->save();
	}
	else
	{
		cout << "输入的数据有误!" << endl;
	}

	//按任键后 清屏回到上级
	system("pause");
	system("cls");
}

void WorkerManager::InitEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1) //普通职工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else//老板
		{
			worker = new Boss(id, name, dId);
		}
		//装填数据
		this->m_EmpArray[index] = worker;
		index++;
	}

	//关闭文件
	ifs.close();
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //用输出的方式打开文件 -- 写文件

	//将每个人数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//关闭文件
	ofs.close();
}

int WorkerManager::countEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //打开文件 读

	int id;
	string name;
	int dId;

	//统计人数
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

int WorkerManager::searchMaxId()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //读文件

	//1、文件不存在
	if (!ifs.is_open())
	{
		return 0;
	}
	else
	{
		char ch;
		ifs >> ch;
		//2、文件存在 数据为空
		if (ifs.eof())
		{
			return 0;
		}
		//3、文件存在 数据不为空
		else
		{
			int max = 0;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (max < this->m_EmpArray[i]->m_Id)
				{
					max = this->m_EmpArray[i]->m_Id;
				}
			}
			return max;
		}
	}
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
