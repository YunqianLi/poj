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

/* Define input and ouput data tpye */
struct INPUT_DATA_t {
	string	data;       // the big data without decimal point "."
	int     fracNum;	// the number of the fraction part
	int		times;		// the exponentiation number, belong to (0, 25]
};
struct OUTPUT_DATA_t {
	string  data;		// the big data without decimal point "."
	int		fracNum;	// the number of the fraction part
};


/* Get input data and split into integer and fractional parts */
void getData(vector<INPUT_DATA_t > & input_data)
{
	string data;
	int times;
	while (cin >> data >> times)// get input data
	{
		// locationing where to remove prefix 0
		int start = 0;	
		while (start < data.length && data.at(start) == 0)
			++start;
		// locationing where to remove suffix 0 (when fractional)
		int end = data.length() - 1;
		int pos = data.find('.');
		if (pos != -1) {
			while (end >= 0 && data.at(end) == '0')
				--end;
		}
		// get valid data
		data = data.substr(start, end - start + 1);
		// remove decimal point and mark the length of fractional part of result
		pos = data.find('.');
		if (pos != -1) {
			data.erase(pos, 1);
			pos = times * (data.length);//???
		}

	}
}

/* Check the big_data */
void checkData(vector<INPUT_DATA_t> & input_data)
{
	INFO("\nCheck input data:");
	for (vector<INPUT_DATA_t>::iterator iter = input_data.begin(); iter < input_data.end(); ++iter)
	{
		INFO((*iter).data << ", " << (*iter).fracNum << ", " << (*iter).times);
	}
}

void mulBigdata(string & _int, string & _frac, int & _fracNum)
{

}

void expBigdata(string & data, int times)
{
	if (times == 1)
		return;
	
}

/* Process the big_data, in this case it is exponential operation  */
void procData(vector<INPUT_DATA_t> & input_data, vector<OUTPUT_DATA_t> & output_data)
{
	int data_length = input_data.size();
	for (int i = 0; i < data_length; ++i)
	{
		OUTPUT_DATA_t	tmp;
		tmp.data = input_data[i].data;
		int times = input_data[i].times;
		tmp.fracNum = input_data[i].fracNum * times;
		if (times <= 0)
		{
			INFO("WARNING: the expNum of input data is not an integer such that 0 < expNum <= 25.")
		}			
		else
		{
			expBigdata(tmp.data, times);
		}		
		output_data.push_back(tmp);//push the calculation result into vector output_result
	}
}

/* Print the result */
void printResult(vector<OUTPUT_DATA_t> & output_result)
{
	INFO("\nResult:");
	int data_length = output_result.size();
	for (int i = 0; i < data_length; ++i)
	{
		INFO("");
	}
}


/* Main function */
int main()
{
	vector<INPUT_DATA_t> input_data;// to contain all input data
	vector<OUTPUT_DATA_t> big_data;// to contain all result data, i.e. big data, i.e. string

	getData(input_data);// get input
	checkData(input_data);// check input 
	procData(input_data, big_data);// calculate result
	printResult(big_data);// print result

	return 0;
}