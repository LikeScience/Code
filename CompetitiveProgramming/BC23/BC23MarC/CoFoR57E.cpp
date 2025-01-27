#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

vector<int> st;

int e(int l, int r, int d, int x) {
    if (l==d && r == d) {
        return st[x];
    }
    int m = (l+r)/2, t=st[x];
    if(d <= m) {t+= e(l,m, d, 2*x+1);}
    else if (d >= m+1) t+= e(m+1,r,d, 2*x+2);
    return t;
}

void u(int l, int r, int dl, int dr, int x, int v) {
    if (l==dl && r == dr) {
        st[x] += v;
        return;
    }
    int m = (l+r)/2;
    if(dr <= m) u(l,m,dl,dr,2*x+1,v);
    else if (dl >= m+1) u(m+1,r,dl,dr,2*x+2,v);
    else {
        u(l,m,dl,m,2*x+1,v);
        u(m+1,r,m+1,dr,2*x+2,v);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a;
    cin >> n;
    vector<pair<int, int> > vin;
    vector<int> v(n), gb(n), sa(n);
    F(i,0,n) {
        cin >> a;
        vin.push_back({a,i});
    }
    sort(vin.begin(), vin.end());
    F(i,0,n) {
        v[vin[i].second] = i;
         
    }
    st.assign(4*n,0);
    F(i,0,n) {
        gb[i] = e(0,n-1,v[i],0);
        if (v[i]>0) u(0,n-1,0,v[i]-1,0,1);
    }
    st.assign(4*n,0);
    for (int i = n-1; i >=0; i--) {
        sa[i] = e(0,n-1,v[i],0);
        if (v[i]<n-1) u(0,n-1,v[i]+1, n-1,0,1);
    }
    ll t = 0;
    F(i,0,n) t+= ((ll)gb[i])*((ll)sa[i]);
    cout << t << '\n'; 
}