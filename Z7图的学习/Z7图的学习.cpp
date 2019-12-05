// Z7图的学习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define MaxVnum 100
typedef char VexType;
typedef int EdgeType;
typedef struct
{
	VexType Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexn, edgen;//---顶点数、边数，为了区分和其他图的不同
}AMGraph;
int Locatevex(AMGraph G, VexType x)
{
	for (int i = 0; i < G.vexn; i++)//---找到顶点的下标
	{
		if (x == G.Vex[i])
		{
			return i;
		}
	}
	return -1;
}
void CreatAMGraph(AMGraph& G)
{
	int i, j;
	VexType u, v;
	cout << "请输入顶点数：\n";
	cin >> G.vexn;
	cout << "请输入边数：\n";
	cin >> G.edgen;
	cout << "请输入顶点信息：\n";
	for (i = 0; i < G.vexn; i++)
	{
		cin >> G.Vex[i];
	}
	for (i = 0; i < G.vexn; i++)
	{
		for (j = 0; j < G.vexn; j++)
		{
			G.Edge[i][j] = 0;
		}
	}
	cout << "请输入每条边所依附的顶点：\n";
	while (G.edgen--)
	{
		cin >> u >> v;
		i = Locatevex(G, u);
		j = Locatevex(G, v);
		if (i != -1 && j != -1)
		{
			G.Edge[i][j] = G.Edge[j][i] = 1;
		}
		else
		{
			cout << "输入顶点信息有误，请重新输入：\n";
			G.edgen++;
		}
	}
}
void Print(AMGraph G)
{
	int i, j;
	cout << "图的邻接矩阵为：" << endl;
	cout << " ";
	for (i = 0; i < G.vexn; i++)
	{
		cout << " " << G.Vex[i];
	}//---加上第一行的修饰
	cout << endl;
	for (i = 0; i < G.vexn; i++)
	{
		cout << G.Vex[i] << " ";//---加上第一列的修饰
		for (j = 0; j < G.vexn; j++)
		{
			cout << G.Edge[i][j] << " ";
		}
		cout << endl;
	}
}
//---邻接表存图
typedef struct AdjNode
{
	int v;
	struct AdjNode* next;
}AdjNode;
typedef struct
{
	VexType data;
	AdjNode* first;
}VexNode;
typedef struct
{
	VexNode Vex[MaxVnum];
	int vexn, edgen;
}ALGraph;
int LocateV(ALGraph G, VexType x)
{
	for (int i = 0; i < G.vexn; i++)
	{
		if (x == G.Vex[i].data)
		{
			return i;
		}
	}
	return -1;
}
void InsertEdge(ALGraph& G, int i, int j)
{
	AdjNode* s;
	s = new AdjNode;
	s->v = j;
	s->next = G.Vex[i].first;
	G.Vex[i].first = s;
	//---加上就是无向图
	AdjNode* p;
	p = new AdjNode;
	p->v = i;
	p->next = G.Vex[j].first;
	G.Vex[j].first = p;
}
void CreatALGraph(ALGraph& G)
{
	int i, j;
	VexType u, v;
	cout << "请输入顶点数和边数：\n";
	cin >> G.vexn >> G.edgen;
	cout << "请输入顶点信息：\n";
	for (i = 0; i < G.vexn; i++)
	{
		cin >> G.Vex[i].data;
	}
	for (i = 0; i < G.vexn; i++)
	{
		G.Vex[i].first = NULL;
	}
	cout << "请依次输入每条边的两个顶点U、V：\n";
	while (G.edgen--)
	{
		cin >> u >> v;
		i = LocateV(G, u);
		j = LocateV(G, v);
		if (i != -1 && j != -1)
		{
			InsertEdge(G, i, j);
		}
		else
		{
			cout << "输入顶点信息有错！请重新输入！\n";
			G.edgen++;
		}
	}
}
void Print(ALGraph G)
{
	cout << "------------邻接表如下：---------------\n";
	for (int i = 0; i < G.vexn; i++)
	{
		AdjNode* t = G.Vex[i].first;
		cout << G.Vex[i].data << "： ";
		while (t != NULL)
		{
			cout << "[" << t->v << "] ";
			t = t->next;
		}
		cout << endl;
	}
}
int main()
{
	// 	AMGraph G;
	// 	CreatAMGraph(G);
	// 	Print(G);
	ALGraph G;
	CreatALGraph(G);
	Print(G);
}