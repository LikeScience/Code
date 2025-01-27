#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++) 
using namespace std;

int c, cc;
vector<int> r;
vector<int> par;
vector<int> d;

int valid (int a, int b) {
    if (a == 0) return 0;
    if (d[b] > d[a]) return int(par[b] == a);
    return valid(a/2,b);
} int valiid (int a) {
    return r[2*a] >= r[a] && r[2*a+1] > r[a];
}

int main() {
    int t, n, q, x, y;
    cin >> t;
    F(z,0,t) {
        cin >> n >> q;
        vector<int> p(n), v(n+1,0), vv(n+1,0);
        d.resize(n+1), par.resize(n+1); r.assign(4*n+4,1e9);
        d[1]=0; par[1]=0; r[1]=-1;
        F(i,2,n+1) {
            cin >> par[i];
            d[i] = d[par[i]]+1;
        }
        F(i,0,n) cin >> p[i];
        F(i,0,n) r[p[i]] = i;
        c = v[0] = int(p[0]==1); cc=0;
        F(i,0,n-1) {
            v[i+1] = valid(p[i],p[i+1]);
            c+=v[i+1];
        }
        F(i,1,n+1) {
            vv[i] = valiid(i);
            cc+= vv[i];
        }
        F(i,0,q) {
            cin >> x >> y; x--;y--;
            if (x>y) swap(x,y);
            swap(p[x],p[y]);
            r[p[x]] = x; r[p[y]] = y;
            c -= v[x] + v[x+1] + v[y] + v[y+1];
            if (y == x+1 && v[x+1]==1) c++;
            cc -= vv[p[x]] + vv[par[p[x]]] + vv[p[y]] + vv[par[p[y]]];
            if (p[y] == par[p[x]] && vv[p[y]]==1) cc++;
            if (p[x] == par[p[y]] && vv[p[x]]==1) cc++;
            if (x == 0) v[x] = (p[0]==1);
            else v[x] = valid(p[x-1],p[x]);
            vv[p[x]] = valiid(p[x]);
            if (p[x] != 1) vv[par[p[x]]] = valiid(par[p[x]]);
            vv[p[y]] = valiid(p[y]);
            if (p[y] != 1) vv[par[p[y]]] = valiid(par[p[y]]);
            v[x+1] = valid(p[x],p[x+1]);
            v[y] = valid(p[y-1],p[y]);
            if (y <n-1) v[y+1] = valid(p[y],p[y+1]);
            c += v[x] + v[x+1] + v[y] + v[y+1];
            if (y == x+1 && v[x+1]==1) c--;
            if (p[y] == par[p[x]] && vv[p[y]]==1) cc--;
            if (p[x] == par[p[y]] && vv[p[x]]==1) cc--;
            cc += vv[p[x]] + vv[par[p[x]]] + vv[p[y]] + vv[par[p[y]]];
            cout << ((c==n && cc == n) ? "YES\n" : "NO\n");
            //F(i,0,n+1) cout << v[i] << " " << vv[i] << '\n';
            //cout << c << " e " << cc << '\n'; 
        }
    }
}