// 1.6字符串的最长回文子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "LongestPalindrome.h"
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	LongestPalindrome lp;
	char str[] = "Pneumonoultramicroscopicsilicovolcanoconiosis";
	cout << lp.LongestPalindrome1(str, 45) << "\n";
	char s[] = "abaaba";
	cout << lp.Manacher(s, 6) << "\n";
}