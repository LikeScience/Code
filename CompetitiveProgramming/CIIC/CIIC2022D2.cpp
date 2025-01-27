#include <iostream>
#include <vector>

#define F(i,s,e) for(ll i = s; i < e; i++) 
#define ll long long

using namespace std;

vector<int> dx()

struct tr {
    ll x;
    ll y;
    ll d;
};
vector<tr> v;
vector<tr> f;

tr trsum(tr a, tr b) {
    tr s;

    return s;
}
    tr create(ll x) {
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
    ll n, q, t, ti, id, l, r, m;

    cin >> n;
    v.push_back({0,0,0});
    for (ll i = 1; i <= n; i++) {
        tr inp = {0,0,0};
        cin >> t; cin >> m;
        if (t == 1) {inp.x = m;}
        else inp.d = m;
        //2cout << t << m;
        v.push_back(inp);
        //cout << v[i] << '\n';
    }
    //cout << 434;
    ft();
    //cout << 1320323;
    /*for (ll i = 1; i <= n; i++) {
        cout << f[i] << '\n'; 
    }*/
    cin >> q;
    for (ll i = 0; i < q; i++) {
        cin >> ti;
        if (ti == 1) {
            cin >> l >> r;
            cout << calc(r+1) - calc(l) << " " << 0 << " " << 0 << '\n';
        }
        else if (ti == 2) {
            cin >> id >> t >> m;
            change(id+1,m);
        }
    }
    return 0;
}