
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
//总结：memset按字节分配内存，所以如果不是char数组的话很难对其赋值
//，但有例外如对0赋值只要在末尾改成sizeof（int）/sizeof（char）就可以
//正常赋值
