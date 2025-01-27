#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    map<int, int> m;
    m[0] = 1;
    cout << m.size() << '\n';
    m[0] = 0;
    cout << m.size();
}