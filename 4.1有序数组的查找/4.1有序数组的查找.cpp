// 4.1有序数组的查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//---有序数组使用二分查找

#include <iostream>

int BinarySearch2(int a[], int n, int value)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (value == a[mid])
			return mid;
		else if (value > a[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main()
{
	std::cout << "Hello World!\n";
	int a[10], e;
	std::cout << "请按顺序输入10个数值：\n";
	for (int i = 0; i < 10; i++)
	{
		std::cin >> e;
		a[i] = e;
	}
	std::cout << "请输入要查的数值：\n";
	int value, l;
	std::cin >> value;
	l = BinarySearch2(a, 10, value) + 1;
	if (l == 0)
		std::cout << "找不到。\n";
	else
		std::cout << "在第" << l << "位。\n";
}