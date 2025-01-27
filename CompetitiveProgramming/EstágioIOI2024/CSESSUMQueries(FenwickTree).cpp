#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> ft;
int MAXN = 2e5;

void update(int idx, ll v) {
    while (idx <= MAXN) {
        ft[idx]+= v;
        idx += idx&-idx;
    }
    return;
}

ll eval(int idx) {
    ll sum=0;
    while (idx > 0) {
        sum += ft[idx];
        idx -= idx&-idx;
    }
    return sum;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> v(n+1);
    for (int i=1; i<=n; i++) cin >> v[i];
    ft.assign(MAXN+1,0);
    for (int i=1; i<=n; i++) update(i,v[i]);
    for (int i = 0; i<q; i++) {
        ll k, a, b;
        cin >> k >> a >> b;
        if (k == 1) {
            update(a,b-v[a]);
            v[a] = b;
        }
        else cout << eval(b) - eval(a-1) << '\n';
    }
}