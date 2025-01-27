#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, b, I, t=0, l, r, p;
    char c;
    cin >> n >> b >> I; l= b; r= b;
    vector<bool> v(n+1);
    F(i,1,n+1) {
        cin >> c;
        v[i] = (c == 'T');
    }
    F(i,0,I) {
        cin >> c >> p;
        if (c=='D') {b+=p;}
        else b-= p;
        if (b>r) {r=b;}
        else if (b<l) l=b;
    }
    F(i,l,r+1) if (v[i]) t++;
    cout << t << '\n';
}