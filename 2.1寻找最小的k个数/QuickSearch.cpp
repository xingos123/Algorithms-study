#include "QuickSearch.h"

void swap1(int* a, int* b) {
	int* temp;
	temp = a;
	*a = *b;
	b = temp;
}
int median3(int a[], int left, int right) {
	int center = (left + right) / 2;
	if (a[left] > a[center]) {
		swap1(&a[left], &a[center]);
	}
	if (a[right] < a[center]) {
		swap1(&a[right], &a[center]);
	}
	//if (a[left] > a[right]) {
	//    swap1(&a[left], &a[right]);
	//}
	if (a[left] > a[center]) {
		swap1(&a[left], &a[center]);
	}
	//swap1(&a[center], &a[right - 1]);
	swap1(&a[center], &a[right]);
	return a[right];
}

void InsertionSort(int* a, int len)
{
	for (int j = 1; j < len; j++)
	{
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
}
void QuickSearch::QuickSearch4(int S[], int k, int left, int right)
{
	int i, j;
	int pivot;
	if (left < right)
	{
		pivot = median3(S, left, right);//---取3个数的中值，避免最坏情况发生
		i = left; j = right - 1;
		for (;;)
		{
			while (S[++i] < pivot)
			{
			}
			while (S[--j] > pivot)
			{
			}
			if (i < j)
			{
				swap(S[i], S[j]);
			}
			else
			{
				break;
			}
			swap(S[i], S[right - 1]);//---重置主元
			if (k <= i)
			{
				QuickSearch4(S, k, left, i - 1);
			}
			else if (k > i + 1)
			{
				QuickSearch4(S, k, i + 1, right);
			}
		}
	}
	else
	{
		InsertionSort(S + left, right - left + 1);//---如果left>right，利用插入排序调整一下
	}
}