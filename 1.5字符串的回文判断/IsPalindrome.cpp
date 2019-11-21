#include "IsPalindrome.h"
#include <iostream>
#include <algorithm>
using namespace std;
bool IsPalindrome::IsPalindrome1(const char* str)
{
	//---ºÏ≤‚∑«∑® ‰»Î
	if (str == NULL)
		return false;

	const char* start = str; const char* end = str; const char* p = str;
	while (*p++ != '\0')
		end = p - 1;
	while (start < end)
	{
		//cout << *start << " " << *end << "\n";
		if (*start++ != *end--)
			return false;
	}
	return true;
}

bool IsPalindrome::IsPalindrome2(const char* str, int n)
{
	if (str == NULL)
		return false;
	// 	const char* start = str; const char* end = str; const char* p = str;
	// 	while (*p++ != '\0')
	// 	{
	// 		end = p - 1;
	// 	}
	const char* start, * mid;
	int m = ((n >> 1) - 1) >= 0 ? (n >> 1) - 1 : 0;
	start = str + m; mid = str + n - 1 - m;
	while (start >= str)
	{
		if (*start != *mid)
		{
			return false;
		}
		--start;
		++mid;
	}
	return true;
}