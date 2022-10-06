#include "speechManager.h"

SpeechManager::SpeechManager()
{
	//初始化成员属性、容器
	this->InitSpeech();

	//创建12具体的选手
	this->createSpeaker();

	//设置随机种子
	srand((unsigned int)time(NULL));

	//加载数据
	this->loadSpeech();
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::InitSpeech()
{
	//容器置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Record.clear();

	//初始化比赛轮数
	this->m_Index = 1;
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		//创建具体选手
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0 ;
		}

		//创建选手编号 并且放入到v1的容器中
		this->v1.push_back(i+1001);

		//选手编号以及对应选手 放入到map容器中
		this->m_Speaker.insert(make_pair(i + 1001, sp));
	}
}

void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "************* 欢迎参加演讲比赛 ************" << endl;
	cout << "************* 1.开始演讲比赛 *************" << endl;
	cout << "************* 2.查看往届记录 *************" << endl;
	cout << "************* 3.清空比赛记录 *************" << endl;
	cout << "************* 0.退出比赛程序 *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::speechDraw()
{
	cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签" << endl;
	cout << "------------------------" << endl;
	cout << "抽签后比赛顺序如下:" << endl;

	if (this->m_Index == 1)
	{
		//第一轮比赛
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//第二轮比赛
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
	cout << "-----第 " << this->m_Index << " 轮比赛正式开始-------" << endl;

	//准备临时容器 存放小组成绩
	multimap<double, int, greater<double>> groupScore;

	//记录人员数
	int num = 0;

	//比赛选手容器
	vector<int> v_Src;
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		//评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		//排序(降序)
		sort(d.begin(),d.end(),greater<double>());
		//取出最高分、最低分
		d.pop_front();
		d.pop_back();

		//计算平均分
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();

		//将平均分放入map容器中
		this->m_Speaker[*it].m_score[this->m_Index - 1] = avg;
		num++;

		//将打分的数据 放入小组临时容器中
		//key是得分 value是选手具体的编号
		groupScore.insert(make_pair(avg, *it));

		//每6个人一小组取出前三名
		if (num % 6 == 0)
		{
			cout << "第 " << num / 6 << " 小组比赛名次:" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " 姓名：" << this->m_Speaker[it->second].m_Name
					<< " 成绩：" << this->m_Speaker[it->second].m_score[this->m_Index -1] << endl;
			}

			//取走前三名
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

			//小组容器清空
			groupScore.clear();
			cout << endl;
		}
	}

	cout << "-------------第 " << this->m_Index << " 轮比赛完毕----------" << endl;;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "---------第 " << this->m_Index << " 轮晋级选手信息如下:----------" << endl;
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
		cout << "编号：" << *it << " 姓名：" << this->m_Speaker[*it].m_Name
			<< " 得分：" << this->m_Speaker[*it].m_score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	//用追加的方式写文件
	ofs.open("speech.csv", ios::out | ios::app);

	//将最终结果中每个选手的数据写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	//关闭
	ofs.close();
	cout << "记录保存完毕" << endl;

	//更改文件的状态
	this->fileIsEmpty = false;
}

void SpeechManager::startSpeech()
{
	//第一轮开始比赛

	//1、抽签
	this->speechDraw();

	//2、比赛
	this->speechContest();

	//3、显示晋级结果
	this->showScore();

	//更新比赛的轮数
	this->m_Index++;

	//第二轮开始比赛

	//1、抽签
	this->speechDraw();

	//2、比赛
	this->speechContest();

	//3、显示最终结果
	this->showScore();

	//4、保存最终结果
	this->saveRecord();

	cout << "本届比赛完毕!" << endl;

	//5、将新增的数据加载到容器中
	this->InitSpeech();
	this->createSpeaker();
	this->m_Record.clear();
	this->loadSpeech();
	cout << "新增比赛记录已经实时加载到容器中" << endl;

	system("pause");
	system("cls");
}

void SpeechManager::loadSpeech()
{
	//开始读文件
	//文件为空
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//文件清空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;
	//将上面单个读取的字符放回
	ifs.putback(ch);

	//开始解析数据
	string data;
	int index = 0;
	while (ifs >> data)
	{
		//存放记录信息
		vector<string> v; 

		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//未找到
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index,v));
		index++;
	}

	//关闭文件
	ifs.close();
}

void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空或者不存在" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第 " << i + 1 << "届"
				<< "冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
				<< "亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
				<< "季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << " "
				<< endl;
		}
	}

	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化属性
		this->InitSpeech();

		//创建选手
		this->createSpeaker();

		//重新加载往届记录
		this->loadSpeech();
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}

void SpeechManager::exit_System()
{
	cout << "欢迎下次再次使用" << endl;
	system("pause");
	exit(0);
}
