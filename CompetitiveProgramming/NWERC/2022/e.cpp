#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    int a, b, k=1; char z;
    cin >> a >> z >> b;
    if (a < b-1) {cout << "impossible" << '\n'; return 0;}
    while((k*b)*(k*b-1)/2 < k*a) k++;
    int d = k*a- (k*b-1);
    int s = 0, l=2;
    vector<pair<int, int> > e = {{1,2}};
    F(i,0,k*b-1) {
        if ((s + (i+1)) <= d) {
            s+=i+1;
            l++;
            e.push_back({l-1,l});
        } else break;
    }
    d -= s;
    if (d >0) {
        l++;
        e.push_back({l,d+1});
    }
    F(i,l+1,k*b+1) {
        e.push_back({1,i});
    }
    cout << k*b << " " << k*b-1 << '\n';
    F(i,0,k*b-1) cout << e[i].first << " " << e[i].second << '\n';
}