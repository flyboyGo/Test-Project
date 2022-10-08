#include "Teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int id, string name, string pwd)
{
	this->m_EmpId = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

Teacher::~Teacher()
{

}

void Teacher::openMenu()
{
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Teacher::showAllOrder()
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
	system("pause");
	system("cls");
}

void Teacher::validOrder()
{
	Order order;
	if (order.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的预约记录如下：" << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < order.m_Size; i++)
	{
		if (order.m_oderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、";
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
			cout << status << endl;
		}
	}

	cout << "请输入审核的预约记录,0代表返回" << endl;
	int select = 0;
	int ret = 0;
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
				cout << "请输入审核结果：" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//通过情况
					order.m_oderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					//不通过情况
					order.m_oderData[v[select - 1]]["status"] = "-1";
				}

				order.updateOrder();
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入有误,请重新输入!" << endl;
	}

	system("pause");
	system("cls");
}


