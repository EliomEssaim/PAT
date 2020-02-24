#include<iostream>
using namespace std;
int hour,minutes,seconds;
int c1,c2,CLK_TCK=100;
int main(){
    cin>>c1>>c2;
    int total_seconds=(float)(c2-c1)/100.0+0.5;
    int total_seconds_left=total_seconds;
    seconds=total_seconds_left%60;total_seconds_left/=60;
    minutes=total_seconds_left%60;total_seconds_left/=60;
    hour=total_seconds_left%60;
    printf("%02d:%02d:%02d\n",hour,minutes,seconds);

    return 0;
}
