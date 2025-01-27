#include <bits/stdc++.h>
#define F(i,s,e) for (int i =s; i<e; i++)
#define ll long long
using namespace std;

int n;
vector<ll> st, a, p, sp;

void stb(int l, int r, int x) {
    if (l==r) {
        st[x] = (sp[l]-(sp[n]-sp[l+1]))*a[l]; 
        return;
    }
    stb(l,(l+r)/2,2*x+1);
    stb((l+r)/2+1,r,2*x+2);
    return;
}

void stu(int l, int r, int dl, int dr, int x, ll u) {
    if (l==dl && r == dr) {
        st[x] += u;
        return;
    } int m = (l+r)/2;
    if (dr <= m) {stu(l,m,dl,dr,2*x+1,u);}
    else if (dl >= m+1) {stu(m+1,r,dl,dr,2*x+2,u);}
    else {
        stu(l,m,dl,m,2*x+1,u);
        stu(m+1,r,m+1,dr,2*x+2,u);
    }
    return;
}

ll ste (int l, int r, int x, int i) {
    if (l==r) {
        return st[x];
    }
    if (i <= (l+r)/2) return st[x] + ste(l,(l+r)/2,2*x+1,i);
    else return st[x] + ste((l+r)/2+1,r,2*x+2,i);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    st.assign(4*n,0); a.resize(n); p.resize(n); sp.resize(n+1);
    sp[0] = 0;
    F(i,0,n) cin >> a[i];
    F(i,0,n) {cin >> p[i]; sp[i+1] = sp[i] + p[i];}
    stb(0,n-1,0);
    F(i,0,n) {
        if (i>0) stu(0,n-1,0,i-1,0,p[i]*a[i]);
        if (i<n-1) stu(0,n-1,i+1,n-1,0,-p[i]*a[i]);
    }
    ll t = 1e18+7, id = -1;
    F(i,0,n) {
        ll x = ste(0,n-1,0,i);
        if (id == -1 || x < t) {
            t = x;
            id = i;
        }
    }
    cout << id << '\n';
}