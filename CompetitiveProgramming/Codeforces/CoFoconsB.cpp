#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main( ) {
    ios::sync_with_stdio(0);
    int t, a, b, k;
    cin >> t;
    F(z,0,t) {
        cin >> a >> b >> k;
        if ((a+b)%2) cout << "NO" << '\n';
        else if (a+b<10) cout << (((a+b)/2 == k) ? "YES" : "NO") << '\n';
        else cout << (((((a+b)/2)%10) == k || (((a+b)/2+5)%10) == k) ? "YES" : "NO") << '\n';
    }
}