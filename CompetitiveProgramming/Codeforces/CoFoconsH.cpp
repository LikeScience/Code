#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

int main( ) {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n; ll x; 
    cin >> t;
    vector<ll> prs, vis(1000, 0);
    F(i,2,1000) if (!vis[i]) {
        prs.push_back(i);
        for (int j = i*i; j < 1000; j +=i) vis[j] = 1;
    }
    F(z,0,t) {
        cin >> n >> x;
        F(i,0,n) cout << prs[i]*x << " \n"[i==n-1];
    }
    
}