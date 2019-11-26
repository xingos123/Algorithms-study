#pragma once
#include <string>
#include <string.h>
#include <string>
class LongestPalindrome
{
public:
	int LongestPalindrome1(const char* s, int n);//---中心拓展法进行判断
	int Manacher(char* s, int n);//---manacher算法
};
