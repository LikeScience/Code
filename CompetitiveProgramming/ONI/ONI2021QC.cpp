#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F(i,s,e) for (ll i=s; i<e; i++)
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int p, n, x;
    cin >> p >> n >> x;
    if (p==1) {
        vector<int> a(x,0), b(x,0);
        int z;
        F(i,0,n) {
            cin >> z;
            a[z%x]++;
        }
        F(i,0,n) {
            cin >> z;
            b[z%x]++;
        } ll t=a[0]*b[0];
        F(i,1,x) t+= a[i]*b[x-i];
        cout << t << '\n';
    } else {
        vector<int> a(n), b(n), v(n);
        bool r=1; ll t=0;
        F(i,0,n) cin >> a[i];
        F(i,0,n) cin >> b[i];
        F(i,0,n) {
            if ((b[i]-a[i]) % x) {r=0;}
            else v[i]=(b[i]-a[i]) / x;
        }
        if (r) {
            t=v[0];
            F(i,1,n) if(v[i]>v[i-1]) t+=v[i]-v[i-1];
            cout << t << '\n';
        } else cout << -1 << '\n';
    }
}