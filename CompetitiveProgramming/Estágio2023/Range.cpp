#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define F(i,z,e) for (ll i = z; i<e; i++)
using namespace std;

vector<ll> st;

 void stu(ll l, ll r, ll d, ll x, ll u) {
    if (l== r) {
        st[x] = u;
        return;
    }ll m = (l+r)/2;
    if (d <= m) {stu(l,m,d,2*x+1, u);}
    else stu(m+1,r,d,2*x+2, u);
    st[x] = max(st[2*x+1], st[2*x+2]);
}

ll ste(ll l, ll r, ll dl, ll dr, ll x) {
    //cout << l << " " << r << " "<< dl << " "<< dr <<  '\n';
    if (l == dl && r == dr) {
        return st[x];
    } ll m = (l+r)/2;
    if (dr <= m) {return ste(l,m,dl,dr,2*x+1);} 
    else if (dl >= m+1) {return ste(m+1,r,dl,dr,2*x+2);}
    else {
        ll a = ste(l,m,dl,m,2*x+1);
        ll b = ste(m+1,r,m+1,dr,2*x+2);
        return max(a,b);
    }
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, li, ri;
    cin >> n;
    vector<pair<ll, ll> > v0; vector<pair<pair<ll, ll>, ll> > v, e; vector<ll> c(n), p(n);
    F(i,0,n) {
        cin >> li >> ri;
        v0.push_back({li, ri});
        v.push_back({{li, -ri},i});
    }
    sort(v.begin(), v.end());
    F(i,0,n) c[i] = v[i].s;
    F(i,0,n) e.push_back({{-v[i].f.s,-v[i].f.f}, i});
    sort(e.begin(), e.end());
    st.assign(4*n, 0);
    
    F(i,0,n) {
        //cout << e[i].s << '\n';
        p[c[e[i].s]] = 1 + ste(0,n-1,e[i].s,n-1,0);
        stu(0,n-1,e[i].s,0,p[c[e[i].s]]);//cout << "DA" << '\n';
    }
    ll m = 0;
    F(i,0,n) m = max(m, p[i]);
    cout << m << '\n';
    F(i,0,n-1) cout << p[i] << ' ';
    cout << p[n-1] << '\n';
}