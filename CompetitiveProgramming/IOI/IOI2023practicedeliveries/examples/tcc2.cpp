#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    int n = 15, q = 10000, maxt=100, maxw=10;
    random_device rd;
    cout << n << " " << q << '\n';
    F(i,0,n-1) cout << i/2 << " \n"[i==n-2];
    F(i,0,n-1) cout << i+1 << " \n"[i==n-2];
    F(i,0,n-1) cout << 1 + rd()%maxt << " \n"[i==n-2];
    F(i,0,n) cout << ((rd()%3) ? rd()%maxw : 0) << " \n"[i==n-1];
    F(i,0,q) cout << rd()%n << " " << rd()%maxw << '\n';
}