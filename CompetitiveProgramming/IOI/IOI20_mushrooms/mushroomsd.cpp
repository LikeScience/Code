#include <bits/stdc++.h>
#include "mushrooms.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int count_mushrooms(int n) {
    vector<int> a = {0}, b, v; int c=1, d, m, x; pbds::iterator it;
    pbds s; random_device rd;
    F(i,1,n) s.insert(i);
    while (!s.empty()) {
        v.clear();
        if (a.size() > b.size()) {
            m = min((int)a.size(), (int)s.size());
            F(i,0,m) {
                v.push_back(a[i]);
                it = s.begin();
                x = *it;
                v.push_back(x);
                s.erase(it);
            }
            d = use_machine(v);
            if (d%2) {b.push_back(x);} else a.push_back(x);
            c += m - (d+1)/2;
        } else {
            m = min((int)b.size(), (int)s.size());
            F(i,0,m) {
                v.push_back(b[i]);
                it = s.begin();
                x = *it;
                v.push_back(x);
                s.erase(it);
            }
            d = use_machine(v);
            if (d%2) {a.push_back(x);} else b.push_back(x);
            c += (d+1)/2;
        }
    }
    return c;
}