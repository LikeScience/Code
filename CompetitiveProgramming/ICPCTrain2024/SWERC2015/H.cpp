#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
#define vl vector<ll>
#define vll vector<vl>
using namespace std;

ll cnt (ll x) {
    if (x <= 0) return 0;
    if (x == 1) return 1;
    vll dv(65), dp(65, vl(65,0));
    F(i,1,65) F(k,1,i+1) if (!(i%k)) dv[i].push_back(k);
    ll tot=0;
    vector<bool> numb;
    for (ll i = x; i; i>>=1) numb.push_back(bool(i&1));
    ll n = (ll)numb.size();

    //Numbers of size less than floor log n
    F (i,1,n) {
        for (ll k : dv[i]) F(j,1,k) dp[i][j]++; //Cases A...B 
        F(j,1,i) tot += dp[i][j] + dp[i-j][j]; //cases A...A are the same as cases A...B except the size of A 
        tot++; //Case 1...1
    } 
    
    ll w = 1, z = 1<<(n-2); 
    //Numbers of size floor log n without all stating ones
    while (z&x) {
        tot += dp[n-w][w]; //cases A...A
        for (ll k : dv[n]) if (k > w) tot++;//Cases A...B
        z >>= 1; w++;
    }
    //Numbers of size floor log n with all stating ones
    ll a = w; bool bbbbb=0; 
    while (n-w>0) {
        if (x&z && !bbbbb) { // b = w-a is number of zeroes so a+b=w
            if (!(n%w) || !((n-a)%w)) {
                bool bbb=1;
                for (ll i = n-w-1; i>=0; i--) {
                    if (numb[i] && !numb[i+w] ) break;
                    else if (numb[i]!=numb[i+w]) {bbb=0; break;}
                }
                if (bbb) tot++;
            }
            bbbbb=1;
        } else if (bbbbb) {
            if (!(n%w) || !((n-a)%w)) tot++;
        }
        z >>=1; w++;
    }   
    return tot+1; //11..10...0
}

int main() {
    ll x, y;
    cin >> x >> y;
    cout << cnt(y) - cnt(x-1) << '\n';
}