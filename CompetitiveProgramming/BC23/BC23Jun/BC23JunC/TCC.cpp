#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F(i,s,e) for (int i =s; i<e; i++)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    int p, n, q, t;
    random_device rd;
    cin >> p >> n >> q >> t;
    cout << p << '\n' << n << " " << q << '\n';
    pbds a, o;
    a.insert(1);
    F(i,2,n+1) o.insert(i);
    if (t == 1) {
        F(i,1,n) {
            int x = (rd()%i), y = (rd()%(n-i));
            int xi = *a.find_by_order(x), yi =  *o.find_by_order(y);
            a.insert(yi); o.erase(yi);
            cout << xi << " " << yi << '\n';
        }
    } else if (t==2) {
        F(i,1,n) cout << i << " " << i+1 << '\n';
    } else if (t == 3) {
        deque<int> tl = {1};
        F(i,1,n) {
            int y = (rd()%(n-i+1));
            int xi = ((i == 1) ? 1 : tl[rd()%2]), yi =  *o.find_by_order(y);
            a.insert(yi); o.erase(yi);
            cout << xi << " " << yi << '\n';
            tl.push_back(yi);
            if (i > 1) tl.pop_front();
        }
    }
    if (p==1) {
    F(z,0,q) {
        cout << (rd()%n)+1 << '\n';
    }
    } else {
       F(z,0,q) {
            cout << (rd()%n)+1 << " " << (rd()%n)+1<< '\n';
        } 
    }
}
