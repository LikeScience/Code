#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
#define f first
#define s second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int q, t=0, ti, qi, o, l, c, d, ccc=0, y, x, k;
    vector<set<pair<int, int> > > m;
    char z;
    cin >> l >> c >> d;
    queue<pair<pair<int, int>, int > > b;
    int v[l][c], vi[l][c];
    vector<pair<int, int> > T(1);
    F(i,0,l) F(j,0,c) {
        cin >> z;
        vi[i][j]=-1;
        if (z == '.') {
            v[i][j]=0;
        } else if (z == '#') {
            v[i][j]=-1;
        } else {
            v[i][j]= ++t;
            T.push_back({i,j});
        }
    } 
    int cc[t+1], w[t+1];
    F(i,1,t+1) w[i]=1;
    F(i,1,t+1) {if (vi[T[i].f][T[i].s] == -1) {
        m.push_back(set<pair<int, int> >());
        b.push({{T[i].f,T[i].s}, d});
        while(!b.empty()) {
            y = b.front().f.f; x = b.front().f.s; k= b.front().s; b.pop();
            if (k <= vi[y][x]) continue;
            if (v[y][x]>0) {
                cc[v[y][x]]=ccc;
                m[ccc].insert({1, v[y][x]});
                k=d;
            }
            vi[y][x]=k;
            if (k==0) continue;
            if (x+1< c && v[y][x+1] != -1 && vi[y][x+1] < k-1) b.push({{y,x+1},k-1}); //R
            if (y+1< l && v[y+1][x] != -1 && vi[y+1][x] < k-1) b.push({{y+1,x},k-1}); //D
            if (x-1>=0 && v[y][x-1] != -1 && vi[y][x-1] < k-1) b.push({{y,x-1},k-1}); //L
            if (y-1>=0 && v[y-1][x] != -1 && vi[y-1][x] < k-1) b.push({{y-1,x},k-1}); //U
        }
        ccc++; 
    }}
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