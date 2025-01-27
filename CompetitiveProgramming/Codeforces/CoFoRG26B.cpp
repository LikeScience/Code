#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; long long x;
    cin >> t;
    F(z,0,t) {
        cin >> x;
        vector<int> v;
        while(x>0) {
            v.push_back(x%10);
            x/=10;
        }
        if (v[0]==9 || v.back()!=1) cout << "NO\n";
        else {
            bool b = 0;
            F(i,1,(int)v.size()-1) {
                if (v[i]==0) {
                    b=1;
                    break;
                }
            } 
            if (b) cout << "NO\n";
            else cout << "YES\n";
        }
    }

}