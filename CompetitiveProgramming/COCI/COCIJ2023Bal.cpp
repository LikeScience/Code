#include <bits/stdc++.h>
#define s second
#define f first
#define F(i,s,e) for(int i = s; i != e; i++)
#define ll long long 
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, n, m, a, b, e, pat;
    ll w;
    vector<int> ot, ir, irp;
    cin >> t;
    F(z,0,t) {
    cin >> n >> m;
    vector<vector<pair<int, int> > > v(n), p(n), pn(n);
    vector<ll> d(n,10000000000000000), dn(n,10000000000000000), l;
    vector<bool> vis(n,0), ae(m,0);
    ot.clear(); ir.clear(); irp.clear();
    
    F(i,0,m) {
        cin >> a >> b >> w;
        l.push_back(w);
        v[a-1].push_back(make_pair(b-1, i));
        v[b-1].push_back(make_pair(a-1, i));
        //cout << i << '\n';
    }
    
    d[0] = 0; 
    set<tuple<ll, int, int, int> > q; //q distance, node, parent, edge
    
    q.insert(make_tuple(0,0,-1,-1));
    while(!q.empty()) { //Dijkstra's Origin
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
    while(!qu.empty()) { //Backtrack Origin
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
        if (pat==1 && a ==1) {ir.push_back(e);}
    }

    vis.assign(n,0);
    dn[n-1] = 0; 
    //tuple: distance, node, parent, edge
    q.insert(make_tuple(0,n-1,-1,-1));
    while(!q.empty()) { //Dijkstra's Destination
        w = get<0>(*q.begin()); b = get<1>(*q.begin()); a = get<2>(*q.begin()); e = get<3>(*q.begin());
        q.erase(q.begin());
        if (!vis[b]) {
            vis[b] = 1;
            dn[b] = w;
            if (b!=n-1)pn[b].push_back({a,e});
            F(i,0,v[b].size()) {
                    if (!vis[v[b][i].f]){q.insert(make_tuple(w+l[v[b][i].s], v[b][i].f,  b, v[b][i].s));}
                    else if (w+l[v[b][i].s]==dn[v[b][i].f]){pn[v[b][i].f].push_back({b, v[b][i].s});}
            }
        } else if (w==dn[b]) {
            pn[b].push_back({a,e});
        }
    }

    //Traverse edges to find shortp+1
    vector<pair<int, int> > spp; //begin(0 side), end(n-1 side), edge idx
    F(i,0,n-1) {
        if (d[i]> d[n-1]) continue;
        F(j,0,v[i].size()) {
            if (d[i]+l[v[i][j].s] == d[v[i][j].f]+1 && d[i]+l[v[i][j].s]+dn[v[i][j].f]==d[n-1]+1) {
                spp.push_back(make_pair(i,v[i][j].f));
                ae[v[i][j].s]=1;
                if (spp.size()==1) b = v[i][j].s;
            }
        }
    }

    if (spp.size() == 1) { //If only one n+1 path, add to non removable edges
        irp.push_back(b);
    }
    //F(i,0,spp.size()) {cout << spp[i].f << " " << spp[i].s << '\n';}
    if (spp.size() != 0) {
    //F(i,0,spp.size()) cout << spp[i].f << '\n';
    //cout << spp.size() << '\n';
    vis.assign(n,0);
    set<pair <ll, int>, greater<pair<ll, int> > > que; //distance, node
    F(i,0,spp.size()) {
        que.insert({d[spp[i].f],spp[i].f });
        vis[spp[i].f]=1;
    }
    
    while(!que.empty()) { //Backtrack n+1enabler edge to origin
        w = que.begin()->f; b = que.begin()->s; 
        que.erase(que.begin());
        if (b==0) {break;}
        
        F(i,0,p[b].size()) {
                if (!vis[p[b][i].f]){
                    vis[p[b][i].f] = 1; 
                    que.insert(make_pair(d[p[b][i].f], p[b][i].f));
                    
                    
                }
                ae[p[b][i].s] = 1;
        }
        
    }

    vis.assign(n,0);
    //que -> distance, node
    F(i,0,spp.size()) {
        que.insert({dn[spp[i].s],spp[i].s });
        vis[spp[i].s]=1;
    }
    
    while(!que.empty()) { //Backtrack n+1enabler edge to destination
        w = que.begin()->f; b = que.begin()->s; 
        que.erase(que.begin());
        if (b==n-1) {break;}
        
        F(i,0,pn[b].size()) {
                if (!vis[pn[b][i].f]){
                    vis[pn[b][i].f] = 1; 
                    que.insert(make_pair(dn[pn[b][i].f], pn[b][i].f));
                }
                ae[pn[b][i].s] = 1;
        }
        
    }
    //F(i,0,m) cout << ae[i]<<'\n';
    //BFS to determine non removable edges
    vis.assign(n,0);
    que.insert({dn[0],0});
    pat=1;
    vis[0]=1;
    while(!que.empty()) {
        w = que.begin()->f; b = que.begin()->s; 
        que.erase(que.begin());
        if (b==n-1) {break;}
        a = pat--;
        F(i,0,v[b].size()) {
                if (!vis[v[b][i].f] && ae[v[b][i].s]){
                    vis[v[b][i].f] = 1; 
                    que.insert(make_pair(dn[v[b][i].f], v[b][i].f));
                    pat++;
                    e = v[b][i].s;
                }
                //if (ae[v[b][i].s]) cout << v[b][i].f+1 << " "<< v[b][i].s+1 << '\n';
        }
        if (pat==1 && a ==1) {irp.push_back(e);}
    } 
    
    //F(i,0,ir.size()) cout << ir[i]+1 << " "; cout << '\n';
    //F(i,0,irp.size()) cout << irp[i]+1 << " "; cout << '\n';
    //Determining what non removable coincides with theoretically removable in sp
    sort(ir.begin(), ir.end());
    sort(irp.begin(), irp.end());
    b=0; //present index in irp
    F(i,0,ir.size()) {
        //cout << ot.size()<< '\n';
        if (b == (int)irp.size()) {
            ot.push_back(ir[i]);
        } else {
            while(irp[b] < ir[i]) {
                b++;
                if (b==(int)irp.size()) break;
            }
            if (b ==(int) irp.size() || ir[i] != irp[b]) ot.push_back(ir[i]);
        }
    }
    cout << ot.size() <<'\n';
    F(i,0,ot.size()) cout << ot[i]+1 << " ";
    } else cout << "0\n";
    cout << '\n';
    }
}