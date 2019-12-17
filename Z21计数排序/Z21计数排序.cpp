// Z21计数排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
void swap(int& a, int& b)
{
	// 	a = a + b;
	// 	b = a - b;
	// 	a = a - b;
	int tem;
	tem = a;
	a = b;
	b = tem;
}

void CountSort(int a[], int n)
{
	int low = 0, co = 0;
	for (low = 0; low < n; low++)
	{
		for (int i = 0; i < n; i++)
		{
			if (low == i) continue;
			if (a[low] >= a[i]) co++;
		}
		swap(a[low], a[co]);
		co = 0;
	}
}
int main()
{
	std::cout << "Hello World!\n";
	int a[9] = { 30,24,5,58,18,36,12,42,39 };
	CountSort(a, 9);
	for (int i = 0; i < 9; i++)
		cout << a[i] << " ";
	return 0;
}