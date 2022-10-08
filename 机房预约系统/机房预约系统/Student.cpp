#include "Student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化
	this->initVector();
}

Student::~Student()
{

}

void Student::openMenu()
{
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t|----------------------------------|\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|----------------------------------|\n";
	cout << "请选择您的操作： " << endl;
}

void Student::applyOrder()
{

	int date = 0; //日期
	int interval = 0; //时间段
	int room = 0; //机房编号

	cout << "机房开放的时间为周一至周五" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	while (true) 
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}


	cout << "请输入申请预约时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择机房：" << endl;
	for (int i = 0; i < vComp.size(); i++)
	{
		cout << vComp[i].m_CompId << "号机房容量为：" << vComp[i].m_CompNum << endl;

	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功，审核中!" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	//实时更新容器
	this->initVector();

	system("pause");
	system("cls");
}

void Student::showOrder()
{
	Order order;
	if (order.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < order.m_Size; i++)
	{
		//string 转为 int
		//string 利用 .c_str() 转 const char *
		//利用 atoi(const char *) 转 int
		if (this->m_Id == atoi(order.m_oderData[i]["stuId"].c_str())) //找到自身的预约
		{
			cout << "预约日期：周" << order.m_oderData[i]["date"] << "  ";
			cout << "时间段：" << (order.m_oderData[i]["interval"] == "1" ? "上午" : "下午") << "  ";
			cout << "机房编号：" << order.m_oderData[i]["roomId"] << "  ";
			string status = "状态：";
			//1、审核中 2、已预约 -1、预约失败 0、取消预约
			if (order.m_oderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (order.m_oderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (order.m_oderData[i]["status"] == "-1")
			{
				status += "预约失败,审核未通过";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	Order order;
	if (order.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < order.m_Size; i++)
	{
		    cout << i + 1 << "、";
			cout << "预约日期：周" << order.m_oderData[i]["date"] << "  ";
			cout << "时间段：" << (order.m_oderData[i]["interval"] == "1" ? "上午" : "下午") << "  ";
			cout << "学号：" << order.m_oderData[i]["stuId"] << "  ";
			cout << "姓名：" << order.m_oderData[i]["stuName"] << " ";
			cout << "机房编号：" << order.m_oderData[i]["roomId"] << "  ";
			string status = "状态：";
			//1、审核中 2、已预约 -1、预约失败 0、取消预约
			if (order.m_oderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (order.m_oderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (order.m_oderData[i]["status"] == "-1")
			{
				status += "预约失败,审核未通过";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
}

void Student::cancelOrder()
{
	Order order;
	if (order.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录是可以取消的,请输入取消的记录" << endl;

	vector<int> v; // 存放在最大容器中的下标编号
	int index = 1;
	for (int i = 0; i < order.m_Size; i++)
	{
		if (this->m_Id == atoi(order.m_oderData[i]["stuId"].c_str())) //找到自身的预约
		{
			if (order.m_oderData[i]["status"] == "1" || order.m_oderData[i]["status"] == "2") //找到审核中或预约成功的激励
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << order.m_oderData[i]["date"] << "  ";
				cout << "时间段：" << (order.m_oderData[i]["interval"] == "1" ? "上午" : "下午") << "  ";
				cout << "机房编号：" << order.m_oderData[i]["roomId"] << "  ";
				
				string status = "状态：";
				//1、审核中 2、已预约 -1、预约失败 0、取消预约
				if (order.m_oderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (order.m_oderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}

	cout << "请输入取消的记录,0代表返回" << endl;
	int select = 0;

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				order.m_oderData[v[select - 1]]["status"] = "0";
				order.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误,请重新输入!" << endl;
	}
	
	system("pause");
	system("cls");
}

void Student::initVector()
{
	//初始化机房容器
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	ComputerRoom comp;
	while (ifs >> comp.m_CompId && ifs >> comp.m_CompNum)
	{
		//将读取的信息放入到容器中
		vComp.push_back(comp);
	}
}
