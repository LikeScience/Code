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
    int P, N, K, X, a, c, cnt = 0, r, sum = 0;
    cin >> P >> N >> K;
    if (P == 1) {
        cin >> c; cnt++;
        for (int i = 1; i < N; i++) {
            cin >> a;
            if (a != c) {
                cnt++; c = a;
            }
        }
        cout << cnt << '\n';
    }
    else if (P == 2) {
        cin >> X >> c; cnt = 1; r = 1;
        multiset<int> s;
        for (int i = 1; i < N; i++) {
            cin >> a;
            if (a != c) {
                s.insert(r);
                r = 1;
                cnt++; c = a;
            }
            else r++;
        }
        s.insert(r);
        multiset<int>::iterator it = s.begin();
        for (int i = 0; i < cnt-X; i++) {
            sum += *it;
            it++;
        }
        cout << sum << '\n';
    }
}