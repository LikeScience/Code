#include <bits/stdc++.h>
#define F(i,x,e) for (ll i = x; i < e; i++)
#define ll long long 
using namespace std;

ll c(ll x) {
    if (x==0) return 0;
    ll y = 0; // -1:dec; 0:eq; 1:inc; 
    vector<ll> v;
    while(x) {
        v.push_back(x%10);
        x/=10;
    }
    if (v.size() <= 2) return 0;
    for(int k = v.size()-2; k >= 0;k--) {
        if ( v[k+1] != v[k]){
            if (y == 0) {
                if (v[k+1] > v[k]) {
                    y=-1;
                } else if (v[k+1] < v[k]){
                    y=1;
                }
            } else if (y==1 && v[k+1] > v[k]) {
                return 1;
            } else if (y==-1 && v[k+1] < v[k]){
                return 1;
            }
        }
    } 
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; ll a, b;
    cin >> t;
    F(z,0, t) {
        cin >> a >> b;
        ll x=0;
        F(i,a,b+1) x += c(i); 
        cout << x << '\n';
    }
}