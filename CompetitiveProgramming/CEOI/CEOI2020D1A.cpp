#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define F(i,s,e) for (ll i = s; i < e; i++)


int main() {
    ll n, z, M = 1e9 + 7, T = 0, ps;
    vector<ll> h, w;
    cin >> n;
    vector<ll> l(n+1), x(n+1);
    l[0] = 0; x[0] = 0;
    h.push_back(0); w.push_back(0);
    F(i,0,n) {
        cin >> z;
        h.push_back(z);
    }
    F(i,0,n) {
        cin >> z;
        w.push_back(z);
    }
    vector<pair<ll, ll> > mh;
    mh.push_back(make_pair(0, 0));

    F(i,1,n+1) {
        if (h[i] > h[i-1]) {
            mh.push_back(make_pair(h[i], i));
            ps = i-1;
        } else if (h[i] == h[i-1]) {
            mh[(ll)mh.size()-1].second = i;
            ps = i-1;
        } else {
            pair<ll, ll> pa = make_pair(h[i], i);
            vector<pair<ll, ll> >::iterator it = upper_bound(mh.begin(), mh.end(), pa);
            ll idx = it - mh.begin();
            for (ll j = (ll)mh.size()-1; j >= idx; j--) {
                mh.pop_back();
            }
            ps = mh[(ll)mh.size()-1].second;
            if (mh[(ll)mh.size()-1].first == h[i]) {
                mh[(ll)mh.size()-1].second = i;
            } else {
                mh.push_back(make_pair(h[i], i));
            }
        }

        //Adding to the total
        ll a = h[i] * w[i];
        ll b = h[i] * w[i] + h[i] + w[i] +1;
        if (!(a % 4)) {a /= 4;}
        else if ((a % 4) == 2) {a /= 2; b /= 2;}
        else {b/= 4;}
        T = (T + (a % M) * (b % M)) % M;
        T = (T + l[ps] * w[i]) % M;
        if (h[i] < h[i-1]) {
            T = (T + ((((x[i-1] - x[ps])%M) * w[i]) % M) * ((h[i]*(h[i] + 1)/2) % M)) % M;
        }

        //Updating l[i] and x[i]
        x[i] = x[i-1] + w[i];
        l[i] = (l[ps] + (w[i]*((h[i]*(h[i]+1)/2)%M)%M) + ((h[i] < h[i-1]) ? (((x[i-1] - x[ps])%M) * ((h[i]*(h[i] + 1)/2) % M) % M) : 0) )%M;
        //cout << T << " " << l[i] << " " << ps << '\n';
    }
    cout << T << '\n';
}
