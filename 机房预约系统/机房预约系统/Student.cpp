#include "Student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��
	this->initVector();
}

Student::~Student()
{

}

void Student::openMenu()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t|----------------------------------|\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|----------------------------------|\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Student::applyOrder()
{

	int date = 0; //����
	int interval = 0; //ʱ���
	int room = 0; //�������

	cout << "�������ŵ�ʱ��Ϊ��һ������" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	while (true) 
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}


	cout << "����������ԤԼʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vComp.size(); i++)
	{
		cout << vComp[i].m_CompId << "�Ż�������Ϊ��" << vComp[i].m_CompNum << endl;

	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������!" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	//ʵʱ��������
	this->initVector();

	system("pause");
	system("cls");
}

void Student::showOrder()
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
		//string תΪ int
		//string ���� .c_str() ת const char *
		//���� atoi(const char *) ת int
		if (this->m_Id == atoi(order.m_oderData[i]["stuId"].c_str())) //�ҵ������ԤԼ
		{
			cout << "ԤԼ���ڣ���" << order.m_oderData[i]["date"] << "  ";
			cout << "ʱ��Σ�" << (order.m_oderData[i]["interval"] == "1" ? "����" : "����") << "  ";
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
	}

	system("pause");
	system("cls");
}

void Student::showAllOrder()
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
}

void Student::cancelOrder()
{
	Order order;
	if (order.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼�ǿ���ȡ����,������ȡ���ļ�¼" << endl;

	vector<int> v; // �������������е��±���
	int index = 1;
	for (int i = 0; i < order.m_Size; i++)
	{
		if (this->m_Id == atoi(order.m_oderData[i]["stuId"].c_str())) //�ҵ������ԤԼ
		{
			if (order.m_oderData[i]["status"] == "1" || order.m_oderData[i]["status"] == "2") //�ҵ�����л�ԤԼ�ɹ��ļ���
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << order.m_oderData[i]["date"] << "  ";
				cout << "ʱ��Σ�" << (order.m_oderData[i]["interval"] == "1" ? "����" : "����") << "  ";
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
				cout << status << endl;
			}
		}
	}

	cout << "������ȡ���ļ�¼,0������" << endl;
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
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "��������,����������!" << endl;
	}
	
	system("pause");
	system("cls");
}

void Student::initVector()
{
	//��ʼ����������
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	ComputerRoom comp;
	while (ifs >> comp.m_CompId && ifs >> comp.m_CompNum)
	{
		//����ȡ����Ϣ���뵽������
		vComp.push_back(comp);
	}
}
