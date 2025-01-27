#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k, A = 0;
    cin  >> n >> k;
    if (n == k) {
        A = 1;
        for (int i = 1; i <= n-1; i++) {
            A*= i;
            A %= 998244353;
        }
    }
    cout << A << '\n';
}