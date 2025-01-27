#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n; ll c=0, r=0, m;
    string s;
    cin >> n >> s;
    vector<ll> t(n,0);
    for (int i = n-1; i>=0; i--) {
        t[i]=c;
        if (s[i]!='A') {c++;}
        else r+= c;
    }
    m=r; c=0;
    F(i,0,n) {
        if (s[i]=='A') {
            c++;
        } else if (s[i]=='?') {
            r+= t[i]- c;
            if (r>m) m=r;
            c++;
        }
    }
    cout << m << '\n';
}