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
};
