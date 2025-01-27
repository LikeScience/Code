#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
#define pr pair<ll, int>

int main() {
    int n;
    cin >> n;
    vector<pr> v;
    F(i,0,n) {
        ll x;
        cin >> x; 
        v.push_back(make_pair(x, i));
    } v;
    set<pr> q;
    F(i,0,n) q.insert({v[i]});
    ll cnt = 0;
    while (!q.empty()) {
        auto it = q.end(); it--;
        pr a = *it;
        q.erase(it);
        cnt+=a.first;
        v[a.second].first=0;
        ll l = 0, r = 0;
        if (a.second>0) {
            l = v[a.second-1].first;   
        } else if (a.second< n-1) {
            r  = v[a.second+1].first; 
        }
        if (l == 0 && a.second == r) {
            cnt+=r;
            v[a.second].first = 0;
            v[a.second+1].first = 0;
            q.erase(v[a.second+1]);
        } else if (r == 0 && a.second == l) {
            if (l == 0 && a.second == r) {
            cnt+=l;
            v[a.second].first = 0;
            v[a.second-1].first = 0;
            q.erase(v[a.second-1]);
        } else if (l>r) {
            cnt += v[a.second]
            q.erase(v[a.second-1]);
            v[a.second-1].first=r;   
        } else {
            q.erase(v[a.second+1]);
            v[a.second+1].first=0;
        }
        
    }

    cout << cnt << '\n';

}
    
