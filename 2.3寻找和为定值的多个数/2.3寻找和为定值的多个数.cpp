// 2.3寻找和为定值的多个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
using namespace std;
list<int>list1;
void SumOfkNumber(int sum, int n)
{
	//---递归出口
	if (n <= 0 || sum <= 0)
	{
		return;
	}
	//---输出找到的结果
	if (sum == n)
	{
		//---翻转list
		list1.reverse();
		for (list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
		{
			cout << *iter << "+";
		}
		cout << n << "\n";
	}
	list1.push_front(n);//---典型的01背包问题
	SumOfkNumber(sum - n, n - 1);//---放n,前n-1个数填满sum-n
	list1.pop_front();
	SumOfkNumber(sum, n - 1);//---不放n，前n-1个数填满sum
}
int main()
{
	std::cout << "Hello World!\n";
	SumOfkNumber(9, 1000);
}