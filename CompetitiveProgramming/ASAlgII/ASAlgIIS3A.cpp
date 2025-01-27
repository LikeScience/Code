#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, n, p;  
    cin >> t;
    F(y,0,t) {
    cin >> n;
    deque<int> d;
    cin >> p;
    d.push_back(p);
    F(i,1,n) {
        cin >> p;
        if (p < d[0]) {
            d.push_front(p);
        } else d.push_back(p);
    }
    F(i,0,n) cout << d[i] << ' ';
    cout << '\n';
    }
}