// Z25使用并查集优化kruskal算法-最小生成图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100;
int father[N];
int n, m;

struct Edge {
	int u;
	int v;
	int w;
}e[N * N];

bool cmp(Edge x, Edge y)
{
	return x.w < y.w;
}

void Init(int n)
{
	for (int i = 1; i <= n; i++)
		father[i] = i;
}

int Find(int x)
{
	if (x != father[x])
		father[x] = Find(father[x]);
	return father[x];
}

bool Union(int a, int b)
{
	int p = Find(a);
	int q = Find(b);
	if (p == q) return 0;
	if (p > q)
		father[p] = q;//小的赋值给大的集合号
	else
		father[q] = p;
	return 1;
}

int Kruskal(int n)
{
	int ans = 0;
	for (int i = 0; i < m; i++)
		if (Union(e[i].u, e[i].v))
		{
			ans += e[i].w;
			n--;
			if (n == 1)
				return ans;
		}
	return 0;
}

int main()
{
	cout << "输入结点数n和边数m:" << endl;
	cin >> n >> m;
	Init(n);
	cout << "输入结点数u,v和边值w:" << endl;
	for (int i = 0; i < m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e, e + m, cmp);
	int ans = Kruskal(n);
	cout << "最小的花费是：" << ans << endl;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		Find(i);
		cout << father[i] << " ";
		if (father[i] == i)
			sum++;
	}
	cout << endl;
	cout << "sum=" << sum << endl;
	return 0;
}
/*
7 12
1 2 23
1 6 28
1 7 36
2 3 20
2 7 1
3 4 15
3 7 4
4 5 3
4 7 9
5 6 17
5 7 16
6 7 25
*/