#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int n, m, p, ps, n1, n2;
vector<vector<int> > al;
vector<pii> q;
vector<int> pth, dth, fir, st;

void dfst(int x, int pa) {
    if (pa != -1) dth[x] = dth[pa]+1;
    pth.push_back(x); fir[x] = (int)pth.size()-1;
    F(i,0,(int)al[x].size()) if (al[x][i] != pa) {
        dfst(al[x][i], x); 
        pth.push_back(x);
    }
}

void dfss(int x, int pa) {
    if (pa != -1) dth[x] = dth[pa]+1;
    pth.push_back(x); fir[x] = (int)pth.size()-1;
    F(i,0,(int)al[x].size()) if (al[x][i] != pa) {
        if (fir[al[x][i]] == -1) {
        dfss(al[x][i], x); 
        pth.push_back(x);
        } else {
            n1 = x; n2 = al[x][i];
        }
    }
}

void stb(int l, int r, int x) {
    if (l == r) {
        st[x] = pth[l];
        return;
    } int m = (l+r)/2;
    stb(l, m, 2*x+1);
    stb(m+1, r, 2*x+2);
    if (dth[st[2*x+1]] < dth[st[2*x+2]]) {
        st[x] = st[2*x+1];
    } else st[x] = st[2*x+2];
}
int ste(int l, int r, int dl, int dr, int x) {
    if (l == dl && r == dr) {
        return st[x];
    } int m = (l+r)/2;
    if (dr <= m) return ste(l, m, dl, dr, 2*x+1);
    else if (dl >= m+1) return ste(m+1, r, dl, dr, 2*x+2);
    int ai = ste(l, m, dl, m, 2*x+1), bi =  ste(m+1, r, m+1, dr, 2*x+2);
    if (dth[ai] < dth[bi]) {
        return ai;
    } else return bi;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ai, bi;
    cin >> n >> m >> p;
    al.resize(n);
    F(i,0,m) {
        cin >> ai >> bi; ai--; bi--;
        al[ai].push_back(bi);
        al[bi].push_back(ai);
    }
    F(i,0,p) {
        cin >> ai >> bi; ai--; bi--;
        q.push_back(mp(ai, bi));
    }
    if (m == n-1) {
        dth.resize(n); fir.resize(n);
        dth[0] = 0;
        dfst(0, -1);
        ps = (int)pth.size();
        st.assign(4*ps, 0);
        stb(0, ps-1, 0);
        F(i,0,p) {
            cout << dth[q[i].fi] + dth[q[i].se] - 2*dth[ste(0, ps-1, min(fir[q[i].fi], fir[q[i].se]), max(fir[q[i].fi], fir[q[i].se]), 0)] << '\n';
        }
    }
    else if (m == n) {
        dth.resize(n); fir.assign(n,-1);
        dth[0] = 0;
        dfss(0, -1);
        ps = (int)pth.size();
        st.assign(4*ps, 0);
        stb(0, ps-1, 0);
        F(i,0,p) {
            int A = dth[q[i].fi] + dth[q[i].se] - 2*dth[ste(0, ps-1, min(fir[q[i].fi], fir[q[i].se]), max(fir[q[i].fi], fir[q[i].se]), 0)];
            int b1 = dth[q[i].fi] + dth[n1] - 2*dth[ste(0, ps-1, min(fir[q[i].fi], fir[n1]), max(fir[q[i].fi], fir[n1]), 0)];
            int b2 =  dth[n2] + dth[q[i].se] - 2*dth[ste(0, ps-1, min(fir[n2], fir[q[i].se]), max(fir[n2], fir[q[i].se]), 0)];
            int c1 = dth[q[i].fi] + dth[n2] - 2*dth[ste(0, ps-1, min(fir[q[i].fi], fir[n2]), max(fir[q[i].fi], fir[n2]), 0)];
            int c2 = dth[n1] + dth[q[i].se] - 2*dth[ste(0, ps-1, min(fir[n1], fir[q[i].se]), max(fir[n1], fir[q[i].se]), 0)];
            int B = b1 + b2 + 1, C = c1 + c2 + 1;
            cout << min({A,B,C}) << '\n';
        }
    } else if (p == 1) {
        vector<bool> vis(n, 0);
        queue<pii> qu;
        qu.push(mp(q[0].fi, 0));
        while(!qu.empty()) {
            int x = qu.front().fi, d = qu.front().se;
            qu.pop();
            if (vis[x]) continue;
            vis[x] = 1;
            if (x == q[0].se) {
                cout << d << '\n';
                return 0;
            }
            F(i,0,(int)al[x].size()) if (!vis[al[x][i]]) qu.push(mp(al[x][i], d+1));
        }
    }
}