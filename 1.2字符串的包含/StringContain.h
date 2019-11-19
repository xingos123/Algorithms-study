#pragma once
#include <string>
#include <algorithm>
using namespace std;
class StringContain
{
public:
	bool StringContain1(string& a, string& b);//--直接进行查询
	bool StringContain2(string& a, string& b);//--排序后轮询
	//--方法三长字符串会溢出，短字符串还可以
	bool StringContain3(string& a, string& b);//--一个思路，先建立一个26个素数的数组，把字符串a进行排序，排序后进行与素数匹配并算出所有字母对于素数的乘积，然后把与b中的进行整除。
	bool StringContain4(string& a, string& b);//--位运算法
};
