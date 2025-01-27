#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, a, P;
    cin >> P;
    if (P == 1) {
    int T = 0;
    map<int, int> m;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (m.find(a) == m.end()) {
            m[a] = 1;
        } else m[a]++;
    }
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        T += (it->second) * (it->second - 1) / 2; 
    }
    cout << T << '\n';
    } else if (P == 2) {
        cin >> N; int ld, ph, maxp = 0, cnt = 0, its;
        set<pair<int, int> > s;
        set<pair<int, int> >::iterator lb;
        pair<int, int> p;
        vector<int> d(N); //prevdistances
        for (int i = 0; i < N; i++) {
            cin >> a;
            pair<int, int> p = make_pair(a, 0);
            lb = lower_bound(s.begin(), s.end(), p);
            if (lb == s.end())  {
                d[i] = i;
            } else if (lb->first == p.first) {
                d[i] = i - lb->second - 1;
                lb++;
            } else {
                d[i] = i - lb->second - 1;
            }
            while(s.begin() != lb) {
                its = s.begin()->second;
                ld = i - its - 1;
                ph = (ld > d[its]) ? (2 * d[its] + 1) : (2 * ld + 1);
                if (ph > maxp) maxp = ph;
                cnt += ((ph / 2) + 1);
                s.erase(s.begin());
            }
            p.second = i; s.insert(p);
        }
        
            while((int)s.size() > 0) {
                its = s.begin()->second;
                ld = N - its - 1;
                ph = (ld > d[its]) ? (2 * d[its] + 1) : (2 * ld + 1);
                if (ph > maxp) maxp = ph;
                cnt += ((ph / 2) + 1);
                s.erase(s.begin());
            }
        cout << maxp << " " << cnt << '\n';
    }
}