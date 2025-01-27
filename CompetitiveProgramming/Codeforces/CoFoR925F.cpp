#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define fi first 
#define se second
#define pll pair<ll, ll> 
#define mp make_pair
using namespace std;


int main() { 
    //ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, k; cin >> t;
   
    F(z,0,t) {
        cin >> n >> k; bool b = 1;
        vector<ll> v(2*n-1,0);
        ll x0, x, x1, y; cin >> x0; 
        F(i,1,n) {
            cin >> v[2*i-1];
        } ll c = 1; v.push_back(1e9); v.push_back(0);
        F(i,1,k) {
            cin >> x; c = 0; if (i == 1) x1 = x;
        //F(i,0,2*n-1) cout << v[i] << " \n"[i==2*n-2];
            F(j,1,n) {
                cin >> y;
                while (!v[c]) {
                    c++; //cout << c << "c\n";
                if (c >= 2*n+1) {b=0; /*cout << "aqui" << i << '\n';*/ break;}
                }
                if (c >= 2*n+1) {continue;}
               //cout << v[c] << '\n';
                if (i == 1) {
                    if (y == x0) {
                    if (v[c] == x) {
                        v[c-1] = v[c+1] = -1;
                        c++;
                    } else if (v[c] == 1e9) {
                        v[c-1] = y;  
                    } else if (c > 2 && v[c-2] == x) {
                        v[c-3] = v[c-1] = -1;
                        c--;
                    }
                    else {
                        c--;
                        v[c] = y;
                    }
                    } else {
                         while (v[c] == x || !v[c]) {
                             c++; //cout << c << "c\n";
                            if (c >= 2*n-1) {b=0; /*cout << "here" << i << '\n';*/ break;}
                        }                
                        if (c >= 2*n-1) {continue;}
                        if (v[c] != y) b = 0;
                    }
                } else {
                    while (v[c] == x || !v[c]) {
                         c++; //cout << c << "c\n";
                        if (c >= 2*n-1) {b=0; /*cout << "here" << i << '\n'; */break;}
                    }                
                    if (c >= 2*n-1) {continue;}
                    if (v[c] == -1) {
                        if (y == x1) {v[c] = 0; c++;}
                        else if (y == x0) {v[c] = y; v[c+2] = 0;}
                        else {b = 0; /*cout << "kkk\n";*/} 
                        //F(i,0,2*n-1) cout << v[i] << " \n"[i==2*n-2];
                    } else if (v[c] != y) {b = 0; /*cout << i << " " << y << " " << c << " " << v[c] << "xig" << '\n';*/}
                }
                c++;
            }

        }
        if (b) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }


}