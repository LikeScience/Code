#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)

using namespace std;
int main() {
    int n, m, k, x; double t; cin >> n >>  m >> k >> t;
    cin >> x; vector<int> exc(n,0);
    F(i,0,x) {int y; cin >> y; exc[y]=1;}
    cout << n << " " << m << " " << k << " " << t << '\n';
    F(i,0,k) {
        vector<int> dl; int m1c=0;
        F(j,0,m) {
            int y; cin >> y;
            if (y != -1 && !exc[y]) dl.push_back(y);
            else m1c++;
            
        }
        F(j,0,(int)dl.size()) cout << dl[j] << " ";
        F(j,0,m1c) cout << -1 << " ";
        cout << '\n';
        
    }

}