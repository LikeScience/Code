#include <bits/stdc++.h>
using namespace std;
#define F(i,s,e) for (int i = s; i<e; i++)

int main() {
    //Sliding window min (value)
    int n, k; cin >> n >> k;
    
vector<int> v(n);
F(i,0,n) cin >> v[i];
vector<int> mins(n-k+1); deque<int> q;
q.push_back(0); if(k==1) mins[0] = v[0];
F(i,1,k) {
  while(q.size() && v[q[q.size()-1]] > v[i]) q.pop_back();
  q.push_back(i);
  if (i == k-1) mins[0] = v[q[0]];
} F(i,k,n){
  if(*q.begin() == i-k) q.pop_front();
  while(q.size() && v[q[q.size()-1]] > v[i]) { q.pop_back(); cout << q[0] << "A\n";}
  q.push_back(i);
  mins[i-k+1] = v[q[0]];
}
F(i,0,n-k+1) cout << mins[i] << '\n';
}