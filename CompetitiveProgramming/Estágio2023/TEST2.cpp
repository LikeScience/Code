#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n << '\n';
    random_device rd;
    F(i,0,n) cout << rd()%100 << '\n';
}