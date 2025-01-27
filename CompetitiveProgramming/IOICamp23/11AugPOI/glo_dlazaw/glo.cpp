#include <vector>
#include <bits/stdc++.h>
#include "glolib.h"
#define F(i,s,e) for (int i = s; i< e; i++)
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;

vector<vector<int> > al;
vector<int> p, d, b;

void dfs1(int x) {
    if (x != 1) {
        d[x] = d[p[x]];
    } else d[x] = 0;
    for (auto i : al[x]) {
        if (i != p[x]) dfs1(i);
    }
}

int main() {
    int n = daj_n();
    pair<pii, int> y;
    p.resize(n+1); d.resize(n+1);
    al.resize(n+1);b.assign(n+1, 0);
    for(int i = 2; i <= n; i++) {
        p[i] = daj_przelozonego(i);
        al[p[i]].push_back(i);
    }
    dfs1(1);
    set<pair<pii, int> > s;
    vector<set<int> > v(n+1);
    F(i,2,n+1) if ((int)al[i].size() == 0) {
        v[p[i]].insert(i);
    } 
    F(i,1,n+1) if ((int)v[i].size() > 0) {
        s.insert({{0, d[i]}, i});
    } 
    while(!s.empty()) {
        auto it = s.lower_bound({{0,0},0});
        if (it != s.end()) {
            y = *it;
            s.erase(it);
            if ((int)v[y.se].size() > 1) {
                s.insert({{y.fi.fi+1, y.fi.se}, y.se});
                b[y.se]++;
            }
        } else {
            it--;
            it = s.lower_bound({{it->fi.fi,0},0});
            y = *it;
            s.erase(it);
            if ((int)v[y.se].size() > 1) {
                s.insert({{y.fi.fi+1, y.fi.se}, y.se});
                b[y.se]++;
            }
        }
        int z = ruch(*v[y.se].begin());
        v[y.se].erase(v[y.se].begin());
        s.erase({{b[p[z]], d[p[z]]}, p[z]});
        b[p[z]]--;
        v[p[z]].erase(z);
        if ((int)v[p[z]].size() > 0) {
            s.insert({{b[p[z]], d[p[z]]}, p[z]});
        }
    }
}
