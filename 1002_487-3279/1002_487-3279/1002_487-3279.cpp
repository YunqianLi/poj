//// 1001_Exponentiation.cpp : 
//// Copyright (c) 2018 YunqianLi. All rights reserved.
//
//#include <iostream>
//#include <vector>
//#include <map>
//#include <string>
#include <time.h>
//#include <algorithm>
//
//using namespace std;
//
//#define DEBUG
//
//
///* Debug-Macro */
//#ifdef DEBUG
//clock_t clock_begin;
//clock_t clock_begin_main;
//#define INFO(str) \
//do {\
//		std::cout << "<LINE" << __LINE__ << "> " << str << std::endl;\
//}while(0)
//#define TIME(name) \
//do {\
//	INFO(name << " time cost is " << double(clock() - clock_begin) / CLOCKS_PER_SEC * 1000 << " ms" ); \
//	clock_begin = clock();}while (0)
//#define TIME_MAIN(name) \
//do {\
//	INFO(name << " time cost is " << double(clock() - clock_begin_main) / CLOCKS_PER_SEC * 1000 << " ms" ); \
//	clock_begin_main = clock();}while (0)
///* Check the input data */
//void checkData(vector<std::string> & telNum)
//{
//	for (vector<std::string>::iterator iter = telNum.begin(); iter < telNum.end(); ++iter)
//		std::cout << *iter << std::endl;
//}
//#else
//#endif
//
//
///* Get and parse input data */
//void getData(vector<std::string> & telNum)
//{
//	freopen("./sample_input.txt", "r", stdin);// to debug locally
//	int numbers;
//	std::cin >> numbers;// (0, 100000]
//	for (int i = 0; i < numbers; ++i)
//	{
//		string tel;
//		std::cin >> tel;
//		telNum.push_back(tel);
//	}
//}
//
//
//
///* Transform format to standard */
//void fmtTransform(std::string & str)
//{
//	for (int i = 0; i < str.length(); ++i)
//	{
//		//if (str[i] <= '9') continue;
//		//else if (str[i] <= 'C') str[i] = '2';
//		//else if (str[i] <= 'F') str[i] = '3';
//		//else if (str[i] <= 'I') str[i] = '4';
//		//else if (str[i] <= 'L') str[i] = '5';
//		//else if (str[i] <= 'O') str[i] = '6';
//		//else if (str[i] <= 'S') str[i] = '7';
//		//else if (str[i] <= 'V') str[i] = '8';
//		//else if (str[i] <= 'Y') str[i] = '9';
//		switch (str[i])
//		{
//		case 'A':
//		case 'B':
//		case 'C':
//			str[i] = '2';
//			break;
//		case 'D':
//		case 'E':
//		case 'F':
//			str[i] = '3';
//			break;
//		case 'G':
//		case 'H':
//		case 'I':
//			str[i] = '4';
//			break;
//		case 'J':
//		case 'K':
//		case 'L':
//			str[i] = '5';
//			break;
//		case 'M':
//		case 'N':
//		case 'O':
//			str[i] = '6';
//			break;
//		case 'P':
//		case 'R':
//		case 'S':
//			str[i] = '7';
//			break;
//		case 'T':
//		case 'U':
//		case 'V':
//			str[i] = '8';
//			break;
//		case 'W':
//		case 'X':
//		case 'Y':
//			str[i] = '9';
//			break;
//		default: break;
//		}
//
//	}
//}
//
//
///* Process the input data
//* first, delete "-"
//* then, transform to standard format
//* then, compare
//* last, sort by ascending
//*/
//void procData(vector<std::string> & input_data, vector<std::string> & output_data)
//{
//	// deal with special case
//	if (input_data.size() == 1) {
//		output_data.push_back("No duplicates.");
//		return;
//	}
//	// common case
//	for (vector<std::string>::iterator iter = input_data.begin(); iter < input_data.end(); ++iter)
//	{
//		// delete "-"
//		iter->erase(std::remove(iter->begin(), iter->end(), '-'), iter->end());
//		// transform to standard format
//		fmtTransform(*iter);
//	}
////#ifdef DEBUG
////	// check data after transform 
////	checkData(input_data);
////#endif
//	// compare
//	int validNum = input_data.size();
//	while (validNum > 1)
//	{
//		string base = input_data.front();
//		int times = 0;
//		vector<std::string>::iterator iter = input_data.begin();
//		for (; iter != input_data.end();)
//		{
//			if (base.compare(*iter) == 0) {// if same, times++ and erase it
//				iter = input_data.erase(iter);
//				++times;
//			}
//			else
//				++iter;
//		}
//		//if (times > 1)// if repeat, push into output_data
//		//	output_data.push_back(base + " " + std::to_string(times));
//		if (times > 1)
//		{
//			std::string times_str;
//			while (times)
//			{
//				times_str.insert(0, 1, char(times % 10 + '0'));
//				times = times / 10;
//			}
//			base.insert(3, "-");
//			output_data.push_back(base + " " + times_str);
//		}
//		validNum = input_data.size();// update validNum for while-loop
//	}
//	if (output_data.size())
//		// sort by ascending(default of sort, descending is std::greater<std::string>() )
//		std::sort(output_data.begin(), output_data.end());
//	else
//		output_data.push_back("No duplicates.");
//}
//
///* Print the result */
//void printResult(vector<std::string> & output_data)
//{
//#ifdef DEBUG
//	
//#endif
//	for (vector<std::string>::iterator iter = output_data.begin(); iter < output_data.end(); ++iter)
//		std::cout << *iter << std::endl;
//}
//
///* Main function */
//int main()
//{
//#ifdef DEBUG
//	clock_begin_main = clock();
//	clock_begin = clock();
//	vector<std::string> input_data;
//	vector<std::string> output_data;
//	TIME("construct()");
//	getData(input_data);
//	TIME("getData()");
//	//INFO("Check input data:");
//	//checkData(input_data);
//	//TIME("checkData()");
//	procData(input_data, output_data);
//	TIME("procData()");
//	INFO("Result:");
//	printResult(output_data);
//	TIME("printResult()");
//	TIME_MAIN("Total");
//#else
//	clock_t clock_begin_main = clock();
//	vector<std::string> input_data;
//	vector<std::string> output_data;
//	getData(input_data);
//	procData(input_data, output_data);
//	printResult(output_data);
//	std::cout << "Total time cost is " << double(clock() - clock_begin_main) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
//#endif
//}

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;
char convert(char c) {
	if (c <= 'C') return '2';
	else if (c <= 'F') return '3';
	else if (c <= 'I') return '4';
	else if (c <= 'L') return '5';
	else if (c <= 'O') return '6';
	else if (c <= 'S') return '7';
	else if (c <= 'V') return '8';
	else if (c <= 'Y') return '9';
}
int main()
{
	clock_t clock_begin_main = clock();
	freopen("./sample_input.txt", "r", stdin);// to debug locally
	int N;
	bool flag = false;
	cin >> N;
	map<string, int> telp_count;
	while (N--) {
		string s, res;
		cin >> s;
		int i = 0;
		for (string::iterator s_it = s.begin(); s_it != s.end(); ++s_it) {
			if (*s_it >= '0' && *s_it <= '9') res.push_back(*s_it);
			if (*s_it >= 'A' && *s_it <= 'Z') res.push_back(convert(*s_it));
		}
		res.insert(3, 1, '-');
		++telp_count[res];
	}
	map<string, int>::iterator map_it = telp_count.begin();
	for (; map_it != telp_count.end(); ++map_it)
		if (map_it->second >= 2) {
			flag = true;
			cout << map_it->first << " " << map_it->second << endl;
		}
	if (!flag)
		cout << "No duplicates." << endl;
	std::cout << "Total time cost is " << double(clock() - clock_begin_main) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	return 0;
}
