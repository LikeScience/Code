#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    int n, m, d=30; string s;
    map<string, bool> v, cit;
    cit["Lisbon"] = cit["Porto"] = cit["Beja"] = cit["Faro"] = cit["Funchal"] = 1;
    vector<int> cnt(d+1,0);
    cin >> n;
    F(i,0,n) {
        cin >> s;
        v[s]=1;
    }
    cin >> m;
    F(i,0,m) {
        string s1, s2, s3, s4, s5;
        int d1, d2;
        cin >> s1 >> s2 >> d1 >> s3 >> s4 >> d2 >> s5;
        if (v[s1] == 1) {
            if (cit[s2] == 1) {
                cnt[d1]++;
            }
            if (cit[s4] == 1) {
                cnt[d2]++;
                if (cit[s2] == 1 && d1 == d2) cnt[d2]--;
            }
            
        }
    }
    int mx = 0, idx=1;
    F(i,1,d+1) {
        if (cnt[i] > mx) {
            mx = cnt[i];
            idx = i;
        }
    }
    cout << idx << '\n' << mx << '\n';
}