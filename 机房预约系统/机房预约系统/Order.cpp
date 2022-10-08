#include "Order.h"

Order::Order()
{
	this->initMap();
}

void Order::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}
	
	ofstream ofs(ORDER_FILE,ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_oderData[i]["date"] << " ";
		ofs << "interval:" << this->m_oderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_oderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_oderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_oderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_oderData[i]["status"] << " " << endl;
	}

	ofs.close();
}

void Order::initMap()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date; //����
	string interval; //ʱ���
	string stuId; //ѧ�����
	string stuName; //ѧ������
	string roomId; //�������
	string status; //ԤԼ״̬

	this->m_Size = 0; //ԤԼ��¼��

	while (ifs >> date && ifs >> interval && ifs >> stuId && 
		   ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		string key;  string value;
		map<string, string> m1;

		//��ȡ��Ϣ
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m1.insert(make_pair(key,value));
		}

		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m1.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m1.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m1.insert(make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m1.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m1.insert(make_pair(key, value));
		}

		//��С��map�������뵽���map������
		this->m_oderData.insert(make_pair(this->m_Size,m1));
		this->m_Size++;
	}

	ifs.close();

}
