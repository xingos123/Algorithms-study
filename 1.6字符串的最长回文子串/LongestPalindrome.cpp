#include "LongestPalindrome.h"
#include <iostream>
#include <algorithm>
using namespace std;

int LongestPalindrome::LongestPalindrome1(const char* s, int n)
{
	int i, j, max, c;
	if (s == 0 || n < 1)
	{
		return 0;
	}
	max = 0;
	//---iΪ���ĵ�����λ��
	for (i = 0; i < n; ++i)
	{
		//---���ĳ���Ϊ����
		for (j = 0; (i - j >= 0) && (i + j < n); ++j)
		{
			if (s[i - j] != s[i + j])
			{
				break;
			}
			c = j * 2 + 1;
		}
		if (c > max)
		{
			max = c;
		}
		//---���ĳ���Ϊż��
		for (j = 0; (i - j >= 0) && (i + j + 1 < n); ++j)
		{
			if (s[i - j] != s[i + j + 1])
			{
				break;
			}
			c = j * 2 + 2;
		}
		if (c > max)
		{
			max = c;
		}
	}
	return max;
}