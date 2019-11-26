// 2.2寻找和为定值的两个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "TwoSum.h"
int main()
{
	TwoSum ts;
	int a[20] = { 8, 1, 9, 7, 2, 4, 5, 6, 10, 3 ,45,22,1,33,2,56,41,39,88,999 };
	ts.TwoSum1(a, 20, 1000);
	std::cout << "Hello World!\n";
}