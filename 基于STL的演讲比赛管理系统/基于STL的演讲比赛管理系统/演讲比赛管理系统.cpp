#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "speechManager.h"

using namespace std;

int main(int argc, char* argv[])
{
	//创建管理类对象
	SpeechManager sm;

	//用来存储用户的选项
	int choice = 0; 
	while (true)
	{
		sm.show_Menu();

		cout << "请输入您的选择： " << endl;
		cin >> choice; // 接受用户的选项

		switch (choice)
		{
		case 1: //开始比赛
			sm.startSpeech();
			break;
		case 2: //查看记录
			sm.showRecord();
			break;
		case 3: //清空记录
			sm.clearRecord();
			break;
		case 0: //退出系统
			sm.exit_System();
			break;
		default://清屏
			system("cls"); 
			break;
		}
	}
	system("pause");
	return 0;
}