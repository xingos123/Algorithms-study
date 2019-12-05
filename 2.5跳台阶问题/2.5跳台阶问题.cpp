// 2.5跳台阶问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

long long Fibonacci(unsigned int n)//---递归计算
{
	int result[3] = { 0,1,2 };
	if (n <= 2)
	{
		return result[n];
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int ClimbStairs(int n)//---递推计算
{
	int dp[3] = { 1,1 };
	if (n < 2)
	{
		return 1;
	}
	for (int i = 2; i <= n; i++)
	{
		dp[2] = dp[0] + dp[1];
		dp[0] = dp[1]; dp[1] = dp[2];
	}
	return dp[2];
}

int main()
{
	time_t s1, s2, e1, e2;
	s1 = clock();
	cout << "1共有：" << Fibonacci(23) << "\n";
	e1 = clock();
	cout << "1花费时间：" << e1 - s1 << "\n";
	s2 = clock();
	cout << "2共有：" << ClimbStairs(23) << "\n";
	e2 = clock();
	cout << "2花费时间：" << e2 - s2 << "\n";
}