// 2.6奇偶数排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

bool IsOddNumber(int data)
{
	return (data & 1) == 1;
}
void OddEventSort2(int data[], int lo, int hi)
{
	int i = lo - 1;
	for (int j = lo; j < hi; j++)
	{
		if (IsOddNumber(data[j]))
		{
			i = i + 1;
			swap(data[i], data[j]);
		}
	}
	swap(data[i + 1], data[hi]);
}
int main()
{
	std::cout << "Hello World!\n";
	int data[] = { 2,34,3,13,15,46,7,6,32,37 ,29,13,645,49,1,59,22,32,14 };
	for (int i = 0; i < 19; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
	OddEventSort2(data, 0, 18);
	for (int i = 0; i < 19; i++)
	{
		cout << data[i] << " ";
	}
}