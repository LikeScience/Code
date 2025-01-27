#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F(i,x,e) for (int i = x; i<e; i++)
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;

int main() {
    int n, q, x1, y1, x2, y2, t=0;
    cin >> n >> q;
    vector<pair<int, pair<int, int> > > v;
    vector<int> o(q);
    F(i,0,n) {
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({x1,{-1,y2-y1}});
        v.push_back({x2,{-1,y1-y2}});
    }
    F(i,0,q) {
        cin >> x1;
        v.push_back({x1,{0,i}});
    }
    sort(v.begin(), v.end());
    F(i,0,(int)v.size()) {
        if (v[i].s.f == -1) t+=v[i].s.s;
        else o[v[i].s.s] = t;
    }
    F(i,0,q) cout << o[i] << '\n';
}