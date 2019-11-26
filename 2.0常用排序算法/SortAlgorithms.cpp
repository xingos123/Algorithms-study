#include "SortAlgorithms.h"

void SortAlgorithms::QuickSort(int* a, int low, int hign)
{
	if (low < hign)
	{
		int i = low, j = hign;
		int x = a[low];
		while (i < j)
		{
			while (i < j && a[j] >= x)
				j--;
			a[i] = a[j];
			while (i < j && a[i] <= x)
				i++;
			a[j] = a[i];
		}
		a[i] = x;
		QuickSort(a, low, i - 1);
		QuickSort(a, i + 1, hign);
	}
}

void SortAlgorithms::InsertionSort(int* a, int len)
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