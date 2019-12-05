// Z5二叉树的学习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
using namespace std;

typedef struct  Bnode
{
	char data;
	struct  Bnode* lchild, * rchild;
}Bnode, * Btree;
void CreateT(Btree& T)//---使用补空法创建二叉树
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = new Bnode;
		T->data = ch;
		CreateT(T->lchild);
		CreateT(T->rchild);
	}
}
Btree CreateTB(char* pre, char* mid, char len)//---根据先序与中序创建树
{
	if (len == 0)
	{
		return NULL;
	}
	char ch = pre[0];
	int index = 0;
	while (mid[index] != ch)
	{
		index++;
	}
	Btree T = new Bnode;
	T->data = ch;
	T->lchild = CreateTB(pre + 1, mid, index);
	T->rchild = CreateTB(pre + index + 1, mid + index + 1, len - index - 1);
	return T;
}
Btree CreateTO(char* last, char* mid, char len)//---根据后序与中序创建树
{
	if (len == 0)
	{
		return NULL;
	}
	char ch = last[len - 1];
	int index = 0;
	while (mid[index] != ch)
	{
		index++;
	}
	Btree T = new Bnode;
	T->data = ch;
	T->lchild = CreateTO(last, mid, index);
	T->rchild = CreateTO(last + index, mid + index + 1, len - index - 1);
	return T;
}
void PreOrder(Btree T)//---先序
{
	if (T)
	{
		cout << T->data << " ";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(Btree T)//---中序
{
	if (T)
	{
		PreOrder(T->lchild);
		cout << T->data << " ";
		PreOrder(T->rchild);
	}
}
void PoOrder(Btree T)//---后序
{
	if (T)
	{
		PreOrder(T->lchild);
		PreOrder(T->rchild);
		cout << T->data << " ";
	}
}
bool LevelTraverse(Btree T)//--层次遍历
{
	Btree p;
	if (!T)
	{
		return false;
	}
	queue<Btree>Q;
	Q.push(T);
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		cout << p->data << " ";
		if (p->lchild)
		{
			Q.push(p->lchild);
		}
		if (p->rchild)
		{
			Q.push(p->rchild);
		}
	}
	return true;
}
int main()
{
	Btree mt;
	char pt[] = "ABDECFG";
	char mid[] = "DBEAFGC";
	char ot[] = "DEBGFCA";
	//CreateT(mt);
	mt = CreateTB(pt, mid, 7);
	PreOrder(mt);
	cout << endl;
	InOrder(mt);
	cout << endl;
	PoOrder(mt);
	cout << endl;
	LevelTraverse(mt);
	cout << endl;

	std::cout << "Hello World!\n";
}