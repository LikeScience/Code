#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    int n = 20000; random_device rd; int acnt=1;
    cout << n << '\n';
    cout << 0 << " ";
    F(i,1,n) {
        int x = rd()%2;
        if (!x) acnt++;
        cout << x << " \n"[i==n-1];
    }
    cout << acnt << '\n';
}