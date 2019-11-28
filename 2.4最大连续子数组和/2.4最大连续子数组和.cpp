// 2.4最大连续子数组和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

int MaxSubArray(int* a, int n)
{
	int maxSum = a[0];
	int currSum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			for (int k = i; k <= j; k++)
			{
				currSum += a[k];
			}
			if (currSum > maxSum)
			{
				maxSum = currSum;
			}
			currSum = 0;
		}
	}
	return maxSum;
}
int MaxSubArray2(int* a, int n)//---动态规划解决
{
	int currSum = 0;
	int maxSum = a[0];//---数组全为负返回最大数
	int i = 0, k = 0; int* b = new int[n];
	for (int j = 0; j < n; j++)
	{
		if (currSum >= 0)
		{
			currSum += a[j];//---当重置之后要去掉之前的元素和之后的元素
			if (j - 1 >= 0)
			{
				if (currSum >= maxSum)
				{
				}
				b[i] = a[j - 1];
				i++;
			}
		}
		else
		{
			currSum = a[j];
			i = 0;
		}
		if (currSum > maxSum)
		{
			maxSum = currSum;
		}
	}
	while (b[k] != NULL)
	{
		cout << b[k] << " ";
		k++;
	}
	cout << "\n";
	return maxSum;
}
int main()
{
	int a[] = { 1,-2,3,10,-4,7,2,-5 ,9,-2 };
	cout << MaxSubArray2(a, 11) << "\n";
}