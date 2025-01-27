#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t = 58, x, m, l = 1;
    cin >> x;
    F(i,0,t-1) {
        cin >> x >> m;l+=(m+1);
        F(j,0,m) F(y,0,3) cin >> x; 
    }
    cout << l+1 <<'\n';
}