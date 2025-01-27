#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1,1);
    int l = 0;
    int m = 0;
    F(z,0,k) {
        int ii;
        cin >> ii; 
        for (int i = ii; i<= n; i+=ii) {
            if (v[i] == 1) {
                l++;
            } else {
                l--;
            }
            v[i] = 1-v[i];
        }
        m = max(m,l);
    }
    cout << m << '\n';
}