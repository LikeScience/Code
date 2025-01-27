#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, m, k, x; 
    cin >> t;
    F(z,0,t) {
        cin >> n >> m >> k; vector<int> a(k+2,0) ,b(k+2,0);
        F(i,0,n)  {
            cin >> x; if (x<= k) a[x]=1; 
        }
         F(i,0,m)  {
            cin >> x; if (x<= k) b[x]=1; 
        }
        int oa = 0, ob = 0, oc = 0; bool y = 0;
        F(i,1,k+1) {
            if (a[i] && b[i]) oc++;
            else if (a[i]) oa++;
            else if (b[i]) ob++;
            else {y = 1; break;}
        }
        if (y || ob > k/2 || oa > k/2) cout << "NO" << '\n';
        else cout << "YES" << '\n';
        
    }
}