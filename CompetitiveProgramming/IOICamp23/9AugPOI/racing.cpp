#include <bits/stdc++.h>
#define ll long long 
#define F(i,s,e) for (ll i = s; i<e; i++)
#define pii pair<ll, ll >
#define fi first
#define se second
#define mp make_pair
using namespace std;


ll n, q, cnt = 0, cnt1=0;
vector<ll> p;
vector<pii> st;



void stb(ll l, ll r, ll x) {
    //cnt++;
    if (l == r) {
        st[x].fi = p[l];
        st[x].se = p[l] + n-l;
        return;
    } ll m = (l+r)/2;
    stb(l, m,2*x+1);
    stb(m+1,r,2*x+2);
    st[x].se = max(st[2*x+1].se, st[2*x+2].se);
    return;
}

void stu(ll l, ll r, ll dl, ll dr, ll x, ll u) {
    //cnt++;
     if (l == dl && r == dr) {
        st[x].fi += u; 
        st[x].se += u; 
        return;
    } ll m = (l+r)/2;
    if (dr <= m) {stu(l,m,dl,dr,2*x+1,u);}
    else if (dl >= m+1) {stu(m+1,r,dl,dr,2*x+2,u);}
    else {
        stu(l,m,dl,m,2*x+1,u);
        stu(m+1,r,m+1,dr,2*x+2,u);
    }
    st[x].se = max(st[2*x+1].se, st[2*x+2].se)+st[x].fi;
    return;
}

ll ste(ll l, ll r, ll x, ll d) {
    //cnt++;
    if (l == r) {
        return st[x].fi;
    }ll m = (l+r)/2;
    if (d <= m) return st[x].fi + ste(l, m, 2*x+1, d);
    else return  st[x].fi + ste(m+1, r, 2*x+2, d);
}

ll stem(ll l, ll r, ll dl, ll dr, ll x) {
    //cnt++;
     if (l == dl && r == dr) { 
        return st[x].se;
    } ll m = (l+r)/2;
    if (dr <= m) {return stem(l,m,dl,dr,2*x+1);}
    else if (dl >= m+1) {return stem(m+1,r,dl,dr,2*x+2);}
    else {
        ll a1 = stem(l,m,dl,m,2*x+1);
        ll a2 = stem(m+1,r,m+1,dr,2*x+2);
        return max(a1,a2);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll z, y, x; char c;
    cin >> n >> q;
    p.resize(n);
    //cout << 1 << '\n';
    F(i,0,n) {
        cin >> p[i];
    }
    //cout << 1 << '\n';
    st.resize(4*n);
    sort(p.begin(), p.end());
    stb(0, n-1, 0);
    F(i,0,q) {
        cin >> c;
        if (c == 'B') {
            cin >> x >> y;
            ll l = 0, r = n-1, m;
            while (l < r) {
                //cnt1++;
                //cout << cnt1 << '\n';
                m = (l+r)/2;
                z = ste(0,n-1,0,m);
                if (z >= x) {
                    r = m;
                } else l = m+1;
            }
            if (l <= n-1 && ste(0,n-1,0,l) >= x)stu(0,n-1,l,n-1,0,y);
        } else if (c == 'K'){
            cin >> x >> y;
            ll l = 0, r = n-1, m;
            while (l < r) {
                //cout << l << " " << r << " "<< cnt1 << '\n';
                //cnt1++;
                m = (l+r)/2;
                if (l +1 == r) m = r;
                z = ste(0,n-1,0,m);
                if (z <= x) {
                    l = m;
                } else r = m-1;
            }
            if (r >= 0 && ste(0,n-1,0,r) <= x)stu(0,n-1,0,r,0,-y);
        } else {
            ll l = 0, r = n-1, m;
            while (l != r) {
                //cnt1++;
                m = (l+r)/2;
                z = ste(0,n-1,0,m) + n;
                if (z >= st[0].se /*(m == n-1 ? 0 : stem(0,n-1,m+1,n-1,0))*/) {
                    r = m;
                } else l = m+1;
            }
            //F(i,0,4*n) cout << st[i].fi << " \n"[i==4*n-1];
            //F(i,0,4*n) cout << st[i].se << " \n"[i==4*n-1];
            cout << n-l << '\n';
        }
        
    }
    //cout << cnt << " " << cnt1 << "C\n";
}