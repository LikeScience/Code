#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++) 
using namespace std;
#define pii pair<int, int>
#define vp vector<pair<int, pii> >
#define fi first
#define se second

vector<int> e;

bool cmp (pair<int, pii> &l, pair<int, pii> &r) {
    if (l.fi < r.fi) return 1;
    else if (l.fi > r.fi) return 0;
    if (l.se.fi < r.se.fi) return 1;
    else if (l.se.fi > r.se.fi) return 0;
    if (e[l.se.se] < e[r.se.se]) return 0;
    else if (e[l.se.se] > e[r.se.se]) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b;
    cin >> n;
    vp v; e.resize(n);
    int r[n];
    F(i,0,n) {
        cin >> a >> b;
        v.push_back({a,{0,i}});
        v.push_back({a+b,{1,i}});
        e[i] = a+b;
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> s;
    F(i,0,2*n) {
        if (v[i].se.fi == 0) {
            a = 0; b = (int)s.size()-1;
            while (b>a || b == 0) {
                bool bb = (b == 0 ? 1 : 0);
                int m = (a+b+1)/2;
                if (s[m] >= e[v[i].se.se]) a = m;
                else b = m-1;
                if (bb && b == 0) break;
            }
            if (b==-1) {
                r[v[i].se.se] = 0;
                if (s.size()==0) s.resize(1);
                s[0]=e[v[i].se.se];
            } else {
                r[v[i].se.se] = a +1;
                if ((int)s.size()<a+2) s.push_back(0);
                s[a+1]=e[v[i].se.se];
            }
        } else {
            if (s[(int)s.size()-1] == v[i].fi) s.pop_back();
        }
    }
    F(i,0,n) cout << r[i] << " \n"[i==n-1];
}