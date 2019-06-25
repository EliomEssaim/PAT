#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> st;
    for(int i=1;i<=5;i++)
        st.push(i);
    cout<< st.top()<<endl;
    st.pop();
    cout<< st.top()<<endl;

    return 0;
}
