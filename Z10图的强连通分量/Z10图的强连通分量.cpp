﻿// Z10图的强连通分量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int maxn = 1000 + 5;
int n, m;
int head[maxn], cnt;
stack<int>s;
bool ins[maxn];
struct Edge
{
	int to, next;
}e[maxn << 1];

int low[maxn], dfn[maxn], num;
void add(int u, int v)
{
	e[++cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}
int minD(int u, int v)
{
	return (u > v) ? v : u;
}
void tarjan(int u)
{
	low[u] = dfn[u] = ++num;
	ins[u] = true;
	s.push(u);
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = minD(low[u], low[v]);
		}
		else if (ins[v])
			low[u] = minD(low[u], dfn[v]);
	}
	if (low[u] == dfn[u])
	{
		int v;
		cout << "连通分量：";
		do
		{
			v = s.top();
			s.pop();
			cout << v << " ";
			ins[v] = false;
		} while (v != u);
		cout << endl;
	}
}

void init()
{
	memset(head, 0, sizeof(head));
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	memset(ins, 0, sizeof(ins));
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
		}
		for (int i = 1; i <= n; i++)
			if (!dfn[i])
				tarjan(i);
	}
	return 0;
}