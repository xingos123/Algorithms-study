// Z20快速排序与归并排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <algorithm>
using namespace std;

int Partation(int a[], int low, int high)
{
	// 	int k = (rand() % (high - low + 1)) + low;
	// 	swap(a[low], a[k]);//---引入随机
	int i = low; int j = high; int p = a[low];
	while (i < j)
	{
		while (i < j && a[i] <= p) i++;
		while (i<j && a[j]>p) j--;
		if (i < j) swap(a[i++], a[j--]);
	}
	if (a[i] > p)
	{
		swap(a[--i], a[low]);
		return i;
	}
	swap(a[i], a[low]);
	return i;
}
void QuickSort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = Partation(a, low, high);
		QuickSort(a, mid + 1, high);
		QuickSort(a, low, mid - 1);
	}
}

void Merge(int a[], int low, int high, int mid)
{
	int* b = new int[high - low + 1];
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j]) b[k++] = a[i++];
		else b[k++] = a[j++];
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= high) b[k++] = a[j++];
	for (i = low, k = 0; i <= high; i++) a[i] = b[k++];
	delete[]b;
}
void MergeSort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = (high + low) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);
		Merge(a, low, high, mid);
	}
}
int main()
{
	int a[9] = { 30,24,5,58,18,36,12,42,39 };
	//QuickSort(a, 0, 8);
	MergeSort(a, 0, 8);
	for (int i = 0; i < 9; i++)
		cout << a[i] << " ";
	return 0;
}