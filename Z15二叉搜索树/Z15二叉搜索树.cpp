// Z15二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define  EndFlag -1
typedef int ElemType;
typedef struct BstNode
{
	ElemType data;
	BstNode* lchild, * rchild;
}BstNode, * BsTree;
BsTree SearchBst(BsTree T, ElemType key)
{
	if (!T || key == T->data)
		return T;
	else if (key < T->data)
		return SearchBst(T->lchild, key);
	else
		return SearchBst(T->rchild, key);
}
void InsertBst(BsTree& T, ElemType e)
{
	if (!T)
	{
		BsTree S = new BstNode;
		S->data = e;
		S->lchild = S->rchild = NULL;
		T = S;
	}
	else if (e < T->data)
		InsertBst(T->lchild, e);
	else if (e > T->data)
		InsertBst(T->rchild, e);
}
void CreateBst(BsTree& T)
{
	T = NULL;
	ElemType e;
	cin >> e;
	while (e != EndFlag)
	{
		InsertBst(T, e);
		cin >> e;
	}
}
void InOrderTraverse(BsTree T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		cout << T->data << "  ";
		InOrderTraverse(T->rchild);
	}
}

//---二叉查找树的删除
void DeleteBst(BsTree& T, ElemType key)
{
	//从二叉排序树T中删除关键字等于key的结点
	BsTree p = T; BsTree f = NULL;
	BsTree q = NULL;
	BsTree s = NULL;
	if (!T) return; //树为空则返回
	while (p)//查找
	{
		if (p->data == key) break;  //找到关键字等于key的结点p，结束循环
		f = p;                //f为p的双亲
		if (p->data > key)
			p = p->lchild; //在p的左子树中继续查找
		else
			p = p->rchild; //在p的右子树中继续查找
	}
	if (!p) return; //找不到被删结点则返回
	//三种情况：p左右子树均不空、无右子树、无左子树
	if ((p->lchild) && (p->rchild))//被删结点p左右子树均不空
	{
		q = p;
		s = p->lchild;
		while (s->rchild)//在p的左子树中继续查找其前驱结点，即最右下结点
		{
			q = s;
			s = s->rchild;
		}
		p->data = s->data;  //s的值赋值给被删结点p,然后删除s结点
		if (q != p)
			q->rchild = s->lchild; //重接q的右子树
		else
			q->lchild = s->lchild; //重接q的左子树
		delete s;
	}
	else
	{
		if (!p->rchild)//被删结点p无右子树，只需重接其左子树
		{
			q = p;
			p = p->lchild;
		}
		else if (!p->lchild)//被删结点p无左子树，只需重接其右子树
		{
			q = p;
			p = p->rchild;
		}
		/*――――――――――将p所指的子树挂接到其双亲结点f相应的位置――――――――*/
		if (!f)
			T = p;  //被删结点为根结点
		else if (q == f->lchild)
			f->lchild = p; //挂接到f的左子树位置
		else
			f->rchild = p;//挂接到f的右子树位置
		delete q;
	}
}
int main()
{
	std::cout << "Hello World!\n";
	BsTree T;
	cout << "请输入一些整型数，-1结束" << endl;
	CreateBst(T);
	cout << "当前有序二叉树中序遍历结果为" << endl;
	InOrderTraverse(T);
	cout << endl;
	ElemType key;//待查找或待删除内容
	cout << "请输入待查找关键字" << endl;
	cin >> key;
	BsTree result = SearchBst(T, key);
	if (result)
		cout << "找到" << key << endl;
	else
		cout << "未找到" << key << endl;
	cout << "请输入待插入关键字" << endl;
	cin >> key;
	InsertBst(T, key);
	InOrderTraverse(T);
	cout << "请输入待删除关键字" << endl;
	cin >> key;
	DeleteBst(T, key);
	cout << "当前有序二叉树中序遍历结果为" << endl;
	InOrderTraverse(T);
	return 0;
	//5  18  20  25  32  45  69 -1
}