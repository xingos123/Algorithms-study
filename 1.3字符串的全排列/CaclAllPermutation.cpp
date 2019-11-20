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
	//1���ҵ����������(����)һ���������λλ��i,x=ai //---����21534�����һ����ai=3��i=4
	for (i = num - 2; (i >= 0) && (perm[i] >= perm[i + 1]); --i)
	{
		;
	}

	//�Ѿ��ҵ���������
	if (i < 0)
	{
		return false;
	}
	int k;
	//---2���ҵ������е�iλ�ұ�,���һ����ai���λ��j,y=aj//---����21534�����һ����5��k=3
	for (k = num - 1; (k > i) && (perm[k] <= perm[i]); --k)
	{
		;
	}
	//---3������x��y
	swap(perm[i], perm[k]);
	//---4���ѵ�i+1λ��Ĳ��ֽ��з�ת
	reverse(perm + 1 + i, perm + num);
	cout << perm << endl;
	return true;
}