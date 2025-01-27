#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int c=0, r=0, co, ro, cm, rm, mx=0, bi, ei, bx, ex;
    string S;
    cin >> S;
    string s(2*S.length()+1, '0');
    F(i,0,S.length()) s[2*i+1] = S[i];
    vector<int> m(s.length(), 0);
    while (c<s.length()) {
        while(c-(r+1) >= 0 && c+(r+1) < s.length() && s[c-(r+1)] == s[c+(r+1)]) r++;
        m[c] = r;
        co = c;
        ro = r;
        c++;
        r=0;
        while (c <= co + ro) {
            cm = co - (c - co);
            rm = co + ro - c;
            if(m[cm]<rm) {
                m[c] = m[cm];
                c++;
            } else if(m[cm]>rm) {
                m[c]=rm;
                c++;
            } else {
                r=rm;
                break;
            }
        }
    }
    //F(i,0,s.length()) cout << m[i] << " "; 
    F(i,0,s.length()) {
        bx = (i-m[i]+1)/2;
        ex = (i+m[i]-1)/2;
        if ((ex-bx+1) >mx) {
            mx = (ex-bx+1);
            bi = bx;
            ei = ex;
        }
    }
    F(i,bi,ei+1) cout << S[i];
    cout << '\n';
}