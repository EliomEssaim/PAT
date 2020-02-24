# while工具箱

~~~C++
while(条件){
    循环体;
    递增条件;
}   
~~~

## 什么情况下只能用while？for循环适用于什么样的场合？

- 在单循环变量稳定递增的情况下：和for比起来 while的写法不够简洁。
- 思考一下有没有用到一个变量稳定递增？有的话就用for

例如：

~~~C++
//b1025
int rev_des=rever_unit;lenth=result_order.size();
    while(rev_des<=lenth){
        reverse(result_order.begin()+rev_des-rever_unit,result_order.begin()+rev_des);
        rev_des+=rever_unit;
    }
~~~

这是原写法。这里需要临时定义了一个后来都用不到的变量rev_des；多占用了一行rev_des+=rever_unit；

而用for写的话：

~~~C++
//b1025
for(int i=rever_unit;i<=(int)result_order.size();i+=rever_unit)
        reverse(result_order.begin()+i-rever_unit,result_order.begin()+i);
~~~

简洁清楚。

- while适用于那些不知道循环次数的场合

比如：当循环的结束条件是某个bool值时，或者再函数中

~~~C++
void loop(int times){
    while(times){
        ..;
    }
}
~~~

简单的循环用for（单变量 递增 递减，能够看出循环的开始和结束） 复杂的循环（比如循环条件多 难以看出循环的开始和结束）

## 怎么样写出x(n-1)?

一定要来一个变量吧x(n)赋值给他例如y；

~~~C++
while(退出条件){
	y①
    变化代码;
    y②
}
~~~

只有两个位置可以选择，当选择①的时候因为变化后就退出了，先留存了x(n)然后继续往下执行，遇到退出条件就退出；这时候我们得到的就是x(n-1)(取得x(n)的值时会使得循环退出)；

如果选择了②当退出时 x 与y保持同一值；无法取得x(n-1);

如果要使得这个位置可以去到x(n-1)，必须在②前也就是y更新前添加退出循环的条件。

**总结：获得x(n-1)要让退出条件后面紧跟x(n)的更新**

## while使用循环变量比起for有什么风险？要注意什么？

如果使用了再里面使用了数组而且用这个变量作为数组的下标输入，那么一定一定要注意数组的越界问题。

通常 越界会带来一些解法上的特殊情况这个也要注意。而for一般安全的多（一般场景下for循环都不会出错）



## do while的存在意义是什么？为什么要使用do while？

do while表示这个循环体必须要执行一次。有时候我们让循环给一个变量 比如string类赋值。

我们不希望得出来的结果是个空字符串。

例如在进制转换的过程中。

0作为特殊的值会一下子退出循环不利于我们后续的判断。

但如果使用do while str就可以被赋值赋上0。

## **如何解决需要下标的时候。内部的break程序导致异步的问题？**

这里的解决办法是内部的break判断要加上原来的条件。

~~~C++
do{
    if(tmpSum<=15){
        if(tmpSum==15){
            printf("%d-%d\n",low,high);
            needHigher=false;
        }
        break;
    }
    tmpSum-=chain[low];
}while(low<=high);

//修改：
do{
    if(tmpSum-chain[low]<=15){
        if(tmpSum==15){
            printf("%d-%d\n",low,high);
            needHigher=false;
        }
        break;
    }
    low--;
}while(low<=high);
~~~



# for工具箱

~~~C++
for(int i=0;i<xxx;i++){
}//循环体i
~~~

## 在表达式输出的时候如果某个部分需要特殊的输出。怎么样写更简洁？

如：

~~~C++
for(int i=0;i<lenth;i++){
        if(i!=lenth-1){
            printf("%05d %d %05d\n",add,result_order[i].value,result_order[i+1].add);
        }else{
            printf("%05d %d -1\n",result_order[i].add,result_order[i].value);
        }
    }//b1025
~~~

这里只有在最后一步产生的不同的步骤；完全可以写在for外头。同理 若特殊顺序是开头也可以写在外头。

~~~C++
for(int i=0;i<lenth-1;i++)//b1025
            printf("%05d %d %05d\n",add,result_order[i].value,result_order[i+1].add); printf("%05d %d -1\n",result_order[lenth-1].add,result_order[lenth-1].value);
~~~

## 如果有两个for循环 共用一个循环变量 循环变量循环的条件是>=0 （第一个for）后需要反弹到5 （第二个for）那么第二个for循环的初始化应该++几次？

两次，因为我们要的是1，跳出循环的值为-1，我们++使得它变成0。再次++获得我们需要的1。

for循环 循环变量最后的值是使得for循环条件不成立的第一个值。这个道理对while循环也通用。

## 什么是for循环基于range的循环？语法格式是什么？语义是什么？遍历容器时候要注意哪三点？

~~~c++
vector<int> vec;

for(auto ele:vec)
    printf("%d",ele);
//ele相当于循环变量。auto必加 ：必加

~~~

使用这个语法并不会导致效率变低！！还会变快

要注意：

1、ele代表的type_value 就是容器类型的每一个元素，而不是下标。以vec为例，第一个ele代表的vec[0]，而不是是下标0.这就导致了我们在遍历需要使用到->first和->second要改成.first和.second。

这个不同迭代器，迭代器模仿的是指针。而ele模仿的是值。所以使用迭代器要用到*要用->而ele只需要.

2、ele是值的复制 要修改、排序只能传引用。auto &。

3、下标不只是下标而是代表链表地址或者是数字的使用不要使用！比如求素数，判断xx值是否成立

遍历输出可以用。

# 数组工具箱

~~~C++
int List[100000];
~~~

## 数组可以看成哪两种意思？

数组有两种意义：一种可以用来书库用；list[1]代表第一本书，list[2]代表第二本书。这是我常常认知的。

然而还有更重要的意义。

**另一种**可以牺牲空间换时间，当成编码用。data[5862]代表编号为5862的单元所代表的数据。常用链表和图算法中。此时完全可以吧data看成一块随机存取的单元。

这个单元可以根据我们给的地址来随时提取里面的数据。常用的比如next[55256]，在链表中给出改地址下一跳的地址。在树中也有类似的应用。

同时我们可以利用map来实现任意类型对数字的映射。这样可以实现随机录入，随机存取了。

结构体 只是不同数据的封装形成了新的数据类型。使用于排序、而且方便引用。

但 如果对链表进行操作 这种白给地址给你的。用数组会更快。

~~~C++
//b1025

~~~



# 代码简洁之道

## 简化逻辑

// 修改前``

```C
if(list.size()>0) {
    return true;
} else {
    return false;    
}

```

// 修改后

```c
return list.size()>0;
```

(1) if/else 语法：if语句包含一个布尔表达式，当if语句的布尔表达式值为false时，else语句块会被执行；

(2) return 关键字：返回一个任意类型的值；

(3) list.size()>0 表达式：list.size()方法本身是一个返回int类型数值的函数，而与>0组成了一个布尔表达式；

## **省略无意义赋值**



![avatar](https://user-gold-cdn.xitu.io/2019/1/2/1680d930e755935e?imageView2/0/w/1280/h/960/format/webp/ignore-error/1)



(1)局部变量list的数据类型与该方法的返回值类型一致，而多余的变量也将会增加JVM垃圾回收的消耗；

(2)局部变量list只是负责接收了mapper.queryList(params)的返回值，而并没有其他逻辑处理；

(3)此代码存在于service层和mapper层之间，可以在框架层面进一步抽象，利用注解、java8 default方法等进一步改进；

## **最小化判断**



![avatar](https://user-gold-cdn.xitu.io/2019/1/2/1680d930e76e0758?imageView2/0/w/1280/h/960/format/webp/ignore-error/1)

代码中if else的存在只是因为sendMessage函数的第二个参数会有两种情况(成功/失败)，尽量让判断最小化；

## 不重复

修改前：

~~~C++
if(validDataNumber==0) {
        cout<<validDataNumber;
    }
    cout<<validDataNumber<<" "<<oldest_name<<" "<<youngest_name;
~~~

修改后：

~~~C++
cout<<validDataNumber;
if(validDataNumber!=0) cout<<oldest_name<<youngest_name;
~~~



# string工具箱

## 年/月/日格式化的日期什么情况下可以用string比较大小？

利用字符串直接比较。

字符串的比较是逐个比较大小（按ascii顺序比较）一旦在某个位置不等于 直接分出胜负。

若遇到短的字符串比较到结尾还是相等而另一方较长则后者比较大。

一些所以日期可以比较。但注意有限制。

例如2020/5/6 2020/12/6 按我们理解是后者比较大，按字符串比较则是后者比较大。

所以进行日期的比较时要注意输入的格式严格相等。

## 给定一个字符串如何快速判断某个字符是否存在？

string中find的函数可以做到，如果没找到返回值为string：npos；

str.find(x)==string:npos可以快速的判断里面是否有某个字符。

（b1029）

## str.substr(pos)是什么意思如果这个变量超过了数组长度怎么办？

取pos后的字符串，不能超过数组长度。超过了会报警。但是如果取等于会获得空字符串。

## 给字符串前补上0的方法有哪三种？

1、通过while(str.size()<xx) str.insert(0,"0");

2、通过先reverse(str.begin(),str,end());

然后str.append(lenth,'0');

3、通过流操作

~~~C++
#include<sstream>
stringstream s;
s<<setw(lenth)<<setfill('0')<<num;
string ans=s.str();
~~~

## **string可以通过+=一个换行符来换行吗？**

可以

# map工具箱

## 如何确定一组字符串里面仅有3个字母a b c.。有哪些方案，用map怎么实现判断？

可以用map中的size来判断含有多少个字符再通过map[a]、map[b]、map[c]>0来说明包含有a b c。

还可以set来判断使用方法和map类似set需要用迭代器iterator 分别与a b c比较。

还可以用三个if来实现if成功就continue 三个if都没返回就输出错误信息。

同理 switch也行



# 标准输出流cin cout工具箱

## 如何实现四舍五入？保留n位有效数字？输入为整数，当数字过短时输出0？保留小数点后n位？

四舍五入：(int)x+0.5;

保留n位有效数字：setprecision(n);如果要补上0要写showpoint。试验一下

**会自动四舍五入**

补0：cout<<setw(4)<<setfill(' ')<<a;这个每次都要写

保留小数点后n位：cout<<setprecision(n)<<fixed<<50.55132;这个写一次就够了而且会自动写0**不用写showpoint**

## 如何把输出中补0的值当成字符串获取？有哪几种方式？用流如何实现？

可以通过while(xx.size()<4) str.insert(0,' ');来实现。

流的话先加入头文件

~~~C++
#include<strstream>
stringstream s;
s<<setw(4)<<setfill(' ');
string str;
str=s.str();//获得了字符串
~~~

## 如果不给定输入的字符串有多少个如何实现一个个录入字符串？（中间有空格分开）有哪几种方法？如何实现？

写一个spilt函数:

~~~C++
getline(cin,str);
str+=" ";
int index=0;
vector<string> list;
while(str.find(' ')!=string::npos){
    index=str.find(' ');
    list.pushback(str.substr(0,index));
    str=str.substr(index+1);
}
~~~

还有就是这样子

~~~C++
while(cin>>str) list.pushback(str);
~~~

当cin遇到eof就会返回0；循环退出；裁判系统用的一般都是文件有eof 而自己输入的时候需要先按ctrl+z然后enter



# vector工具箱

## vector.insert(vector.begin()+2,0)插入后，原来vector[2]在新元素的前面还是后面？

后面。根据我们的习惯 方便我们指哪插哪。

## vector如何声明二维数组并初始化为-1?

vector<vector<int>> display(row, vector<int>(col, -1));

# 函数工具箱

## 如何传入一个vector的数组并可以在之中修改？

使用传引用符号&

## string & 函数名(string & a);里面的&是什么意思？

 string &是个类型名 指的是string的引用 这个函数里面return 一般return输入参数，绝对不能return函数里面创建的临时变量。这个函数本身一般作为另一个需要传入引用的函数的参数

## 传引用的函数再传引用给下一个函数要注意什么问题？

传引用的时候如果外层的传引用有const修饰而内层的没有会导致编译失败，因为当传引用给内层函数，const内层函数没有限定const所以有可能导致const被修改。

用const修饰的变量不能够传递给可能导致该变量被修改的操作。

## 如何不断二分数组？怎么写会导致无限递归。

设这个数组的下标范围0 ~ k；

输入的函数标明 start ~ end代表数组的下标范围例如 void divide(int start,int end);

选取中间的下标则计算式为 mid=(start+end)/2；

由于取整效应最终start会等于end所以如果函数的继续条件为start<=end 就会无限递归。

现在可以这么写：

~~~C++
 void divide(int start,int end){
     if(start<end){
         divide(start,mid);
         divide(mid+1,end);//这里写成mid会造成区域重复
	}else return ;
}
~~~



**注意**：在处理数组的时候也是一分为二 分为start,mid和mid+1,end，不然绝对会造成逻辑出错。

# 浮点数工具箱

## cout<<setprecision(2)<<fixed<<0.005输出多少？

0.00因为默认四舍五入不会截断。题目没有要求四舍五入就不要四舍五入。

## 输出保留小数点后两位的浮点数要注意些什么？

-0.00是非法的检测方法有：这个值是不正常的需要改成0.00辨识的方式就是加上(a+0.005)>0&&a<0;

(这个是保留小数点后两位的情况)

# 内存工具箱

## 递归的层数最多多少层？

所用的空间由连接器决定一般是64k

层数一般在一万层。

## c++ new的用法怎么用？

char *a=new char[500];

delete []a;

# 警告工具箱

## 什么是左值 右值？

以a=1+2；

等号为分解左边的（在内存中占有位置的）叫做左值，右边（在内存中不占有位置的）叫做右值

# 文件工具箱

## 指定一个txt文件插入换行符可行吗？为什么fstream读入后不能立马写?如何定位到特定位置修改内容？

插入是不可能可以插入的。因为插入的操作相当于把后面全部的字符串复制下来，头部添加新的内容。删除内容后再添加复制的内容。

不如开个新文件写入。

所有的文件打开后都是在内存里面。你写是有延迟的。

猜测是因为写在了内存没有写回文件。或者这个是非法操作。

反正 在读入后面添加一行finout.seekp(finout.tellg(), ios::beg);

把写入位置定位一下就可以写了。



上面是在特定的内容后修改什么。

如果要修改特定的内容。

不能在读入的后面添加finout.seekp(finout.tellg(), ios::beg);

因为读入后指针已经+1了你写也是写后面的内容。

可以用peek来判断

~~~C++
if (finout.peek() == '1') {
				finout.seekp(finout.tellg(), ios::beg);
				finout << "*" << flush;
			}
~~~



