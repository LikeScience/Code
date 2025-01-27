#include <bits/stdc++.h>
#define F(i,s,e) for (int i =s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    F(i,0,n) cin >> a[i];
    vector<int> d = {0};
    int t=1; d.push_back(a[0]);
    F(i,1,n) {
        if (a[i] > a[i-1]) {
            t++;
            d.push_back(a[i]);
        } else if (a[i] < a[i-1]) {
            
            while (d[(int)d.size()-1] > a[i]) {
                d.pop_back();
            }
            if (d[(int)d.size()-1] < a[i]) t++;
            d.push_back(a[i]);
        }
    }
    cout << t << '\n';
}