#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x;
    map<ll, ll> m;
    map<ll, ll>::iterator it;
    cin >> n;
    vector<ll> v(n+1);
    F(i,0,n) {
        cin >> x;
        it = m.lower_bound(x);
        if (it == m.begin()) {m.erase(v[1]); m[x] = 1; v[1]=x;}
        else {
            --it;
            m.erase(v[it->second+1]);
            v[it->second+1] = x; 
            m[x] = it->second+1;
        }
    }
    it = m.end(); it--;
    cout << it->second << '\n';
}