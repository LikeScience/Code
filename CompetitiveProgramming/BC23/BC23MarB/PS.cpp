#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll p, n, h;
    cin >> p >> n;
    if (p == 1) {
        vector<ll> e, o; ll m = 0;
        cin >> h;
        if (h % 2) {
            o.push_back(h);
            e.push_back(0);
        } else {
            e.push_back(max((ll)0, h));
            o.push_back(0);
        } m = max( e[0], (ll)0);
        F(i,1,n) {
            cin >> h;
        if (h % 2) {
            if (o[i-1] == 0) {
                o.push_back(max(h,h+e[i-1]));
                e.push_back((ll)0);
            } else {
            o.push_back(max(h,h+e[i-1]));
            e.push_back(max((ll)0,h+o[i-1]));
            }
            
        } else {
            e.push_back(max((ll)0, max(h,h+e[i-1])));
            if (o[i-1] == 0) {o.push_back((ll)0);}
            else o.push_back(h+o[i-1]);
        }
            m = max(e[i], m);
        }
        cout << m << '\n';
    } else {
        ll x;
        map<ll, ll> m;
        map<ll, ll>::iterator it;
        vector<ll> v(n+1);
        F(i,0,n) {
            cin >> x;
            it = m.lower_bound(x);
            if (it == m.begin()) {
                m.erase(v[1]);
                m[x] = 1;
                v[1]=x;
            } else {
                --it;
                m.erase(v[it->second+1]);
                v[it->second+1] = x; 
                m[x] = it->second+1;
            }   
        }
        it = m.end(); it--;
        cout << it->second -1 << '\n';
    }

}