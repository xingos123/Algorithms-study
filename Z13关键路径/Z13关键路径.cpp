// Z13关键路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//---拓扑排序、事件最早发生事件和最迟发生时间、活动的最早发生事件与关键路径

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int MaxVnum = 100;//---顶点数最大
int indeg[MaxVnum];//---入度数组
int ve[MaxVnum], vl[MaxVnum];//---事件vi的最早发生时间与最迟发生时间

typedef string VexType;
typedef struct AdjNode
{
	int v;//---邻结点下标
	int weight;//---权值
	struct AdjNode* next;//---指向下一个邻结点指针
}AdjNode;
typedef struct VexNode
{
	VexType data;
	AdjNode* first;
}VexNode;
typedef struct
{
	VexNode Vex[MaxVnum];
	VexNode converse_Vex[MaxVnum];//---逆邻接表
	int vexnum, edgenum;
}ALGraph;

int locatevex(ALGraph G, VexType x)
{
	for (int i = 0; i < G.vexnum; i++)//查找顶点信息的下标
		if (x == G.Vex[i].data)
			return i;
	return -1;//没找到
}
void insertedge(ALGraph& G, int i, int j, int w)//插入一条边
{
	AdjNode* s1, * s2;
	//创建邻接表结点
	s1 = new AdjNode;
	s1->v = j;
	s1->weight = w;
	s1->next = G.Vex[i].first;
	G.Vex[i].first = s1;
	//创建逆邻接表结点
	s2 = new AdjNode;
	s2->v = i;
	s2->weight = w;
	s2->next = G.converse_Vex[j].first;
	G.converse_Vex[j].first = s2;
}
void printg(ALGraph G)
{
	cout << "---------------邻接表如下-----------------\n";
	for (int i = 0; i < G.vexnum; i++)
	{
		AdjNode* t = G.Vex[i].first;
		cout << G.Vex[i].data << "：";
		while (t != NULL)
		{
			cout << "--" << t->v << "+" << t->weight << "--\t";
			t = t->next;
		}
		cout << "\n";
	}
	cout << "-----------------逆邻接表如下--------------------\n";
	for (int i = 0; i < G.vexnum; i++)
	{
		AdjNode* p = G.converse_Vex[i].first;
		cout << G.converse_Vex[i].data << "：";
		while (p != NULL)
		{
			cout << "--" << p->v << "+" << p->weight << "--\t";
			p = p->next;
		}
		cout << endl;
	}
}
void CreateALGraph(ALGraph& G)
{
	int i, j, w;
	VexType u, v;
	cout << "请输入顶点数和边数:" << endl;
	cin >> G.vexnum >> G.edgenum;
	cout << "请输入顶点信息:" << endl;
	for (i = 0; i < G.vexnum; i++)//输入顶点信息，存入顶点信息数组
	{
		cin >> G.Vex[i].data;
		G.converse_Vex[i].data = G.Vex[i].data;
		G.Vex[i].first = NULL;
		G.converse_Vex[i].first = NULL;
	}
	cout << "请依次输入每条边的两个顶点及权值u,v,w" << endl;
	while (G.edgenum--)
	{
		cin >> u >> v >> w;
		i = locatevex(G, u);//查找顶点u的存储下标
		j = locatevex(G, v);//查找顶点v的存储下标
		if (i != -1 && j != -1)
			insertedge(G, i, j, w);
		else
		{
			cout << "输入顶点信息错！请重新输入！" << endl;
			G.edgenum++;//本次输入不算
		}
	}
}
void FindInDegree(ALGraph G)//求出各顶点的入度存入数组indegree中
{
	int i, count;
	for (i = 0; i < G.vexnum; i++)
	{
		count = 0;
		AdjNode* p = G.converse_Vex[i].first;
		if (p)
		{
			while (p)
			{
				p = p->next;
				count++;
			}
		}
		indeg[i] = count;
	}
	cout << "入度数组为：" << endl;
	for (int i = 0; i < G.vexnum; i++)//输出入度数组
		cout << indeg[i] << "\t";
	cout << endl;
}

bool TopologicalSort(ALGraph G, int topo[])//拓扑排序
{
	//有向图G采用邻接表存储结构
	//若G无回路，则生成G的一个拓扑序列topo[]并返回true，否则false
	int i, m;
	stack<int>S;      //初始化一个栈S，需要引入头文件#include<stack>
	FindInDegree(G);  //求出各顶点的入度存入数组indegree[]中
	for (i = 0; i < G.vexnum; i++)
		if (!indeg[i])//入度为0者进栈
			S.push(i);
	m = 0;            //对输出顶点计数，初始为0
	while (!S.empty())//栈S非空
	{
		i = S.top();    //取栈顶顶点i
		S.pop();      //栈顶顶点i出栈
		topo[m] = i;    //将i保存在拓扑序列数组topo中
		m++;          //对输出顶点计数
		AdjNode* p = G.Vex[i].first;  //p指向i的第一个邻接点
		while (p) //i的所有邻接点入度减1
		{
			int k = p->v;			 //k为i的邻接点
			--indeg[k];       //i的每个邻接点的入度减1
			if (indeg[k] == 0)  //若入度减为0，则入栈
				S.push(k);
			p = p->next;      //p指向顶点i下一个邻接结点
		}
	}
	if (m < G.vexnum)//该有向图有回路
		return false;
	else
		return true;
}

bool CriticalPath(ALGraph G, int topo[])//G为邻接表存储的有向网，输出G的各项关键活动
{
	int n, i, k, j, e, l;
	if (TopologicalSort(G, topo))
	{
		cout << "拓扑序列为：" << endl;
		for (int i = 0; i < G.vexnum; i++)//输出拓扑序列
			cout << topo[i] << "\t";
		cout << endl;
	}
	else
		cout << "该图有环，无拓扑序列！" << endl;
	n = G.vexnum;                 //n为顶点个数
	for (i = 0; i < n; i++)     //给每个事件的最早发生时间置初值0
		ve[i] = 0;
	//按拓扑次序求每个事件的最早发生时间
	for (i = 0; i < n; i++)
	{
		k = topo[i];                    //取得拓扑序列中的顶点序号k
		AdjNode* p = G.Vex[k].first;    //p指向k的第一个邻接顶点
		while (p != NULL)
		{            	             //依次更新k的所有邻接顶点的最早发生时间
			j = p->v;                   //j为邻接顶点的序号
			if (ve[j] < ve[k] + p->weight)   //更新顶点j的最早发生时间ve[j]
				ve[j] = ve[k] + p->weight;
			p = p->next;                //p指向k的下一个邻接顶点
		}
	}
	for (i = 0; i < n; i++)                 			//给每个事件的最迟发生时间置初值ve[n-1]
		vl[i] = ve[n - 1];
	//按逆拓扑次序求每个事件的最迟发生时间
	for (i = n - 1; i >= 0; i--)
	{
		k = topo[i];                    //取得逆拓扑序列中的顶点序号k
		AdjNode* p = G.Vex[k].first;    //p指向k的第一个邻接顶点
		while (p != NULL)
		{            			      //根据k的邻接点，更新k的最迟发生时间
			j = p->v;              	  //j为邻接顶点的序号
			if (vl[k] > vl[j] - p->weight)   //更新顶点k的最迟发生时间vl[k]
				vl[k] = vl[j] - p->weight;
			p = p->next;                //p指向k的下一个邻接顶点
		}
	}
	cout << "事件的最早发生时间和最迟发生时间：" << endl;
	for (int i = 0; i < n; i++)
		cout << ve[i] << "\t" << vl[i] << endl;

	//判断每一活动是否为关键活动
	cout << endl;
	cout << "关键活动路径为:";
	for (i = 0; i < n; i++)                //每次循环针对vi为活动开始点的所有活动
	{
		AdjNode* p = G.Vex[i].first;    //p指向i的第一个邻接顶点
		while (p != NULL)
		{
			j = p->v;             	  //j为i的邻接顶点的序号
			e = ve[i];                 //计算活动<vi, vj>的最早开始时间e
			l = vl[j] - p->weight;      //计算活动<vi, vj>的最迟开始时间l
			if (e == l)               	//若为关键活动，则输出<vi, vj>
				cout << "<" << G.Vex[i].data << "," << G.Vex[j].data << ">    ";
			p = p->next;                 //p指向i的下一个邻接顶点
		}
	}
	return true;
}

int main()
{
	std::cout << "Hello World!\n";
	ALGraph G;

	CreateALGraph(G);
	int* topo = new int[G.vexnum];
	printg(G);
	CriticalPath(G, topo);
	return 0;
}