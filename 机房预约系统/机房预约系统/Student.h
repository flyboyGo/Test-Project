#pragma once
#include <iostream>
#include "Identity.h"
#include <string>
#include <vector>
#include "ComputerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "Order.h"

using namespace std;

class Student : public Identity
{
public:
	//ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vComp;

public:
	Student();

	Student(int id,string name,string pwd);

	~Student();

	//�˵�ҳ��
	virtual void openMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//��ʼ����Ա����
	void initVector();

};

