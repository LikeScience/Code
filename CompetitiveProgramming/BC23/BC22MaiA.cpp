#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

#define ll long long
#define F(i,s,e) for(long long i = s; i < e; i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, h, a, b, id;
    cin >> t;
    vector<ll> sum, dif, pred;
    F(ti,0,t) {
        cin  >> n >> h;
        dif.resize(n-1); sum.resize(n-1); pred.resize(n-1); 
        if (n == 1) {
            cin >> a;
            cout << h << '\n'; 
        } else {
        F(i,0,n) {
            cin >> a;
            if (i == 0) {
                b = a;
            } else {   
                dif[i-1] = a - b;
                b = a;
            }
        }
        sort (dif.begin(), dif.end());
        F(i,0,n-1) {
        
            if (i == 0) {
                sum[i] = dif[i];
                pred[i] = dif[i] * n;
            } else {
                sum[i] = sum[i-1] + dif[i];
                pred[i] = sum[i-1] + (n-i) * dif[i];
            }
            //cout << dif[i] << " " << sum[i] << " " << pred[i] << endl;
        }
        vector<ll>::iterator it = lower_bound(pred.begin(), pred.end(), h);
        id = it - pred.begin();
        if (it == pred.end()) {
            cout << dif[n-2] + h - pred[n-2] << '\n';
        } else if (h == *it) {
            cout << dif[id] << '\n';
        } else if (it == pred.begin()) {
            cout << ((h % n) ? (h / n + 1) : (h / n)) << '\n';
        } else {
            h -= sum[id-1];
            cout << ((h % (n-id)) ? (h / (n-id) + 1) : (h / (n-id))) << '\n';
        }
        }
    }
}