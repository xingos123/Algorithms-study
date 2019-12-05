// 2.7荷兰国旗.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;
void DucthFlag(int a[], int n)
{
	int begin, current, end;
	begin = current = 0; end = n - 1;
	while (current <= end)
	{
		if (a[current] == 0)
			swap(a[current++], a[begin++]);
		else if (a[current] == 1)
			current++;
		else
			swap(a[current], a[end--]);
	}
}
int main()
{
	int a[] = { 1,2,1,0,2,0,1,2,1,1,1,1,1,1,1,1,1,1,0,1,2,1,0 };
	DucthFlag(a, 23);
	for (int i = 0; i < 23; i++)
		cout << a[i] << " ";
}