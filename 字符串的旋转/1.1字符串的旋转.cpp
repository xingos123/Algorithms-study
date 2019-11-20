// 字符串的旋转.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ReverseMethods.h"
using namespace std;
int main()
{
	ReverseMethods re;
	char s[] = "student";
	//re.LeftRotateString(s, 7, 6);
	cout << "三步旋转：" << re.ReverseString2(s, 'e') << endl;

	char str[] = "I am a student.";
	//re.AllReverse(str, 5, 15);
	cout << "三步旋转：" << re.ReverseString3(str) << endl;
}