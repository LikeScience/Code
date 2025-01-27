#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;
#include <chrono>
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();
    ios::sync_with_stdio(0); cin.tie(0);
    int c, r, t;
    cin >> r >> c >> t;
    vector<vector<char> > mp(r, vector<char>(c));
    F(i,0,r) F(j,0,c) cin >> mp[i][j];
    vector<vector<vector<vector<int> > > > idx(r, vector<vector<vector<int> > > (c, vector<vector<int> > (2))); // 0-> horiz 1 -> vert
    vector<vector<vector<vector<vector<int> > > > > al(r, vector<vector<vector<vector<int> > > > (c, vector<vector<vector<int> > >(2)));
    vector<vector<int> > h(2);
    F(i,0,r) {
        int x = 0;
        bool obs = 0;
        F(j,0,c) {
            if (mp[i][j] == 'O') obs = 1;
            if (mp[i][j] == '.' || mp[i][j] == 'H') {
                if (obs) {
                    x = j;
                    idx[i][j][0] = {i,j,0};
                } else {
                    idx[i][j][0] = {i,x,0};
                }
                obs = 0;
            }
            if (mp[i][j] == 'H') h[0] = idx[i][j][0];
        }
    }
    F(j,0,c) {
        int x = 0;
        bool obs = 0;
        F(i,0,r) {
            if (mp[i][j] == 'O') obs = 1;
            if (mp[i][j] == '.' || mp[i][j] == 'H') {
                if (obs) {
                    x = i;
                    idx[i][j][1] = {i,j,1};
                } else {
                    idx[i][j][1] = {x,j,1};
                }
                obs = 0;
            }
            if (mp[i][j] == 'H') h[1] = idx[i][j][1];
        }
    }
    F(i,0,r) {
        F(j,1,c) {
            if ((mp[i][j] == '.' || mp[i][j] == 'H') && mp[i][j-1] == 'O') {
                al[idx[i][j][0][0]][idx[i][j][0][1]][idx[i][j][0][2]].push_back(idx[i][j][1]);
            }
            if ((mp[i][j-1] == '.' || mp[i][j-1] == 'H') && mp[i][j] == 'O') {
                al[idx[i][j-1][0][0]][idx[i][j-1][0][1]][idx[i][j-1][0][2]].push_back(idx[i][j-1][1]);
            }
        }
    }
    F(j,0,c) {
        F(i,1,r) {
            if ((mp[i][j] == '.' || mp[i][j] == 'H') && mp[i-1][j] == 'O') {
                al[idx[i][j][1][0]][idx[i][j][1][1]][idx[i][j][1][2]].push_back(idx[i][j][0]);
            }
            if ((mp[i-1][j] == '.' || mp[i-1][j] == 'H') && mp[i][j] == 'O') {
                al[idx[i-1][j][1][0]][idx[i-1][j][1][1]][idx[i-1][j][1][2]].push_back(idx[i-1][j][0]);
            }
        }
    }
   
    F(z,0,t) {
        vector<vector<vector<bool> > > vis(r, vector<vector<bool > > (c, vector<bool> (2,0)));
        int mn = 1000000000;
        int ri, ci;
        cin >> ri >> ci; ri--; ci--;
        if (mp[ri][ci] == 'O') {cout << "DJUADIA" << '\n'; continue;}
        queue<pair<vector<int>, int> > q;
        q.push({idx[ri][ci][0], 1});
        while (!q.empty()) {
            vector<int> x = q.front().first; int k = q.front().second;
            q.pop();
            if (!vis[x[0]][x[1]][x[2]]) {
                //cout << x[0] << " " << x[1] << " " << x[2] << '\n';
                vis[x[0]][x[1]][x[2]] = 1;
                if (x == h[0] || x == h[1]) {mn = k; break;}
                F(i,0,(int)al[x[0]][x[1]][x[2]].size()) q.push({al[x[0]][x[1]][x[2]][i],k+1});
            }
        }
        while(!q.empty()) q.pop();
        vis.assign(r, vector<vector<bool > > (c, vector<bool> (2,0)));
        q.push({idx[ri][ci][1], 1});
        while (!q.empty()) {
            vector<int> x = q.front().first; int k = q.front().second;
            q.pop();
            if (!vis[x[0]][x[1]][x[2]]) {
                //cout << x[0] << " " << x[1] << " " << x[2] << '\n';
                vis[x[0]][x[1]][x[2]] = 1;
                if (x == h[0] || x == h[1]) {mn = min(k,mn); break;}
                F(i,0,(int)al[x[0]][x[1]][x[2]].size()) q.push({al[x[0]][x[1]][x[2]][i],k+1});
            }
        }
        if (mn == 1000000000) {
            cout << "Stuck" << '\n';
        } else cout << mn << '\n';
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << '\n';
}