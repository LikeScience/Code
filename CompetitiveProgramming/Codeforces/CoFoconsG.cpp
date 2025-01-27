#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main( ) {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, k; string s;
    cin >> t;
    F(z,0,t) {
        cin >> n >> k >> s;
        char c = '0';
        vector<int> v;  
        F(i,0,n) {
            if (s[i] != c) {
                v.push_back(1);
                c = s[i];
            } else v[v.size()-1]++;
        } int x = 0;
        if (v.size()<k+1) {
            F(i,0,v.size()) x+= v[i];
            cout << x << '\n'; continue;
        } int mx = 0;
        F(i,0,k+1) {
            x += v[i];
        } mx=x;
        F(i,k+1,v.size()) {
            x -= v[i-k-1]; x+= v[i];
            mx = max(mx, x);
        }
        cout << mx << '\n';
    }
    
}