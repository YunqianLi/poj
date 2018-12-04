// 1001_Exponentiation.cpp : 
// Copyright (c) 2018 YunqianLi. All rights reserved.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DEBUG
//#define ONLINE_JUDGE

/* Debug-Macro */
#ifdef DEBUG
#define INFO(str) std::cout << str << std::endl;
#else
#define INFO(str) 
#endif

/* Define input and ouput data tpye */
struct INPUT_DATA_t {
	std::string	  data;       // the big data without decimal point "."
	int			  times;      // the exponentiation number, belong to (0, 25]
	int		      fracNum;	  // the number of the fractional part of the result
};


/* Get and parse input data */
void getData(vector<INPUT_DATA_t > & input_data)
{
#ifndef ONLINE_JUDGE
	freopen("./sample_input.txt", "r", stdin);// to debug locally
#endif
	INPUT_DATA_t in_data;
	while (std::cin >> in_data.data >> in_data.times)// get input data
	{
		// remove suffix 0 (when fractional)
		if (in_data.data.find('.') != -1) {
			int end = in_data.data.length() - 1;
			while (end >= 0 && in_data.data.at(end) == '0')
				--end;
			in_data.data = in_data.data.substr(0, end + 1);
		}
		// remove decimal point and mark the length of fractional part of result
		int pos = in_data.data.find('.');
		if (pos != -1) {
			int length = in_data.data.length();
			in_data.data.erase(pos, 1);
			in_data.fracNum = in_data.times * (length - pos - 1);
		}
		// remove prefix 0
		int start = 0;
		while ((start < in_data.data.length()) && (in_data.data.at(start) == '0'))
			++start;		
		in_data.data = in_data.data.substr(start, in_data.data.length() - start);
		// reverse data to compute more easily
		std::reverse(in_data.data.begin(), in_data.data.end());
		// push into input_data
		input_data.push_back(in_data);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);// to debug locally
#endif
}

/* Check the input data */
void checkData(vector<INPUT_DATA_t> & input_data)
{
	INFO("\nCheck input data:");
	for (vector<INPUT_DATA_t>::iterator iter = input_data.begin(); iter < input_data.end(); ++iter)
	{
		INFO((*iter).data << ", " << (*iter).fracNum << ", " << (*iter).times);
	}
}

std::string & mulBigdata(const std::string & multiplicand, const std::string & multiplier)
{
	string product;
	// simplify: multiplicand->m, multiplier->n, only if len1 >= len2
	const string* m = &multiplicand;
	const string* n = &multiplier;
	if (multiplicand.length() < multiplier.length())
	{// exchange m and n, if len1<len2
		m = &multiplier;
		n = &multiplicand;
	}
	for (int i = 0; i < n->length(); ++i)
	{
		
	}

	return product;
}

void expBigdata(std::string & data, int times)
{
	if (times == 1)
		return;
	std::string result;
	result = data;
	for (int i = 0; i < times; ++i)
	{
		result = mulBigdata(result, data);// multiply iteratively
	}	
	data = result;
	/* TODO: reduce the number of multiply operations */
	//if (times % 2 == 0)
	//{

	//}
	//else
	//{

	//}
}

void mvDecimalPoint(std::string & bigdata, int fracNum)
{
	if (bigdata.length() >= fracNum)
	{
		bigdata.insert(fracNum,".");
	}
	else
	{
		std::string zeroStr(fracNum - bigdata.length(), '0');
		zeroStr.append(".");
		bigdata.append(zeroStr);
	}
	std::reverse(bigdata.begin(), bigdata.end());
}

/* Process the big_data, in this case it is exponential operation  */
void procData(vector<INPUT_DATA_t> & input_data, vector<std::string> & output_data)
{
	string	bigdata;
	for (vector<INPUT_DATA_t>::iterator iter = input_data.begin(); iter < input_data.end(); ++iter)
	{		
		if (iter->times <= 0)
		{
			INFO("WARNING: the expNum of input data is not an integer such that 0 < expNum <= 25.");
			bigdata = "INVALID INPUT!";
		}
		else
		{
			bigdata = iter->data;
			expBigdata(bigdata, iter->times);
			mvDecimalPoint(bigdata, iter->fracNum);
		}
		output_data.push_back(bigdata);//push the calculation result into vector output_result
	}
}

/* Print the result */
void printResult(vector<std::string> & output_data)
{
	INFO("\nResult:");
	for (vector<std::string>::iterator iter = output_data.begin(); iter < output_data.end(); ++iter)
	{
		INFO((*iter));
	}
}

string& tempTset()
{
	string tmp = "hello";
	return tmp;
}

/* Main function */
int main()
{
	vector<INPUT_DATA_t> input_data;// to contain all input data
	vector<std::string> big_data;// to contain all result data, i.e. big data, i.e. string

	//getData(input_data);// get input
	//checkData(input_data);// check input 
	//procData(input_data, big_data);// calculate result
	//printResult(big_data);// print result

	string tmp;
	tmp = tempTset();

	return 0;
}