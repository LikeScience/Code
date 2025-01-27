#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, p=0;
    ll a, s = 0;
    multiset<ll> v;
    multiset<ll>::iterator it;
    cin >> n;
    F(i,0,n) {
        cin >> a;
        if(a>=0) {
            s+=a;
            p++;
        } else if (s+a >= 0) {
            v.insert(a);
            s+=a;
            p++;
        } else if (v.size()) {
            it = v.begin(); 
            if (*it < a) {
                s-=*it;
                s+=a;
                v.erase(it);
                v.insert(a);
            }
        }
    }
    cout << p << '\n';
}