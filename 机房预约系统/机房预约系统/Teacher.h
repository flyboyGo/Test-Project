#pragma once
#include <iostream>
#include "Identity.h"
#include <map>
#include <fstream>
#include "Order.h"
#include <vector>

using namespace std;

class Teacher : public Identity
{
public:
	//ְ����
	int m_EmpId;

	//ԤԼ��¼����

public:
	Teacher();

	Teacher(int id, string name, string pwd);

	~Teacher();

	//�˵�����
	virtual void openMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

};

