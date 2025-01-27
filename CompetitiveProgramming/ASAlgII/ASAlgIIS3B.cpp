#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int q;
    cin >> q;
    map<string, string> m, a;
    map<string, string>::iterator it;
    string o, n, t;
    F(i,0,q) {
        cin >> o >> n;
        it = a.find(o);
        if (it == a.end()) {
            m[o] = n;
            a[n] = o;
        } else {
            t=a[o];
            a[n]=t;
            m[t] = n;
        }
    }
    cout << (int)m.size() << '\n';
    for(it=m.begin();it!=m.end();it++) {
        cout << it->first << " " << it->second << '\n';
    }
}