#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F(i,s,e) for (ll i=s; i<e; i++)
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int p, n, k;
    cin >> p >> n >> k;
    vector<int> a(n), b(n);
    if (p==1) {
        F(i,0,n) cin >> a[i];
        F(i,0,n) cin >> b[i];
        F(i,0,n) a[i] += k*b[i];
        cout << a[0];
        F(i,1,n) cout << " " <<  a[i];
        cout << '\n';
    } else {
        F(i,0,n) cin >> a[i];
        if (n<=3*k) {
            int t=0;
            F(i,0,n) t+= a[i];
            cout << t << '\n';
        } else {
            vector<int> fl(n), fb(n), sl(n), sb(n); int m=0;
            fl[0] = a[0];
            F(i,1,k) fl[i] = fl[i-1] + a[i];
            F(i,k,n) fl[i] = fl[i-1] + a[i] - a[i-k];
            fb[0] = fl[0];
            F(i,1,n) fb[i] = max(fb[i-1], fl[i]);
            F(i,k,n) sl[i] = fl[i]+fb[i-k];
            sb[k]=sl[k];
            F(i,k+1,n) sb[i] = max(sb[i-1], sl[i]);
            F(i,2*k,n) m=max(m,fl[i]+sb[i-k]);
            cout << m << '\n';
        }
    }
}