#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, k;
    cin >> t;
    F(z,0,t) {
        cin >> n >> k; vector<int> v(n);
        int x = 0;
        F(i,0,k) {
            int a = (n-i-1)/k+1;
            if ((i%2)) {
                F(j,0,a) v[i+k*j] = ++x;
            } else  {x+=a; F(j,0,a) v[i+k*j] = x-j;}
        }
        F(i,0,n) cout << v[i] << " \n"[i==n-1];
    }
}