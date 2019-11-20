#include "CaclAllPermutation.h"
#include <iostream>
#include <algorithm>
using namespace std;

void CaclAllPermutation::CaclAllPermutation1(char* str, int from, int to)
{
	if (to <= 1)
	{
		return;
	}
	if (from == to)
	{
		for (int i = 0; i <= to; i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
	else
	{
		for (int j = from; j <= to; j++)
		{
			swap(str[j], str[from]);
			CaclAllPermutation1(str, from + 1, to);
			swap(str[j], str[from]);
		}
	}
}

bool CaclAllPermutation::CaclAllPermutation2(char* perm, int num)
{
	int i;
	//1、找到排列中最后(最右)一个升序的首位位置i,x=ai //---比如21534，最后一个是ai=3，i=4
	for (i = num - 2; (i >= 0) && (perm[i] >= perm[i + 1]); --i)
	{
		;
	}

	//已经找到所有排列
	if (i < 0)
	{
		return false;
	}
	int k;
	//---2、找到排列中第i位右边,最后一个比ai大的位置j,y=aj//---比如21534，最后一个是5，k=3
	for (k = num - 1; (k > i) && (perm[k] <= perm[i]); --k)
	{
		;
	}
	//---3、交换x与y
	swap(perm[i], perm[k]);
	//---4、把第i+1位后的部分进行翻转
	reverse(perm + 1 + i, perm + num);
	cout << perm << endl;
	return true;
}