#pragma once
#include<iostream>
#include "Identity.h"
#include <fstream>
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include <vector>
#include <algorithm>
#include "ComputerRoom.h"

using namespace std;

class Manager : public Identity
{
public:
	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<ComputerRoom> vComp;

public:
	Manager();

	Manager(string name, string pwd);

	~Manager();

	//�˵�����
	virtual void openMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showRomm();

	//�������ԤԼ��Ϣ
	void clearAllOrder();

	//��ʼ������
	void InitVector();

	//����ظ�(����1 ѧ��/ְ���� ����2 �ļ�����)
	bool checkRepeat(int id, int type);
};

