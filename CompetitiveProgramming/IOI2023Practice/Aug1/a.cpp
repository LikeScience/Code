#include <bits/stdc++.h>
#define ll long long
#define F(i,x,e) for (ll i = x; i<e; i++)
using namespace std;

vector<ll> st;

void stu(ll l, ll r, ll dl, ll dr, ll x, ll v) {
    if (l == dl && r == dr) {
        st[x] += v;
        return;
    } ll m = (l+r)/2;
    if (dr <= m) {
        stu(l,m,dl,dr,2*x+1,v);
    } else if (dl >= m+1) {
        stu(m+1,r,dl,dr,2*x+2,v);
    } else {
        stu(l,m,dl,m,2*x+1,v);
         stu(m+1,r,m+1,dr,2*x+2,v);
    }
    return;
} 

ll ste(ll l, ll r, ll x, ll d) {
    if (l == r) {
        return st[x];
    } ll m = (l+r)/2;
    if (d <= m) return st[x] + ste(l,m,2*x+1,d);
    else return st[x] + ste(m+1,r,2*x+2,d);
}

int main() {
    ll n, t=0; 
    ifstream fin("haircut.in",ifstream::in);
    
    fin >> n;
    vector<ll> v(n), inv(n,0), o(n);
    F(i,0,n) fin >> v[i];
    st.assign(4*n, 0);
    F(i,0,n) {
        if (v[i] < n) {
            ll y = ste(0, n-1, 0, v[i]);
            inv[v[i]] += y; t+= y;
        }
        if (v[i] > 0) stu(0, n-1, 0, v[i]-1, 0, 1);
        //F(x,0,4*n) fout << st[x] << ' '; 
        //fout << '\n';
    }
    for (ll i = n-1; i>= 0; i--) {
        t-= inv[i];
        o[i]= t;
    }
    fin.close();
    ofstream fout("haircut.out",ofstream::out);
    F(i,0,n) fout << o[i] << '\n';
}