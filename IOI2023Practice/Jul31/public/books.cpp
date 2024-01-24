#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

#include "books.h"

using namespace std;
//
// --- Sample implementation for the task books ---
//
// To compile this program with the sample grader, place:
//     books.h books_sample.cpp sample_grader.cpp
// in a single folder and run:
//     g++ books_sample.cpp sample_grader.cpp
// in this folder.
//

void solve(int N, int K, long long A, int S) {
    vector<ll> d(N+1,-1); 
    vector<int> ot;
    int l=1, r=N, m;
    while (1) {
        if (r == 1) impossible();
        if (l == r || l == N+1) break;
        m = (l+r)/2;
        d[m] = skim(m);
        if (d[m] < A) l = m+1;
        else r = m;
    } if (d[l] == -1) d[l] = skim(l);
    if (d[l] < A) l = N+1;
    ll t = 0;
    F(i,1,K) {
        d[i] = skim(i);
        t+=d[i];
    }
    if (l != N+1) {
        if (l < K) impossible();
        
        if (t + d[l] <= 2*A) {
            F(i,1,K) ot.push_back(i);
            ot.push_back(l);
            answer(ot);
        }
    }
    if (l != K) {
        d[K] = skim(K);
        }
    t += d[K];
    if (t > 2*A) impossible();
    if (t >= A) {
        F(i,1,K+1) ot.push_back(i);
        answer(ot);
    }
    F(i,1,K+1) {
            t -= d[i];
           if (d[l-i] == -1) d[l-i] = skim(l-i);
            t += d[l-i];
            if (A <= t && t <= 2*A) {
                F(j,i+1,K+1) ot.push_back(j);
                F(j,l-i,l) ot.push_back(j);
                answer(ot);
            }
        
    }
    impossible();

    
}
