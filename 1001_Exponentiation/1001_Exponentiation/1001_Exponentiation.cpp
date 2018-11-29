// 1001_Exponentiation.cpp : 
// Copyright (c) 2018 YunqianLi. All rights reserved.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DEBUG

/* Debug-Macro */
#ifdef DEBUG
#define INFO(str) cout << str << endl;
#else
#define INFO(str) 
#endif

/* Define data tpye according to input data */
struct BIG_DATA_t {
	string	_int;// integer part of input data
	string	_frac;// fractional part of input data
	int		_n;// the exponentiation number, belong to (0, 25]
};

/* Get input data and split into integer and fractional parts */
void getData(vector<BIG_DATA_t > & big_data)
{
	string str;
	unsigned int str_int;
	unsigned int str_frac;
	int n;
	while (cin >> str >> n)// get input data
	{
		INFO("input data : " << str << ", " << n);
		BIG_DATA_t tmp;
		int length = strlen(str.c_str());
		sscanf(str.c_str(), "%d.%d", &str_int, &str_frac);// split str into two parts
		INFO(str_int);
		INFO(str_frac);
		tmp._int = to_string(str_int);
		tmp._frac = to_string(str_frac);
		tmp._n = n;
		INFO("after split : " << tmp._int << ", " << tmp._frac << ", " << tmp._n);
		big_data.push_back(tmp);// push into big_data
	}
}

/* Process the big_data, in this case it is exponential operation  */
void procData(vector<BIG_DATA_t> & big_data)
{
	for (vector<BIG_DATA_t>::iterator iter = big_data.begin(); iter < big_data.end(); ++iter)
	{

	}
}


/* Main function */
int main()
{
	vector<BIG_DATA_t> big_data;// to contain all input data
	getData(big_data);// get input data and split
	//procData(big_data);// calculate the result

	return 0;
}