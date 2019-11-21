// 1.4字符串转化成整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "StrToInt.h"
using namespace std;

int main()
{
	StrToInt si;
	char s[] = "4852";
	std::cout << si.StrToInt1(s) << endl;

	char str[] = " - ere 2 3 dd3 1 8 9aaa0 67";
	cout << "\n" << si.StrToInt2(str) << endl;

	int num = 6;
	while (true)
	{
		if (si.JudgeAnumber5(num))
			break;
		++num;
	}
	cout << num << endl;
}