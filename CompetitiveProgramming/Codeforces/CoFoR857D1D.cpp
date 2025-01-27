#include <bits/stdc++.h>
#define F(i,s,e) for (long long i = s; i < e; i++)
#define ll long long
#define f first
#define s second
#define pz pair<ll, pair<ll, ll> >
#define pw pair<pz, pair<ll, ll> >
using namespace std;

ll M = 2e18;

bool comp(pw &a, pw &b) {
    if (a.f.f < b.f.f) {
        return 0;
    }
    else if (a.f.f > b.f.f) {
        return 1;
    } else if (a.f.s.s > b.f.s.s) {
        return 0;
    } else if (a.f.s.s < b.f.s.s) {
        return 1;
    } else return (a.f.s.f < b.f.s.f);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, m, p, a, b, si;
    cin >> t;
    F(z,0,t) {
        cin >> n >> m >> p;
        vector<pair<ll, ll> > al[n];
        ll w[n];
        F(i,0,n) cin >> w[i];
        F(i,0,m) {
            cin >> a >> b >> si;
            al[a-1].push_back({b-1,si});
        }
        // {min_perf; {max_inc; avail_mon}}
        vector<vector<pz> > v(n, vector<pz>(n, {M, {0,0}})); 
        vector<vector<bool> > vis(n, vector<bool>(n));
        priority_queue<pw, vector<pw>, decltype(&comp) > q(comp);
        q.push({{0,{w[0], p}}, {0,0}});
        while(!q.empty()) {if (!vis[q.top().s.f][q.top().s.s]) {
            a = q.top().s.f; b=q.top().s.s;
            vis[a][b]=1;
            v[a][b] = q.top().f;
            F(i,0,al[a].size()) {
                pz x; ll y = al[a][i].s - v[a][b].s.s; 
                x.s.f = max(v[a][b].s.f, w[al[a][i].f]);
                if (y<=0) {
                    x.f = v[a][b].f;
                    x.s.s = -y;
                } else {
                    x.f = v[a][b].f + y/v[a][b].s.f + ((y % v[a][b].s.f) ? 1 : 0); 
                    x.s.s = ((y % v[a][b].s.f) ? (y/v[a][b].s.f + 1) * v[a][b].s.f - y : 0);
                }
                q.push({x, {al[a][i].f, a}});
                q.push({x, {al[a][i].f, b}});
            }
        }
        q.pop();
        }
        ll mn = v[n-1][0].f;
        F(i,1,n) mn = min(v[n-1][i].f, mn);
        cout << ((mn == M) ? -1 : mn) << '\n'; 
    }
}