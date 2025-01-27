#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main( ) {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n; 
    cin >> t;
    F(z,0,t) {
        cin >> n;   vector<int> v(n), o;
        F(i,0,n) cin >> v[i];
        int mx = 0;
        F(i,0,n) mx = max(mx,v[i]);
        map<int, bool> vis;
        F(i,0,n) {
            if (!vis[v[i]]) {
                o.push_back(v[i]);
            }   else o.push_back(mx-v[i]);
            vis[v[i]] = 1;
        }
        F(i,0,n) cout << o[i] << " \n"[i==n-1];
    }
    
}