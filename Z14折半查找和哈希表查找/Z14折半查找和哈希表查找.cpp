// Z14折半查找和哈希表查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int M = 100;
int x, n, i;
int s[M];

int BinarySearch(int s[], int n, int x)//---二分查找非递归
{
	int low = 0, hign = n - 1;
	while (low <= hign)
	{
		int middle = low + (hign - low) / 2;
		if (x == s[middle])
			return middle;
		else if (x > s[middle])
			low = middle + 1;
		else
			hign = middle - 1;
	}
	return -1;
}
int recursionBS(int s[], int x, int low, int high)//---二分查找递归
{
	if (low > high)
		return -1;
	int middle = low + (high - low) / 2;
	if (x == s[middle])
		return middle;
	else if (x < s[middle])
		return recursionBS(s, x, low, middle - 1);
	else
		return recursionBS(s, x, middle + 1, high);
}
int main()
{
	std::cout << "Hello World!\n";
	cout << "该数列中的元素个数n为：";
	cin >> n;
	cout << "请依次输入数列中的元素：";
	for (i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n); //二分查找的序列必须是有序的，如果无序需要先排序
	cout << "排序后的数组为：";
	for (i = 0; i < n; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "请输入要查找的元素：";
	cin >> x;
	//i = BinarySearch(s, n, x);
	i = recursionBS(s, x, 0, n - 1);
	if (i == -1)
		cout << "该数列中没有要查找的元素" << endl;
	else
		cout << "要查找的元素在第" << i + 1 << "位" << endl;//位序和下标差1
	return 0;
}