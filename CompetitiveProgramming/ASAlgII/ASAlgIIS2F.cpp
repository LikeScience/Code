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
    int n, m, z;
    ll w, a, d = -1, pt = MX, p0t = MX;
    cin >> n >> m >> w;
    vector<vector<int> > v(n);
    
    F(i,0,n) F(j,0,m) {
        cin >> z; 
        v[i].push_back(z);
    }
    vector<vector<bool> > vi(n, vector<bool> (m,0));
    queue<qe> q;
    q.push({0,0,0});
    vi[0][0] = 1;
    while(q.size() != 0) {
        qe h = q.front();
        q.pop();
        //cout << h.x << " " << h.y << " " << h.d << '\n';
        if (v[h.x][h.y] != 0) {
            a = h.d*w+(ll)v[h.x][h.y];
            if (a < pt) pt = a;
        }
        if (h.x == n-1 && h.y == m-1) {
            d = h.d;
        }
        if (h.x != 0 && !vi[h.x-1][h.y] && v[h.x-1][h.y] != -1) {
            vi[h.x-1][h.y] = 1;
            q.push({h.x-1, h.y, h.d+1});
        }
        if (h.x != n-1 && !vi[h.x+1][h.y] && v[h.x+1][h.y] != -1) {
            vi[h.x+1][h.y] = 1;
            q.push({h.x+1, h.y, h.d+1});
        }
        if (h.y != 0 && !vi[h.x][h.y-1] && v[h.x][h.y-1] != -1) {
            vi[h.x][h.y-1] = 1;
            q.push({h.x, h.y-1, h.d+1});
        }
        if (h.y != m-1 && !vi[h.x][h.y+1]&& v[h.x][h.y+1] != -1) {
            vi[h.x][h.y+1] = 1;
            q.push({h.x, h.y+1, h.d+1});
        }
    }
    q.push({n-1,m-1,0});
    //cout << pt << " " << d << '\n';
    vi.assign(n, vector<bool>(m, 0));
    vi[n-1][m-1]=1;
    while(q.size() != 0) {
        qe h = q.front();
        q.pop();
        if (v[h.x][h.y] != 0) {
            a = h.d*w+(ll)v[h.x][h.y];
            if (a < p0t) p0t = a;
        }
        if (h.x != 0 && !vi[h.x-1][h.y] && v[h.x-1][h.y] != -1) {
            vi[h.x-1][h.y] = 1;
            q.push({h.x-1, h.y, h.d+1});
        }
        if (h.x != n-1 && !vi[h.x+1][h.y] && v[h.x+1][h.y] != -1) {
            vi[h.x+1][h.y] = 1;
            q.push({h.x+1, h.y, h.d+1});
        }
        if (h.y != 0 && !vi[h.x][h.y-1] && v[h.x][h.y-1] != -1) {
            vi[h.x][h.y-1] = 1;
            q.push({h.x, h.y-1, h.d+1});
        }
        if (h.y != m-1 && !vi[h.x][h.y+1] && v[h.x][h.y+1] != -1) {
            vi[h.x][h.y+1] = 1;
            q.push({h.x, h.y+1, h.d+1});
        }
    }
    //cout << p0t << '\n';
    a = d*w;
    cout << (d == -1 ? ((pt == MX || p0t == MX) ? -1 : pt+p0t) : ( (pt == MX || p0t == MX) ? a : (a < pt + p0t ? a : pt + p0t))) << '\n';
}