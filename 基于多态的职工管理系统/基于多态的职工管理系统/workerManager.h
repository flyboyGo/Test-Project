#pragma once //��ֹͷ�ļ��ظ�����
#include <iostream> //���������������ͷ�ļ�
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.txt" //�ļ�·��

using namespace std; //ʹ�ñ�׼�����ռ�

class WorkerManager
{
public:

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//�ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;
	
	//���캯��
	WorkerManager();

	//�˵�����
	void showMenu();

	//�˳�����
	void exitSystem();

	//��ӡ����
	void showEmp();

	//��պ���
	void cleatEmp();

	//������
	void sortEmp();

	//���Һ���
	void findEmp();

	//�޸ĺ���
	void modEmp();

	//ɾ������
	void delEmp();

	//���ں��� ������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int isExit(int id);

	//��Ӻ���
	void addEmp();

	//��ʼ������
	void InitEmp();

	//���溯��
	void save();

	//ͳ�ƺ���
	int countEmpNum();

	//Ѱ�����ְ����
	int searchMaxId();

	//��������
	~WorkerManager();
};

