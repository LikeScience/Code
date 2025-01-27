#include <bits/stdc++.h>

using namespace std;

#define lld long long
#define rep(i,s,e) for(int i = s; i < e; i++) 
#define trav(a,v) for(auto a : v)
int dist[1000000];
vector<int> dp, vis;
vector<vector<int > > ch;

void dpf(int x) {
    vis[x] = 1; dp[x] = 1;
    trav(a,ch[x]) {
        if (!vis[a]) {
            dpf(a);
            dp[x]+=dp[a];
        }
    }
    return;
}

int main () {
    int n, k, q;
    cin >> n; int m = n*n;
    vector <vector<int> > boss(n+1), sub(n+1);
    ch.resize(n+1);
    rep(i,1,n+1) {
        cin >> k;
        rep(j,0,k) {
            cin >> q;
            boss[i].push_back(q);
            sub[q].push_back(i);
        }
    }
    rep(source,1,n+1){
        rep(i,1,n+1)dist[i]=-1;
        queue<int> q;
        q.push(source);
        dist[source]=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            trav(a,sub[u]){
                if(dist[a]==-1) {
                    dist[a]=dist[u]+1,q.push(a);
                    ch[u].push_back(a);
                }
            }
        }
        dp.assign(n+1,n+1);
        vis.assign(n+1,0);
        rep(i,1,n+1) if(!vis[i]) {
            dpf(i); //em vez de dfs podia ser a soma das distancias
        }
        int s = 0;
        rep(i,1,n+1) {
            s+=dp[i];
        }
        if (s < m) m = s;
    }
    cout << m << '\n';
}