#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define ll long long
#define F(i,s,e) for(ll i = s; i < e; i++) 

int main() {
    ll n, mn = 0, idx;
    cin >> n;
    vector<ll> a(n), p(n);
    vector<ll> sp(n);
    F(i,0,n) {
        cin >> a[i];
    }
    F(i,0,n) {
        cin >> p[i];
        sp[i] = (i == 0) ? p[i] : (sp[i-1] + p[i]);
    }
    F(i,1,n) {
        mn += p[i] * (a[i] - a[0]); 
    }
    ll A = mn;
    F(i,1,n) {
        

    }

}