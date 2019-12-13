﻿// Z19斐波那契数列的logn解法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int Mod = 10000;
struct mat
{
	ll a[2][2];
};
mat mat_mul(mat x, mat y)
{
	mat res;
	memset(res.a, 0, sizeof(res.a));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % Mod;
	return res;
}
void mat_pow(int n)
{
	mat c, res;
	c.a[0][0] = 1;//初始矩阵
	c.a[0][1] = 1;
	c.a[1][0] = 1;
	c.a[1][1] = 0;
	memset(res.a, 0, sizeof(res.a));
	for (int i = 0; i < 2; i++)
		res.a[i][i] = 1;//单位矩阵
	while (n)
	{
		if (n & 1)
			res = mat_mul(res, c);
		c = mat_mul(c, c);
		n = n >> 1;
	}
	printf("%I64d\n", res.a[0][1]);//long long(或者_int64),%I64d
}
int main()
{
	int n;
	while (~scanf_s("%d", &n) && n != -1)
	{
		mat_pow(n);
	}
	return 0;
}