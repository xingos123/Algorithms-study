// Z6哈夫曼树与编码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define  MAXVALUE 10000
#define  MAXBIT 100
#define  MAXLEAF 30
#define  MAXNODE MAXLEAF*2-1
typedef struct
{
	double weight;
	int parent;
	int lc;
	int rc;
	char value;
}Hnode;//---结点结构体
typedef struct
{
	int bit[MAXBIT];
	int start;
}Hcode;//---编码结构体
Hnode huffn[MAXNODE];
Hcode huffc[MAXLEAF];
void HuffTree(Hnode huffn[MAXNODE], int n)
{
	int i, j, x1, x2;
	double m1, m2;
	for (i = 0; i < 2 * n - 1; i++)
	{
		huffn[i].weight = 0;
		huffn[i].parent = -1;
		huffn[i].lc = -1;
		huffn[i].rc = -1;
	}
	for (i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个结点的权值和数据:\n";
		cin >> huffn[i].value >> huffn[i].weight;
	}//---初始化哈夫曼完成
	cout << endl;
	for (i = 0; i < n - 1; i++)
	{
		m1 = m2 = MAXVALUE;
		x1 = x2 = 0;
		for (j = 0; j < n + i; j++)
		{
			if (huffn[j].weight < m1 && huffn[j].parent == -1)
			{
				m2 = m1;
				x2 = x1;
				m1 = huffn[j].weight;
				x1 = j;
			}
			else if (huffn[j].weight < m2 && huffn[j].parent == -1)
			{
				m2 = huffn[j].weight;
				x2 = j;
			}
		}
		huffn[x1].parent = n + i;
		huffn[x2].parent = n + i;
		huffn[n + i].weight = m1 + m2;
		huffn[n + i].lc = x1;
		huffn[n + i].rc = x2;//---更新五个域
		cout << "两个权值：" << huffn[x1].weight << " " << huffn[x2].weight;
	}//---哈夫曼树构建完成
	cout << endl;
}
void HuffCode(Hcode huffc[MAXLEAF], int n)
{
	Hcode cd;
	int i, j, c, p;
	for (i = 0; i < n; i++)
	{
		cd.start = n - 1;
		c = i;
		p = huffn[c].parent;
		while (p != -1)
		{
			if (huffn[p].lc == c)
			{
				cd.bit[cd.start] = 0;
			}
			else
			{
				cd.bit[cd.start] = 1;
			}
			cd.start--;
			c = p;
			p = huffn[c].parent;
		}
		for (j = cd.start + 1; j < n; j++)
		{
			huffc[i].bit[j] = cd.bit[j];
		}
		huffc[i].start = cd.start;
	}
}
int main()
{
	int i, j, n;
	cout << "请输入N:\n";
	cin >> n;
	HuffTree(huffn, n);
	HuffCode(huffc, n);
	for (i = 0; i < n; i++)
	{
		cout << huffn[i].value << "：编码为：";
		for (j = huffc[i].start + 1; j < n; j++)
		{
			cout << huffc[i].bit[j];
		}
		cout << endl;
	}
	std::cout << "Hello World!\n";
}