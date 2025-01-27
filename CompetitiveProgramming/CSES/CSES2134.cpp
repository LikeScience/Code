#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
#define f first
#define s second
using namespace std;

int n, cc;
vector<int> eu, fi, v, p, h, sub, c, ch, pos;
vector<pair<int, int> > stl;
vector<vector<int> > al, cl, st;

int dfs1(int x, int pa) {
    sub[x]=1;
    p[x] = pa;
    h[x]=h[pa]+1;
    fi[x] = (int)eu.size();
    eu.push_back(x);
    F(i,0,al[x].size()) {
        if (al[x][i] == pa) continue;
        sub[x]+=dfs1(al[x][i], x);
        eu.push_back(x);
    }
    return sub[x];
}

pair<int, int> lca(int l, int r, int dl, int dr, int x) {
    if (l== dl && r == dr) {
        return stl[x];
    }
    if (dr <= (l+r)/2) {
        return lca(l,(l+r)/2,dl,dr,2*x+1); 
    } else if (dl >= (l+r)/2+1) {
        return lca((l+r)/2+1,r,dl,dr,2*x+2); 
    } else {
        pair<int, int> a = lca(l,(l+r)/2,dl,(l+r)/2,2*x+1), b = lca((l+r)/2+1,r,(l+r)/2+1,dr,2*x+2); 
        return ((a.f < b.f) ? a : b);
    }
}

void stlc(int l, int r, int x) {
    if (l==r) {
        stl[x] = {h[eu[l]], eu[l]};
        return;
    }
    stlc(l,(l+r)/2,2*x+1);
    stlc((l+r)/2+1,r,2*x+2);
    if (stl[2*x+1].f< stl[2*x+2].f) {stl[x] = stl[2*x+1];}
    else stl[x] = stl[2*x+2];
    return;
}

void dfs2(int x, int pa) {
    int id, m=0;
    if (al[x].size() == 1 && x != 1) return;
    F(i,0,al[x].size()) {
        if (al[x][i] == pa) continue;
        if (sub[al[x][i]] > m) {
            m = sub[al[x][i]];
            id = i;
        }
    }
    c[al[x][id]]=cc;
    pos[al[x][id]]=(int)cl[cc].size();
    cl[cc].push_back(al[x][id]);
    dfs2(al[x][id], x);
    F(i,0,al[x].size()) {
        if (al[x][i] == pa || i == id) continue;
        c[al[x][i]]=++cc; 
        pos[al[x][i]]=0;
        ch.push_back(al[x][i]);
        cl.push_back({al[x][i]});
        dfs2(al[x][i], x);
    }
}

void stc(int l, int r, int x, int i) {
    if (l==r) {
        st[i][x] = v[cl[i][l]];
        return;
    }
    stc(l,(l+r)/2,2*x+1, i);
    stc((l+r)/2+1,r,2*x+2, i);
    if (st[i][2*x+1] > st[i][2*x+2]) {st[i][x] = st[i][2*x+1];}
    else st[i][x] = st[i][2*x+2];
}

void stu(int l, int r, int d, int x, int i) {
    if (l==r) {
        st[i][x] = v[cl[i][l]];
        return;
    }
    if (d<= (l+r)/2) {stu(l,(l+r)/2, d, 2*x+1, i);}
    else stu((l+r)/2+1,r,d,2*x+2, i);
    if (st[i][2*x+1] > st[i][2*x+2]) {st[i][x] = st[i][2*x+1];}
    else st[i][x] = st[i][2*x+2];
}

int stf(int l, int r, int dl, int dr, int x, int i) {
    if (l== dl && r == dr) {
        return st[i][x];
    }
    if (dr <= (l+r)/2) {
        return stf(l,(l+r)/2,dl,dr,2*x+1, i); 
    } else if (dl >= (l+r)/2+1) {
        return stf((l+r)/2+1,r,dl,dr,2*x+2, i); 
    } else {
        return max(stf(l,(l+r)/2,dl,(l+r)/2,2*x+1, i), stf((l+r)/2+1,r,(l+r)/2+1,dr,2*x+2, i)); 
    }
}

int fnd(int x, int d) {
    //cout << pos[x] << " " << pos[d] << x << '\n';
    if (c[x] == c[d]) {
        return stf(0,cl[c[x]].size()-1,pos[d], pos[x],0, c[x]);
    }
    return max(stf(0,cl[c[x]].size()-1,0, pos[x],0, c[x]), fnd(p[ch[c[x]]], d));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int q, a, b, x; cc=0;
    cin >> n >> q;
    fi.resize(n+1);
    v.resize(n+1);
    h.assign(n+1,0);
    p.resize(n+1);
    c.resize(n+1);
    al.resize(n+1);
    pos.resize(n+1);
    sub.assign(n+1, 0);
    F(i,1,n+1) cin >> v[i];
    F(i,0,n-1) {
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    sub[1]=dfs1(1,0);
    stl.resize(4*eu.size());
    stlc(0,eu.size()-1, 0);
    ch.push_back(1);
    c[1]=0;
    cl.push_back({1});
    pos[1]=0;
    dfs2(1,0);
    F(i,0,cc+1) {
        st.push_back(vector<int>(4*cl[i].size()));
        stc(0,cl[i].size()-1,0, i);
    }
    
    vector<int> o;
    F(i,0,q) {
        cin >> x >> a >> b;
        if (x == 1) {
            v[a]=b;
            stu(0,cl[c[a]].size()-1,pos[a],0,c[a]);
        /*F(i,0,cc+1) {
        F(j,0,cl[i].size()) cout << cl[i][j] << " ";
        cout << "||";
        F(j,0,cl[i].size()) cout << v[cl[i][j]] << " ";
        cout << '\n';
        F(j,0,st[i].size()) cout << st[i][j] << " ";
        cout << '\n';
    }*/
        } else {
            int lc=lca(0, eu.size()-1, min(fi[a],fi[b]), max(fi[a],fi[b]), 0).s;
            //cout << lc << '\n';
            if (lc==a) {
                o.push_back(fnd(b,lc));
            } else if(lc==b) {
                o.push_back(fnd(a, lc));
            } else {
                o.push_back(max(fnd(a,lc), fnd(b, lc)));
            }
        }
    }
    cout << o[0];
    F(i,1,o.size()) cout << " " << o[i];
    cout << '\n';
}