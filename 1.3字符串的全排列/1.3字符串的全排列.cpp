// 1.3字符串的全排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CaclAllPermutation.h"

int main()
{
	CaclAllPermutation ca;
	//char a[] = "iloveu";
	//ca.CaclAllPermutation1(a, 0, 5);

	char b[] = "11345";
	while (ca.CaclAllPermutation2(b, 5))
	{
	}
}