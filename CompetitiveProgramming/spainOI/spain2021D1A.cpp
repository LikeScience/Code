#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define F(i,s,e) for(int i = s; i < e; i++) 

int main() {
    int mx = 40060;
    vector<int> primes, ispr(mx,1);
    ispr[0] = 1; ispr[1] = 1;
    F(i,2,mx+1) {
        if(ispr[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= mx; j+=i){
                ispr[j] = 0;
            }
        }
        
    }
    
    cout << primes.size() << endl;
    /*int dif = 0, idx;
    F(i,1,4203) {
        if (primes[i]-primes[i-1] > dif) {
            dif = primes[i] - primes[i-1];
            idx = i-1;
        } 
    } cout << idx << " " << dif << '\n';
    cout << primes[(int)primes.size()-1] << '\n';*/
    int l = 0, r = (int)primes.size()-1;
    cout << "?" << " " << 2 << " " << 2 << '\n';
    string s;
    cin >> s;
    if (s == "NO") {
        cout << "! 1" << '\n';
    } else {
    while(1) {
        if (l == r) break;
        int m = (l+r)/2+1;
        cout << "?" << " " << primes[m] << " " << primes[m] << '\n';
        cin >> s;
        if (s == "SI") {
            l = m;
        }
        else r = m-1;
    }
    
    }
}