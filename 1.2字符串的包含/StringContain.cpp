#include "StringContain.h"
#include <iostream>
bool StringContain::StringContain1(string& a, string& b)
{
	for (int i = 0; i < b.length(); ++i)
	{
		int j;
		for (j = 0; j < a.length() && a[j] != b[i]; ++j);
		if (j >= a.length())
			return false;
	}
	return true;
}

bool StringContain::StringContain2(string& a, string& b)
{
	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	for (int pa = 0, pb = 0; pb < b.length();)
	{
		while (pa < a.length() && (a[pa] < b[pb]))
		{
			++pa;
		}
		if (pa >= a.length() || (a[pa] > b[pb]))
		{
			return false;
		}
		++pb;
	}
	return true;
}

bool StringContain::StringContain3(string& a, string& b)
{
	const int p[27] = { 2 ,3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 91, 97, 101 };
	float f = 1;
	for (int i = 0; i < a.length(); ++i)
	{
		float x = p[a[i] - 'a'];
		if ((int)f % (int)x)
		{
			f *= x;
		}
	}
	for (int j = 0; j < b.length(); ++j)
	{
		float y = p[b[j] - 'a'];
		if ((int)f % (int)y)
		{
			return false;
		}
	}
	return true;
}

bool StringContain::StringContain4(string& a, string& b)
{
	int hash = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		hash |= (1 << (a[i] - 'a'));//--获取一个整数签名例如5120255
	}
	//cout << hash << endl;
	for (int j = 0; j < b.length(); ++j)
	{
		//cout << (1 << (b[j] - 'a')) << endl;
		if ((hash & (1 << (b[j] - 'a'))) == 0)//--与运算判断，经过hash算后是否存在表中
		{
			return false;
		}
	}
	return true;
}

bool StringContain::StringContain5(string& a, string& b)
{
	int hash1 = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		hash1 |= (1 << (a[i] - 'a'));
	}
	cout << hash1 << endl;
	int hash2 = 0;
	for (int j = 0; j < b.length(); ++j)
	{
		hash2 |= (1 << (b[j] - 'a'));
	}
	cout << hash2 << endl;
	if (hash1 == hash2)
	{
		return true;
	}
	else
	{
		return false;
	}
}