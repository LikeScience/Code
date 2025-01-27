#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
#define f first
#define s second
using namespace std;

int l, c, d, ccc;
vector<int> cc;
vector<set<pair<int, int> > > m;
vector<vector<int> > v, vi;

void dfs(int y, int x, int k) {
    if (v[y][x]>0) {
        cc[v[y][x]]=ccc;
        m[ccc].insert({1, v[y][x]});
        k=d;
    }
    vi[y][x]=k;
    if (k==0) return;
    if (x+1< c && v[y][x+1] != -1 && vi[y][x+1] < k-1) dfs(y,x+1,k-1); //R
    if (y+1< l && v[y+1][x] != -1 && vi[y+1][x] < k-1) dfs(y+1,x,k-1); //D
    if (x-1>=0 && v[y][x-1] != -1 && vi[y][x-1] < k-1) dfs(y,x-1,k-1); //L
    if (y-1>=0 && v[y-1][x] != -1 && vi[y-1][x] < k-1) dfs(y-1,x,k-1); //U
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int q, t=0, ti, qi, o; ccc=0;
    char z;
    cin >> l >> c >> d;
    vector<pair<int, int> > T(1);
    v.assign(l, vector<int>(c));
    vi.assign(l, vector<int>(c, -1));
    F(i,0,l) F(j,0,c) {
        cin >> z;
        if (z == '.') {
            v[i][j]=0;
        } else if (z == '#') {
            v[i][j]=-1;
        } else {
            v[i][j]= ++t;
            T.push_back({i,j});
        }
    } 
    cc.resize(t+1);
    vector<int> w(t+1,1);
    F(i,1,t+1) if (vi[T[i].f][T[i].s] == -1) {
        m.push_back(set<pair<int, int> >());
        dfs(T[i].f,T[i].s, d);
        ccc++; 
    }
    o=ccc;
    cin >> q;
    F(i,0,q) {
        cin >> ti >> qi;
        o-=m[cc[ti]].begin()->f;
        m[cc[ti]].erase({w[ti], ti});
        m[cc[ti]].insert({qi, ti});
        o+=m[cc[ti]].begin()->f;
        w[ti] = qi;
        cout << o << '\n';
    }
}