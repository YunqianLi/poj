// 1001_Exponentiation.cpp : 
// Copyright (c) 2018 YunqianLi. All rights reserved.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include<Psapi.h>

using namespace std;

#define DEBUG

/* Debug-Macro */
#ifdef DEBUG
#include <time.h>
#define INFO(str) std::cout << "<LINE" << __LINE__ << "> " << str << std::endl;
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
#ifdef DEBUG
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
		reverse(in_data.data.begin(), in_data.data.end());
		// push into input_data
		input_data.push_back(in_data);
	}
#ifdef DEBUG
	fclose(stdin);// to debug locally
#endif
}

/* Check the input data */
void checkData(vector<INPUT_DATA_t> & input_data)
{
	INFO("Check input data:");
	for (vector<INPUT_DATA_t>::iterator iter = input_data.begin(); iter < input_data.end(); ++iter)
	{
		INFO((*iter).data << ", " << (*iter).fracNum << ", " << (*iter).times);
	}
}

/* Bigdata's multiply operation 
* for example: 123 x 45 = 5535
* in this case: multiplicand is "321" and multiplier is "54"
* and the result should be "5355"
* so the input and ouput must be reverse to pirnt the right result.
*/
std::string mulBigdata(const std::string & multiplicand, const std::string & multiplier)
{
	string product;
	// simplify: multiplicand->m, multiplier->n, only if len1 >= len2
	const string* mStr = &multiplicand;
	const string* nStr = &multiplier;
	if (multiplicand.length() < multiplier.length())
	{// exchange m and n, if len1<len2
		mStr = &multiplier;
		nStr = &multiplicand;
	}
	// use int[] array to hold the mStr string
	int mLen = mStr->length();
	int nLen = nStr->length();
	int *m = new int[mLen];
	int *n = new int[nLen];
	for (int i = 0; i < mLen; ++i)
	{
		m[i] = mStr->at(i) - '0';
	}
	for (int i = 0; i < nLen; ++i)
	{
		n[i] = nStr->at(i) - '0';
	}
	// mainloop to compute product
	int p = m[0] * n[0] % 10;//p->product,
	product.push_back(p + '0');// product[0]
	int c1 = m[0] * n[0] / 10;//c1->inherent_carrier = m[i]*n[j]/10
	int c2 = 0;//c2->accumulate_carrier = sum( m(i)*n(j)%10 )
	for (int i = 1; i < mLen + nLen - 1; ++i)
	{// product[1, mLen+nLen-2]
		p = 0;
		int c1_new = 0;
		if (i < nLen - 1)
		{// product[1, nlen-2]
			for (int j = 0; j <= i; ++j)
			{
				p += n[j] * m[i - j] % 10;
				c1_new += n[j] * m[i - j] / 10;
			}
		}
		else if (i >= nLen - 1 && i < mLen)
		{// [nlen-1, mLen-1]
			for (int j = 0; j < nLen; ++j)
			{
				p += n[j] * m[i - j] % 10;
				c1_new += n[j] * m[i - j] / 10;
			}
		}
		else if (i >= mLen)
		{// product[mLen, mLen+nLen-2]
			for (int j = mLen - 1; j >= i - nLen + 1; --j)
			{
				p += m[j] * n[i - j] % 10;
				c1_new += m[j] * n[i - j] / 10;
			}
		}
		p += c1 + c2;
		c2 = p / 10;
		p = p % 10;
		c1 = c1_new;
		product.push_back(p + '0');
	}
	if (c1 + c2 > 0)
	{// product[mLen+nLen-1]
		product.push_back(c1 + c2 + '0');
	}
	// release array
	delete[]m;
	delete[]n;
	// return result
	return product;
}

/* Bigdata's exponetiation operation */
void expBigdata(std::string & data, int times)
{
	if (times == 1)
		return;
	std::string result;
	result = data;
	for (int i = 0; i < times - 1; ++i)
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

/* Move decimal point based on the fracNum to get the right result */
void mvDecimalPoint(std::string & bigdata, int fracNum)
{
	if (fracNum)
	{
		if (bigdata.length() >= fracNum)
		{
			bigdata.insert(fracNum, ".");
		}
		else
		{
			bigdata.append(fracNum - bigdata.length(), '0');
			bigdata.append(".");
		}
	}
	reverse(bigdata.begin(), bigdata.end());
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
		std::cout << *iter << std::endl;
	}
}

/* Main function */
int main()
{
	vector<INPUT_DATA_t> input_data;// to contain all input data
	vector<std::string> big_data;// to contain all result data, i.e. big data, i.e. string

	getData(input_data);// get input
#ifdef DEBUG
	checkData(input_data);// check input 
#endif

#ifdef DEBUG
	clock_t begin, end;
	begin = clock();
#endif

	procData(input_data, big_data);// calculate result
	printResult(big_data);// print result

#ifdef DEBUG
	end = clock();
	double dur = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "\nTime cost is " << dur * 1000 << "ms. ";
	std::cout << "Program exit." << std::endl;
#endif
//#pragma comment(lib,"Psapi.lib")
//	HANDLE handle = GetCurrentProcess();
//	PROCESS_MEMORY_COUNTERS pmc;
//	GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
//	printf("%d\r\n", pmc.WorkingSetSize);  //结果保存单位是B，可以除以1000保存为kb格式

	return 0;
}