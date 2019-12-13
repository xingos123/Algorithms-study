// Z18插入排序与冒泡排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//---插入排序、冒泡排序

#include <iostream>
using namespace std;
#define  Maxsize 100

void StraightInsertSort(int r[], int n)
{
	int i, j;
	for (i = 2; i <= n; i++)
		if (r[i] < r[i - 1])
		{
			r[0] = r[i];
			r[i] = r[i - 1];
			for (j = i - 1; r[j] > r[0]; j--)
				r[j + 1] = r[j];
			r[j + 1] = r[0];
		}
}
void BubbleSort(int r[], int n)
{
	int i, j, temp;
	bool flag;
	i = n - 1;
	flag = true;
	while (i > 0 && flag)
	{
		flag = false;
		for (j = 0; j < i; j++)
			if (r[j] > r[j + 1])
			{
				flag = true;
				temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
			}
		for (j = 0; j <= i; j++)
			cout << r[j] << "  ";
		cout << endl;
		i--;
	}
}
int main()
{
	int i, n, r[Maxsize + 1];
	cout << "请输入数列中的元素个数n为：" << endl;
	cin >> n;
	cout << "请依次输入数列中的元素：" << endl;
	for (i = 0; i < n; i++)
		cin >> r[i];
	//StraightInsertSort(r, n);
	BubbleSort(r, n);
	cout << "直接插入排序结果：" << endl;
	for (i = 0; i < n; i++)
		cout << r[i] << " ";
	return 0;
}