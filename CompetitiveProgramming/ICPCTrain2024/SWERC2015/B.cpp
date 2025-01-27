#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++) 
#define vi vector<int>  
using namespace std;

vector<vi> perms;
vi path;
vi cl1, cl2;

bool bipartite(vector<vi> edg) {
    cl1.assign(n,0); cl1.assign(n,0);
    for (vi x : edge) {
        
    }
}

void gen(int x, int o) {
    if (x == 26 && o == 3) {
        perms.push_back(path);
        return;
    }
    if (o<3 && 26-x>=3-o) {
        path.push_back(1);
        gen(x+1,o+1);
        path.pop_back();
    }
    if (25-x >= 3-o) {
        path.push_back(0);
        gen(x+1,o);
        path.pop_back();
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x, y, a, b; cin >> n;
    vector<vi> v(26, vi(3, 1)); char c1, c2;
    vector<vi> ones, no;
    F(i,0,n) {
        cin >> c1 >> c2 >> x >> y;
        a = c1 - 'A'; b = c2 - 'A';
        if (y == 2) {
            v[a][0] = v[b][0] = v[a][-x+3] = v[b][-x+3] = 0; // -x+3 is 1 when x=2 and 2 when x=1 
        } else if (y == 0) {
            v[a][x] = v[b][x] = 0;
        } else {
            vi tmp = {a, b, x};
            ones.push_back(tmp);
        }
    } bool r = 1;
    while (r) {
        r = 0;
        for (vi i : ones) {
            x = i[2]; y = -x+3;
            if (!(v[i[0]][0] || v[i[0]][y])) v[i[1]][x] = 0;
            if (!(v[i[1]][0] || v[i[1]][y])) v[i[0]][x] = 0;
            if (v[i[0]][x] && v[i[1]][x]) {
                no.push_back(i);
            } else {
                r = 1;
                if (v[i[0]][x] == 0) v[i[1]][0] = v[i[1]][y] = 0; 
                if (v[i[1]][x] == 0) v[i[0]][0] = v[i[0]][y] = 0; 
            }
        }
        ones = no; no.clear();
    }
    F(i,0,3) F(j,0,3) cout << v[i][j] << " \n"[j==2]; 
    int cnt = 0; 
    gen(0,0);
    vector<vi> apag;
    for (vi p : perms) {
        vector<vi> c = v, on = ones;
         no.clear();
        F(i,0,26) {
            if (p[i]) {
                c[i][1] = c[i][2] = 0;
            } else c[i][0] = 0;
        }
        bool r = 1;
        while (r) {
            r = 0;
            for (vi i : on) {
                x = i[2]; y = -x+3;
                if (!(c[i[0]][0] || c[i[0]][y])) c[i[1]][x] = 0;
                if (!(c[i[1]][0] || c[i[1]][y])) c[i[0]][x] = 0;
                if (c[i[0]][x] && c[i[1]][x]) {
                    no.push_back(i);
                } else {
                    r = 1;
                    if (c[i[0]][x] == 0) c[i[1]][0] = c[i[1]][y] = 0; 
                    if (c[i[1]][x] == 0) c[i[0]][0] = c[i[0]][y] = 0; 
                }
            }
            on = no; no.clear();
        }
        bool bb = 0;
        F(i,0,26) if (c[i][0] == c[i][1] && c[i][1] == c[i][2] && !c[i][2]) {bb = 1; break;}
        if (bb) continue;
        {cnt++; apag.push_back(p);}
    }
    F(i,0,5) F(j,0,26) cout << apag[i][j] << " \n"[j==25]; 
    cout << cnt << '\n';
}