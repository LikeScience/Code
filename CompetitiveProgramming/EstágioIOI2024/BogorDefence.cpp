#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> a(n+1), v(n+1,0);
    map<int, int > m;
    F(i,1,n+1) {
        cin >> a[i];
        
        if (a[i]<=i) {
            v[i-a[i]+1]++;
            auto it = m.upper_bound(i-a[i]);
            if (it == m.begin()) {
                x=v[i-a[i]+1];
            } else {
                it--;
                x = max(m[a[i]],it->second+v[i-a[i]+1]);
                it++;it++;
            }
            cout << i << " " << x << '\n' << flush;
            m[a[i]] = x;
            while(it != m.end() &&it->second <= x) {
                m.erase(it); it++;
            }
        }
    } auto it = m.end(); it--;
    cout << n-it->second << '\n';
}