#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main( ) {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, ls; string s;
    cin >> t;
    F(z,0,t) {
        string o = "";
        cin >> s; ls = (int)s.size()/2;
        F(i,0,ls) {
            if ('A' <= s[2*i] && s[2*i] <= 'Z') {
                F(j,0,s[2*i+1]-'0') o += s[2*i];
            } else {
                F(j,0,s[2*i]-'0') o += s[2*i+1];
            }
        }
        cout << o << '\n';
        
    }
}