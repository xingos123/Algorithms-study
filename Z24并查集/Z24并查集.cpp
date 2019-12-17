// Z24并查集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
const int N = 100;
int fa[N], n, m;

void init()
{
	for (int i = 1; i <= n; i++)
		fa[i] = i;
}
int find(int x)
{
	if (x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}
void union1(int x, int y)
{
	int a, b;
	a = find(x); b = find(y);
	if (a != b)
		fa[b] = a;
}
int main()
{
	int x, u, v, sum = 0;
	cout << "input n and m:" << endl;
	cin >> n >> m;
	init();
	cout << "input u and v" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		union1(u, v);
	}
	for (int i = 1; i <= n; i++)
	{
		find(i);
		cout << fa[i] << " ";
		if (fa[i] == i)
			sum++;
	}
	cout << endl;
	cout << "sum=" << sum << endl;
	return 0;
}