#pragma once
#include <iostream>
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>


using namespace std;

class Order
{
public:
	//ԤԼ��¼��
	int m_Size;

	//ԤԼ��¼��Ϣ����  key��¼��  valueԤԼ��¼����ϸ��Ϣ
	map<int, map<string, string>> m_oderData;

public:

	Order();

	//���º���
	void updateOrder();

	//��ʼ������
	void initMap();
	
};

