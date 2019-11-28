﻿// Z字符串的学习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
using namespace std;

int BF(string a, string b)
{
	int i = 1, j = 1, sum = 0;
	int alen = a.length(), blen = b.length();
	while (i <= alen && j <= blen)
	{
		sum++;
		if (a[i - 1] == b[j - 1])
		{
			i++; j++;
		}
		else
		{
			i = i - j + 2; j = 1;
		}
	}
	cout << "共比较了：" << sum << "次。\n";
	if (j > blen)
		return i - blen;
	else
		return 0;
}
int* get_next(string t)
{
	int* next = new int[t.length()];
	int j = 1, k = 0;
	next[0] = next[1] = 0;
	while (j < t.length())
	{
		if (k == 0 || t[j - 1] == t[k - 1])
			next[++j] = ++k;
		else
			k = next[k];
	}
	return next;
}
int KMP(string a, string b)
{
	int i = 1, j = 1, sum = 0;
	int* next = get_next(b);
	int alen = a.length(), blen = b.length();
	while (i <= alen && j <= blen)
	{
		sum++;
		if (a[i - 1] == b[j - 1])
		{
			i++; j++;
		}
		else
		{
			j = next[j];
		}
	}
	cout << "共比较了：" << sum << "次。\n";
	if (j > blen)
		return i - blen;
	else
		return 0;
}
int main()
{
	string a = "abaadefderss";
	string b = "adef";
	cout << "BF算法：位置在：" << BF(a, b) << "处。\n";
	cout << "KMP算法：位置在：" << KMP(a, b) << "处。\n";
}