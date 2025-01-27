#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

int main( ) {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    F(z,0,t) {
        cin >> n;
        vector<int> v(n);
        F(i,0,n) cin >> v[i];
        sort(v.begin(), v.end());
        int i = 0, t=0;
        while (i < n && v[i]<0) {
            if (i == n-1) {t+= v[i]; break;}
            if (v[i+1] < 0) {t += v[i+1]*v[i]; i+=2;}
            else if (v[i+1] > 0) {t += v[i]; break;}
            else break;
        } i = n-1;
        while (i >= 0 && v[i] > 0 ) {
            if (i == 0) {t+= v[i]; break;}
            if (v[i-1] == 1) {t+= v[i]; i--;}
            else if (v[i-1] > 0) {t += v[i-1]*v[i]; i-=2;}
            else if (v[i-1] <= 0) {t += v[i]; break;}
        }

        cout << t << '\n';
    }
    
}