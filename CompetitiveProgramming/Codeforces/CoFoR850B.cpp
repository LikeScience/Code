#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
#define f first
#define s second
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    ll t, n, a, b, w, h, l, r;
    cin >> t;
    
    F(z,0,t) {
        cin >> n >> w >> h;
        vector<pair <ll, ll> > av, bv;
        F(i,0,n) {
            cin >> a;
            av.push_back(make_pair(a-w,a+w));
        }
        F(i,0,n) {
            cin >> b;
            bv.push_back(make_pair(b-h,b+h));
        }
        if (h>w) {
            cout << "NO" << '\n';
            continue;
        }
        sort(av.begin(),av.end());
        sort(bv.begin(),bv.end());
        l = -bv[0].f+av[0].f;
        r = -bv[0].s+av[0].s;
        F(i,1,n) {
            if (-bv[i].f+av[i].f > l) l = -bv[i].f+av[i].f;
            if (-bv[i].s+av[i].s < r) r = -bv[i].s+av[i].s;
        }
        if (r<l)  {
            cout << "NO" << '\n';
        } else cout << "YES" << '\n';
    }
}