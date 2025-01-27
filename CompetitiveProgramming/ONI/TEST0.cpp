#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    random_device rd;
    int n; cin >> n;
    char c[n];
    cout << 2 << " " << 1 << " " << n << '\n';
    F(i,0,n) {
        int x = rd()%3;
        if (x == 0) {c[i] = 'B';}
        else if (x==1) {c[i] = 'A';}
        else c[i] = 'V';
    }
    F(i,0,n) cout << c[i];
    cout << '\n';
}