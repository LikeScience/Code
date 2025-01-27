#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;
//#include <chrono>
//using namespace std::chrono;

int main() {
    //auto start = high_resolution_clock::now();
    ios::sync_with_stdio(0); cin.tie(0);
    int c, r, t;
    cin >> r >> c >> t;
    char mp[r][c];
    F(i,0,r) F(j,0,c) cin >> mp[i][j];
    int idx[r][c][2]; // 0-> horiz 1 -> vert
    vector<vector<int> > al;
    int h[2];
    int cnt=-1;
    F(i,0,r) {
        bool obs = 1;
        F(j,0,c) {
            if (mp[i][j] == 'O') obs = 1;
            if (mp[i][j] == '.' || mp[i][j] == 'H') {
                if (obs) {
                    idx[i][j][0] = ++cnt;
                    al.push_back({});
                } else {
                    idx[i][j][0] = cnt;
                }
                obs = 0;
            }
            if (mp[i][j] == 'H') h[0] = idx[i][j][0];
        }
    }
    F(j,0,c) {
        bool obs = 1;
        F(i,0,r) {
            if (mp[i][j] == 'O') obs = 1;
            if (mp[i][j] == '.' || mp[i][j] == 'H') {
                if (obs) {
                    idx[i][j][1] = ++cnt;
                    al.push_back({});
                } else {
                    idx[i][j][1] = cnt;
                }
                obs = 0;
            }
            if (mp[i][j] == 'H') h[1] = idx[i][j][1];
        }
    }
    F(i,0,r) {
        F(j,1,c) {
            if ((mp[i][j] == '.' || mp[i][j] == 'H') && mp[i][j-1] == 'O') {
                al[idx[i][j][0]].push_back(idx[i][j][1]);
            }
            if ((mp[i][j-1] == '.' || mp[i][j-1] == 'H') && mp[i][j] == 'O') {
                al[idx[i][j-1][0]].push_back(idx[i][j-1][1]);
            }
        }
    }
    F(j,0,c) {
        F(i,1,r) {
            if ((mp[i][j] == '.' || mp[i][j] == 'H') && mp[i-1][j] == 'O') {
                al[idx[i][j][1]].push_back(idx[i][j][0]);
            }
            if ((mp[i-1][j] == '.' || mp[i-1][j] == 'H') && mp[i][j] == 'O') {
                al[idx[i-1][j][1]].push_back(idx[i-1][j][0]);
            }
        }
    }
    F(z,0,t) {
        vector<bool> vis(cnt+1);
        int mn = 1000000000;
        int ri, ci;
        cin >> ri >> ci; ri--; ci--;
        //if (mp[ri][ci] == 'O') {cout << "DJUADIA" << '\n'; continue;}
        queue<pair<int, int> > q;
        q.push({idx[ri][ci][0], 1});
        while (!q.empty()) {
            int x = q.front().first; int k = q.front().second;
            q.pop();
            if (!vis[x]) {
                vis[x] = 1;
                if (x == h[0] || x == h[1]) {mn = k; break;}
                F(i,0,(int)al[x].size()) q.push({al[x][i],k+1});
            }
        }
        while(!q.empty()) q.pop();
        vis.assign(cnt+1,0);
        q.push({idx[ri][ci][1], 1});
        while (!q.empty()) {
            int x = q.front().first; int k = q.front().second;
            q.pop();
            if (!vis[x]) {
                vis[x] = 1;
                if (x == h[0] || x == h[1]) {mn = min(k,mn); break;}
                F(i,0,(int)al[x].size()) q.push({al[x][i],k+1});
            }
        }
        if (mn == 1000000000) {
            cout << "Stuck" << '\n';
        } else cout << mn << '\n';
    }
    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start);
    //cout << duration.count() << '\n';
}