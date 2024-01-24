#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    set<string> s;
    int N, k;
    string inp
    for (int i = 0; i < N; i++) {
        cin >> inp;
        set<int>::iterator it = s.find(inp);
        if (it == s.end()) {
            s.insert(inp);
            cout << "Ok, o seu produto ainda nao estava na lista."
        }
    }
}