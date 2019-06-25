#include<iostream>
#include<queue>
using namespace std;
struct fruit{
        string name;
        int price;
        friend bool operator < (fruit f1,fruit f2){
            return f1.price<f2.price;
        };
    }f1,f2,f3;
int main()
{
    queue<int> q;
    for(int i=1;i<=5;i++)
        q.push(i);
    printf("%d %d\n",q.front(),q.back());
    q.pop();
    cout<<q.front()<<endl;
    priority_queue<int> pq;
    pq.push(3);
    pq.push(4);
    pq.push(2);
    pq.push(1);
    printf("%d\n",pq.top());
    printf("%d\n",pq.top());
    pq.pop();
    cout<<pq.top()<<endl;
    priority_queue<int,vector<int>,greater<int> > minQ;
    minQ.push(8);
    minQ.push(7);
    minQ.push(3);
    minQ.push(5);
    minQ.push(1);
    cout<<minQ.top()<<endl;
    minQ.pop();
    cout<<minQ.top()<<endl;

    priority_queue<fruit> fq;
    f1.name="ÌÒ×Ó";
    f1.price=3;
    f2.name="Àæ×Ó";
    f2.price=4;
    f3.name="Æ»¹û";
    f3.price=1;
    fq.push(f1);
    fq.push(f2);
    fq.push(f3);
    cout<<fq.top().name<<" "<<fq.top().price<<endl;


    return 0;
};
