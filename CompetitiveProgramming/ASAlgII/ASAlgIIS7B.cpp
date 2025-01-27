#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int P, A, p, a;
    string s;
    cin >> s;
    A=((int)s[0]>92);
    a=((int)s[0]<92);
    F(i,1,s.length()) {
        //cout << A << " "<< a << '\n';
        P=A; p=a;
        A = P + ((int)s[i]>92);
        a = min(P+((int)s[i]<92), p+((int)s[i]<92));
    }
    cout << min(A,a) << '\n';
}