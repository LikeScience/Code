#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

using namespace std;
using namespace __gnu_pbds;

#define o_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>  

int main() {
    int n, q, a; cin >> n;
    o_set os;
    for (int i = 0; i < n; i++) {
        cin >> a; os.insert(a);
    } cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a;
        cout << *(os.find_by_order(a-1)) << " " << os.order_of_key(a) << '\n';
    }
}
