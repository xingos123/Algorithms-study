// Z队列的学习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define MAXSIZE 100
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef struct Squeue
{
	int* base;//---基地址
	int front, rear;//---头指针，尾指针
}Queue;
bool InitQ(Queue& q)
{
	q.base = new int[MAXSIZE];//---分配空间
	if (!q.base)
	{
		return false;
	}
	q.front = q.rear = 0;//---头指针与尾指针置为零，队列为空
	return true;
}
bool PushQ(Queue& q, int e)//---入队
{
	// 	if ((q.rear + 1) % MAXSIZE == 0)//---用取余处理临界状态，充分利用空间，达成循环队列（入队）
	// 	{
	// 		q.rear = 0;
	// 	}
	if ((q.rear + 1) % MAXSIZE == q.front)
		return false;
	/*q.base[(q.rear++) % MAXSIZE] = e;*/
	q.base[q.rear] = e;
	q.rear = (q.rear + 1) % MAXSIZE;
	return true;
}
bool PopQ(Queue& q, int& e)//---出队
{
	// 	if ((q.front + 1) % MAXSIZE == 0)//---用取余处理临界状态，充分利用空间，达成循环队列
	// 	{
	// 		q.front = 0;
	// 	}
	if (q.rear == q.front)
		return false;
	/* 	e = q.base[(q.front++) % MAXSIZE];*/
	e = q.base[q.front];
	q.front = (q.front + 1) % MAXSIZE;
	return true;
}
int QLength(Queue q)
{
	return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}
int main()
{
	std::cout << "Hello World!\n";
	int n, x;
	Queue Q;
	InitQ(Q);
	cout << "请输入要入队的个数n:\n";
	cin >> n;
	cout << "请输入依次入队的元素：\n";
	while (n--)
	{
		cin >> x;
		PushQ(Q, x);
	}
	cout << "正在输出队中的所有元素...\n";
	while (Q.front != Q.rear)
	{
		PopQ(Q, x);
		cout << x << "\t";
		if (x == 99)
			break;
	}
	cout << "\n出队完成。\n";
	cout << "现在队的长度：" << QLength(Q) << "\n";
	//---使用STL完成栈的操作
	stack<int> s; int t, y;
	cout << "请输入要入队的个数t:\n";
	cin >> t;
	cout << "请输入依次入队的元素：\n";
	while (t--)
	{
		cin >> y;
		s.push(y);
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}