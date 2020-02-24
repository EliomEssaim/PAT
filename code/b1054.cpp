#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
using namespace std;
string originInput;
double vaildData, sum = 0.0;
int main() {
	int n, cntValid = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> originInput;
		stringstream toNum, toStr;
		bool wrongFlag = false;
		toNum.str(originInput);
		toNum >> vaildData; toStr << setprecision(2) << fixed << vaildData;
		for(int i=0;i<(int)originInput.size()&&!wrongFlag;i++)
            if(originInput[i]!=toStr.str()[i])wrongFlag=true;
		if (wrongFlag|| vaildData < -1000 || vaildData>1000)
			cout << "ERROR: " << originInput << " is not a legal number" << endl;
		else {
			cntValid++;
			sum += vaildData;
		}
	}
	if (cntValid == 0)cout << "The average of 0 numbers is Undefined" << endl;
	else if (cntValid == 1) cout << "The average of 1 number is " << setprecision(2) << fixed << sum;
	else cout << "The average of " << cntValid << " numbers is " << setprecision(2) << fixed << sum / cntValid;
	return 0;
}
