#include <bits/stdc++.h>
#define F(i,s,e) for (int i= s; i<e; i++)
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
using namespace std;

int n, m, ai, bi, ci, mc=0, MAXN= 1e5+1, MAXL, ps;
vector<int> dth, pth, fr, par, T, st;
vector<vector<int> > al;
vector<vector<pair<int, map<int, bool> > > > v;

void dfs1(int x) {
    pth.push_back(x);if (x != 1) dth[x] = dth[par[x]]+1;
    v[x][0].se[T[x]] =1;
    v[x][0].fi = x;
    if (x != 1) {
        v[x][1].se = v[x][0].se;
        v[x][1].se[T[par[x]]] = 1;
        v[x][1].fi = par[x];
        for (int i = 2; 1<<(i-1) <= dth[x]; i++) {
            v[x][i].fi = v[v[x][i-1].fi][i-1].fi;
            v[x][i].se = v[x][i-1].se;
            for (auto as : v[v[x][i-1].fi][i-1].se) {
                v[x][i].se[as.first] = 1;
            }
        }
    }
    fr[x] = (int)pth.size()-1;
    
    F(i,0,(int)al[x].size()) if (fr[al[x][i]] == -1) {
        par[al[x][i]] = x;
        dfs1(al[x][i]);
        pth.push_back(x);
    }
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

bool fb(int x, int a, int c) {
    //cout << x << " " << a << '\n';
    //F(i,0,mc+1) cout << v[x][0].se[i];
    //cout << '\n';
    if (x == a) return v[x][0].se[c];
    for (int i = MAXL-1; i>=1;i--)if ((1<<(i-1)) <= dth[x]) {
        if (dth[v[x][i].fi] >= dth[a]) {
            //cout << x << " " << i << " " << v[x][i].fi << " " << v[x][i].se[c]<< '\n';
            return v[x][i].se[c] | fb(v[x][i].fi, a, c);
        }
    }
    return 0;
}

int main() {
    fstream fin("milkvisits.in", fstream::in);
    fin >> n >> m;
    al.resize(n+1);
    vector<pair<pii, int> > q(m);
    MAXL = int(log2(n))+1;
    v.assign(n+1, vector<pair<int, map<int, bool> > >(MAXL));
    dth.assign(n+1, -1); fr.assign(n+1, -1); par.assign(n+1, -1); T.resize(n+1);
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
        int lca = ste(0,ps-1,min(fr[q[i].fi.fi], fr[q[i].fi.se]),max(fr[q[i].fi.fi], fr[q[i].fi.se]), 0 );
        //cout << lca << '\n';
        bool a = fb(q[i].fi.fi, lca,q[i].se ), b =fb(q[i].fi.se, lca, q[i].se);
        fout << (a || b);
    }
    fout << '\n';
    
}