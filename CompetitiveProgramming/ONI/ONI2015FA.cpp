#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll k, p, n;
    cin >> k >> p;
    vector<ll> p10 = {1}, p9 = {1}, fac = {1}, al = {0,9};
    F(i,0,15) p10.push_back(10*p10[i]);
    F(i,0,15) p9.push_back(9*p9[i]);
    F(i,1,9) fac.push_back(i*fac[i-1]);
    vector<vector<ll> > c(9);
    F(i,0,9) F(j,0,i+1) c[i].push_back(fac[i]/(fac[j]*fac[i-j]));
    F(i,2,17) {
        ll x = 9*p10[(i+1)/2-1], y=0;
        if (k >= i/2) {x*=p10[i/2];}
        else {
            F(j,0,k+1) y += c[i/2][j]*p9[j];
            x*=y;
        }
        al.push_back(al[i-1]+x);
        //cout << i << " "<<  al[i] << '\n';
    }    
    F(z,0,p) {
        cin >> n;
        ll u = lower_bound(al.begin(), al.end(), n) - al.begin();
        if (u==1 || n==9) {cout << n << '\n'; continue;}
        n-= al[u-1]+1; ll v = u, r=0, kl=0;
        while (v>0) {
            
            if (v== u/2) kl = k;
            if (v > u/2) {
                ll x = p10[v-1 - u/2], y=0;
                if (k >= u/2) {x*=p10[u/2];}
                else {
                    F(j,0,k+1) y += c[u/2][j]*p9[j];
                    x*=y;
                }
                ll m = n/x;
                n-=m*(x);
                
                r+=((u == v) ? m+1 : m)*p10[v-1];
                //cout << v <<  "VVV" << x << " " << n << " " << r<< '\n';
            } else {
                ll x1 = 1, x2 = 1, a=(r/p10[u-v])%10;
                F(j,1,min(kl,v)) x1 += c[v-1][j]*p9[j];
                F(j,1,min(kl+1,v)) x2 += c[v-1][j]*p9[j];
                //cout << "VAAVA" << '\n';
                if (n < a*x1 && kl>0) {
                    ll m = n/x1;
                    n-=m*(x1);
                    r+=m*p10[v-1];
                    kl--;
                } else if (n < a*x1 + x2 || kl ==0) {
                    n-= a*x1;
                    r+= a*p10[v-1];
                } else { 
                    n-= a*x1 + x2;
                    ll m = n/x1;
                    n-=m*(x1);
                    r+=(a+m+1)*p10[v-1];
                    kl--;
                }
            }
            v--;
        }
        cout << r << '\n';
    }
}