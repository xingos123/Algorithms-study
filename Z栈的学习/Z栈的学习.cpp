// Z栈的学习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  MAXSIZE 100
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct  SqStack
{
	int* top;
	int* base;
}Sqstack;
bool InitS(Sqstack& S)//---栈的初始化
{
	S.base = new int[MAXSIZE];
	if (!S.base)
	{
		return false;
	}
	S.top = S.base;
	return true;
}
bool PushS(Sqstack& S, int e)//---进栈
{
	if (S.top - S.base == MAXSIZE)
	{
		return false;
	}
	*(S.top++) = e;
	return true;
}
bool PopS(Sqstack& S, int& e)//---出栈
{
	if (S.top == S.base)
	{
		return false;
	}
	e = *(--S.top);//--在前表示先进行减的运算然后进行赋值，在后则表示先赋值再运算
	return true;
}
bool GetTopS(Sqstack S, int& e)//---取栈顶
{
	if (S.top == S.base)
	{
		return false;
	}
	e = *(S.top - 1);
	return true;
}
int main()
{
	std::cout << "Hello World!\n";
	int x; Sqstack S;
	InitS(S);
	cout << "请输入要入栈的个数n:\n";
	int n;
	cin >> n;
	cout << "请输入依次入栈的元素：\n";
	while (n--)
	{
		cin >> x;
		PushS(S, x);
	}
	cout << "正在输出所有栈的元素...\n";
	while (S.top != S.base)
	{
		GetTopS(S, x);
		cout << x << "\t";
		PopS(S, x);
	}

	cout << "\n出栈完成。\n";
}