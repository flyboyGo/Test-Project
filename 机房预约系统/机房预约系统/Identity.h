#pragma once //��ֹͷ�ļ��ظ�����
#include <iostream>

using namespace std;

//��ݳ������
class Identity
{
public:
	//�û���
	string m_Name;
	//����
	string m_Pwd;

public:
	//�����˵� ���麯��
	virtual void openMenu() = 0;

	//����������
	virtual ~Identity() {};
};

