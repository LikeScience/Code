#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i != e; i++)
#define ll long long 

using namespace std;

struct qe {
    int x;
    int y;
    ll d;
};

ll MX = 1000000000000000000;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, m, z;
    ll w, a, d = -1, pt = MX, p0t = MX;
    cin >> n >> m >> w;
    int v[n][m];
    
    F(i,0,n) F(j,0,m) {
        cin >> v[i][j]; 
        
    }
    short vi[n][m] = {};
    queue<qe> q;
    q.push({0,0,0});
    vi[0][0] = 1;
    while(!q.empty()) {
        qe h = q.front();
        q.pop();
        //cout << h.x << " " << h.y << " " << h.d << '\n';
        if (v[h.x][h.y] != 0) {
            a = h.d+(ll)v[h.x][h.y];
            if (a < pt) pt = a;
        }
        if (h.x == n-1 && h.y == m-1) {
            d = h.d;
        }
        if (h.x != 0 && !vi[h.x-1][h.y] && v[h.x-1][h.y] != -1) {
            vi[h.x-1][h.y] = 1;
            q.push({h.x-1, h.y, h.d+w});
        }
        if (h.x != n-1 && !vi[h.x+1][h.y] && v[h.x+1][h.y] != -1) {
            vi[h.x+1][h.y] = 1;
            q.push({h.x+1, h.y, h.d+w});
        }
        if (h.y != 0 && !vi[h.x][h.y-1] && v[h.x][h.y-1] != -1) {
            vi[h.x][h.y-1] = 1;
            q.push({h.x, h.y-1, h.d+w});
        }
        if (h.y != m-1 && !vi[h.x][h.y+1]&& v[h.x][h.y+1] != -1) {
            vi[h.x][h.y+1] = 1;
            q.push({h.x, h.y+1, h.d+w});
        }
    }
    q.push({n-1,m-1,0});
    //cout << pt << " " << d << '\n';
    vi[n-1][m-1]=2;
    while(!q.empty()) {
        qe h = q.front();
        q.pop();
        if (v[h.x][h.y] != 0) {
            a = h.d+(ll)v[h.x][h.y];
            if (a < p0t) p0t = a;
        }
        if (h.x != 0 && vi[h.x-1][h.y] != 2 && v[h.x-1][h.y] != -1) {
            vi[h.x-1][h.y] = 2;
            q.push({h.x-1, h.y, h.d+w});
        }
        if (h.x != n-1 && vi[h.x+1][h.y] !=2 && v[h.x+1][h.y] != -1) {
            vi[h.x+1][h.y] = 2;
            q.push({h.x+1, h.y, h.d+w});
        }
        if (h.y != 0 && vi[h.x][h.y-1] != 2 && v[h.x][h.y-1] != -1) {
            vi[h.x][h.y-1] = 2;
            q.push({h.x, h.y-1, h.d+w});
        }
        if (h.y != m-1 && vi[h.x][h.y+1] !=2 && v[h.x][h.y+1] != -1) {
            vi[h.x][h.y+1] = 2;
            q.push({h.x, h.y+1, h.d+w});
        }
    }
    //cout << p0t << '\n';
    
    cout << (d == -1 ? ((pt == MX || p0t == MX) ? -1 : pt+p0t) : ( (pt == MX || p0t == MX) ? d : (d < pt + p0t ? d : pt + p0t))) << '\n';
}