#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
int main() {
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);
    string str;
    map<string, int> mapp;
    bool flag = false;
    for (int i = 1; i <= m; i++) {
        cin >> str;
        if (mapp[str] == 1) s = s + 1;
        if (i == s && mapp[str] == 0) {
            mapp[str] = 1;
            cout << str << endl;
            flag = true;
            s = s + n;
        }
    }
    if (flag == false) cout << "Keep going...";
    return 0;
}
//����������
//�ڼ��Ϊ3��ǰ���� ��������Ѿ����û��н���
//ȡ������һλ�н��Ҵ���λ��ʼ�ټ���3��
