#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)

using namespace std;

int main() {
    int n, m, a, b; cin >> n >> m;
    vector<bool> r(n,0);
    F(i,0,m) {
        
        cin >> a >> b;
        r[a-1] = 1; r[b-1] = 1;
        
    }
    F(i,0,n) if(!r[i]) {
            cout << n-1 << '\n';
            F(j,0,n) if (j !=i){
                cout << i+1 << " " << j+1 << '\n';
            }
        break;
    } 
}