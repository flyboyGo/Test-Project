#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "speechManager.h"

using namespace std;

int main(int argc, char* argv[])
{
	//�������������
	SpeechManager sm;

	//�����洢�û���ѡ��
	int choice = 0; 
	while (true)
	{
		sm.show_Menu();

		cout << "����������ѡ�� " << endl;
		cin >> choice; // �����û���ѡ��

		switch (choice)
		{
		case 1: //��ʼ����
			sm.startSpeech();
			break;
		case 2: //�鿴��¼
			sm.showRecord();
			break;
		case 3: //��ռ�¼
			sm.clearRecord();
			break;
		case 0: //�˳�ϵͳ
			sm.exit_System();
			break;
		default://����
			system("cls"); 
			break;
		}
	}
	system("pause");
	return 0;
}