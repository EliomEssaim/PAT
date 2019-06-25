#include<iostream>
#include<queue>
using namespace std;
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
    return 0;
};
