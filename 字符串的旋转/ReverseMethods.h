#pragma once

class ReverseMethods
{
public:
	//---��ͨ��ת
	void LeftShiftOne(char* s, int n);//---�ѵ�һ��ת�����һ��
	void LeftRotateString(char* s, int n, int m);//---��ǰM��ת�����һ��
	//--������ת
	void SingleReverse(char* s, int st, int en);//--��������ת
	void AllReverse(char* s, int m, int n);//---ȫ����ת

	char* ReverseString1(char* s);//---�ȷ�ת���ʣ�Ȼ�������巭ת����
	char* ReverseString3(char* s);//---�����巭ת���ӣ�Ȼ���ٷ�ת����

	//---�����е����ӽ����ع�
	char* ReverseString2(char* s, char c);//---��ĳһ�ַ�Ϊ�ֽ��ߣ����ַ�ǰ�İ�����˳��ŵ�����
};
