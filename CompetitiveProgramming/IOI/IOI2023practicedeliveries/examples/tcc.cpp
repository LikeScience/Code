#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    int n = 500, q = 100, maxt=100, maxw=10;
    random_device rd;
    cout << n << " " << q << '\n';
    /*F(i,0,n-1) cout << i << " \n"[i==n-2];
    F(i,0,n-1) cout << i+1 << " \n"[i==n-2];*/
    pbds a, b; b.insert(0);
    F(i,1,n) a.insert(i);
    vector<int> u, v;
    F(i,1,n) {
        int ax = rd()%i, ay = rd()%(n-i), x, y;
        x = *b.find_by_order(ax), y =*a.find_by_order(ay);
        u.push_back(x); v.push_back(y);
        a.erase(y); b.insert(y);
    }
    //F(i,0,n-1) cout << u[i] << " " << v[i] << '\n';
    F(i,0,n-1) cout << u[i] << " \n"[i==n-2];
     F(i,0,n-1) cout << v[i] << " \n"[i==n-2];
    F(i,0,n-1) cout << 1 + rd()%maxt << " \n"[i==n-2];
    F(i,0,n) cout << rd()%maxw << " \n"[i==n-1];
    F(i,0,q) cout << rd()%n << " " << rd()%maxw << '\n';
}