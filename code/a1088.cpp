#include<iostream>
#include<algorithm>
using namespace std;
typedef long long type;
type gcd(type a, type b) {
	if (b == 0) return 1;
	return a % b == 0 ? b : gcd(b, a%b);//gcd的适用性
}
void display(type a1, type b1) {//type没用心
	type g1 = gcd(abs(a1), b1);
	a1 /= g1; b1 /= g1;
	if (b1 == 0) { cout << "Inf"; return; }//inf的优先要更高
	if (a1 == 0) { cout << 0; return; }
	if (b1 < 0) { b1 = abs(b1); a1 = -a1; }
	bool k = false, k2 = false;
	if (a1 < 0) { cout << "(-"; a1 = abs(a1); k = true; }
	if (a1 >= b1) { cout << a1 / b1; a1 = a1 % b1; k2 = true; }//等号也要
	if (a1 != 0 && k2) cout << " " << a1 << "/" << b1;
	if (a1 != 0 && !k2) cout << a1 << "/" << b1;
	if (k) cout << ")";
}
int main() {
	type a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	type g1 = gcd(abs(a1), b1), g2 = gcd(abs(a2), b2);
	a1 /= g1; b1 /= g1; a2 /= g2; b2 /= g2;
	display(a1, b1); cout << " + "; display(a2, b2); cout << " = "; display(a1*b2 + a2 * b1, b2*b1); cout << endl;
	display(a1, b1); cout << " - "; display(a2, b2); cout << " = "; display(a1*b2 - a2 * b1, b2*b1); cout << endl;
	display(a1, b1); cout << " * "; display(a2, b2); cout << " = "; display(a1*a2, b2*b1); cout << endl;
	display(a1, b1); cout << " / "; display(a2, b2); cout << " = "; display(a1*b2, a2*b1); cout << endl;//没有注意到符号转移

	return 0;
}
