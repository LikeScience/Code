#include <bits/stdc++.h>
using namespace std;
#define F(i,s,e) for (ll i = s; i<e; i++) 
#define ll long long
//#define v5i vector<vector<vector<vector<vector<ll> > > > > 
#define v4i vector<vector<vector<vector<ll> > > > 
#define v3i vector<vector<vector<ll> > > 
#define v2i vector<vector<ll> >
#define vi vector<ll> 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    //v5i v(19, v4i(10, v3i(10, v2i(2, vi(2,1e18+7)))));
    v4i v(19, v3i(10, v2i(10, vi(10, (2,1e18+7)))));
    F(i,1,19) F(j,0,10) F(k,1,10) F(l,0,10){
        if (i == 1) {
            if (j ==0) {
            }
            else if (k==1) {
                v[i][j][k] =  v[i-1][j][9] +  (v[i][0][1] - v[i-1][0][9]);
                v[i][j][k][1] = v[i]
            }
            else if (j >= k+1) {
                v[i][j][k][l] = min(v[i][j][k][0]+1,min (v[i][j][k] +  (v[i][j][k] - v[i][j][k-1]), 0));
            } else {
                 v[i][j][k] =  v[i][0][k] +  (v[i][0][k] - v[i][0][k-1]);
            }
            
        }

    }
    
   
}