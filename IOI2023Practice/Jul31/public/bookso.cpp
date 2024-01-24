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
    {
        vector<ll> d(N+1); bool b=0; int id;
        vector<int> ot;
        F(i,1,N+1) {
            d[i] = (ll)skim(i);
            if (b == 0 && d[i] >= A) {
                b = 1; id = i;
            }
        }
         ll t1 = 0;
            F(i,1,K+1) {
                t1 += d[i];
            }
            if (t1 > 2*A) impossible();
            if (t1 >= A) {
                F(i,1,K+1) ot.push_back(i);
                answer(ot);
            }
            F(i,K+1,N+1) {
                t1-=d[i-K];
                t1+=d[i];
                if (A <= t1 && t1 <= 2*A) {
                    F(j,i-K+1,i+1) ot.push_back(j);
                    answer(ot);
                }
            }
            if (b == 0) impossible();
            else {
                t1=d[id]; 
                if (id <= K-1) impossible();
                F(i,1,K) t1 += d[i];
                if (t1 <= 2*A) {
                    F(i,1,K) ot.push_back(i);
                    ot.push_back(id);
                    answer(ot);
                }
                impossible();
            }
        
    }
    
}
