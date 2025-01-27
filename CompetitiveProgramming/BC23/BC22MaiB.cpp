#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

#define ll long long
#define F(i,s,e) for(int i = s; i < e; i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, r, x, O, mis;
    map<int, int>::iterator it;
    cin >> t;
    F(ti,0,t) {
        cin >> n >> r;
        map<int, int> m;
        F(i,0,n) {
            cin >> x;
            O = 0; mis = 0;
            it = m.find(x);
            if (it == m.end()) {
                m[x] = 1;
            } else {
                it->second += 1;
            }
        }
        it = m.end();
            it--;
            while(1) {
                if (it->first <= O) {
                    break;
                }
                mis++; O += r;
                if (it == m.begin()) {break;}
                it--;
            }
            cout << mis << '\n';
    }
    
}