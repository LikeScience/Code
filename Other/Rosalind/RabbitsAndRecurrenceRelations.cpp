#include <fstream>
#include <string>
#include <vector>

#define F(i,s,e) for(long long i = s; i < e; i++)

using namespace std;


int main() {
    fstream ifs ("rosalind_fib.txt", fstream::in);
    vector<long long> f = {1,1};
    long long n, k; ifs >> n >> k;
    F(i,2,n) {
        f.push_back(f[i-1] + k*f[i-2]);
    }
    ifs.close();
    fstream ofs ("RARR.txt", fstream::out);
    ofs << f[n-1] << '\n';
    ofs.close();
}