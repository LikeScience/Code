#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int> > , rb_tree_tag, tree_order_statistics_node_update> pbds; 


int main() {
    int n, q, p, k, a, b; char c;
    cin >> n >> q;
    vector<int> v(n+1);
    pbds s;
    F(i,0,n) {cin >> p; v[i+1]=p; s.insert(make_pair(p, i+1));}
    F(i,0,q) {
        cin >> c; 
        if (c == '!') {
            cin >> k >> p;
            s.erase(make_pair(v[k], k));
            s.insert(make_pair(p, k));
            v[k] = p;
        } else {
            cin >> a >> b;
            cout << s.order_of_key({b, 1e9}) - s.order_of_key({a-1, 1e9}) << '\n';
        }
    }      

}