#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    fstream f("rosalind_hamm.txt", fstream::in);
    string a, b;
    int hd = 0;
    f >> a >> b;
    f.close();
    for (int i = 0; i < (int)a.length(); i++) {
        hd += (a[i] != b[i]);
    }
   
    cout << hd << '\n';

}