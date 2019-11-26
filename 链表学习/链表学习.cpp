// 链表学习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
typedef struct Lnode
{
	int data;
	struct Lnode* next;
}Lnode, * Linklist;//---定义链表数据结构
bool InitL(Linklist& L)//---初始化
{
	L = new Lnode;//---创建头结点
	if (!L)
	{
		return false;
	}//---生成节点失败
	L->next = NULL;
	return true;
}
void HCreateL(Linklist& L)
{
	int n;//---输入n个值
	Linklist s;
	L->next = NULL;
	cout << "请输入元素个数n:\n";
	cin >> n;
	cout << "请依次输入元素:\n";
	cout << "头插法生成链表中...";
	while (n--)
	{
		s = new Lnode;
		cin >> s->data;
		s->next = L->next;
		L->next = s;
	}
}
void ECreateL(Linklist& L)
{
	int n;
	Linklist s, r;
	L->next = NULL;
	r = L;
	cout << "请输入元素个数n:\n";
	cin >> n;
	cout << "请依次输入元素:\n";

	while (n--)
	{
		s = new Lnode;
		cin >> s->data;
		s->next = NULL;
		r->next = s;
		r = s;
	}
	cout << "尾插法生成链表中...\n";
}
bool GetEFromL(Linklist L, int i, int& e)//---取第i个值
{
	int j = 1;
	Linklist p;
	p = L->next;
	while (j < i && p)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		return false;
	}
	e = p->data;
	return true;
}
bool LocateEFromL(Linklist L, int e)
{
	Linklist p;
	p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
	}
	if (!p)
	{
		return false;
	}
	return true;
}
bool InsertToL(Linklist& L, int i, int e)
{
	int j;
	Linklist p, s;//---一个获取位置，一个插入
	p = L->next;
	j = 1;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
	{
		return false;
	}
	s = new Lnode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool DeleteFromL(Linklist& L, int i)
{
	Linklist p, q;
	p = L->next;
	int j = 1;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
	{
		return false;
	}
	q = p->next;
	p->next = q->next;
	delete q;
	return true;
}
void PrintL(Linklist L)
{
	Linklist p;
	p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}

//---两个有序链表合并
void MergeL(Linklist La, Linklist Lb, Linklist& Lc)
{
	Linklist p, q, r;
	p = La->next;
	q = Lb->next;
	Lc = La;
	r = Lc;
	while (p && q)
	{
		if (p->data <= q->data)
		{
			r->next = p; r = p;
			p = p->next;
		}
		else
		{
			r->next = q; r = q;
			q = q->next;
		}
	}
	r->next = p ? p : q;
	delete Lb;
}
void FindMidL(Linklist L)//---快慢指针查找中间值
{
	Linklist p, q;
	p = q = L;
	while (p && p->next)
	{
		p = p->next->next;
		q = q->next;
	}
	cout << q->data << "\n";
}
void FindKFromL(Linklist L, int k)//---在单链表中查找倒数第K个节点，使用快慢指针，达到p到达最后一个节点时，q与p的差值为k
{
	Linklist p, q;
	p = q = L;
	int i = 0, j = 0;
	while (p)
	{
		p = p->next;
		j++;
	}
	while (q && i < j - k)
	{
		q = q->next;
		i++;
	}
	cout << q->data << "\n";
}
int main()
{
	// 	int i, x, e, choose;
	// 	Linklist L;
	// 	cout << "1. 初始化\n";
	// 	cout << "2. 创建单链表（前插法）\n";
	// 	cout << "3. 创建单链表（尾插法）\n";
	// 	cout << "4. 取值\n";
	// 	cout << "5. 查找\n";
	// 	cout << "6. 插入\n";
	// 	cout << "7. 删除\n";
	// 	cout << "8. 输出\n";
	// 	cout << "0. 退出\n";
	// 	choose = -1;
	// 	while (choose != 0)
	// 	{
	// 		cout << "请输入数字选择:";
	// 		cin >> choose;
	// 		switch (choose)
	// 		{
	// 		case 1: //初始化一个空的单链表
	// 			if (InitL(L))
	// 				cout << "初始化一个空的单链表!\n";
	// 			break;
	// 		case 2: //创建单链表（前插法）
	// 			HCreateL(L);
	// 			cout << "前插法创建单链表输出结果:\n";
	// 			PrintL(L);
	// 			break;
	// 		case 3: //创建单链表（尾插法）
	// 			ECreateL(L);
	// 			cout << "尾插法创建单链表输出结果:\n";
	// 			PrintL(L);
	// 			break;
	// 		case 4: //单链表的按序号取值
	// 			cout << "请输入一个位置i用来取值:";
	// 			cin >> i;
	// 			if (GetEFromL(L, i, e))
	// 			{
	// 				cout << "查找成功\n";
	// 				cout << "第" << i << "个元素是：" << e << endl;
	// 			}
	// 			else
	// 				cout << "查找失败\n\n";
	// 			break;
	// 		case 5: //单链表的按值查找
	// 			cout << "请输入所要查找元素x:";
	// 			cin >> x;
	// 			if (LocateEFromL(L, x))
	// 				cout << "查找成功\n";
	// 			else
	// 				cout << "查找失败! " << endl;
	// 			break;
	// 		case 6: //单链表的插入
	// 			cout << "请输入插入的位置和元素（用空格隔开）:";
	// 			cin >> i;
	// 			cin >> x;
	// 			if (InsertToL(L, i, x))
	// 				cout << "插入成功.\n\n";
	// 			else
	// 				cout << "插入失败!\n\n";
	// 			break;
	// 		case 7: //单链表的删除
	// 			cout << "请输入所要删除的元素位置i:";
	// 			cin >> i;
	// 			if (DeleteFromL(L, i))
	// 				cout << "删除成功!\n";
	// 			else
	// 				cout << "删除失败!\n";
	// 			break;
	// 		case 8: //单链表的输出
	// 			cout << "当前单链表的数据元素分别为:\n";
	// 			PrintL(L);
	// 			cout << endl;
	// 			break;
	// 		}
	// 	}
	Linklist La = new Lnode, Lb = new Lnode, Lc = new Lnode;
	cout << "创建La有序链表：\n";
	ECreateL(La);
	cout << "创建Lb有序链表：\n";
	ECreateL(Lb);
	cout << "合并两个有序链表中...\n";
	MergeL(La, Lb, Lc);

	PrintL(Lc);
	cout << "寻找链表中间值中...\n";
	FindMidL(Lc);
	cout << "请输入要查找的倒数的位置：\n";
	int k;
	cin >> k;
	cout << "寻找链表倒数第" << k << "的值中...\n";
	FindKFromL(Lc, k);
	return 0;
}