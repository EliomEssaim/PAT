
#include"stdio.h"
#include"string.h"
#include <stdlib.h>
#include <malloc.h>
int month[2][13]={
{0,31,29,31,30,31,30,31,31,30,31,30,31},
{0,31,28,31,30,31,30,31,31,30,31,30,31}
};
bool IsLeapYear(int year)
{
	return (year%4==0&&year%100!=0)||(year%400==0);
}
int main()
{
	int y1,m1,d1;
	int y2,m2,d2;
	int tmp;
	

	return 0;
}
//�ܽ᣺memset���ֽڷ����ڴ棬�����������char����Ļ����Ѷ��丳ֵ
//�������������0��ֵֻҪ��ĩβ�ĳ�sizeof��int��/sizeof��char���Ϳ���
//������ֵ
