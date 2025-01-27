#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
#define f first
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, n, a;
    ll s;
    
    cin >> t;
    
    F(z,0,t) {
        vector<int> v;
        cin >> n; s=0;
        F(i,0,n) {
            cin >> a;
            v.push_back(a);
        } sort(v.begin(), v.end());
        s+=v[0]-1; v[0]=1;
        F(i,1,n) {
            if (v[i]>v[i-1]) {
                s+=v[i]-v[i-1] -1;
                v[i]= v[i-1]+1;
            }
        }
        cout << s << '\n';
    }
}