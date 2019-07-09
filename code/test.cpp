#include<iostream>
#include<cctype>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
    int x, y;
};
bool cmp1(node a, node b) {
    return a.x < b.x;
}
int main() {
    vector<int> v(3);
    v={2,3,7};
    vector<string> v2;
    v2.push_back("hello");
    v2.push_back("world");
    v2.push_back("kksk");
    string sum = accumulate(v2.begin() , v2.end() , string("µþÖ½"));
    cout<<sum<<endl;
    int arr[4]={7,5,3,6};
    vector<node> v1(3);
    v1={node{7,4},{6,3}};
    cout << *max_element(v.begin(), v.end())<<endl;
    cout << *min_element(arr, arr + 4)<<endl;
    cout << (*max_element(v1.begin(), v1.end(), cmp1)).y<<endl;


    char* str2=to_string(555);;

    cout<<str2<<endl;
    return 0;
}
