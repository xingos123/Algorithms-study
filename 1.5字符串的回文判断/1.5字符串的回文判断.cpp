// 1.5字符串的回文判断.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "IsPalindrome.h"
using namespace std;
int main()
{
	IsPalindrome ip;
	char a[] = "eaiae";
	if (ip.IsPalindrome2(a, 5))
		cout << "yes\n";
	else
		cout << "no\n";
}