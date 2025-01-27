#include <bits/stdc++.h>
#define F(i,s,e) for (int i=s; i<e; i++)
#define ll long long
using namespace std;

vector<int> st, pt, f, dt, pa;
vector<vector<int> > al;

void dfs(int x) {
    f[x] = (int)pt.size();
    if (x != 1) dt[x] = dt[pa[x]]+1;
    pt.push_back(x);
    F(i,0,(int)al[x].size()) {
        dfs(al[x][i]);
        pt.push_back(x);
    }
    return;
}

void stc(int l, int r, int x) {
    if (l == r) {
        st[x] = pt[l];
        return;
    }
    stc(l, (l+r)/2, 2*x+1);
    stc((l+r)/2+1,r, 2*x+2);
    if (dt[st[2*x+1]] < dt[st[2*x+2]]) {
        st[x] = st[2*x+1];
    } else st[x] = st[2*x+2];
    return;
}

int stf(int l, int r, int dl, int dr, int x) {
    if (l == dl && r == dr) {
        return st[x];
    } int m = (l+r)/2;
    if (dr <= m) {return stf(l, m, dl, dr, 2*x+1);}
    else if (dl >= m+1){return stf(m+1, r, dl, dr, 2*x+2);}
    else {
        int a = stf(l, m, dl, m, 2*x+1), b = stf(m+1, r, m+1, dr, 2*x+2);
        if (dt[a] < dt[b]) return a;
        else return b;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int p, n, q, a, b, c, d;
    cin >> p >> n >> q;
    pa.resize(n+1);
    al.resize(n+1);
    F(i,0,n-1) {
        cin >> a >> b;
        pa[b] = a;
        al[a].push_back(b);
    }
    if (p == 1) {
        vector<int> v(n+1); v[1] = 0;
        queue<int> qu; qu.push(1);
        while (!qu.empty()) {
            int x = qu.front(); qu.pop();
            if (x != 1) v[x] = v[pa[x]]+1;
            F(i,0,(int)al[x].size()) qu.push(al[x][i]);
        }
        F(i,0,q) {
            cin >> c;
            cout << v[c] << '\n';
        }
    } else if (p==2) { 
        st.resize(8*n); f.resize(n+1); dt.resize(n+1);
        dt[1] = 0;
        dfs(1);
    
        stc(0, (int)pt.size()-1, 0);
        
        F(i,0,q) {
            cin >> c >> d;
            cout << stf(0,(int)pt.size()-1,min(f[c],f[d]), max(f[c], f[d]),0) << '\n';
        }
    }
}