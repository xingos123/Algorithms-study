#pragma once
#include <string>
#include <algorithm>
using namespace std;
class StringContain
{
public:
	bool StringContain1(string& a, string& b);//--ֱ�ӽ��в�ѯ
	bool StringContain2(string& a, string& b);//--�������ѯ
	//--���������ַ�������������ַ���������
	bool StringContain3(string& a, string& b);//--һ��˼·���Ƚ���һ��26�����������飬���ַ���a����������������������ƥ�䲢���������ĸ���������ĳ˻���Ȼ�����b�еĽ���������
	bool StringContain4(string& a, string& b);//--λ���㷨
	bool StringContain5(string& a, string& b);//--��λ�ʣ����Ȱ�str a����λ���㴦��Ȼ�����ֵ�����ͬ�ַ����Ľ�����ѯ��
};
