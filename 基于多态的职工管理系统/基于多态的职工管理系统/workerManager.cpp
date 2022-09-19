#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�

	//1���ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������!" << endl; //�������
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	else
	{
		char ch;
		ifs >> ch;
		//2���ļ����� ����Ϊ��
		if (ifs.eof())
		{
			//�ļ�Ϊ��
			cout << "�ļ�Ϊ��" << endl;
			//��ʼ������
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
			ifs.close();
			return;
		}
		//3���ļ����� ���ݲ�Ϊ��
		else
		{
			int num = this->countEmpNum();
			cout << "ְ������Ϊ��" << num << endl;
			this->m_EmpNum = num;
			this->m_FileIsEmpty = false;
			//���ٿռ�
			this->m_EmpArray = new Worker * [this->m_EmpNum];
			//���ļ��е����ݣ��浽������
			this->InitEmp();

			//for (int i = 0; i < this->m_EmpNum; i++)
			//{
			//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
			//		<< " ������" << this->m_EmpArray[i]->m_Name
			//		<< " ���ű�ţ�" << this->m_EmpArray[i]->m_DeptId
			//		<< endl;
			//}
		}
	}
}

void WorkerManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); //�˳�����
}

void WorkerManager::showEmp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty == true)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::cleatEmp()
{
	cout << "ȷ������ļ���"
		<< " 1��ȷ�� "
		<< " 2������ "
		<< endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc); //ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::sortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ķ�ʽ "
			<< " 1������ְ������ "
			<< " 2������ְ������ "
			<< endl;
		
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i; //������Сֵ ���� ���ֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1) //����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else if(select == 2) //����
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "�������" << endl;
				}
			}

			//��������
			if (i != minOrMax)
			{
				Worker* tmp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = tmp;
			}
		}
	}
	cout << "����ɹ�" << endl;

	//�������ݵ��ļ���
	this->save();
	this->showEmp();
}

void WorkerManager::findEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��"
			<< " 1����ְ����Ų��� "
			<< " 2����ְ���������� "
			<< endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//���ձ�Ų���
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = this->isExit(id);
			if (ret != -1)
			{
				//�ҵ�ְ��
				cout << "���ҳɹ�,��Ա������Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if(select == 2)
		{
			//������������
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			//�Ƿ�鵽�ı�ʶ
			bool flag = false; //Ĭ��δ���絽

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					flag = true;
					cout << "���ҳɹ�,��ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "���޴���" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::modEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->isExit(id);
		if (ret != -1)
		{
			//���絽���
			//����ԭ�ȵ�ְ�����
			int id = this->m_EmpArray[ret]->m_Id;
			//�ͷ�ԭ��ָ��Ŀռ�����
			delete this->m_EmpArray[ret];

			string name;
			int dSelect = 0;
			
			cout << "�������µ�������" << endl;
			cin >> name;

			cout << "�������µĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;

			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				cout << "�������" << endl;
				break;
			}

			//�������� ��������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ�" << endl;

			//�������ݵ��ļ���
			this->save();
		}
		else
		{
			cout << "���޴���,�޸�ʧ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::delEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExit(id);

		if (index != -1) //ְ�����ڣ�������Ҫɾ��indexλ���ϵ�ְ����Ϣ
		{
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//���������м�¼����
			this->m_EmpNum--;
			//ͬ���������ݵ��ļ���
			this->save();
			//�����ļ��Ƿ�Ϊ�յı�ʶ��
			if (this->countEmpNum() == 0)
			{
				this->m_FileIsEmpty = true;
			}
			else
			{
				this->m_FileIsEmpty = false;
			}

			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ��,δ�ҵ���ְ��" << endl;
		}
	}
	//������� ���
	system("pause");
	system("cls");
}

int WorkerManager::isExit(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//�ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::addEmp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;//�����û����������   
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum; //�¿ռ�����

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ�����,�������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id; //ְ�����
			string name; //ְ������
			int dSelect; //����ѡ��

			//cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			//cin >> id;
			id = this->searchMaxId() + 1;

			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "�������!" << endl;
				break;
			}

			//������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//�ɹ���Ӻ� �������ݵ��ļ���
		this->save();
	}
	else
	{
		cout << "�������������!" << endl;
	}

	//���μ��� �����ص��ϼ�
	system("pause");
	system("cls");
}

void WorkerManager::InitEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1) //��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else//�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		//װ������
		this->m_EmpArray[index] = worker;
		index++;
	}

	//�ر��ļ�
	ifs.close();
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //������ķ�ʽ���ļ� -- д�ļ�

	//��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//�ر��ļ�
	ofs.close();
}

int WorkerManager::countEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ� ��

	int id;
	string name;
	int dId;

	//ͳ������
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

int WorkerManager::searchMaxId()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�

	//1���ļ�������
	if (!ifs.is_open())
	{
		return 0;
	}
	else
	{
		char ch;
		ifs >> ch;
		//2���ļ����� ����Ϊ��
		if (ifs.eof())
		{
			return 0;
		}
		//3���ļ����� ���ݲ�Ϊ��
		else
		{
			int max = 0;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (max < this->m_EmpArray[i]->m_Id)
				{
					max = this->m_EmpArray[i]->m_Id;
				}
			}
			return max;
		}
	}
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
