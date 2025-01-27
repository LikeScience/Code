#include <bits/stdc++.h>
#define F(i,s,e) for (int i= s; i<e; i++)
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
using namespace std;

int n, m, ai, bi, ci, mc=0, ps;
vector<int> dth, pth, fr, par, T, st, las, ans, lca;
vector<vector<int> > al, vis, li;
vector<pair<pii, int> > q;


void dfs1(int x) {
    pth.push_back(x);if (x != 1) dth[x] = dth[par[x]]+1;
    fr[x] = (int)pth.size()-1;
    
    F(i,0,(int)al[x].size()) if (fr[al[x][i]] == -1) {
        par[al[x][i]] = x;
        dfs1(al[x][i]);
        pth.push_back(x);
    }
    las[x] = (int)pth.size()-1;
}
void stb(int l, int r, int x) {
    if (l == r) {
        st[x] = pth[l]; 
        return;
    } int m = (l+r)/2;
    stb(l, m, 2*x+1);
    stb( m+1,r, 2*x+2);
    if (dth[st[2*x+1]] < dth[st[2*x+2]]) {
        st[x] = st[2*x+1];
    } else st[x] = st[2*x+2];
}

int ste(int l, int r, int dl, int dr, int x) {
     if (l == dl && r == dr) {
        return st[x];
    } int m = (l+r)/2;
    if (dr <= m)  {return ste(l, m, dl, dr, 2*x+1);}
    else if (dl >= m+1)  {return ste(m+1, r, dl, dr, 2*x+2);}
    else {
        int a = ste(l, m, dl, m, 2*x+1), b = ste(m+1, r, m+1, dr, 2*x+2);
        if (dth[a] < dth[b]) {return a;}
        else return b;
    }
}

void dfs2(int x) {
    li[T[x]].push_back(x);
    F(i,0,(int)vis[x].size()) {
        int v = vis[x][i];
        if (!li[q[v].se].empty()) {
            int y; if (x == q[v].fi.fi) {y = q[v].fi.se;}
            else y = q[v].fi.fi;
            int z = li[q[v].se][li[q[v].se].size()-1];
             if (!(fr[z] < fr[y] && las[y] < las[z])) ans[v] = 1;
             else if (z == lca[v])ans[v] = 1;
        }
       
    }
    F(i,0,(int)al[x].size( )) if (al[x][i] != par[x]) dfs2(al[x][i]);
    li[T[x]].pop_back();
}

int main() {
    fstream fin("milkvisits.in", fstream::in);
    fin >> n >> m;
    al.resize(n+1);
    q.resize(m);
    dth.assign(n+1, -1); fr.assign(n+1, -1); par.assign(n+1, -1); T.resize(n+1), las.assign(n+1,0); ans.assign(m, 0); vis.resize(n+1); lca.resize(m); li.resize(n);
    F(i,1,n+1) fin >> T[i];
    F(i,0,n-1) {
        fin >> ai >> bi;
        al[ai].push_back(bi);
        al[bi].push_back(ai);
    }
    
    F(i,0,m) {
        fin >> ai >> bi >> ci;
        mc = max(mc, ci);
        q[i] = mp(mp(ai,bi), ci);
    }fin.close();
    dth[1] = 0;
    dfs1(1);
    ps = (int)pth.size();
    st.assign(4*ps,0);
    stb(0, ps-1, 0);
    fstream fout("milkvisits.out", fstream::out);
    F(i,0,m) {
        lca[i] = ste(0,ps-1,min(fr[q[i].fi.fi], fr[q[i].fi.se]),max(fr[q[i].fi.fi], fr[q[i].fi.se]), 0 );
        //cout << lca[i] << '\n';
        vis[q[i].fi.fi].push_back(i);
        vis[q[i].fi.se].push_back(i);
    }
    dfs2(1);
    F(i,0,m) fout << ans[i];
    fout << '\n';
    
}