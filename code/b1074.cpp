#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string ans, scale, aInput, bInput;
int carryBit = 0, sum = 0;
int main() {
	cin >> scale >> aInput >> bInput;
	reverse(aInput.begin(), aInput.end());
	reverse(bInput.begin(), bInput.end());
	reverse(scale.begin(), scale.end());
	while (aInput.size() != scale.size())aInput += "0";
	while (bInput.size() != scale.size())bInput += "0";
	for (int i = 0; i < (int)scale.size(); i++) {
		if (scale[i] == '0')scale[i] = '0' + 10;
		sum = aInput[i] - '0' + bInput[i] - '0' + carryBit;
		ans += to_string(sum % (scale[i] - '0'));
		carryBit = sum / (scale[i] - '0');
	}
	if(carryBit!=0)ans+="1";
	reverse(ans.begin(), ans.end());
	int beginIndex=0;
	while(ans[beginIndex]=='0')beginIndex++;
	ans=beginIndex==(int)ans.size()?"0":ans.substr(beginIndex);
	cout<<ans<<endl;
	return 0;
}
