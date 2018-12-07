// 1001_Exponentiation.cpp : 
// Copyright (c) 2018 YunqianLi. All rights reserved.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <time.h>
#include <algorithm>

using namespace std;

#define DEBUG

/* Debug-Macro */
#ifdef DEBUG
#include <time.h>
#define INFO(str) std::cout << "<LINE" << __LINE__ << "> " << str << std::endl;
#else
#define INFO(str) 
#endif


/* Get and parse input data */
void getData(vector<std::string> & telNum)
{
#ifdef DEBUG
	freopen("./sample_input.txt", "r", stdin);// to debug locally
#endif
	int numbers;
	std::cin >> numbers;// (0, 100000]
	for (int i = 0; i < numbers; ++i)
	{
		string tel;
		std::cin >> tel;
		telNum.push_back(tel);
	}
}

/* Check the input data */
void checkData(vector<std::string> & telNum)
{
	INFO("Check input data:");
	for (vector<std::string>::iterator iter = telNum.begin(); iter < telNum.end(); ++iter)
		INFO((*iter));
}

/* Transform format to standard */
void fmtTransform(std::string & str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		switch (str[i])
		{
		case 'A':
		case 'B':
		case 'C':
			str[i] = '2';
			break;
		case 'D':
		case 'E':
		case 'F':
			str[i] = '3';
			break;
		case 'G':
		case 'H':
		case 'I':
			str[i] = '4';
			break;
		case 'J':
		case 'K':
		case 'L':
			str[i] = '5';
			break;
		case 'M':
		case 'N':
		case 'O':
			str[i] = '6';
			break;
		case 'P':
		case 'R':
		case 'S':
			str[i] = '7';
			break;
		case 'T':
		case 'U':
		case 'V':
			str[i] = '8';
			break;
		case 'W':
		case 'X':
		case 'Y':
			str[i] = '9';
			break;
		default: break;
		}
	}
}


/* Process the input data
* first, delete "-"
* then, transform to standard format
* then, compare
* last, sort by ascending
*/
void procData(vector<std::string> & input_data, vector<std::string> & output_data)
{
	// deal with special case
	if (input_data.size() == 1)	{
		output_data.push_back("No duplicates.");
		return;
	}
	// common case
	for (vector<std::string>::iterator iter = input_data.begin(); iter < input_data.end(); ++iter)
	{
		// delete "-"
		iter->erase(std::remove(iter->begin(), iter->end(), '-'), iter->end());
		// transform to standard format
		fmtTransform(*iter);
	}
#ifdef DEBUG
	// check data after transform 
	checkData(input_data);
#endif
	// compare
	int validNum = input_data.size();
	while (validNum > 1)
	{
		string base = input_data.front();
		int times = 0;
		vector<std::string>::iterator iter = input_data.begin();
		for (; iter != input_data.end();)
		{
			if (base.compare(*iter) == 0){// if same, times++ and erase it
				iter = input_data.erase(iter);
				++times;
			}else
				++iter;
		}
		if (times > 1)// if repeat, push into output_data
			output_data.push_back(base + " " + std::to_string(times));
		validNum = input_data.size();// update validNum for while-loop
	}
	if (output_data.size())
	    // sort by ascending(default of sort, descending is std::greater<std::string>() )
		std::sort(output_data.begin(), output_data.end());
	else
		output_data.push_back("No duplicates.");
}

/* Print the result */
void printResult(vector<std::string> & output_data)
{
#ifdef DEBUG
	INFO("\nResult:");
#endif
	for (vector<std::string>::iterator iter = output_data.begin(); iter < output_data.end(); ++iter)
		std::cout << *iter << std::endl;
}

/* Main function */
int main()
{
	vector<std::string> input_data;
	vector<std::string> output_data;

	getData(input_data);
#ifdef DEBUG
	checkData(input_data);
#endif

#ifdef DEBUG
	clock_t begin, end;
	begin = clock();
#endif

	procData(input_data, output_data);
	printResult(output_data);

#ifdef DEBUG
	end = clock();
	double dur = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "\nTime cost is " << dur * 1000 << "ms. ";
	std::cout << "Program exit." << std::endl;
#endif

	return 0;
}