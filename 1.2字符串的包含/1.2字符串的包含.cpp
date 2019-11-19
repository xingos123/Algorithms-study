// 1.2字符串的包含.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "StringContain.h"

int main()
{
	StringContain sc;
	string a = "defabccwsgtrfgnbgherfbnhr", b = "eaz";
	if (sc.StringContain4(a, b) == true)
	{
		cout << "包含" << endl;
	}
	else
	{
		cout << "不包含" << endl;
	}
}