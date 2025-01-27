#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

#define ll long long
#define F(i,s,e) for(int i = s; i < e; i++)

int fmin (int a, int b, int c) {
    return (a <= b) ? (a <= c ? a : c) : (b <= c ? b : c);
}

int nxtsq (int x) {
    return x + 2 * (int)sqrt(x) + 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int P, D, cnt, mx=0;
    char a;
    cin >> P >> D;
    vector<vector<int> > m(D, vector<int>(D,0));
    if (P == 1) {
        F(i,0,D) {
            cnt = 0;
            F(j,0,D) {
                cin >> a;
                if (a == '#') {
                    if (cnt > mx) mx = cnt;
                    cnt = 0;
                }
                else if (a == '.') {
                    cnt++;
                    m[i][j] = 1;
                }
            }
            if (cnt > mx) mx = cnt;
        }
        F(j,0,D) {
            cnt = 0; 
            F(i,0,D) {
                if (m[i][j] == 0) {
                    if (cnt > mx) mx = cnt;
                    cnt = 0;
                }
                else if (m[i][j] == 1) cnt++;
            }
            if (cnt > mx) mx = cnt;
        }
        cout << mx << '\n';
    }
    else if (P == 2) {
        F(i,0,D) {
            if (i == 0) F(j,0,D) {
                cin >> a;
                if (a == '.') {
                    mx = 1;
                    m[i][j] = 1;
                }
            }
            else F(j,0,D) {
                cin >> a;
                if (a == '.' && j == 0) {
                    m[i][j] = 1;    
                    if (mx == 0) mx = 1;
                }
                else if (a == '.'){
                    int x = fmin(m[i-1][j], m[i-1][j-1], m[i][j-1]);
                    //cout << x << endl;
                    int y = nxtsq(x);
                    m[i][j] = y;
                    if (y > mx) mx = y;
                }
            }
        }
        cout << mx << '\n';
    }
}