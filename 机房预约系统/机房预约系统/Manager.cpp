#include "Manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������
	this->InitVector();
}

Manager::~Manager()
{

}

void Manager::openMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2����ӽ�ʦ" << endl;

	string fileName; //�������ļ���
	string tip; //��ʾid��
	string errTip; //������ʾ

	ofstream ofs; //�ļ���������

	int select = 0;
	cin >> select; //�����û���ѡ��

	if (select == 1)
	{
		//���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errTip = "ѧ���ظ�������������!";
	}
	else if (select == 2)
	{
		//��ӽ�ʦ
		fileName = TEACHER_FILE;
		tip = "������ְ���ţ�";
		errTip = "ְ�����ظ�������������!";
	}

	//����׷�ӵķ�ʽ д�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id; //ѧ�Ż�ְ����
	string name; //����
	string pwd; //����

	cout << tip << endl;
	//���id�Ƿ��ظ�
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


	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�!" << endl;

	system("pause");
	system("cls");

	//�ر��ļ�
	ofs.close();

	//���³�ʼ������
	this->InitVector();

}

void printStudent(Student &stu)
{
	cout << "ѧ�ţ�" << stu.m_Id << " ������" << stu.m_Name << " ���룺" << stu.m_Pwd << endl;
}

void printTeacher(Teacher& tea)
{
	cout << "ְ���ţ�" << tea.m_EmpId << " ������" << tea.m_Name << " ���룺" << tea.m_Pwd << endl;
}

void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£� " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "������ʦ��Ϣ���£� " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");

}

void Manager::showRomm()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
	{
		cout << "������ţ�" << it->m_CompNum << " ����������" << it->m_CompNum << endl;
	}

	system("pause");
	system("cls");
}

void Manager::clearAllOrder()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");
}

void Manager::InitVector()
{
	//�������
	this->vStu.clear();
	this->vTea.clear();
	this->vComp.clear();


	//��ȡ�ļ���Ϣ ѧ�� ��ʦ ����
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "ѧ���ļ���ȡʧ��!" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ��������Ϊ��" << this->vStu.size() << endl;
	ifs.close();

	

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʦ�ļ���ȡʧ��!" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << this->vTea.size() << endl;
	ifs.close();



	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�����ļ���ȡʧ��!" << endl;
		return;
	}
	ComputerRoom comp;
	while (ifs >> comp.m_CompId && ifs >> comp.m_CompNum)
	{
		vComp.push_back(comp);
	}
	cout << "��ǰ��������Ϊ��" << this->vComp.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
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
		//����ʦ
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
 