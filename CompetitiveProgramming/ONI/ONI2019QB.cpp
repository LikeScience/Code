#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, m, z, q;
    cin >> n >> m;
    vector<int> v;
    F(i,0,m) {
        cin >> z;
        v.push_back(z);
    }
    sort(v.begin(), v.end());
    cin >> q;
    F(i,0,q) {
        cin >> z;
        cout << m- (upper_bound(v.begin(), v.end(), z-1) - v.begin()) << '\n';
    }
}