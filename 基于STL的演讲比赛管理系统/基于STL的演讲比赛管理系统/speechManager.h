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

//����ݽ������Ĺ�����
class SpeechManager
{
public:

	//�����һ�ֱ���ѡ�ֱ������
	vector<int> v1;

	//��һ�ֽ���ѡ�ֱ������
	vector<int> v2;

	//���ǰ����ѡ�ֱ������
	vector<int> vVictory;

	//��ű���Լ���Ӧ����ѡ������
	map<int, Speaker> m_Speaker;

	//��ű���������
	int m_Index;

	//��������¼������
	map<int, vector<string>> m_Record;

	//�ļ��Ƿ�Ϊ�յı�ʶ��
	bool fileIsEmpty;

public:

	//���캯��
	SpeechManager();

	//��������
	~SpeechManager();

	//��ʼ�����ܺ���
	void InitSpeech();

	//����12��ѡ��
	void createSpeaker();

	//�˵����ܺ���
	void show_Menu();

	//��ǩ���ܺ���
	void speechDraw();

	//�������Ĺ��ܺ���
	void speechContest();

	//��ʾ�÷ֹ��ܺ���
	void showScore();

	//�����¼���ܺ���
	void saveRecord();

	//�������幦���߼�����
	void startSpeech();

	//��ȡ��¼���ܺ���
	void loadSpeech();

	//չʾ�����¼��Ϣ
	void showRecord();

	//��ռ�¼���ܺ���
	void clearRecord();

	//�˳����ܺ���
	void exit_System();
};
