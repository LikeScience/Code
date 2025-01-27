#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int n, sx, sy, ex, ey, pi = 0;
int v[4][4], vi[4][4];
vector<pair<char, int>> p;

void r(int ax, int ay) {
    if (ax == ex && ay == ey) {
        cout << "Path no " << ++pi << ":\n";
        F(i,0,p.size()) cout << p[i].first << p[i].second << '\n';
    }
    for (int i = 1; i <= v[ax][ay]; i++) {
        if (ax+i>n-1) break;
        if (vi[ax+i][ay] || !v[ax+i][ay]) continue;
        p.push_back({'R',i});
        vi[ax+i][ay]=1;
        r(ax+i,ay);
        vi[ax+i][ay]=0;
        p.pop_back();
    }
    for (int i = 1; i <= v[ax][ay]; i++) {
        if (ay+i>n-1) break;
        if (vi[ax][ay+i] || !v[ax][ay+i]) continue;
        p.push_back({'D',i});
        vi[ax][ay+i]=1;
        r(ax,ay+i);
        vi[ax][ay+i]=0;
        p.pop_back();
    }
    for (int i = 1; i <= v[ax][ay]; i++) {
        if (ax-i<0) break;
        if (vi[ax-i][ay] || !v[ax-i][ay]) continue;
        p.push_back({'L',i});
        vi[ax-i][ay]=1;
        r(ax-i,ay);
        vi[ax-i][ay]=0;
        p.pop_back();
    }
     for (int i = 1; i <= v[ax][ay]; i++) {
        if (ay-i<0) break;
        if (vi[ax][ay-i] || !v[ax][ay-i]) continue;
        p.push_back({'U',i});
        vi[ax][ay-i]=1;
        r(ax,ay-i);
        vi[ax][ay-i]=0;
        p.pop_back();
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin >> n;
    
    F(i,0,n) {
        F(j,0,n) {
            cin >> v[j][i];
            vi[i][j]=0;
        }
    }
    cin >> sx >> sy >> ex >> ey;
    vi[sx][sy]=1;
    r(sx, sy);
    
    if (pi == 0) cout << "No path\n";
}