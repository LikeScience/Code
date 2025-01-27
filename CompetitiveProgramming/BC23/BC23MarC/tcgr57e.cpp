#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    int n, m=1e9, k, p;
    random_device rd;
    cin >> n >> k >> p;
    cout << n << '\n';
    if (k!=0) m = k;
    set<int> s;
    vector<int> v;
    F(i,0,n) {
        while(1) {
            int x = (rd()%m) +1;
            if (s.find(x) == s.end()) {
                s.insert(x);
                v.push_back(x);
                break;
            }
        }
    }
    if (p==2) sort(v.begin(), v.end(), greater<int>());
    F(i,0,n-1) cout << v[i] << " ";
    cout << v[n-1] << '\n';
}