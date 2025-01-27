#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F(i,s,e) for (int i =s; i<e; i++)
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n), b(q);
    F(i,0,n) cin >> a[i];
    sort(a.begin(), a.end());
    F(i,0,q) cin >> b[i];
    F(i,0,q) {
        int c=0;
        vector<ll> pk = {1};
        while(pk[(int)pk.size()-1] < a[n-1]) {pk.push_back(b[i]*pk[(int)pk.size()-1]);}
        F(j,0,n) {
            int pm=0; ll aj = a[j];
            for (int z = (int)pk.size()-1; z>=0; z--) {
                pm += aj/pk[z];
                aj -= pk[z]*(aj/pk[z]);
            }
            if (pm == m) c++;
            //cout << b[i] << " " << a[j] << "  " << pm << '\n';
        }
        cout << c << '\n';
    }
}