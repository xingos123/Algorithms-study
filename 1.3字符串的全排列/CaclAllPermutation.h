#pragma once
class CaclAllPermutation
{
public:
	void CaclAllPermutation1(char* str, int from, int to);//---�ݹ�ʵ��ȫ����
	bool CaclAllPermutation2(char* perm, int num);//---�ֵ���ʵ��ȫ����
	//---�ֵ�����������У�����abc����aaa,bbb,ccc,abc,acb,aac��
	//---�ַ����������adc����a,b,c,ad,ac��
	//---���еĴ�ӡ//����������
	void CaclAllPermutation5();
};
