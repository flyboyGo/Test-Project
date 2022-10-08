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
	//预约记录数
	int m_Size;

	//预约记录信息容器  key记录数  value预约记录的详细信息
	map<int, map<string, string>> m_oderData;

public:

	Order();

	//更新函数
	void updateOrder();

	//初始化容器
	void initMap();
	
};

