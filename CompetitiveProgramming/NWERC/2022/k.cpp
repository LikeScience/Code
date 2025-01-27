#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<set<int> > al(k);
    vector<bool> sl(k,0);
    int lk = k;
    F(i,0,n) {
        int a, b; cin >> a >> b;
        if (a == b) {al[a-1].insert(lk++); continue;}
        al[a-1].insert(b-1);
        al[b-1].insert(a-1);
    }
    queue<int> q; vector<int> vis(k,0);
    bool b = 1; int cc=0; bool et = 0;
    F(i,0,k) if (!vis[i]) {
        q.push(i); cc++; bool etl = 1;
        while(!q.empty()) {
            int x = q.front(); q.pop();
            if (!vis[x]) {
                vis[x] = 1;
                if ((int)al[x].size() == 0) {
                    etl=0;
                    cc--;
                    break;
                    
                } 
                if ((int)al[x].size() == 1) {
                    int y = *al[x].begin();
                    if (y < k && !vis[y]) {
                            q.push(y);
                            continue;
                    }
                    etl=0;
                    break;
                }
                int cnt = 0;
                for(int y : al[x]) {
                    if (y >= k) continue;
                    if ((int)al[y].size() > 1) {
                        cnt++;
                        q.push(y);
                    } else vis[y] = 1;
                }
                if (cnt > 2) {b = 0; break;}
                if (cnt < 2)  etl = 0;
            }
            if (!b) break;
        }
        if (etl) et = 1;
        if (!b) break;
    } if (et && cc > 1) b = 0;
    cout << (b ? "possible" : "impossible") << '\n';
}