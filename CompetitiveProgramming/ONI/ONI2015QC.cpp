#include <bits/stdc++.h>
#define F(i,x,e) for (ll i = x; i < e; i++)
#define f first
#define s second
#define ll long long 
using namespace std;

vector<vector<ll> > cb(28);
vector<ll> na(19);

ll ab(ll x) {
    return (x > 0) ? x : -x;
}

ll c(ll x) {
    if (x==0) return 0;
    ll t=0, x0=x;
    ll y = 0; // -1:dec; 0:eq; 1:inc; 
    vector<ll> v;
    while(x) {
        v.push_back(x%10);
        x/=10;
    } ll k = (ll)v.size()-1;
    t+=na[k];
    if (k <= 1) return 0;
    while(k >= 1) {
        if (k < (ll)v.size()-2 && v[k+2] != v[k+1]){
            if (y == 0) {
                if (v[k+2] > v[k+1]) {
                    y=-1;
                } else if (v[k+2] < v[k+1]){
                    y=1;
                }
            } else if (y==1 && v[k+2] > v[k+1]) {
                return x0-t;
            } else if (y==-1 && v[k+2] < v[k+1]){
                return x0-t;
            }
        }
        if (k == (ll)v.size()-1) {
            F(a, 1,v[k]) F(b,0,10) t+= cb[k+1-2+ab(b-a)][ab(b-a)];
        } else {
        if (y==0) {
            F(a,0,v[k]) {
                if (v[k+1] < a) {F(b,a,10) t+= cb[k+1-2+ab(b-a)][ab(b-a)];}
                else if (v[k+1] == a) {F(b,0,10) t+= cb[k+1-2+ab(b-a)][ab(b-a)];}
                else F(b,0,a+1) t+= cb[k+1-2+ab(b-a)][ab(b-a)];
            }
        } else if (y==1) {
            F(a,v[k+1],v[k]) F(b,a,10) t+= cb[k+1-2+ab(b-a)][ab(b-a)];
        } else if (y==-1) {
            F(a,0,min(v[k],v[k+1]+1)) F(b,0,a+1) t+= cb[k+1-2+ab(b-a)][ab(b-a)];
        }
        }
        k--;
    } 
        if (y == 0) {
            if (v[k+2] > v[k+1]) {
                y=-1;
            } else if (v[k+2] < v[k+1]) {
                y=1;
            }
        } else if (y==1 && v[k+2] > v[k+1]) {
            return x0-t;
        } else if (y==-1 && v[k+2] < v[k+1]){
            return x0-t;
        }
        if (y==0) {
            t+= v[0]+1;
        } else if (y==1) {
            if (v[0] >= v[1]) t+= v[0]-v[1]+1;
        } else if (y==-1) {
            t+= min(v[1],v[0])+1;
        }
    return x0-t;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    na[0] = 0; na[1] = 9; na[2] = 99;
    cb[0].push_back(1);
    F(i,1,28) {
        cb[i].push_back(1);
        F(j,1,i) cb[i].push_back(cb[i-1][j-1]+cb[i-1][j]);
        cb[i].push_back(1);
    }
    F(n,3,19) {
        na[n] = na[n-1];
        F(a,1,10) {
            F(b,0,10) {
                na[n] += cb[n-2+ab(b-a)][ab(b-a)];
            }
        }
    }
    ll t; ll a, b;
    cin >> t;
    F(z,0, t) {
        cin >> a >> b;
        cout << c(b) - c(a-1) << '\n';
    }
}