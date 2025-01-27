#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F(i,s,e) for(int i = s; i != e; i++)
#define f first
#define ll long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> id_set;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, n, a;
    ll s;
    
    cin >> t;
    
    F(z,0,t) {
        id_set v;
        cin >> n; s=0;
        cin >> a;
        s+=a-1; v.insert(a);
        cout << s << '\n';
        F(i,1,n) {
            cin >> a;
            s.insert(a);
        }
        cout << s << '\n';
    }
}