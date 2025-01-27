#include "stations.h"
#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

vector<vector<int> > al;
int ml=-1;
vector<int> l;

void dfs(int x, int p, bool m) {
    if (!m) l[x] = ++ml;
    for (auto it : al[x]) if (it != p) dfs(it,x,!m);
    if (m) l[x] = ++ml;
    //cout << x << " " << l[x] << '\n';
}

std::vector<int> label(int n, int k, std::vector<int> u, std::vector<int> v) {
    l.clear(); al.clear();
    l.resize(n); al.resize(n);
    ml = -1;
    F(i,0,n-1) {
        al[u[i]].push_back(v[i]);
        al[v[i]].push_back(u[i]);
        //cout << u[i] << " " << v [i] << '\n';
    }
    dfs(0,-1, 0);
    //F(i,0,n) {for (auto it : al[i]) cout << it << ' '; cout << '\n';}
    return l;
}
int find_next_station(int s, int t, std::vector<int> c) {
    if ((int)c.size() == 1) return c[0];
    if (s > c[0]) {
        if (t > s || t < c[1]) return c[0];
        F(i,1,(int)c.size()-1) if (t >= c[i] && t < c[i+1]) return c[i];
        return c[(int)c.size()-1];
    } else {
        if (t < s || t > c[(int)c.size()-2]) return c[(int)c.size()-1];
        for (int i = (int)c.size()-2;i > 0; i--) if (t <= c[i] && t > c[i-1]) return c[i];
        return c[0];
    }       
}
