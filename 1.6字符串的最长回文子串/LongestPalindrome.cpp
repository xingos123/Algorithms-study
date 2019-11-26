#include "LongestPalindrome.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int LongestPalindrome::LongestPalindrome1(const char* s, int n)
{
	int i, j, max, c;
	if (s == 0 || n < 1)
	{
		return 0;
	}
	max = 0;
	//---i为回文的中心位置
	for (i = 0; i < n; ++i)
	{
		//---回文长度为奇数
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
		//---回文长度为偶数
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

int LongestPalindrome::Manacher(char* s1, int n)
{
	const int MAXN = 2233;

	char s2[MAXN];
	int tot = 0, p[MAXN];

	s2[tot++] = '$'; s2[tot++] = '#';
	for (int i = 1; i <= n; i++) {
		s2[tot++] = s1[i]; s2[tot++] = '#';
	}
	int mxlen = 0, mx = 0, id;
	for (int i = 1; i < tot; i++) {
		if (i < mx) p[i] = std::min(p[(id << 1) - i], mx - i);
		else p[i] = 1;
		while (s2[i - p[i]] == s2[i + p[i]]) p[i]++;
		if (mx < i + p[i]) {
			id = i; mx = i + p[i];
		}
		mxlen = std::max(mxlen, p[i] - 1);
	}
	cout << s2 << "\n" << p << "\n";
	return mxlen;
	return 0;
}