#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i<e; i++) 
using namespace std;

int main() {
    int t, n, m;
    cin >> t; F(z,0,t) {
        cin >> n >> m;
        cout << n*(m/2) << '0'; 
    }
}