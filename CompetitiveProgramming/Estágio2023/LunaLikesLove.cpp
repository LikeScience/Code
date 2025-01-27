#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define F(i,s,e) for (int i=s; i<e; i++)
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a; cin >> n; ll t = n;
    vector<int> p(n+1, -1);
    pbds s;
    F(i,0,2*n) {
        cin >> a;
        if (p[a] == -1) {
            s.insert(i);
            p[a] = i;
        } else {
            s.erase(p[a]);
            t += (ll)s.size() - (ll)s.order_of_key(p[a]);
        }
    }
    cout << t << '\n';
}