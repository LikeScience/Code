#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define pii pair<int, int >
#define fi first
#define se second
#define mp make_pair
using namespace std;

int t, n, k;
vector<int> v;
vector<bool> s;
bool cs() {
    if ((int)s.size() == n-1) {
        map<pii, bool> m;
        F(i,0,n-1) if (s[i]){
            if (m[mp(v[i], v[i+1])]) return 0;
            m[mp(v[i], v[i+1])] = 1;
        }
        return 1;
    } int ss = (int)s.size();
    bool a1=0, a2=0;
    if ((ss > 0 && ss < n-2) && s[ss-1]) {
    s.push_back(0);
    a1 = cs();
    s.pop_back();
    }
    s.push_back(1);
    a2 = cs();
    s.pop_back();
    return a1 || a2;
}

int  main() {
    
    cin >> t;
    F(z,0,t) {
        cin >> n >> k;
        v.resize(n);
        F(i,0,n) {
            cin >> v[i];
            
        }
        cout << ((cs()) ? "TAK" : "NIE") << '\n';
    }
}
