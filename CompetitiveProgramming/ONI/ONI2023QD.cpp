#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
#define fi first
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int p, t, n, m;
    cin >> p >> t;
    if (p==1) {
        F(z,0,t) {
            cin >> n >> m; 
            char x;  vector<int> p(n,0), v(n,0); int l=0, r=0;
            F(i,0,n) {
                cin >> x;
                p[i] = (x == 'V');
            }
            F(i,0,m) {
                cin >> x;
                l += (x == 'V');
            }
            F(i,0,m) v[m-1] += p[i];
            F(i,m,n) v[i] = v[i-1] + p[i] - p[i-m];
            F(i,m-1,n) if ((l + v[i]) % 2) r++;
            cout << r << '\n';
        }
    } else {
        F(z,0,t) {
            cin >> n >> m; 
            char x;  vector<int> p(n,0), v(n,0), w(n,0), a(n,0); int l=0, r=0;
            F(i,0,n) {
                cin >> x;
                p[i] = (x == 'V');
            }
            F(i,0,m) {
                cin >> x;
                l += (x == 'V');
            }
            F(i,0,m) v[m-1] += p[i];
            F(i,m,n) v[i] = v[i-1] + p[i] - p[i-m];
            F(i,m-1,n) if ((l + v[i]) % 2) r++;
            //cout << r << '\n';
            F(i,m-1,n) v[i] = (v[i]+l)%2;
            //F(i,m-1,n) cout << v[i] << " ";
            //cout << '\n';
            F(i,0,n) a[i] = min(min(i+1,m),min(n-i, n-m+1));
            //F(i,0,n) cout << a[i] << " ";
            // cout << '\n';
            w[0] = v[m-1];
            F(i,1,n) {
                w[i]=w[i-1];
                if (i+m-1<n) w[i]+=v[i+m-1];
                if (i>=m) w[i]-=v[i-1];
            }
             //F(i,0,n) cout << w[i] << " ";
            int d =0;
            F(i,0,n) d = min(d,a[i]-w[i]-w[i]);
            cout << r+d << '\n';
        }
    }

}