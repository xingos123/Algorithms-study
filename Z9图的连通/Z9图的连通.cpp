// Z9图的连通.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1000 + 5;
int n, m;
int head[maxn], cnt, root;
struct Edge {
	int to, next;
}e[maxn << 1];
int low[maxn], dfn[maxn], num;
int minD(int u, int v)
{
	return (u > v) ? v : u;
}
void add(int u, int v)
{
	e[++cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}
void TarjanBridge(int u, int fa)
{
	dfn[u] = low[u] = ++num;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == fa)
			continue;
		if (!dfn[v])
		{
			TarjanBridge(v, u);
			low[u] = minD(low[u], low[v]);
			if (low[v] > dfn[u])
				cout << u << "―" << v << "是桥" << endl;
		}
		else
			low[u] = minD(low[u], dfn[v]);
	}
}
void TarjanCut(int u, int fa)
{
	dfn[u] = low[u] = ++num; int count = 0;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == fa)
			continue;
		if (!dfn[v])
		{
			TarjanCut(v, u);
			low[u] = minD(low[u], low[v]);
			if (low[v] >= dfn[u])
			{
				count++;
				if (u != root || count > 1)
				{
					cout << u << "是割点\n";
				}
			}
		}
		else
			low[u] = minD(low[u], dfn[v]);
	}
}
void init()
{
	memset(head, 0, sizeof(head));
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	cnt = num = 0;
}
int main()
{
	while (cin >> n >> m)
	{
		init();
		int u, v;
		while (m--)
		{
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
		for (int i = 1; i <= n; i++)
			if (!dfn[i])
			{
				root = i;
				TarjanCut(i, 0);
			}
	}
	return 0;
}