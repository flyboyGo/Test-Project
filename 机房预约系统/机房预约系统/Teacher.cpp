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
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Teacher::showAllOrder()
{
	Order order;
	if (order.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < order.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << order.m_oderData[i]["date"] << "  ";
		cout << "ʱ��Σ�" << (order.m_oderData[i]["interval"] == "1" ? "����" : "����") << "  ";
		cout << "ѧ�ţ�" << order.m_oderData[i]["stuId"] << "  ";
		cout << "������" << order.m_oderData[i]["stuName"] << " ";
		cout << "������ţ�" << order.m_oderData[i]["roomId"] << "  ";
		string status = "״̬��";
		//1������� 2����ԤԼ -1��ԤԼʧ�� 0��ȡ��ԤԼ
		if (order.m_oderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (order.m_oderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (order.m_oderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��,���δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
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
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵�ԤԼ��¼���£�" << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < order.m_Size; i++)
	{
		if (order.m_oderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���" << order.m_oderData[i]["date"] << "  ";
			cout << "ʱ��Σ�" << (order.m_oderData[i]["interval"] == "1" ? "����" : "����") << "  ";
			cout << "ѧ�ţ�" << order.m_oderData[i]["stuId"] << "  ";
			cout << "������" << order.m_oderData[i]["stuName"] << " ";
			cout << "������ţ�" << order.m_oderData[i]["roomId"] << "  ";
			string status = "״̬��";
			//1������� 2����ԤԼ -1��ԤԼʧ�� 0��ȡ��ԤԼ
			if (order.m_oderData[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << status << endl;
		}
	}

	cout << "��������˵�ԤԼ��¼,0������" << endl;
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
				cout << "��������˽����" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//ͨ�����
					order.m_oderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					//��ͨ�����
					order.m_oderData[v[select - 1]]["status"] = "-1";
				}

				order.updateOrder();
				cout << "������" << endl;
				break;
			}
		}
		cout << "��������,����������!" << endl;
	}

	system("pause");
	system("cls");
}


