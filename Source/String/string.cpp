#include "stdafx.h"
using namespace std;





//////////////////////////////////////////////////////////////////////////////
void TestString()
{
	string str("aa.txt");

	auto pos = str.find(".txt");
}





/*
//string��Ĳ��Һ�����
int find(char c, int pos = 0) const;//��pos��ʼ�����ַ�c�ڵ�ǰ�ַ�����λ��
int find(const char *s, int pos = 0) const;//��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
int find(const char *s, int pos, int n) const;//��pos��ʼ�����ַ���s��ǰn���ַ��ڵ�ǰ���е�λ��
int find(const string &s, int pos = 0) const;//��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
//���ҳɹ�ʱ��������λ�ã�ʧ�ܷ���string::npos��ֵ
int rfind(char c, int pos = npos) const;//��pos��ʼ�Ӻ���ǰ�����ַ�c�ڵ�ǰ���е�λ��
int rfind(const char *s, int pos = npos) const;
int rfind(const char *s, int pos, int n = npos) const;
int rfind(const string &s,int pos = npos) const;
//��pos��ʼ�Ӻ���ǰ�����ַ���s��ǰn���ַ���ɵ��ַ����ڵ�ǰ���е�λ�ã��ɹ���������λ�ã�ʧ��ʱ����string::npos��ֵ
int find_first_of(char c, int pos = 0) const;//��pos��ʼ�����ַ�c��һ�γ��ֵ�λ��
int find_first_of(const char *s, int pos = 0) const;
int find_first_of(const char *s, int pos, int n) const;
int find_first_of(const string &s,int pos = 0) const;
//��pos��ʼ���ҵ�ǰ���е�һ����s��ǰn���ַ���ɵ���������ַ���λ�á�����ʧ�ܷ���string::npos
int find_first_not_of(char c, int pos = 0) const;
int find_first_not_of(const char *s, int pos = 0) const;
int find_first_not_of(const char *s, int pos,int n) const;
int find_first_not_of(const string &s,int pos = 0) const;
//�ӵ�ǰ���в��ҵ�һ�����ڴ�s�е��ַ����ֵ�λ�ã�ʧ�ܷ���string::npos
int find_last_of(char c, int pos = npos) const;
int find_last_of(const char *s, int pos = npos) const;
int find_last_of(const char *s, int pos, int n = npos) const;
int find_last_of(const string &s,int pos = npos) const;
int find_last_not_of(char c, int pos = npos) const;
int find_last_not_of(const char *s, int pos = npos) const;
int find_last_not_of(const char *s, int pos, int n) const;
int find_last_not_of(const string &s,int pos = npos) const;
//find_last_of��find_last_not_of��find_first_of��find_first_not_of���ƣ�ֻ�����ǴӺ���ǰ����
*/