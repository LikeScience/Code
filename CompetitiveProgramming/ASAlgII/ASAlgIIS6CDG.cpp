#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m=0, M=0;
        cin >> n;
        int a[n] = {};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        //m, M=a[0];
        //cout << m << '\n';
        for (int j = 0; j < n; j++) {
            m = max(a[j], a[j]+m);
            if (m>M) {
                M=m;
            }
        }
        cout << M << '\n';
    }
}