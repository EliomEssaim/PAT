[TOC]





# 英语词汇

## 单词

- consecutive **连续**
- utility**实用**
- Deduplication**去重**
- degree**度**，代表树中所有节点的子节点数目最大的那个数
- depth/height**深度/高度**；对树而言都是一个东西
- parentheses**括号**
- corresponding**相应的**
- emitter**发射器**（emission排放）
- seniority**资历**
- stat**统计**
- pedigree **血统**

## 句子

The quick brown fox jumps over the lazy dog.

**significant digits**有效数字

**not compatible** 不兼容

**5-digit**五位

warning: suggest parentheses around assignment used as truth value **==**写成了**=**

**distinct** positive integer 不同的正整数

accurate up to 1 decimal **place**精确到小数点后1位

Then the next line contains *N* numbers, each number *S**i* is the index of the supplier for the *i*-th member. *S**r**o**o**t* for the root supplier is defined to be −1.

# 数据结构

## 最优化题目

- 1090. Highest Price in Supply Chain (25)-PAT甲级真题（DFS） 父亲表示法怎么转变为孩子表示；

## 链表

- A1032

- A1052

- A1047（如何反转静态链表？如何反转普通的链表？）

- ~~~C++
  if(delans.size()){//不写这个会出现段错误
          for(int i=0;(unsigned)i<delans.size()-1;i++)
              printf("%05d %d %05d\n",delans[i].addr,delans[i].key,delans[i+1].addr);
        printf("%05d %d -1\n",delans[delans.size()-1].addr,delans[delans.size()-1].key);
      }
  ~~~


## 堆栈与队列

## 树

### 二叉树

~~~C++
//树的结构体定义
struct node{
    int data;
    node* lchild;
    node* rchild;
}
//节点的创建
node* newNode(int v){
    node* tmp=new node;
    tmp->data=v;
    tmp->lchild=NULL;
    tmp->rchild=NULL;
    return tmp;
}
//节点的查找以及修改
void searchAndModifyNode(node* root,int x,int newData){
    if(root==NULL)
        return;
    if(root->data==x){
        root->data=newData;
    }else{
        searchAndModifyNode(root->lchild,x,newData);
        searchAndModifyNode(root->rchild,x,newData);
    }
    return ;
}
//插入节点（视情况而定，这里不完整）
void insertNode(node* &root,int data){
    if(root==NULL){
        root=newNode(data);
        return;
    }
    return ;
}
//四种遍历
void preorder(node* root){
    if(root==NULL)
        return ;
    printf("%d",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void inorder(node* root){
    if(root==NULL)
        return ;
    preorder(root->lchild);
    printf("%d",root->data);
    preorder(root->rchild);
}
void postorder(node* root){
    if(root==NULL)
        return ;
    preorder(root->lchild);
    preorder(root->rchild);
    printf("%d",root->data);
}
void layerOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tmp=q.front();
        q.pop();
        printf("%d",tmp->data);
        if(tmp->lchild!=NULL)
            q.push(tmp->lchild);
        if(tmp->rchild!=NULL)
            q.push(tmp->rchild);
    }
    return ;
}
//先序+中序创建唯一树
TreeNode* buildTree(int root, int start, int end) {
    if(start > end) return NULL;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    TreeNode* t = new TreeNode();
    t->left = buildTree(root + 1, start, i - 1);
    t->right = buildTree(root + 1 + i - start, i + 1, end);
    t->data = pre[root];
    return t;
}
/*说明一下经常模糊的地方*/
//1、数组的两个下标相减+1为两个下标之间的长度
//2、pos~pos+lenth实际有lenth+1长所以实际要写入时要减一 string左闭右开就成立了 
/*后序+中序转先序*/
#include <cstdio>
using namespace std;
int post[] = {3, 4, 2, 6, 5, 1};
int in[] = {3, 2, 4, 1, 6, 5};
void pre(int root, int start, int end) {//root是后序的root，start是中序的start
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    printf("%d ", post[root]);
    pre(root - 1 - end + i, start, i - 1);
    pre(root - 1, i + 1, end);
}
//求二叉树的高度
int PostOrderGetHeight(BinTree){
    int HL,HR,MaxH;
    if(BT){
        HL=PostOrderGetHeight(BT->Left);
        HR=PostOrderGetHeight(BT->Right);
        MaxH=(HL>HR)?HL:HR;
        return (MaxH+1);
    }else return 0;
}
~~~



### 普通树

​	分析树类的题目，写递归算法时，要注意代码和**当前层**的关系，尤其到了递归终点时要判断自己要的数据是否准备好，还是**差一个当前层键值**没有录入。

~~~C++
struct node{
    int weight;
    vector<int> childAddr;
};
void bfs(int root){//层序遍历
    queue<int> q;
    int layerEnd=root;
    int layer=0;
    q.push(root);
    while(!q.empty()){
        int frontAddr=q.front();
        q.pop();
        if(tree[frontAddr].childAddr.empty()) layerLeaves[layer]++;
        for(int i=0;i<(int)tree[frontAddr].childAddr.size();i++){
            q.push(tree[frontAddr].childAddr[i]);
        }
        if(frontAddr==layerEnd){
            if(layerEnd!=root)printf(" %d",layerLeaves[layer]);
            else printf("%d",layerLeaves[layer]);
            if(!q.empty()) layerEnd=q.back();//这个q.empty()使用队列或堆栈的值前必须判空
            layer++;
        }
    }
}
void dfs(int index, int depth) {//对层用的dfs a1004 把depth去掉就是个dfs模板
    if(v[index].size() == 0) {
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return ;
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
/*维护一个公共量 可以记录树的路径 这个公共量可以设为全局变量 遍历时传下标即可*/
/*==改成>=有if else要判断四个情况是否都是自己想要的*/
void dfs(int index, int nodeNum, int sum){//a1053的值得二刷暴露很多问题
    if(sum<target&&tree[index].childAddr.empty()) return;//严谨
    if(sum>target) return;
    if(sum==target){
        if(tree[index].childAddr.empty()){
            path[nodeNum]=tree[index].weight; 
            for(int i=0;i<=nodeNum;i++)
                printf("%d%c",path[i],i==nodeNum?'\n':' ');
        }
        else return;
    }
    for(int i=0;i<(int)tree[index].childAddr.size();i++){
        path[nodeNum]=tree[index].weight;
	 dfs(tree[index].childAddr[i],nodeNum+1,sum+tree[tree[index].childAddr[i]].weight);
    }
} 
~~~



## 图



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
v.push_back(node{s, score, -1, -1, 0});//如果vector是结构体可以这么写
//vector可以用来做hash！
/*********分割线*****************/
//vector的访问方式有哪两种？
#include<vector>
vector<int> vi;
vi.pushback();
vi.popback();
vi.size();
vi.resize();//重新分配空间
vi.clear();
vi.insert(?,?);
vi.erase(?,?)//单个元素写法 区间的写法	
~~~

## set(集合)

~~~c++
set<int>::iterator sit=Singles.begin();
printf("%d",*sit);//set的访问方式
multiset<int> st;//只排序不去重
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

- sort可用

~~~c++
#include<string>//string忽略空格//string可以用下标访问吗？
using namespace std;
string str1,str2[n];//n为变量 这种写法是允许的
str1+=str2;
str2-=str1;//没有这种写法

scanf("%s", &a[0]);//这样可以使用scanf了
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
- **vector**可以用来做hash！快很多

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
//用BFS算法时如果需要的是修改元素而不是访问元素，最好存储编号（如数组的下标）。
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
//sort数组地址（或者说迭代器加上*）是什么类型 cmp的输入参数就是什么类型
```

- sort函数实现排名（PAT A1025）
- **vector**、**string**也可以用此排序

# 编程语言知识补充

## 语法

### new

~~~C++
typename* p=new typename;
int* p=new int;//申请一个int型变量的空间
int* p=new int[1000]//申请1000个int型变量的空间
~~~



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

**float**比特数为32，有效数字为6-7，数值范围为 -3.4E+38 和 3.4E+38

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

//简洁写法
printf("%d%c", v[path[i]].w, i != nodeNum - 1 ? ' ' : '\n');
```

### 四舍五入

- 浮点数保留小数点后的数据，有时会自动四舍五入，有时不会自动四舍五入。题目没说就别写float的四舍五入

  **如果把一个浮点数赋给一个整数变量后，一定不会四舍五入。**

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
    StudentList(int _num,char *_name){
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

### 用后置++最后的值会变成这个数组的size，使用时注意判断用的是size-1，还是size（a1086）

# 经典算法的实现

## 素数——埃氏筛法

```c++
bool isprime(int a) {
    for (int i = 2; i * i <= a; i++)
        if(a % i == 0) return false;
    return true;
}
```

## BFS

~~~C++
void BFS(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        取出首元素top;
        访问队首元素top;
        将队首元素出队;
        将top的下一层节点中未曾入队的节点全部入队，并设置为已入队;
    }
}
~~~

# 思路错误题目集合

- a1090.Highest Price in Supply Chain (25)-PAT甲级真题（DFS）
- b1098狼人杀-简单版(20分) 
- 缺什么条件补什么条件；

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

- 对下标从1开始但却仍在用<=（不自觉的用）

- 题目不会傻到给你一个数据直接输出就好了

- vector分配空间后，没有使用全部大小却使用size

- 无符号-1 变成int类的最大值

~~~C++
for(int i=0;i<(int)delans.size()-1;i++)//最好这么写，但是要注意size太大的话（超过int的一半）会出问题
            printf("%05d %d %05d\n",delans[i].addr,delans[i].key,delans[i+1].addr);
        printf("%05d %d -1\n",delans[delans.size()-1].addr,delans[delans.size()-1].key);
~~~

- if else分支流程不清楚导致 答案错误 （pat1053）
- 混淆层与值的对应关系 a1053树的遍历
- 遍历树时把一个层的特征变量+=了 导致该变量成为一个局部的量被其他兄弟结点共享。a1053的sum
- 答案错误 if else出现漏洞(难以察觉的逻辑错误)
- 答案错误、运行时错误：写错符号i写错成j
- 使用队列或堆栈的值前不判空a1004
- 答案没说四舍五入你却四舍五入了a1079
















































