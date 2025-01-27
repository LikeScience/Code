#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> pbds;

//s.find_by_order(k) - iterator to the kth element - O(log n)
//s.order_of_key(k) - # of elements smaller than k in the pbds - O(log n)


int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    pbds s;
    for (int i=0; i<n; i++) s.insert(make_pair(v[i], i));
    for (int i = 0; i<q; i++) {
        char k; int a, b;
        cin >> k >> a >> b; 
        if (k == '!') {
            a--;
            s.erase(make_pair(v[a],a));
            s.insert(make_pair(b,a));
            v[a]=b;
        }
        else cout << s.order_of_key({b, 1e9}) - s.order_of_key({a-1, 1e9}) << '\n';
    }


}