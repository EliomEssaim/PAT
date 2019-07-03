#include<iostream>
#include<cctype>
#include<string>
#include<math.h>
using namespace std;
int main()
{
    double p,r;
    int depth=2;
    p=1.80;
    r=1.00;
    printf("%.5f\n",7.0*p*pow(1+r/100,depth));
    return 0;
}
