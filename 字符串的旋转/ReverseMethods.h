#pragma once

class ReverseMethods
{
public:
	//---普通旋转
	void LeftShiftOne(char* s, int n);//---把第一个转到最后一个
	void LeftRotateString(char* s, int n, int m);//---把前M个转到最后一个
	//--三步旋转
	void SingleReverse(char* s, int st, int en);//--单部分旋转
	void AllReverse(char* s, int m, int n);//---全部旋转

	char* ReverseString1(char* s);//---先翻转单词，然后再整体翻转句子
	char* ReverseString3(char* s);//---先整体翻转句子，然后再翻转单词

	//---对文中的例子进行重构
	char* ReverseString2(char* s, char c);//---以某一字符为分界线，把字符前的按正常顺序放到后面
};
