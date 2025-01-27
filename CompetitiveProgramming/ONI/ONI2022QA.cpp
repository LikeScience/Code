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
    int P, N, K, a, mx, mxid, mxcnt;
    cin >> P >> N >> K;
    if (P==1) {
        vector<int> v(K+1,0);
        for (int i = 0; i < N; i++) {
            cin >> a;
            v[a]++;
        }
        mx = 0; mxcnt = 0;
        for (int i = 1; i <= K; i++) {
            if (v[i]> mx) {
                mxcnt=1; mxid = i; mx = v[i];
            }
            else if (v[i] == mx) mxcnt++;
        }
        cout << ((mxcnt>1) ? 0 : mxid) << '\n';
    }
    else if (P == 2) {
        vector<int> v(K+1,0);
        for (int i = 0; i < N; i++) {
            cin >> a;
            v[a]++;
        }
        cout << v[1];
        for (int i = 2; i <= K; i++) {
            cout << " " << v[i];
        }
        cout << '\n';
    }
    else if (P==3) {
        vector<vector<int> > m (N, vector<int> (K+1));
        for (int i = 0; i < N; i++) for (int j = 0; j < K; j++) {
            cin >> a;
            m[i][a] = j;
        }
        mxid = 1; 
        for (int i = 2; i <= K; i++) {
            mxcnt = 0; //num won by previous max
            for (int j = 0; j < N; j++) {
                if (m[j][mxid] < m[j][i]) mxcnt++; 
            }
            if (mxcnt < (N - mxcnt)) mxid = i;
        }
        bool b = 1;
        for (int i = 1; i <= K; i++) {
            if (i == mxid) continue;
            mxcnt = 0;
            for (int j = 0; j < N; j++) {
                if (m[j][mxid] < m[j][i]) mxcnt++; 
            }
            if (mxcnt <= (N - mxcnt)){
                b = 0;
                break;
            };
        }
        if (b) {
            cout << mxid << '\n';
        }
        else cout << 0 << '\n';
    }
}
