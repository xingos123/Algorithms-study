#pragma once
class CaclAllPermutation
{
public:
	void CaclAllPermutation1(char* str, int from, int to);//---递归实现全排列
	bool CaclAllPermutation2(char* perm, int num);//---字典序实现全排列
	//---字典序的所有排列，例如abc包括aaa,bbb,ccc,abc,acb,aac等
	//---字符的所有组合adc，有a,b,c,ad,ac等
	//---序列的打印//递增子序列
	void CaclAllPermutation5();
};
