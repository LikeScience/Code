#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;
#define pii pair<int, int>
#define ppii pair<pair<int, int>, int>
#define fi first
#define se second

int n;
vector<vector<int> > d;

struct stx {
    int m = 1e9+1;
    stx* x00 = NULL;
    stx* x10 = NULL;
    stx* x01 = NULL;
    stx* x11 = NULL;
    bool b = 0;
};

vector<stx> t;

void stu(int l1, int r1, int l2, int r2, int d1, int d2, stx &x, int v) {
    if (!x.b) {
        x.b = 1;
        int k = (int)t.size();
        F(i,0,4) t.push_back(stx());
        x.x00 = &t[k];
        x.x01 = &t[k+1];
        x.x10 = &t[k+2];
        x.x11 = &t[k+3];
    }
    if (l1 == r1 && l2 == r2) {
        x.m = min(v, x.m);
    }
    else if (l1 == r1) {
        int m2 = (l2+r2)/2;
        if (d2 <= m2) stu(l1,r1,l2,m2,d1,d2, *x.x00, v);
        else stu(l1,r1,m2+1,r2,d1,d2, *x.x01, v);
        x.m = min(x.x00->m, x.x01->m);
    } else if (l2 == r2) {
        int m1 = (l1+r1)/2;
        if (d1 <= m1) stu(l1,m1,l2,r2,d1,d2, *x.x00, v);
        else stu(m1+1,r1,l2,r2,d1,d2, *x.x10, v);
        x.m = min(x.x00->m, x.x10->m);
    } else {
        int m1 = (l1+r1)/2;
        int m2 = (l2+r2)/2;
        if (d1 <= m1) {
            if (d2 <= m2) {
                stu(l1,m1,l2,m2,d1,d2, *x.x00, v);
            } else {
                stu(l1,m1,m2+1,r2,d1,d2, *x.x01, v);
            }
        } else {
            if (d2 <= m2) {
                stu(m1+1,r1,l2,m2,d1,d2, *x.x10, v);
            } else {
                 stu(m1+1,r1,m2+1, r2,d1,d2, *x.x11, v);
            }
        }
        x.m = min(min(x.x00->m, x.x01->m), min(x.x10->m, x.x11->m));
    }
}

int ste(int l1, int r1, int l2, int r2, int dl1, int dr1, int dl2, int dr2, stx &x, int v) {
    if (x.m == 1e9+1) return 1e9+1; 
    if (l1 == dl1 && r1 == dr1 && l2 == dl2 && r2 == dr2) {
        return x.m;
    }
    else {
        int m1 = (l1+r1)/2;
        int m2 = (l2+r2)/2;
        if (dr1 <= m1) {
            if (dr2 <= m2) {
                return ste(l1,m1,l2,m2,dl1, dr1, dl2, dr2, *x.x00, v);
            } else if (dl2 > m2) {
                return ste(l1,m1,m2+1,r2,dl1, dr1, dl2, dr2, *x.x01, v);
            } else {
                return min(ste(l1,m1,l2,m2,dl1, dr1, dl2, m2, *x.x00, v), ste(l1,m1,m2+1,r2,dl1, dr1, m2+1, dr2, *x.x01, v));
            }
        } else if (dl1 > m1) {
            if (dr2 <= m2) {
                return ste(m1+1,r1,l2,m2,dl1, dr1, dl2, dr2, *x.x10, v);
            } else if (dl2 > m2) {
                return ste(m1+1,r1,m2+1, r2,dl1, dr1, dl2, dr2, *x.x11, v);
            } else {
                return min(ste(m1+1,r1,l2,m2,dl1, dr1, dl2, m2, *x.x10, v),ste(m1+1,r1,m2+1, r2,dl1, dr1, m2+1, dr2, *x.x11, v) );
            }
        } else {
            if (dr2 <= m2) {
                return min(ste(l1,m1,l2,m2,dl1, m1, dl2, dr2, *x.x00, v),ste(m1+1,r1,l2,m2,m1+1, dr1, dl2, dr2, *x.x10, n));
            } else if (dl2 > m2) {
                return min(ste(l1,m1,m2+1,r2,dl1, m1, dl2, dr2, *x.x01, v), ste(m1+1,r1,m2+1, r2,m1+1, dr1, dl2, dr2, *x.x11, v));
            } else {
                return min(min(ste(l1,m1,l2,m2,dl1, m1, dl2, m2, *x.x00, v), ste(l1,m1,m2+1,r2,dl1, m1, m2+1, dr2, *x.x01, v)), min(ste(m1+1,r1,l2,m2,m1+1, dr1, dl2, m2, *x.x10, v),ste(m1+1,r1,m2+1, r2,m1+1, dr1, m2+1, dr2, *x.x11, v)));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    t.reserve(8e6);
    int e, ai, bi, wi;
    cin >> n >> e;
    vector<vector<pair<int, int> > > a(n);
    vector<vector<int> > c(2);
    d.assign(3,vector<int>(n,1e9));
    F(i,0,e) {
        cin >> ai >> bi >> wi;
        a[ai].push_back(make_pair(bi,wi));
        a[bi].push_back(make_pair(ai,wi));
    }
    F(s,0,3) {
        priority_queue<pii, vector<pii>, greater<pii> > p;
        p.push({0,s});
        vector<bool> vis(n, 0);
        while(!p.empty()) {
            int y = p.top().fi, x = p.top().se;
            p.pop();
            if (!vis[x]) {
                vis[x] = 1;
                d[s][x] = y;
                for (pii i : a[x]) if (!vis[i.fi] && d[s][i.fi] > d[s][x] + i.se) p.push({d[s][x] + i.se, i.fi});
            }
            
        }
        if (s != 2) {
                set<int> ss; for (int i : d[s]) ss.insert(i);
                for (auto it = ss.begin(); it != ss.end(); it++) c[s].push_back(*it);
         }
    }
    vector<int> sz = {(int)c[0].size(), (int)c[1].size()};
    stx src;
    F(i,0,n) {
        int aa = lower_bound(c[0].begin(), c[0].end(), d[0][i]) - c[0].begin();
        int bb = lower_bound(c[1].begin(), c[1].end(), d[1][i]) - c[1].begin();
        stu(0,sz[0]-1,0,sz[1]-1,aa,bb,src, d[2][i]);
    }
    int cnt = 0;
    F(i,0,n) {
        int aa = lower_bound(c[0].begin(), c[0].end(), d[0][i]) - c[0].begin();
        int bb = lower_bound(c[1].begin(), c[1].end(), d[1][i]) - c[1].begin();
        if (ste(0,sz[0]-1,0,sz[1]-1,0,aa,0,bb,src, 0) >= d[2][i]) {
            if (aa == 0 || ste(0,sz[0]-1,0,sz[1]-1,0,aa-1,0,bb,src, 0) > d[2][i]) {
                if (bb == 0 || ste(0,sz[0]-1,0,sz[1]-1,0,aa,0,bb-1,src, 0) > d[2][i]) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
}

