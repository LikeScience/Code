#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define f first
#define w second
#define F(i,x,e) for (int i=x; i<e ; i++)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    int p, n, a, v;
    cin >> p >> n;
    set<pair<int, int> > s;
    if (p== 1) {
        F(i,0,n) {
            cin >> a >> v;
            s.insert({a,v});
        }
        cout << (int)s.size() << '\n';
    } else {
        map<pair<int, int>, int > m, d;
        map<pair<int, int>, int >::iterator it, lb;
        F(i,0,n) {
            cin >> a >> v;
            m[{a,v}]++;
        } a=0;
        for (it = m.begin(); it!= m.end(); it++) {
            v=0;
            for (lb = m.begin(); lb != it; lb++) {
                if (lb->f.f < it->f.f && lb->f.w < it->f.w) v+= lb->w;
            }
            a=max(a,v);
        }
        cout << a << '\n';
    }
}