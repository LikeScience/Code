#include "cards.h"
#include <algorithm>
#include <map>
#include <vector>
//#include <iostream>
#include <utility>

using namespace std;

int n, k;

map<vector<int>, vector<int> > m;

vector<int> fac = {1, 1, 2, 6, 24, 120, 720, 5040};

void init_magician(int N, int K) {
  n = N; k = K;
  if (k == 3) {
    if (n ==5) {
    m[{1, 2}] = {3};
    m[{1, 4}] = {2};
    m[{1, 5}] = {2};
    m[{1, 3}] = {4};
    m[{5, 1}] = {3};
    m[{4, 1}] = {5};
    m[{2, 3}] = {4};
    m[{3, 2}] = {5};
    m[{2, 4}] = {5};
    m[{3, 4}] = {5};
    } else if (n==4){
    m[{1, 2}] = {3};
    m[{1, 4}] = {2};
    m[{1, 3}] = {4};
    m[{2, 3}] = {4};
    } else {
      m[{1, 2}] = {3};
    }
  }
  return;
}

void init_assistant(int N, int K) {
  n = N; k = K;
  if (k == 3) {
    if (n ==5) {
    m[{1, 2, 3}] = {1, 2};
    m[{1, 2, 4}] = {1, 4};
    m[{1, 2, 5}] = {1, 5};
    m[{1, 3, 4}] = {1, 3};
    m[{1, 3, 5}] = {5, 1};
    m[{1, 4, 5}] = {4, 1};
    m[{2, 3, 4}] = {2, 3};
    m[{2, 3, 5}] = {3, 2};
    m[{2, 4, 5}] = {2, 4};
    m[{3, 4, 5}] = {3, 4};
    } else if (n==4){
    m[{1, 2, 3}] = {1, 2};
    m[{1, 2, 4}] = {1, 4};
    m[{1, 3, 4}] = {1, 3};
    m[{2, 3, 4}] = {2, 3};
    } else {
    m[{1, 2, 3}] = {1, 2};
    }
  }
  return;
}

std::vector<int> choose_cards(std::vector<int> cards) {
  vector<int> v(0);
  //cout << n << k << '\n';
  if (k == 2) {
    if(n==2) {
      v.push_back(1);
    }
    else {
      //cout << "asa" << '\n';
      vector<int> a(4,0); int abs;
      for (int i = 0; i <= 1; i++) {
        a[cards[i]] = 1;
      }
      for (int i = 1; i < 4; i++) {
        if(!a[i]) {
          abs = i; break;
        }


      }
      //cout << abs << '\n';
      v.push_back((abs%3) + 1);
    }
  } else if (k == 3) {
    
    return m[cards];
  } else if(k == 6) {
    int c =cards[0]-1;
    vector<int>dc, st = {1,2,3,4};
    for (int i = 3; i >= 0; i--) {
      dc.push_back(st[(c)/fac[i]]);
      //cout << st[c/fac[i]] << " "<< cards[0] <<'\n';
      st.erase(lower_bound(st.begin(),st.end(),st[(c)/fac[i]]));
      c %= fac[i];
      
    }
    for (int i=0; i < 4; i++) {
      v.push_back(cards[dc[i]]);
    } v.push_back(cards[5]);



  } else if(k == 8) {
    int c;
    if (cards[1] - cards[0] <= 5000) {
    	c = cards[1] - cards[0];
    	
    	vector<int>::iterator it = cards.begin(); it++;
    	cards.erase(it);
    } else {
   	c = cards[0] + n - cards[1];
    	cards.erase(cards.begin());
    	//cout << "0dis" << c << '\n';
    }
    c--;
    vector<int>dc, st = {1,2,3,4, 5, 6, 7};
    for (int i = 6; i >= 0; i--) {
      dc.push_back(st[(c)/fac[i]]);
      //cout << st[c/fac[i]] << " "<< cards[0] <<'\n';
      st.erase(lower_bound(st.begin(),st.end(),st[(c)/fac[i]]));
      c %= fac[i];
      
    }
    for (int i=0; i < 7; i++) {
      v.push_back(cards[dc[i]-1]);
    }
  }

	//cout << v.size() << endl;
  return v;
}

int find_discarded_card(std::vector<int> cards) {
  //cout << n << k << endl;
  if (k == 2) {
    if (n==2) {return 2;} else {
      //cout << cards[0] << '\n';
      return (cards[0]%3)+1;
    }
  }
  else if (k==3) {
    return m[cards][0];
  } else if (k==6) {
    vector<int>st = {1,2,3,4}, fn(k-1); int A=0;
    vector<pair<int, int> > vc;
    for (int i= 0; i < k-1; i++) {
      vc.push_back(make_pair(cards[i], i));
    }
    sort(vc.begin(), vc.end());
    for (int i = 1; i <=k-1;i++) {
      fn[vc[i-1].second] = i;
      //cout << vc[i-1].second << '\n';
    }
    for (int i = 3; i >= 1; i--) {
      vector<int>::iterator it = lower_bound(st.begin(),st.end(), fn[3-i]);
      
      A += (it - st.begin()) * fac[i];
      
      st.erase(it);
    }
    return A+1;
  } else if (k==8) {
    vector<int>st = {1,2,3,4,5, 6, 7}, fn(k-1); int A=0;
    vector<pair<int, int> > vc;
    for (int i= 0; i < k-1; i++) {
      vc.push_back(make_pair(cards[i], i));
    }
    sort(vc.begin(), vc.end());
    for (int i = 1; i <=k-1;i++) {
      fn[vc[i-1].second] = i;
      //cout << vc[i-1].second << '\n';
    }
    for (int i = 6; i >= 1; i--) {
      vector<int>::iterator it = lower_bound(st.begin(),st.end(), fn[6-i]);
      
      A += (it - st.begin()) * fac[i];
      
      st.erase(it);
    }
    A += (vc[0].first + 1);
    //cout << ((A == n) ? A : (A % n)) << '\n';
    return ((A == n) ? A : (A % n));
  }
  return 0;
}
