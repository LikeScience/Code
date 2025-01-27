#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

vector<int> a;
vector<pair<int, int> > st;
pair<int, int> m1 = {-2,-2};

void stb (int l, int r, int x) {
    if (l == r) return;
    int m = (l+r)/2;
    stb(l , m, 2*x+1);
    stb(m+1 , r, 2*x+2);
    if (st[2*x+1] != m1) st[x] = st[2*x+1];
    else if (st[2*x+2] != m1) st[x] = st[2*x+2];
    else if (a[l] != a[r]) st[x] = make_pair(l,r);
}

pair<int, int> ste(int l, int r, int dl, int dr, int x) {
    if (l == dl && r == dr) return st[x];
    int m = (l+r)/2;
    if (dr <= m) return ste(l,m,dl,dr,2*x+1);
    else if (dl > m) return ste(m+1,r,dl,dr,2*x+2);
    pair<int, int> p1 = ste(l,m,dl,m,2*x+1), p2 = ste(m+1,r,m+1,dr,2*x+2);
    if (p1 != m1) return p1;
    if (p2 != m1) return p2;
    if (a[m] != a[m+1]) return make_pair(m, m+1);
    return m1;
}

int main() {
    //ios::sync_with_stdio(0); cin.tie(0);
    int t, n, q;
    cin >> t;
    F(z,0,t) {
        cin >> n; a.resize(n);
        st.assign(4*n, m1);
        F(i,0,n) cin >> a[i];
        stb(0,n-1,0);
        cin >> q;
        F(z,0,q) {
            int l, r; cin >> l >> r;
            pair<int, int> p = ste(0, n-1, l-1, r-1, 0);
            cout << p.fi+1 << " " << p.se+1 << '\n';
        }
        cout << '\n';
    }
}