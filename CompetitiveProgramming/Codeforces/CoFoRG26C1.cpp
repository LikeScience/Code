#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; int n;
    cin >> t;
    F(z,0,t) {
        cin >> n;
        vector<ll> v(n), mn(n), mx(n);
        F(i,0,n) cin >> v[i];
        mn[0]=v[0]; mx[0] = abs(v[0]);
        F(i,1,n) {
            mx[i] = max(mx[i-1]+v[i], abs(mn[i-1]+v[i]));
            mn[i] = mn[i-1]+v[i];
        } 
        cout << mx[n-1] << '\n';
    }
}