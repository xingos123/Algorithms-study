// 2.8矩阵相乘.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

void MulMatrix(int matrixA[][3], int matrixB[][3], int matrixC[][3], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrixC[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
}
int main()
{
	int m1[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int m2[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int m3[3][3];
	MulMatrix(m1, m2, m3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << m3[i][j] << "\t";
		}
		std::cout << "\n";
	}
}