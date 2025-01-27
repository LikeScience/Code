#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (ll i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; ll n, k;
    cin >> t; 
    F(z,0,t) {
        cin >> n >> k;
        if (k%2 || k > ((n+1)/2)*(n - (n%2))) {
            cout << "No\n";
            continue;
        }
        vector<int> v; ll k0=k;
        F(i,1,n+1) v.push_back(i);
        ll b=0, c=0; 
        if (n%2==0) {
            n--; c=1;
            if (k>((n+1)/2)*(n - 1)) b=(k-((n+1)/2)*(n - 1))/2;
            k-=b;
            //cout << b << '\n';
        }k/=2; 
        for (ll i = 0; i<n/2;i++) {
            if (k>=2*(n/2-i)) {
                k-=2*(n/2-i);
                swap(v[i], v[n-i-1]);
            }
        }
        if (k==1) {
            swap(v[n/2-1], v[n/2]);
            if (v[n/2]==n/2+2) swap(v[n/2], v[n/2+1]); 
        }
        if (c) n++;
        if (b) swap(v[n-1],v[b-1]);
        cout << "Yes\n";
        F(i,0,n) cout << v[i] << " \n"[i==n-1];
        ll x = 0;
        F(i,0,n) x+= abs(i+1-v[i]);
        if (x!= k0) cout << "LIChO\n";
    }
}