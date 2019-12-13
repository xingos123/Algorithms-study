// 4.2行列递增矩阵的查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
const int COL = 4;
const int ROW = 4;

bool YoungMatrix(int a[][COL], int key)
{
	int i = 0, j = COL - 1;
	int var = a[i][j];
	while (true)
	{
		if (var == key)
			return true;
		else if (var < key && i < ROW - 1)
			var = a[++i][j];
		else if (var > key&& j > 0)
			var = a[i][--j];
		else
			return false;
	}
}

int main()
{
	std::cout << "Hello World!\n";
	int a[ROW][COL] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	cout << YoungMatrix(a, 5);
}