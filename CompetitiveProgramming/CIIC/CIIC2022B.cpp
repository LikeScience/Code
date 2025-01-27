#include <iostream>
#include <vector>

#define F(i,s,e) for(int i = s; i < e; i++) 

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, ai, bi, d;
    cin >> n >> q;
    vector<int> A(n), B(n), Ac(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        Ac[i] = A[i];
    }
    F(i,0,n) {
        cin >> B[i];
    }
    for (int i = 0; i < n-2; i++) {
        d = B[i] - Ac[i];
        Ac[i+1] -= d;
        Ac[i+2] += d;
    }
    if (Ac[n-1] == B[n-1] && Ac[n-2] == B[n-2]) {
        cout << "YES" << '\n';
    } else cout << "NO" << '\n';
}