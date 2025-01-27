#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)

using namespace std;

int main() {
    int n, d, a, b, k, idx; cin >> n >> d;
    vector<vector<int> > al(n);
    
    F(i,0,n) {
        cin >> d;
        
        F(j,0,d) {
            cin >> b; al[i].push_back(b-1);
        }
    }
    cin >> k;
    vector<int> r;
    F(i,0,k) {
        cin >> a;
        r.push_back(a-1);
    }
    a = 1;
    F(i,0,k-1) {
        b = 0;
        F(j,0,(int)al[r[i]].size()) {
            if (al[r[i]][j] == r[i+1]) {
                b = 1;
                break;
            }
        }
        if (!b) {
            a = 0; break;
        } 
    }
    cout << a << '\n';
}