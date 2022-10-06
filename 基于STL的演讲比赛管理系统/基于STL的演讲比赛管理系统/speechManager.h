#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <time.h>
#include <fstream>
#include "speaker.h"


using namespace std;

//设计演讲比赛的管理类
class SpeechManager
{
public:

	//保存第一轮比赛选手编号容器
	vector<int> v1;

	//第一轮晋级选手编号容器
	vector<int> v2;

	//最后前三名选手编号容器
	vector<int> vVictory;

	//存放编号以及对应具体选手容器
	map<int, Speaker> m_Speaker;

	//存放比赛的轮数
	int m_Index;

	//存放往届记录的容器
	map<int, vector<string>> m_Record;

	//文件是否为空的标识符
	bool fileIsEmpty;

public:

	//构造函数
	SpeechManager();

	//析构函数
	~SpeechManager();

	//初始化功能函数
	void InitSpeech();

	//创建12名选手
	void createSpeaker();

	//菜单功能函数
	void show_Menu();

	//抽签功能函数
	void speechDraw();

	//比赛核心功能函数
	void speechContest();

	//显示得分功能函数
	void showScore();

	//保存记录功能函数
	void saveRecord();

	//比赛整体功能逻辑函数
	void startSpeech();

	//读取记录功能函数
	void loadSpeech();

	//展示往届记录信息
	void showRecord();

	//清空记录功能函数
	void clearRecord();

	//退出功能函数
	void exit_System();
};
