#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

#define ll long long
#define F(i,s,e) for(long long i = s; i < e; i++)

ll absv(ll x) {return (x >= 0 ? x : -x);}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll C, N, D, ai, cnt;
    cin >> C;
    for (ll j = 0; j < C; j++) {
        cin >> N >> D;
        cnt = 0;
        map<ll,ll> m;
        F(i,0,N) {
            cin >> ai;
            bool b = 1;
            for (map<ll,ll>::iterator t = m.begin(); t != m.end(); t++) {
                if (absv(t->first - ai) <= D) {
                    m.erase(m.begin(),t);
                    b= 0;
                    break;
                }
            }
            if (b) m.clear();
            b = 1;
            if (m.size() > 0) {
            for (map<ll,ll>::iterator t = m.end(); 1; t--) {
                if (t == m.end()) continue;
                if (absv(t->first - ai) <= D) {
                    m.erase(++t, m.end());
                    b = 0;
                    break;
                }
            }
            }
            if (b) m.clear();
            map<ll,ll>::iterator it = m.find(ai);
            if (it != m.end()) {
                cnt += it->second;
                (it->second)++;
            }
            else m[ai] = 1;
        }
        cout << cnt << '\n';
    }
}