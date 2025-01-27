#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++) 
using namespace std;
#define fi first
#define vi vector<int>
#define pii pair<int, int>
#define se second

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 1e5, e = 5e5, w = 100;
    cout << n << " " << e << '\n';
    random_device rd;
    F(i,0,e) {
        cout << rd()%n << " " << rd()%n << " " << (rd()%w)+1 << '\n';
    }
}