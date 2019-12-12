// Z15哈希表查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//---链地址法又叫拉链法

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define  M 15
#define  NULLKey 0

typedef struct OVnode
{
	int v;
	struct  OVnode* next;
}OVnode;
typedef struct Hnode
{
	int data;
	OVnode* next;
}Hnode;
typedef struct
{
	Hnode Hash[M];
}HashTable;
void InitH(HashTable& H)
{
	for (int i = 0; i < M; i++)
	{
		H.Hash[i].data = NULLKey;
		H.Hash[i].next = NULL;
	}
}
int HK(int key)
{
	return key % 13;
}
bool InsertHash(HashTable& H, int key)
{
	int h0 = HK(key);
	if (H.Hash[h0].data == NULLKey)
	{
		H.Hash[h0].data = key;
		return true;
	}
	else
	{
		OVnode* h = new OVnode;
		h->v = key;
		h->next = H.Hash[h0].next;
		H.Hash[h0].next = h;
		return true;
	}
	return false;
}
int SearchHash(HashTable H, int key)
{
	int h0 = HK(key); int x = 1;
	if (H.Hash[h0].data == NULLKey)
		return -1;
	else if (H.Hash[h0].data == key)
		return x;
	else
	{
		OVnode* p;
		p = H.Hash[h0].next;
		while (p != NULL)
		{
			x++;
			if (p->v == key)
				return x;
			p = p->next;
		}
		return -1;
	}
}
void PrintH(HashTable H)
{
	for (int i = 0; i < M; i++)
	{
		if (H.Hash[i].data != NULLKey)
		{
			cout << "第" << i + 1 << "位：" << H.Hash[i].data << "  ";

			OVnode* p = H.Hash[i].next;
			while (p != NULL)
			{
				cout << p->v << "  ";
				p = p->next;
			}
			cout << endl;
		}
	}
}
int main()
{
	std::cout << "Hello World!\n";
	HashTable H; int x;

	InitH(H);
	cout << "输入12个关键字，存入哈希表中：" << endl;
	for (int i = 0; i < 12; i++)
	{
		cin >> x;
		if (!InsertHash(H, x))
		{
			cout << "创建哈希表失败！" << endl;
			return 0;
		}
	}
	cout << "输出哈希表：" << endl;
	PrintH(H);
	cout << "输入要查找的关键字" << endl;
	cin >> x;
	int y = HK(x);
	int result = SearchHash(H, x);
	if (result != -1)
		cout << "在第" << y + 1 << "-" << result << "位置找到" << endl;
	else
		cout << "未找到" << endl;
	return 0;
}