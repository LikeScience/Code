#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, d, r, a, t;
    
    cin >> n >> d >> r; 
    while (n) {
        vector<int> x, y;
        t=0;
        F(i,0,n) {
            cin >> a;
            x.push_back(a);
        }
        F(i,0,n) {
            cin >> a;
            y.push_back(a);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end(), greater<int>());
        F(i,0,n) {
            if (x[i]+y[i] > d) t+= x[i]+y[i]-d;
        }
        cout << r*t << '\n';
        cin >> n >> d >> r; 
    }
}