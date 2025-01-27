#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F(i,s,e) for (int i = s; i < e; i++)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    int n, mx=0, mv, t=0;
    cin >> n;
    vector<int> v(n);
    F(i,0,n) {
        cin >> v[i];
        mx = (v[i] > mx) ? v[i] : mx;
    }
    vector<int> d(mx+1,0);
    F(i,0,n) {
        d[v[i]] += 1;
    }
    sort(v.begin(), v.end());
    for (int i = n-1; i>=0; i--) {
        if (i == n-1 || v[i] != v[i+1]) {
        mv=0;
        for (int s = 2*v[i]; s<=mx; s+= v[i]) {
            mv = max(mv, d[s]);
        }
        d[v[i]] += mv;
        t = max(t,d[v[i]]);
        }
    }
    cout << t << '\n';
}