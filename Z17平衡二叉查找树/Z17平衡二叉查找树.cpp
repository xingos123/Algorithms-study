// Z17平衡二叉查找树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//---插入、查找、删除、调平衡

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct AVLNode
{
	int data;
	int height;
	struct AVLNode* lchild;
	struct AVLNode* rchild;
}*AVLTree;//---平衡二叉树数据结构
AVLTree Empty(AVLTree& T)
{
	if (T == NULL) return NULL;
	Empty(T->lchild);
	Empty(T->rchild);
	delete T;
	return NULL;
}//---删除树
inline  int Height(AVLTree T)
{
	if (T == NULL) return 0;
	return T->height;
}
void UpdateHeight(AVLTree& T)
{
	int h = Height(T->lchild) > Height(T->rchild) ? Height(T->lchild) : Height(T->rchild);//---没找到max函数
	T->height = h + 1;
}
AVLTree LL_Rotation(AVLTree& T)//LL旋转
{
	AVLTree temp = T->lchild;
	T->lchild = temp->rchild;
	temp->rchild = T;
	UpdateHeight(T);
	UpdateHeight(temp);
	return temp;
}
AVLTree RR_Rotation(AVLTree& T)//RR旋转
{
	AVLTree temp = T->rchild;
	T->rchild = temp->lchild;
	temp->lchild = T;
	UpdateHeight(T);
	UpdateHeight(temp);
	return temp;
}
AVLTree LR_Rotation(AVLTree& T)//LR旋转
{
	T->lchild = RR_Rotation(T->lchild);
	return LL_Rotation(T);
}
AVLTree RL_Rotation(AVLTree& T)//RL旋转
{
	T->rchild = LL_Rotation(T->rchild);
	return RR_Rotation(T);
}
AVLTree Insert(AVLTree& T, int x)
{
	if (T == NULL)
	{
		T = new AVLNode;
		T->lchild = T->rchild = NULL;
		T->data = x;
		T->height = 1;
		return T;
	}
	if (T->data == x) return T;
	if (x < T->data)
	{
		T->lchild = Insert(T->lchild, x);
		if (Height(T->lchild) - Height(T->rchild) == 2)
		{
			if (x < T->lchild->data)
				T = LL_Rotation(T);
			else
				T = LR_Rotation(T);
		}
	}
	else
	{
		T->rchild = Insert(T->rchild, x);
		if (Height(T->rchild) - Height(T->lchild) == 2)
		{
			if (x > T->rchild->data)
				T = RR_Rotation(T);
			else
				T = RL_Rotation(T);
		}
	}
	UpdateHeight(T);
	return T;
}

AVLTree Adjust(AVLTree& T)
{
	if (T == NULL) return NULL;
	if (Height(T->lchild) - Height(T->rchild) == 2)
	{
		if (Height(T->lchild->lchild) >= Height(T->lchild->rchild))
			T = LL_Rotation(T);
		else
			T = LR_Rotation(T);
	}
	if (Height(T->rchild) - Height(T->lchild) == 2)
	{
		if (Height(T->rchild->rchild) >= Height(T->rchild->lchild))
			T = RR_Rotation(T);
		else
			T = RL_Rotation(T);
	}
	UpdateHeight(T);
	return T;
}
AVLTree Delete(AVLTree& T, int x)
{
	if (T == NULL) return NULL;
	if (T->data == x)
	{
		if (T->rchild == NULL)
		{
			AVLTree temp = T;
			T = T->lchild;
			delete temp;
		}
		else
		{
			AVLTree temp;
			temp = T->rchild;
			while (temp->lchild)
				temp = temp->lchild;
			T->data = temp->data;
			T->rchild = Delete(T->rchild, T->data);
			UpdateHeight(T);
		}
		return T;
	}
	if (T->data > x)
		T->lchild = Delete(T->lchild, x);
	if (T->data < x)
		T->rchild = Delete(T->rchild, x);
	UpdateHeight(T);
	if (T->lchild)
		T->lchild = Adjust(T->lchild);
	if (T->rchild)
		T->rchild = Adjust(T->rchild);
	if (T) T = Adjust(T);
	return T;
}

void Preorder(AVLTree T)//前序遍历方便看树的结果
{
	if (T == NULL) return;
	cout << T->data << "\t" << T->height << endl;
	Preorder(T->lchild);
	Preorder(T->rchild);
}

void Inorder(AVLTree T)//中序遍历方便看树的结果
{
	if (T == NULL) return;
	Inorder(T->lchild);
	cout << T->data << "\t" << T->height << endl;
	Inorder(T->rchild);
}

void Posorder(AVLTree T)//后序遍历方便看树的结果
{
	if (T == NULL) return;
	Posorder(T->lchild);
	Posorder(T->rchild);
	cout << T->data << "\t" << T->height << endl;
}

void show(AVLTree T)
{
	Preorder(T);
	cout << endl;
	Inorder(T);
	cout << endl;
	Posorder(T);
}

AVLTree CreateAVL(AVLTree& T)
{
	int n, x;
	cin >> n;//结点数
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		T = Insert(T, x);
	}
	return T;
}
int main()
{
	int x;
	AVLTree root = NULL;
	root = Empty(root);
	CreateAVL(root);
	show(root);
	cin >> x;
	root = Delete(root, x);
	show(root);
	return 0;
}