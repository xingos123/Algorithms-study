// 2.1寻找最小的k个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "QuickSearch.h"

struct Lnode
{
	int data;
	struct Lnode* next;
};
int fac(int a)
{
	if (a == 1)//---中止条件
	{
		return 1;
	}
	else
	{
		return a * fac(a - 1);//---每一步要处理的问题，及返回值
	}
}
int fbn(int a)
{
	if (a == 1 || a == 2)
	{
		return 1;
	}
	else
	{
		return fbn(a - 1) + fbn(a - 2);
	}
}
long double fbn2(int n)
{
	long double temp;
	if (n < 1)
	{
		return -1;
	}
	long double* a = new long double[n + 1];
	a[0] = a[1] = 1;
	for (int i = 2; i < n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		cout << a[i] << endl;
	}
	temp = a[n];
	delete[]a;
	return temp;
}
int main()
{
	Lnode* L = new Lnode;
	Lnode* End = new Lnode;
	L->next = NULL;
	End = L;
	for (int li = 0; li < 9; li++)
	{
		Lnode* T = new Lnode;
		T->data = li + 1;
		End->next = T;//---只是End->next的地址变为下一个地址，但是End的地址仍然是原来的地址
		End = T;//---进行该操作使为End的地址重新赋值变为T
	}
	End->next = NULL;
	Lnode* p = L->next;//---切记不要对初始链表进行改动，否则就找不回来啦
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
	Lnode* lm = new Lnode;
	lm = L;
	for (int lj = 0; lj < 5; lj++)
	{
		lm = lm->next;
	}
	cout << lm->data << "\n";
	QuickSearch qs;
	int a[20] = { 8, 1, 9, 7, 2, 4, 5, 6, 10, 3 ,45,22,1,33,2,56,41,39,88,999 };
	//qs.QuickSearch4(a, 5, 0, 19);
	//cout << fixed << setprecision(0);
	for (int i = 0; i < 20; ++i)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
	int b = 13;
	cout << fac(b) << "\n";
	cout << fbn(20) << "\n";
	int m = 1; int n = 1;
	for (int g = 0; g < 20; g++)//---简化使空间复杂度将为1，时间复杂度为n
	{
		n = m + n;
		m = n - m;
		cout << n << "\n";
	}
	//cout << fbn2(100);

	//---洛谷1421-小玉买文具
	int alg = 10, blg = 3;
	int clg = 19;
	cout << (alg * 10 + blg) / clg << endl;
}