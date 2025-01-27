#include <bits/stdc++.h>
using namespace std;
#define F(i,s,e) for (int i = s; i<e; i++) 
#define ll long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n+1,1e9); v[0] = 0;
    F(i,1,n+1) {
        int x = i;
        while (x > 0) {
            int z = x%10; x/=10;
            if (z != 0) v[i] = min(v[i],v[i-z]+1);
        }
    }
    cout << v[n] << '\n';
    //F(nn,1,n+1) {
        int cnt = 0;
        int i = n;
    while (i > 0) {
        int x = i, mx = 0; 
        while (x > 0) {
            int z = x%10; x/=10;
            if (z != 0) {
                mx = max(mx, z);
            }
        }
        i -= mx;
        cnt++;
        
    }
    cout << cnt << '\n';
    //if (cnt != v[nn]) cout << cnt << " " << v[nn] << '\n'; 
    //}
    //F(z,0,n+1) cout << v[z] << " ";
}