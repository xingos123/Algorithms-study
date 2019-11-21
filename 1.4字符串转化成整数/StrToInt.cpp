#include "StrToInt.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool StrToInt::JudgeAnumber5(int num)
{
	int i = 0;
	while (i < 5 && num>0)
	{
		if ((num - 1) % 5 == 0)
		{
			int temp = (num - 1) / 5 + 1;
			num -= temp;
			++i;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int StrToInt::StrToInt1(const char* str)
{
	int n = 0;
	while (*str != 0)
	{
		int c = *str - '0';
		n = n * 10 + c;
		++str;
	}
	return n;
}

int StrToInt::StrToInt2(const char* str)
{
	static const int MAX_INT = (int)((unsigned)~0 >> 1);
	static const int MIN_INT = -(int)((unsigned)~0 >> 1) + 1;
	unsigned int n = 0;
	//---判断是否为空
	if (str == 0)
	{
		return 0;
	}
	//---处理空格
	while (isspace(*str))
	{
		++str;
	}
	//---处理正负
	int sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		++str;
	}
	//---确定是数字后才执行循环
	//while (isdigit(*str))
	while (*str != '\0')
	{
		if (isdigit(*str))
		{
			//---处理溢出
			int c = *str - '0';
			if (sign > 0 && (n > MAX_INT / 10 || (n == MIN_INT / 10 && c > MAX_INT % 10)))
			{
				n = MAX_INT;
				break;
			}
			else if (sign < 0 && (n > (unsigned)MIN_INT / 10 || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10)))
			{
				n = MIN_INT;
				break;
			}
			cout << c;
			//---把之前得到的数字乘以10，再加上当前字符表示的数字
			n = n * 10 + c;

			++str;
		}
		else
		{
			++str;
		}
	}

	return sign > 0 ? n : -n;
}