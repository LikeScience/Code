#include <bits/stdc++.h>
#define F(i,s,e) for (int i= s; i<e; i++)
#define fi first
#define se second
#define pii pair<int, int>
using namespace std;

int main() {
    fstream fin("pump.in", fstream::in);
    int n, m, ai, bi;
    double t=0;
    fin >> n >> m;
    vector<vector<pii> > al(n+1);
    vector<int> c(m), f(m);
    F(i,0,m) {
        fin >> ai >> bi >> c[i] >> f[i];
        al[ai].push_back(make_pair(bi, i));
        al[bi].push_back(make_pair(ai, i));
    }
    fin.close();
    F(i,1,1001) {
        vector<int> dis(n+1, 1e9+1); vector<bool> ad(n+1, 0);
        priority_queue<pii, vector<pii>, greater<pii> > p;
        p.push(make_pair(0,1));
        while (!p.empty()) {
            if (ad[p.top().se]) {
                p.pop();
            } else {
                int x = p.top().se;
                dis[x] = p.top().fi;
                p.pop();
                F(j,0,(int)al[x].size()) if (!ad[al[x][j].fi] && f[al[x][j].se] >= i){
                    if (dis[al[x][j].fi] > dis[x] + c[al[x][j].se]) {
                        dis[al[x][j].fi] = dis[x] + c[al[x][j].se];
                        p.push(make_pair(dis[x] + c[al[x][j].se], al[x][j].fi));
                    }
                }
            }
        }
        if (dis[n] != 1e9+1) {
            t = max(t, double(i)/double(dis[n]));
        }   
    }
    fstream fout("pump.out", fstream::out);
    fout << int(1000000*t) << '\n';
}