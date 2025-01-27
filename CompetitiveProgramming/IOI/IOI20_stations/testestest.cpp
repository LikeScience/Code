#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> uid(0,100);
    //for (int i = 0; i < 100; i++) cout << uid(mt) << '\n';
    vector<int> v;
    for (int i = 0; i < 100; i++) v.push_back(i);
    shuffle(v.begin(),v.end(), mt);
     for (int i = 0; i < 100; i++) cout << v[i] << " ";
    pbds p;
    auto it = p.find_by_order(0);
    int i = p.order_of_key(1);
}
