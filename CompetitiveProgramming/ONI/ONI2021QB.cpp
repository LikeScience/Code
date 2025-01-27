#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F(i,s,e) for (ll i=s; i<e; i++)
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int p, n, m; ll t=0;
    cin >> p >> n >> m;
    vector<ll> a(n);
    F(i,0,n) cin >> a[i];
    sort(a.begin(), a.end());
    if (p==1) {
        F(i,0,m) t+= a[i];
    } else {
        F(i,1,n)  if (a[i] != a[i-1] && m>0){
            if (m >i*(a[i]-a[i-1])) {
                m-=i*(a[i]-a[i-1]);
                t+=i*((a[i]-1)*a[i]/2-(a[i-1]-1)*a[i-1]/2);
            } else {
                t+=i*((a[i-1]-1+m/i)*(a[i-1]+m/i)/2-(a[i-1]-1)*a[i-1]/2);
                t+=(m%i)*(a[i-1]+m/i);
                m=0;
            }
            
        }
        if (m>0) {
            t+=n*((a[n-1]-1+m/n)*(a[n-1]+m/n)/2-(a[n-1]-1)*a[n-1]/2);
            t+=(m%n)*(a[n-1]+m/n);
        }
    }
    cout << t << '\n';
}