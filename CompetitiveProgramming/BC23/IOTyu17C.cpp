#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream ci("fire.in", fstream::in);
    fstream cou("fire.out", fstream::out);
    ll n, k, x;
    ci >> n >> k;
    ll c[n], v[n];
    F(i,0,n) ci >> c[i];
    ci.close();
    F(i,0,n) {
        v[i] = c[i] + ((i-k-1 < 0) ? 0 : v[i-k-1]); 
        //cout << v[i] << " ";
        F(j,1,k+1) if (i >= j){
            x = c[i-j] + ((i-j-k-1 < 0) ? 0 : v[i-j-k-1]); 
            if (x < v[i]) v[i] = x;
        }
        F(j,1,k+1) if(i+j <= n-1) {
            x = c[i+j] + ((i+j-k-1 < 0) ? 0 : v[i+j-k-1]); 
            if (x < v[i]) v[i] = x;
        }
        //cout << v[i] << '\n';
    }
    cou << v[n-1] << '\n';
    cou.close();
}