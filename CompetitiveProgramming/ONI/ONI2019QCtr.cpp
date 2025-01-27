#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, k, id=0;
    ll d;
    bool p=0;
    cin >> n >> d >> k;
    ll v[n];
    vector<int> o;
    deque<ll> s;
    F(i,0,n) {
        cin >> v[i];
        s.push_back({v[i]+d});
        while (s[0] < v[i]) s.pop_front();
        cout << i <<s.size() << '\n';
        if (s.size()>k) {
            if (p) {
                o.push_back(++id);
            } else {
                while(id<=i) {
                    if (v[id] >= v[i]-d) o.push_back(id+1);
                    id++;
                }
                p=1;
            }
        } else if(p) p=0;
    }
    cout << o.size() <<'\n';
    F(i,0,(int)o.size()-1) cout << o[i] << " ";
    if (o.size()) cout << o[o.size()-1];
    cout << '\n';
}