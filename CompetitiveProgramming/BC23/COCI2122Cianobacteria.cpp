#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

vector<vector<int> > al, cc;
int ccc = -1;
vector<bool> vis;
vector<int> h;

void hdfs(int x) {
    vis[x] = 1;
    F(i,0,(int)al[x].size()) if (!vis[al[x][i]]) {
        hdfs(al[x][i]);
    }
    if ((int)al[x].size() == 0) h[x]=1;
    else {
        int mx = 0;
        F(i,0,(int)al[x].size()) if (mx < h[al[x][i]]) mx =  h[al[x][i]];
        h[x] = mx+1;
    }
}

int ndfs(int x) {
    vis[x] = 1;
    int t = 0;
    F(i,0,(int)al[x].size()) if (!vis[al[x][i]]) {
        t = max(t,ndfs(al[x][i]));
    }
    int f = 0, s = 0;
    F(i,0,(int)al[x].size()) if (h[x] > h[al[x][i]]) {
        if (h[al[x][i]] >= f) {
            s = f;
            f = h[al[x][i]];
        } else if (h[al[x][i]] >= s) {
            s = h[al[x][i]];
        }
    }
    t = max(f+s+1, t);
    //cout << x << " " << t << '\n';
    return t;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    al.resize(n+1);
    vis.assign(n+1,0);
    F(i,0,m) {
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    queue<int> q;
     
    F(i,1,n+1) if (!vis[i]){
        ccc++;
        cc.push_back({});
        q.push(i);
        while(!q.empty()) {
            if (!vis[q.front()]) {
            vis[q.front()]=1;
            cc[ccc].push_back(q.front());
            F(j,0,(int)al[q.front()].size()) {
                q.push(al[q.front()][j]);
            } }
            q.pop();
        }
    }
    
    vis.assign(n+1,0);
    h.resize(n+1);
    F(i,0,ccc+1) {
        hdfs(cc[i][0]);
    }
    //F(i,0,n) cout << h[i+1] << " ";
    vis.assign(n+1,0);
    int t = 0;
    F(i,0,ccc+1) {
        t += ndfs(cc[i][0]);
    }
    cout << t << '\n';
}