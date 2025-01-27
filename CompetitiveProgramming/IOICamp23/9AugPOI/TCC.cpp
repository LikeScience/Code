#include <bits/stdc++.h>
#define ll long long 
#define F(i,s,e) for (ll i = s; i<e; i++)
#define pii pair<ll, ll >
#define fi first
#define se second
#define mp make_pair
using namespace std;

int main() {
    random_device rd;
    int n= 300000, q = 50000;
    cout << n << " " << q << '\n'; 
    F(i,0,n) cout << (rd()%(1000000)) << " \n"[i==n-1];
    F(i,0,q) {
        int z = rd()%3;
        if (z == 0) {
            cout << 'B' << " " << (rd()%(1000000)) << " " << (rd()%(1000000)) << '\n';
        } else if (z == 1) {
            cout << 'K' << " " << (rd()%(1000000)) << " " << (rd()%(1000000)) << '\n';
        } else {
            cout << 'Z' << '\n';
        }
    }
}