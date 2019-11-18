#include "ReverseMethods.h"
#include <iostream>

void ReverseMethods::LeftShiftOne(char* s, int n)
{
	char temp = s[0];
	for (int i = 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	s[n - 1] = temp;
}

void ReverseMethods::LeftRotateString(char* s, int n, int m)
{
	while (m--)
	{
		LeftShiftOne(s, n);
	}
}

void ReverseMethods::SingleReverse(char* s, int st, int en)
{
	while (st < en)
	{
		char temp = s[st];
		s[st++] = s[en];
		s[en--] = temp;
	}
}

void ReverseMethods::AllReverse(char* s, int m, int n)
{
	m %= n;
	SingleReverse(s, 0, m - 1);
	SingleReverse(s, m, n - 1);
	SingleReverse(s, 0, n - 1);
}