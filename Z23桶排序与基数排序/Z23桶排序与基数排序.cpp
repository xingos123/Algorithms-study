// Z23桶排序与基数排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//两种基数排序，1、二维数组；2、两个一维数组

#include <iostream>
using namespace std;

const int maxn = 1000;
int a[maxn], n;
int MaxBit(int a[], int n)
{
	int d = 1; int p = 10;
	for (int i = 0; i < n; i++)
	{
		while (a[i] >= p)//---可能会出现1,200这种情况
		{
			p *= 10;
			d++;
		}
	}
	return d;
}
void RadixSort(int a[], int n)
{
	int d = MaxBit(a, n);
	int* temp = new int(n);
	int* count = new int(n);
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++)
	{
		for (j = 0; j < n; j++)//---每次清空计数器
		{
			count[j] = 0;
		}
		for (j = 0; j < n; j++)
		{
			k = (a[j] / radix) % 10;
			count[k]++;
		}
		for (j = 1; j < 10; j++)
		{
			count[j] += count[j - 1];
		}
		for (j = n - 1; j >= 0; j--)
		{
			k = (a[j] / radix) % 10;
			temp[--count[k]] = a[j];
		}
		cout << "第" << i << "次排序结果：" << endl;
		for (int i = 0; i < n; i++)
			cout << a[i] << "\t";
		cout << endl;
		radix = radix * 10;
	}
	delete[]temp;
	delete[]count;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	RadixSort(a, n);
	return 0;
}