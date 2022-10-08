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

//ѧ���Ӳ˵�
void studentMenu(Identity* student)
{
	while (true)
	{
		//ѧ���˵�
		student->openMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showOrder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else if(select == 0) //ע����¼
		{
			delete student;
			cout << "ע���ɹ�" << endl;
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

//��ʦ�Ӳ˵�
void teacherMenu(Identity* teacher)
{
	while (true)
	{
		//��ʦ�˵�
		teacher->openMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//�������Ա���Ӳ˵�����
void managerMenu(Identity * manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->openMenu();

		//������ָ�� תΪ����ָ�� ������������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û���ѡ��
		cin >> select;

		if (select == 1) //����˺�
		{
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			man->showRomm();
		}
		else if (select == 4)//���ԤԼ
		{
			man->clearAllOrder();
		}
		else if(select == 0) //ע����¼
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

//��¼�ӿ�ȫ�ֺ���
//����1 �����ļ���  ����2 �����������
void LoginIn(string fileName, int type)
{
	//����ָ��ָ�������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û��������Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж��û������
	if (type == 1) 
	{
		//ѧ��
		cout << "�������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		//��ʦ
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		//���ļ��ж�ȡ��ѧ����Ϣ
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��Ϣͨ��" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//����ѧ���Ӳ˵�����
				person = new Student(id,name,pwd);
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		//���ļ��ж�ȡ�Ľ�ʦ��Ϣ
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ�����Ϣ��֤ͨ��" << endl;
				system("pause");
				system("cls");

				//�����ʦ�Ӳ˵�����
				person = new Teacher(id, name, pwd);
				teacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		//���ļ��ж�ȡ�Ĺ���Ա��Ϣ
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա�����Ϣ��֤ͨ��" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//�������Ա���Ӳ˵�����
				managerMenu(person);

				return;
			}
		}
	}

	cout << "��¼�����֤ʧ��" << endl;
	system("pause");
	system("cls");
	return;
}

int main(int argc, char* argv[])
{
	int select = 0;

	while (true)
	{

		cout << "======================  ��ӭ��������ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select; //�����û�ѡ��

		switch (select)
		{
		case 1:  //ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");

	return 0;
}