// 1001_Exponentiation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct DATA_t {
	string R;
	unsigned int n;
};


int main()
{



	vector<DATA_t > data;
	getData(data);
	procData(data);
}


void getData( vector<DATA_t > & data )
{
	DATA_t tmpData;
	while ( cin >> tmpData.R >> tmpData.n )
	{
		data.push_back(tmpData);
	}
}

void procData(vector<DATA_t> & data)
{
	
	for(vector<DATA_t >::iterator iter; iter)
}

