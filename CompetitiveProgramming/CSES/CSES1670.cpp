
#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

vector<int> fac = {1};

int id (vector<vector<int> > &v) {
    int x = 0;
    for (int y = 9; y > 0; y--) {
        int cnt = 0;
    F(i,0,3) F(j,0,3) {
        if (v[i][j]<y) cnt++;
        else if (v[i][j] == y) {
            x += cnt*fac[v[i][j]-1];
            break;
        }
    }
    } 
    return x;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    F(i,0,9) fac.push_back((i+1)*fac[i]);
    vector<vector<int> > a(3, vector<int>(3));
    int vis[362880] = {}; 
    F(i,0,3) F(j,0,3) cin >> a[i][j];
    
    queue<pair<vector<vector<int> >, int > > q;
    q.push({a,0});
    while(!q.empty()) {
        vector<vector<int> > x = q.front().first;
        int ix = id(x), dist = q.front().second; q.pop();
        //cout << ix << '\n';
        if (!vis[ix]) {
        if (ix == 362879) {
            cout << dist << '\n';
            break;
        }
        vis[ix]=1;
        F(i,0,2) F(j,0,3) {
            swap(x[i][j], x[i+1][j]);
            q.push({x, dist+1});
            swap(x[i][j], x[i+1][j]);
        }
        F(i,0,3) F(j,0,2) {
            swap(x[i][j], x[i][j+1]);
            q.push({x, dist+1});
            swap(x[i][j], x[i][j+1]);
        }
        }
    }

}