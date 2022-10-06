#include "speechManager.h"

SpeechManager::SpeechManager()
{
	//��ʼ����Ա���ԡ�����
	this->InitSpeech();

	//����12�����ѡ��
	this->createSpeaker();

	//�����������
	srand((unsigned int)time(NULL));

	//��������
	this->loadSpeech();
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::InitSpeech()
{
	//�����ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Record.clear();

	//��ʼ����������
	this->m_Index = 1;
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		//��������ѡ��
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0 ;
		}

		//����ѡ�ֱ�� ���ҷ��뵽v1��������
		this->v1.push_back(i+1001);

		//ѡ�ֱ���Լ���Ӧѡ�� ���뵽map������
		this->m_Speaker.insert(make_pair(i + 1001, sp));
	}
}

void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "************* ��ӭ�μ��ݽ����� ************" << endl;
	cout << "************* 1.��ʼ�ݽ����� *************" << endl;
	cout << "************* 2.�鿴�����¼ *************" << endl;
	cout << "************* 3.��ձ�����¼ *************" << endl;
	cout << "************* 0.�˳��������� *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::speechDraw()
{
	cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "------------------------" << endl;
	cout << "��ǩ�����˳������:" << endl;

	if (this->m_Index == 1)
	{
		//��һ�ֱ���
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//�ڶ��ֱ���
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	cout << "------------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::speechContest()
{
	cout << "-----�� " << this->m_Index << " �ֱ�����ʽ��ʼ-------" << endl;

	//׼����ʱ���� ���С��ɼ�
	multimap<double, int, greater<double>> groupScore;

	//��¼��Ա��
	int num = 0;

	//����ѡ������
	vector<int> v_Src;
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		//��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		//����(����)
		sort(d.begin(),d.end(),greater<double>());
		//ȡ����߷֡���ͷ�
		d.pop_front();
		d.pop_back();

		//����ƽ����
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();

		//��ƽ���ַ���map������
		this->m_Speaker[*it].m_score[this->m_Index - 1] = avg;
		num++;

		//����ֵ����� ����С����ʱ������
		//key�ǵ÷� value��ѡ�־���ı��
		groupScore.insert(make_pair(avg, *it));

		//ÿ6����һС��ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "�� " << num / 6 << " С���������:" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << " ������" << this->m_Speaker[it->second].m_Name
					<< " �ɼ���" << this->m_Speaker[it->second].m_score[this->m_Index -1] << endl;
			}

			//ȡ��ǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			//С���������
			groupScore.clear();
			cout << endl;
		}
	}

	cout << "-------------�� " << this->m_Index << " �ֱ������----------" << endl;;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "---------�� " << this->m_Index << " �ֽ���ѡ����Ϣ����:----------" << endl;
	vector<int> v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��ţ�" << *it << " ������" << this->m_Speaker[*it].m_Name
			<< " �÷֣�" << this->m_Speaker[*it].m_score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	//��׷�ӵķ�ʽд�ļ�
	ofs.open("speech.csv", ios::out | ios::app);

	//�����ս����ÿ��ѡ�ֵ�����д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	//�ر�
	ofs.close();
	cout << "��¼�������" << endl;

	//�����ļ���״̬
	this->fileIsEmpty = false;
}

void SpeechManager::startSpeech()
{
	//��һ�ֿ�ʼ����

	//1����ǩ
	this->speechDraw();

	//2������
	this->speechContest();

	//3����ʾ�������
	this->showScore();

	//���±���������
	this->m_Index++;

	//�ڶ��ֿ�ʼ����

	//1����ǩ
	this->speechDraw();

	//2������
	this->speechContest();

	//3����ʾ���ս��
	this->showScore();

	//4���������ս��
	this->saveRecord();

	cout << "����������!" << endl;

	//5�������������ݼ��ص�������
	this->InitSpeech();
	this->createSpeaker();
	this->m_Record.clear();
	this->loadSpeech();
	cout << "����������¼�Ѿ�ʵʱ���ص�������" << endl;

	system("pause");
	system("cls");
}

void SpeechManager::loadSpeech()
{
	//��ʼ���ļ�
	//�ļ�Ϊ��
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//�ļ����
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	//�����浥����ȡ���ַ��Ż�
	ifs.putback(ch);

	//��ʼ��������
	string data;
	int index = 0;
	while (ifs >> data)
	{
		//��ż�¼��Ϣ
		vector<string> v; 

		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//δ�ҵ�
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index,v));
		index++;
	}

	//�ر��ļ�
	ifs.close();
}

void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߲�����" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "�� " << i + 1 << "��"
				<< "�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
				<< "�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
				<< "������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << " "
				<< endl;
		}
	}

	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������
		this->InitSpeech();

		//����ѡ��
		this->createSpeaker();

		//���¼��������¼
		this->loadSpeech();
		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}

void SpeechManager::exit_System()
{
	cout << "��ӭ�´��ٴ�ʹ��" << endl;
	system("pause");
	exit(0);
}
