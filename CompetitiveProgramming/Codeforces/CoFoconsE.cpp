#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main( ) {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, m; 
    cin >> t;
    F(z,0,t) {
        cin >> n >> m;
        int a=0, b=0, ai, bi;
        F(i,0,n) {cin >> ai; a+=ai; }
        
        F(i,0,m) {cin >> bi; b+=bi; }
        if (a > m) cout << 'Y';
        else cout << 'N';
        if (a>=m && b >= n) cout << 'Y';
        
        else cout << 'N';
        
        if (b > n) cout << 'Y' << '\n';
        else cout << 'N' << '\n';
    }
    
}