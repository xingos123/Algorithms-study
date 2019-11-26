#include "TwoSum.h"

void TwoSum::QuickSort1(int a[], int low, int high)
{
	if (low < high)
	{
		int  i = low, j = high;
		int x = a[i];
		while (i < j && a[j] >= x)
		{
			--j;
		}
		a[i] = a[j];
		while (i < j && a[i] <= x)
		{
			++i;
		}
		a[j] = a[i];
		a[i] = x;
		QuickSort1(a, low, i - 1);
		QuickSort1(a, i + 1, high);
	}
}

void TwoSum::TwoSum1(int a[], unsigned int length, int sum)
{
	//sort(a, a + length);
	QuickSort1(a, 0, length - 1);
	for (int s1 = 0; s1 < length; s1++)
	{
		cout << a[s1] << " ";
	}
	cout << "\n";
	int begin = 0, end = length - 1;
	while (begin < end)
	{
		long currSum = a[begin] + a[end];
		if (currSum == sum)
		{
			cout << a[begin] << "+" << a[end] << "=" << sum << "\n";
			break;
		}
		else
		{
			if (currSum < sum)
			{
				++begin;
			}
			else
			{
				--end;
			}
		}
	}
}