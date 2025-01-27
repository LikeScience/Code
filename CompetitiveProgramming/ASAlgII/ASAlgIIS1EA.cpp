#include <bits/stdc++.h>
using namespace std;
#define F(i,s,e) for (int i = s; i < e; i++)

int  main() {
    int n, m, t, s, z;
    cin >> t;
    F(y,0,t) {
        s = 0;
        cin >> n >> m;
        F(i,0,n) {
            cin >> z; s+= z;
        }
        if (m < n) {cout << -1 << '\n';}
        else {
            
        }
    } 
}