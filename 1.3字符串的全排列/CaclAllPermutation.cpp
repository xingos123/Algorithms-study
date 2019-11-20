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