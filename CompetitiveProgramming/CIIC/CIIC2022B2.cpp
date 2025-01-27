#include <iostream>
#include <vector>

#define F(i,s,e) for(int i = s; i < e; i++)
#define ll long long

using namespace std;

    vector<ll> v;
vector<ll> f;

    ll create(ll x) {
        f[x] = v[x];
        if (x%2) {
            return f[x];
        }
        else {
            ll y = x, i = 0;
            while(y) {
                
                if (y%2) {
                    y-= 1; break;
                }
                y = y>>1; i++;
            }
            for (ll j = i-1; j >= 0; j--) {
                y = y << 1; y++;
                f[x] += create(y << j);
                i--;
            }
            return f[x];
        }
    }

void ft() {
        ll x = (ll)v.size()-1;
        //cout << 392329 << '\n';
        f.resize(x+1);
        ll y = x, i = 0;
            while(y>0) {
                //cout << y << endl;
                if (y%2) {
                    f[y<<i] = create(y<<i);
                }
                y = y >> 1; i++;
            }
    return;
}

ll calc(ll a) {
    if (a == 0) return 0;
    ll i = 0, r = 0;
    while(a) {
        if (a%2) r += f[a<<i];
        a = a >> 1; i++;
    }
    return r;
}

void change (ll id, ll ne) {
     ll y = id, i = 0;
      int x = (int)v.size()-1;
     while(y) {
        if (y%2) break;
        y = y >> 1; i++; x = x >> 1;
     }
     ll z = y << i;
    f[z] -= v[id];
    f[z] += ne;
    //cout << z << endl;
    y = y >> 1; i++; x = x >> 1;
   
    while(y) {
            //cout << y << endl;
            if (y%2 == 0) {
                ll z = (y+1) << i;
                if (z <= (int)v.size()) {
                    f[z] -= v[id];
                    f[z] += ne;
                    //cout << z << endl;
                }
            }
            x = x >> 1;
            y = y >> 1; i++;
            }
            while(x) {
                    ll z = 1 << i;
                    f[z] -= v[id];
                    f[z] += ne;
                    //cout << z << endl;
                x = x >> 1; i++;
            }
    v[id] = ne;
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, ai, bi, d;
    cin >> n >> q;
    vector<int> A(n), B(n), Ac(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        Ac[i] = A[i];
    }
    F(i,0,n) {
        cin >> B[i];
    }
    for (int i = 0; i < n-2; i++) {
        d = B[i] - Ac[i];
        Ac[i+1] -= d;
        Ac[i+2] += d;
    }
    if (Ac[n-1] == B[n-1] && Ac[n-2] == B[n-2]) {
        cout << "YES" << '\n';
    } else cout << "NO" << '\n';
}