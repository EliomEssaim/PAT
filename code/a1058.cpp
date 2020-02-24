#include<iostream>
using namespace std;
long long a, b, gal, sic, knut;
int main() {
	scanf("%lld.%lld.%lld", &gal, &sic, &knut);
	a = knut + sic * 29 + gal * 29 * 17;
	scanf("%lld.%lld.%lld", &gal, &sic, &knut);
	b = knut + sic * 29 + gal * 29 * 17;
	printf("%lld.%lld.%lld", (a + b) / 29 / 17, (a + b) / 29 % 17, (a+b)% 29);
	return 0;
}
