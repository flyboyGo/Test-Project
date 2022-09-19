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

	//ʵ���������߶���
	WorkerManager wm = WorkerManager();

	//�û���ѡ��
	int choice = 0;

	while (true)
	{
		//�˵�����
		wm.showMenu();

		cout << "���������ѡ�" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: //����ְ��
			wm.addEmp();
			break;
		case 2: //��ʾְ��
			wm.showEmp();
			break;
		case 3: //ɾ��ְ��
			wm.delEmp();
			break;
		case 4: //�޸�ְ��
			wm.modEmp();
			break;
		case 5: //����ְ��
			wm.findEmp();
			break;
		case 6: //����ְ��
			wm.sortEmp();
			break;
		case 7: //����ĵ�
			wm.cleatEmp();
			break;
		default:
			system("cls"); //��������
			break;
		}
	}
	return 0;
}