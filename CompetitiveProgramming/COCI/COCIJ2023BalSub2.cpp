#include <bits/stdc++.h>
#define s second
#define f first
#define F(i,s,e) for(int i = s; i != e; i++)
#define ll long long 
using namespace std;    

int main() { //Subtask 2
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, n, m, a, b, e, pat;
    ll w, o;
    cin >> t;
    F(z,0,t) {
    cin >> n >> m;
    vector<vector<pair<int, int> > > v(n), p(n);
    vector<ll> d(n,10000000000000000), /*dn(n,10000000000000000),*/ l;
    vector<bool> vis(n,0);
    vector<int> ot;
    F(i,0,m) {
        cin >> a >> b >> w;
        l.push_back(w);
        v[a-1].push_back(make_pair(b-1, i));
        v[b-1].push_back(make_pair(a-1, i));
        if ((a == 1 && b == n) || (a == n && b == 1)) {
            o = w;
        }
        //cout << i << '\n';
    }
    
    d[0] = 0; 
    set<tuple<ll, int, int, int> > q; //distance, node, parent, edge
    q.insert(make_tuple(0,0,-1,-1));
    while(q.size() > 0) { //Dijkstra's
        w = get<0>(*q.begin()); b = get<1>(*q.begin()); a = get<2>(*q.begin()); e = get<3>(*q.begin());
        q.erase(q.begin());
        if (!vis[b]) {
            vis[b] = 1;
            d[b] = w;
            if (b!=0)p[b].push_back({a,e});
            F(i,0,v[b].size()) {
                    if (!vis[v[b][i].f]){q.insert(make_tuple(w+l[v[b][i].s], v[b][i].f,  b, v[b][i].s));}
                    else if (w+l[v[b][i].s]==d[v[b][i].f]){p[v[b][i].f].push_back({b, v[b][i].s});}
            }
        } else if (w==d[b]) {
            p[b].push_back({a,e});
        }
    }
    //F(i,0,n) cout << d[i] << " "; cout << '\n';
    //F(i,0,n) {F(j,0,p[i].size()) {cout << p[i][j].f << '|' <<  p[i][j].s << " ";} cout << '\n';}
    vis.assign(n,0);
    set<pair<ll, int> > qu; //distance, node
    qu.insert({0,n-1});
    pat=1;
    vis[n-1]=1;
    while(qu.size() > 0) { //Backtrack
        w = qu.begin()->f; b = qu.begin()->s; 
        qu.erase(qu.begin());
        if (b==0) {break;}
        a = pat--;
        F(i,0,p[b].size()) {
                if (!vis[p[b][i].f]){
                    vis[p[b][i].f] = 1; 
                    qu.insert(make_pair(w+l[p[b][i].s], p[b][i].f));
                    pat++;
                    e = p[b][i].s;
                }
                
        }
        if (pat==1 && a ==1) {ot.push_back(e);}
    }
    sort(ot.begin(), ot.end());
    cout << ot.size() <<'\n';
    F(i,0,ot.size()) cout << ot[i]+1 << " ";
    cout << '\n';
    }
}