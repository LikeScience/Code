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
vector<bool> fin;

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
    al.resize(n+1);b.assign(n+1, 0); fin.assign(n+1, 0);
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
            b[*v[y.se].begin()]++;
            fin[*v[y.se].begin()] = 1;
            if ((int)v[y.se].size() > 1) {
                s.insert({{y.fi.fi+1, y.fi.se}, y.se});
                b[y.se]++;
            } else if (y.se != 1) {
                int x = y.se;
                while(x != 0) {
                    //cout << 1 << '\n';
                    int pbx = b[x];
                    b[x] = 0; bool bb = 1;
                    for (auto i : al[x]) {
                        if (fin[i]) {
                            b[x] += (b[i] > 0 ? 1 : -1);
                        } else bb = 0;
                    }
                    if (bb) {x = p[x];fin[x] = 1;}
                    else {
                        s.erase({{pbx, d[x]}, x});
                        if ((int)v[x].size() > 0)s.insert({{b[x], d[x]}, x});
                        break;
                    }
                } 
            }
        } else {
            it--;
            it = s.lower_bound({{it->fi.fi,0},0});
            y = *it;
            s.erase(it);
            b[*v[y.se].begin()]++;
            fin[*v[y.se].begin()] = 1;
            if ((int)v[y.se].size() > 1) {
                s.insert({{y.fi.fi+1, y.fi.se}, y.se});
                b[y.se]++;
            }
            else if (y.se != 1) {
                int x = y.se;
                while(x != 0) {
                    //cout << 2 << '\n';
                    int pbx = b[x];
                    b[x] = 0; bool bb = 1;
                    for (auto i : al[x]) {
                        if (fin[i]) {
                            b[x] += (b[i] > 0 ? 1 : -1);
                        } else bb = 0;
                    }
                    if (bb) {x = p[x];
                    fin[x] = 1;}
                    else {
                        s.erase({{pbx, d[x]}, x});
                        if ((int)v[x].size() > 0)s.insert({{b[x], d[x]}, x});
                        break;
                    }
                } 
            }
        }
        int z = ruch(*v[y.se].begin());
        v[y.se].erase(v[y.se].begin());
        s.erase({{b[p[z]], d[p[z]]}, p[z]});
        b[p[z]]--;
        b[z]--;
        fin[z] = 1;
        v[p[z]].erase(z);
        if ((int)v[p[z]].size() > 0) {
            s.insert({{b[p[z]], d[p[z]]}, p[z]});
        } else if (p[z] != 1) {
                int x = p[z];
                while(x != 0) {
                    //cout << 1 << '\n';
                    int pbx = b[x];
                    b[x] = 0; bool bb = 1;
                    for (auto i : al[x]) {
                        if (fin[i]) {
                            b[x] += (b[i] > 0 ? 1 : -1);
                        } else bb = 0;
                    }
                    if (bb) {x = p[x]; fin[x] = 1;}
                    else {
                        s.erase({{pbx, d[x]}, x});
                        if ((int)v[x].size() > 0)s.insert({{b[x], d[x]}, x});
                        break;
                    }
                } 
            }
    }
}
