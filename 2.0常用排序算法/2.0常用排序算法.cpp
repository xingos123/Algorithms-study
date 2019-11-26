// 2.0常用排序算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "SortAlgorithms.h"
int main()
{
	SortAlgorithms sa;
	int a[20] = { 8, 1, 9, 7, 2, 4, 5, 6, 10, 3 ,45,22,1,33,2,56,41,39,88,999 };
	//sa.QuickSort(a, 0, 19);
	sa.InsertionSort(a, 20);
	for (int i = 0; i < 20; ++i)
	{
		cout << a[i] << " ";
	}
}