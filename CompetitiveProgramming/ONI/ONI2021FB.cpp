#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long
#define F(i,s,e) for(ll i = s; i < e; i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll P, N, K;
    cin >> P >> N >> K;
    if (P == 1) {
        vector<ll> v(N); set<ll> s; vector<ll> out;
        F(i,0,N) cin >> v[i];
        F(i,1, K+1) {
            if(i>=N) break;
            s.insert(v[i]);
        }
        F(i,0,N) {
            set<ll>::iterator it = s.lower_bound(v[i]);
            if (it == s.begin()) {
                out.push_back(-1);
            } else {
                it--;
                out.push_back(*it);
            }
            if (i + K < N-1) s.insert(v[i+1+K]);
            if (i < N-1) s.erase(v[i+1]);
            s.insert(v[i]);
            if(i-K >= 0) s.erase(v[i-K]);
        }
        cout << out[0];
        F(i, 1, N) {
            cout << " " <<  out[i];
        } cout << '\n';
    } else if (P == 2) {
        ll a, m, x, lmax, maxi = 0, idmax, l, r;
        vector<ll> in, sin /*sorted input for bin search*/, v(N), s(N), p(N), c(N);
        vector<vector<ll> > dp(N, vector<ll> (K));
        F(i,0,N) {
            cin >> a;
            sin.push_back(a);
            in.push_back(a);
        }
        sort(sin.begin(), sin.end());
        m = N/2; l = 0; r = N-1;
        while(N>=K) { //Not relevant condition
        //cout << m << endl;
            x = sin[m];
            F(i,0,N) {
                if (in[i] < x) v[i] = -1;
                else  v[i] = 1;
                s[i] = (i == 0) ? v[0] : (s[i-1] + v[i]);
            }
            if (K == 1) {
                lmax = (s[N-1] >= 0) ? 1 : 0;
            } else {
            F(i,0,N-K+1) { //equiv u = 0
                if(s[i] >= 0) {
                    p[i] = 1;
                } else p[i] = 0;
            }
            F(u,1,K-1){
                F(i,u,N-K+u+1){
                    lmax = 0;
                    F(j,u-1,i) {
                        x = p[j] + ((s[i]-s[j] >= 0) ? 1 : 0);
                        if (x > lmax) lmax = x;
                    }
                    c[i] = lmax;
                    //cout << u << " " << i << " " << c[i] << endl;

                }
                F(i,u,N-K+u+1){
                    p[i] = c[i];
                }
            }
            F(j,K-1,N) { // equiv a u = K-1
                x = p[j-1] +((s[N-1]-s[j-1] >= 0) ? 1 : 0);
                if (x > lmax) lmax = x;
            }
            }
            if (lmax > K/2+1) {
                if (lmax <= maxi) {maxi = lmax; idmax = m;}
                l = m+1; m = (l+r+1)/2;
                if (l>= N) break;
            } else if (lmax < K/2+1) {
                  r = m-1; m = (l+r+1)/2;
                  if (r<0) break;
            } else {
                maxi = lmax; idmax = m;
                l = m+1; m = (l+r+1)/2;
                if (l>=N) break;
            }
            if (r < l) break;
        }
        cout << sin[idmax] << '\n';
    }
}