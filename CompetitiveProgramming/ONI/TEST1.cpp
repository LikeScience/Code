#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    vector<int>v;
    F(i,0,10) {
    vector<int> v;
    cout << v.size() << '\n';
    F(j,0,i) v.push_back(j);
    cout << v.size();
    }
}