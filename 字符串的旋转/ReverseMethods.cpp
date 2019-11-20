#include "ReverseMethods.h"
#include <iostream>
#include <algorithm>
using namespace std;
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

char* ReverseMethods::ReverseString1(char* s)
{
	char* start = s; char* end = s; char* p = s;
	while (*p++ != '\0')
	{
		if (*p == ' ' || *p == '\0')
		{
			end = p - 1;
			while (start < end)
			{
				swap(*start++, *end--);
			}
			start = end = p + 1;
		}
	}
	start = s;
	end = p - 2;
	while (start < end)
	{
		swap(*start++, *end--);
	}
	return s;
}

char* ReverseMethods::ReverseString3(char* s)
{
	char* start = s; char* end = s; char* p = s;
	while (*p++ != '\0')//---先获取末尾
	{
		end = p - 1;
	}
	while (start < end)
	{
		swap(*start++, *end--);
	}
	start = end = p = s;
	while (*p++ != '\0')
	{
		if (*p == ' ' || *p == '\0')
		{
			end = p - 1;
			while (start < end)
			{
				swap(*start++, *end--);
			}
			start = end = p + 1;
		}
	}

	return s;
}

char* ReverseMethods::ReverseString2(char* s, char c)
{
	char* start = s; char* end = s; char* p = s;
	while (*p++ != '\0')
	{
		if (*p == c)
		{
			end = p - 1;
			while (start < end)
			{
				swap(*start++, *end--);
			}
			start = end = p + 1;
		}
		if (*p == '\0')
		{
			start = start - 1;//---向前提前一个字符
			end = p - 1;
			while (start < end)
			{
				swap(*start++, *end--);
			}
			start = end = p + 1;
		}
	}
	start = s; end = p - 2;
	while (start < end)
	{
		swap(*start++, *end--);
	}
	return s;
}