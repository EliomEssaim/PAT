[TOC]





# 英语词汇

## 单词

- consecutive **连续**
- utility**实用**

## 句子

The quick brown fox jumps over the lazy dog.

**significant digits**有效数字

**not compatible** 不兼容

**5-digit**五位

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
    //逆序输出 可用堆栈实现
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

# STL知识补充

## vector(可变长数组)

- sort可用

~~~c++
vector<int> couple(100000,-1);//这样可以初始化vector为-1
vector<int> GoodsList(amount);//这个才是vector预分配空间
vector<int> guest[guestNum];//错误声明方法这样生成的数组是vector<int>类型的不能直接赋值
vector<int> guest(guestNum);//正确声明长度为guestNum 首地址为guest 数组
ans[i].name.c_str()；//c_str()这样就可以用printf了
v.push_back(node{s, score, -1, -1, 0});//如果vector是结构体可以这么写
  
/*********分割线*****************/
//vector的访问方式有哪两种？
#include<vector>
vector<int> vi;
vi.pushback();
vi.popback();
vi.size();
vi.clear();
vi.insert(?,?);
vi.erase(?,?)//单个元素写法 区间的写法	
~~~

## set(集合)

~~~c++
set<int>::iterator sit=Singles.begin();
printf("%d",*sit);//set的访问方式
multiset<int> st;//只排序不去重
ans[i].name.c_str()//c_str()这样就可以用printf了
/*********分割线*****************/
//set的访问方式？
#include<set>
set<int>  st;
st.insert(?);
st.find();//返回值是什么？
st.erase(?,?);//单个元素的两种方法 删除区间的一种方法
st.size();
st.clear();

~~~

## string

sort可用

~~~c++
#include<string>//string忽略空格//string可以用下标访问吗？
using namespace std;
string str1,str2[n];//n为变量 这种写法是允许的
str1+=str2;
str2-=str1;//没有这种写法
ans[i].name.c_str()//c_str()这样就可以用printf了
/*********分割线*****************/
string str="asdfdfwq",str2;
zeroPos=3;
str2=str.substr(0,zeroPos);
cout<<str2<<endl;//输出？                                                          asd
/*********分割线*****************/
//如何删除一个元素与一排元素？
//如何插入多个元素？
//string的访问方式有哪两种？
//默写：
string str;
str.insert(?,?);
str.erase(?,?);//删除一个元素的两个写法 删除区间的两种写法
str.substr(?,?);
string::npos
str.find(?);
str.replace(?,?,?)//两种写法
/*********分割线*****************/    
getline(cin, str);//获得一行数据 使用之前要用 getchar();把\n吃掉！！！
~~~

## map(映射)

~~~c++
map<string, int> mp;
~~~

- **int会被初始化为0！！**
- map的会以键**从小到大**排序
- unodered_map只映射**不排序**（#include <unordered_map>）**C++11**
- 

~~~C++
//map访问方式有哪两种？

/*********分割线*****************/  
#include<map>
using namespace std;
map<char,int> mp;
map<char,int>::iterator it=mp.begin();
it.first=?;
it.second=?;
mp.find(?);
mp.erase(?);//删除单个元素的两种方法？删除区间元素的一个方法
mp.size();
mp.clear();
/*********分割线*****************/
map<int,vector<int> > unCompatible;
unCompatible[gsA].push_back(gsB);//unCompatible[gsA]代表vector已经是vector类了！
~~~

- //逆序输出map
  for(map<int,int>::**reverse_iterator** it=**mp.rbegin()**;it!=**mp.rend()**;it++)
          cout<<it->first<<" "<<it->second<<endl;

## queue（队列）

~~~C++
#include<queue>
using namespace std;
queue<int> q;
q.push(i);
q.pop();//取出但不返回值
q.front();
q.back();//返回值但不取出
q.empty();//使用pop和front之前必先使用empty判断是否为空
q.size();
~~~

### priority_queue(优先队列)

~~~C++
#include<queue>
using namespace std;
priority_queue<int> q;//没有front back
q.size();
q.top();//返回值但不取出
q.push();
q.pop();//取出但不返回值
q.empty();//无论是优先队列还是
priority_queue<int,vector<int>,less<int> >q;//less<int> 从顶向下变小如果是greater<int> 从顶向下变大
/************结构体的优先队列**************/
struct fruit{
        string name;
        int price;
        friend bool operator < (fruit f1,fruit f2){
            return f1.price<f2.price;
        };
    }f1,f2,f3;
//.....
priority_queue<fruit> fq;
f1.name="桃子";
f1.price=3;
f2.name="梨子";
f2.price=4;
f3.name="苹果";
f3.price=1;
fq.push(f1);
fq.push(f2);
fq.push(f3);
fq.top();//输出梨子 4；因为默认为less所以top是最大的，而struct里面定义价格小的比较小所以价格最大即优先级最大的
~~~

## stack(堆栈)

~~~C++
#include<stack>
using namespace std;
stack<int> st;
st.push();
st.pop();
st.top();
st.empty();
st.size();
~~~

## pair(对)

~~~C++
/*
相当于结构体
struct pair{
typename first;
typename second;
}
*/
#include<utility>//添加map会自动添加utility
using namespace std;
pair<string,int> p;
pair<string,int> p1("haha",5);//初始化方法一
p=make_pair("haha",5);//初始化方法二
cout<< p.first << " " << p.second <<endl;//访问方式
/* pair可以比较大小，但是先比较first才比较second*/
//pair可以让map用insert函数而不是单单只能用迭代器和下标来访问
mp.insert(make_pair("hahaa",5));
mp.insert(pair<string,int>("haha",10));//类型名直接加小括号
~~~

## Algorithm头文件

~~~C++
max(x,y);min(x,y);abs(x);//操作对象都是整数abs如果想用浮点数要用math.h下的fabs()
swap(x,y);
reverse(it,it2);//左闭右开的将区间的迭代器进行反转，数组可用vector可用string可用
next_permutation(a,a+3);//给出按字典序的下一个全排列如 123 132 213 231....最后会输出false
//a是数组整型指针
fill(a,a+5,3);//对指针范围内（左闭右开），进行赋值
lower_bound(first,last,val);
upper_bound(fitst,last,val);//在有序！！数组或者容器中查找第一个值大/小于等于val的元素的指针/迭代器
//如果想要获得下标可以用指针减去，头指针就是下标了
~~~

### sort函数

```c++
void sort(数组首地址,数组尾地址+1,cmp函数)
bool cmp(结构体a,结构体b){return a>b;}//按照从大到小排序，不写cmp就是从小到大
```

- sort函数实现排名（PAT A1025）
- **vector**、**string**也可以用此排序

# 编程语言知识补充

## 函数类

### memset函数

```c++
//按字节赋值只能是0或者-1不会出错
memset(数组名,值,sizeof(数组格式));
//如果想赋值其他值使用fill
fill(first,last,val);
//first为容器的首迭代器，last为容器的末迭代器，val为将要替换的值。
```

### find函数

~~~c++
#include<algorithm>
待查值的地址=find(数组的起始地址,数组的终止地址+1,待查找的值);
~~~

### stoi函数

~~~c++
#include<math.h>//用到了pow
float stoi(string str)//将字符串转换为数字
{
    int ret=0,p=1;
    int zeroPos=str.find('.');

    if(zeroPos==string::npos)
    {
        for(int i=str.size()-1;i>=0;i--,p*=10)
            ret+=(str[i]-'0')*p;
        return (float)ret;
    }
    else
    {
        int leftNum=0,rightNum=0;
        string left,right;
        left=str.substr(0,zeroPos);
        right=str.substr(zeroPos+1,str.size()-zeroPos-1);

        for(int i=left.size()-1;i>=0;i--,p*=10)
            leftNum+=(left[i]-'0')*p;
        for(int i=right.size()-1,p=1;i>=0;i--,p*=10)
            rightNum+=(right[i]-'0')*p;
        return (float)leftNum+(float)rightNum/pow(10,right.size());
    }
}
~~~

### tolower和toupper函数

~~~c++
#include <cctype>
//大小写转换 针对单个字符而言！
 for(int i=0;i<str.size();i++)
        str[i]=tolower(str[i]);
~~~



------



## 非函数类

### 各种类型的最大值

**unsigned int** 32 位4294967296 **十位**  int*int 中int最好不超过**50000**！int+int中int不要超过**1,000,000,000**一个亿

**long** 和**int** 在64位机下的长度是一样的

**long long**是64位的 18446744073709551616无符号十进制下是 **20位**

### II的优先级小于&&

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

### 用c++求x的y次方的方法：

~~~c++
//方法一
#include <math.h>
pow(x, y);
//方法二：
#include <math.hpp	>
Power(x, y);
~~~

### 浮点数比较大小

- eps最好取1e-8

### 以某数字a(如2)为起点 以b(如3)为周期实现循环输出1、 2....b

~~~c++
(i-2+2*3)%3
(i-a+b*a)%b//适用于b比a大的情况！
 if (uid>=s && (uid-s)%n==0)
~~~

- const和&(传引用)可以加快程序运行速度

# 经典算法的实现

## 素数——埃氏筛法

```c++
bool isprime(int a) {
    for (int i = 2; i * i <= a; i++)
        if(a % i == 0) return false;
    return true;
}
```



# 常见错误

- 闰年的规律是四年一闰百年不闰四百年再闰 闰年二月份有29天 平年是28天

  ```c++
   return ((year%4==0)&&(year%100!=0))||(year%400==0)
  ```

- ~~~C++
  scanf("%lld")//这么写codeblocks会报警但是没有问题
  ~~~

- a/b取得是商！a%b取得是余数 常常因为要取前面的数（商）写成 a%b

-  ~~~c++
   A.insert(i,'0');//这么写是错误的，必须用双引号
  A[0]!="0"//这么写不行 比较的时候必须用单引号
  ~~~

- int IsExist[100010]=**{0}**;忘记初始化

- vector<int>  a**[b]**;不能使用中括号！！要使用小括号来预分配空间

- "Yes"No"**大小写**不注意！这种情况下也会报错**答案错误**而不是格式错误。也会有**答案正确**，因为可能你Yes写对了 答案有全是Yes的

- 结构体要写在main外面

- 由于是英文题对输出格式控制不敏感，如没注意要输出5位（a1032）




















































