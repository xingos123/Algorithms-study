// Z22选择排序与堆排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
void SelectSort(int a[], int n)
{
	int i, j, k, temp;
	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[k])
				k = j;
		if (k != i)
		{
			temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
		for (int i = 0; i < 9; i++)
			cout << a[i] << " ";
		cout << "\n";
	}
}

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void Sink(int a[], int k, int n)
{
	while (2 * k <= n)
	{
		int j = 2 * k;
		if (j < n && a[j] < a[j + 1]) j++;//---存在右孩子且右比左大
		if (a[k] >= a[j]) break;//---满足大顶堆
		else swap(a[k], a[j]);//---交换
		k = j;
	}
}
void CreateHeap(int a[], int n)
{
	for (int i = n / 2; i > 0; i--)
		Sink(a, i, n);
}
void HeapSort(int a[], int n)
{
	CreateHeap(a, n);
	while (n > 1)
	{
		swap(a[1], a[n--]);
		Sink(a, 1, n);
	}
}
int main()
{
	int a[] = { 0,30,24,5,58,18,36,12,42,39 };
	HeapSort(a, 9);
	for (int i = 1; i < 10; i++)
		cout << a[i] << " ";
	return 0;
}