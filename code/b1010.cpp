#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool firstOut = true;
string input;
vector<int> List;
int main() {
	int exponent, coefficient, index = 0;
	getline(cin, input);
	input+=" ";
	while (input.find(' ')!=string::npos) {
        index=input.find(' ');
        List.push_back(stoi(input.substr(0, index)));
        input=input.substr(index+1);
	}
	for (int i = 0; i + 1 < (int)List.size(); i +=2) {
		coefficient = List[i]; exponent = List[i + 1];
		if (exponent != 0) {
			if (!firstOut)cout << " ";
			cout << coefficient * exponent;
			cout << " " << --exponent;
			firstOut = false;
		}
	}
    if(firstOut) cout<<"0 0";
	return 0;
}
