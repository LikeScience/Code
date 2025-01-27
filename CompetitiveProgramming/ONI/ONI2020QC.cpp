#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F(i,s,e) for (ll i=s; i<e; i++)
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll p, n, k;
    cin >> p >> n >> k;
    ll s[n];
    F(i,0,n) cin >> s[i];
    if (p==1) {
        ll t=0, m;
        F(i,0,k) {
            t+=s[i];
        } m=t;
        F(i,k,n) {
            t+= s[i] - s[i-k];
            m = min(m,t);
        }
        cout << m << '\n';
    } else if (p==2) {
        vector<ll> m = {0};
        F(i,1,n+1) {
            m.push_back(m[i-1] + s[i-1]);
        }
        ll l = 1, r = m[n], t;
        while(1) {
            ll cnt=0;
            t = (l+r)/2;
            F(i,1,n+1) {
                //cout << i - (lower_bound(m.begin(), m.end(), m[i]-t)-m.begin()) << " "<< m[i]-t << '\n';
                cnt += i - (lower_bound(m.begin(), m.end(), m[i]-t)-m.begin());
            }
            //cout << t << " " << cnt << '\n';
            if (cnt > k) {(r = t-1);}
            else if (cnt < k) {(l = t+1);}
            else break;
        }
        ll mx = 0;
        F(i,1,n+1) {
            mx = max(mx, m[i] - *lower_bound(m.begin(), m.end(), m[i]-t));
            //cout << "t" << i << " " << *lower_bound(m.begin(), m.end(), m[i]-t) << '\n';
        }
        cout << mx << '\n';
    } else {

    }
}