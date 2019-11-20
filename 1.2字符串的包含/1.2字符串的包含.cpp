// 1.2字符串的包含.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "StringContain.h"

int main()
{
	StringContain sc;
	string a = "aeg", b = "eag", c = "gea";
	string str[] = { "aeg","aga","ewe","aa","c" };
	for (int i = 0; i < 5; i++)
	{
		if (sc.StringContain5(a, str[i]))
		{
			cout << "包含" << endl;
		}
		/*while (sc.StringContain5(a, str[i]) == true)
		{
			cout << "包含" << endl;
		}*/
	}
	/*if (sc.StringContain5(a, c) == true)
	{
		cout << "包含" << endl;
	}
	else
	{
		cout << "不包含" << endl;
	}*/
}