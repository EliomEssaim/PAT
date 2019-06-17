[TOC]



# 英语词汇

## 单词

- word
- happy
- threshold
- PAT
- LCM
- AVL

## 句子

The quick brown fox jumps over the lazy dog.



# 数据结构

## 链表类

## 树类



## 图类



## 堆栈与队列

## 路径规划

------



# 常用模板

## 1.进制转换

```C++
//P进制转换为十进制
int P2dec(int x,int p)
{
    int product=1,sum=0;
    while(x>0)
    {
        sum+=(x%10)*product;
        x/=10;
        product*=p; 
    }
    return sum;
}
//十进制转换为p进制
int dec2P(int x,int p)
{
    int z[40];
    //等于0 另外处理
    for(i=0;x/p!=0;i++)
    {
        z[i]=x%p;
        x/=p;
    }
    //逆序输出；
}
```

## 2.素数表的编程实现

```c++
vector<int> prime(500000, 1);  
for(int i = 2; i * i < 500000; i++)
        for(int j = 2; j * i < 500000; j++)
            prime[j * i] = 0;
```



## 3.最大公约数和最小公倍数

```c++
int gcd(int a,int b)
{
    return a%b==0?b:gcd(b,a%b);
}
/* a*b可能会有溢出问题！*/
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
```





------

------



# 编程语言知识补充

## 函数类

### sort函数

```c++
void sort(数组首地址,数组尾地址+1,cmp函数)
bool cmp(结构体a,结构体b){return a>b;}//按照从大到小排序，不写cmp就是从小到大
```

- sort函数实现排名（PAT A1025）

### memset函数

```c++
//按字节赋值只能是0或者-1不会出错
memset(数组名,值,sizeof(数组格式));
//如果想赋值其他值使用fill
fill(first,last,val);
//first为容器的首迭代器，last为容器的末迭代器，val为将要替换的值。
```



------



## 非函数类

### 各种类型的最大值

**unsigned int** 32 位4294967296 **十位**  int*int 中int最好不超过**50000**！int+int中int不要超过**1,000,000,000**一个亿

**long** 和**int** 在64位机下的长度是一样的

**long long**是64位的 18446744073709551616无符号十进制下是 **20位**



### 输出格式控制

```c++
//按4位输出不够补0
printf("%04d",a);
//保留小数点后两位
printf(".2f",a);
//在while循环下实现 保证第一个不打出*后面的都打出了*号
if(state) printf("*");
printf("%d", i);
state = true;
```

### 四舍五入

```c++
//对float
#include<math.h>
round(double x);
//形成整数小数部分四舍五入舍去
(int)(a*10+0.5)/10
//保留小数点后2位
(a*100+0.5)/100
```

### 结构体的构造函数编程

```c++
struct StudentList{
    long long num;
    char name[10];
    StudentList(int _num,char *_name)
    {
        num=_num;
        name=_name;
    }
}
```



# 经典算法的实现

## 素数——埃氏筛法

```c++

```



# 常见错误

- 闰年的规律是四年一闰百年不闰四百年再闰 闰年二月份有29天 平年是28天

  ```c++
   return ((year%4==0)&&(year%100!=0))||(year%400==0)
  ```

- test for git 





























