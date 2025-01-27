#include "towns.h"
#include <set>
#include <vector>
//#include <iostream> // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <algorithm>
#include <random>

using namespace std;

int rn(int i) {
  random_device rd;
  return (rd() % i);
}

int find_town(int N) {
  vector<vector<int> > v(N, vector<int>(N,0));
  vector<int> oc (N,0);
  /*set<int> s;
  for (int i = 0; i < N; i++) {
    s.insert(i);
  }
  set<int>::iterator ft;*/
  vector<int> s;
  for (int i = 0; i < N; i++) {
    s.push_back(i);
  }
  vector<int>::iterator ft;
  bool b, bbb, bbbbb = 0;
  //int cnt = 0; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  while(int(s.size()) > 3) {
    random_shuffle(s.begin(), s.end(), rn);
    //for (int i = 0; i < (int)s.size(); i++) {cout << s[i] << " ";}
    for (/*set<int>::iterator it = s.begin()*/ vector<int>::iterator it = s.begin(); it != s.end(); ) {
    	//cout << *it << '\n';
    	ft = it;
    	ft++; if (ft == s.end()) {ft = s.begin(); bbbbb = 1;};
    	bbb= 0;
    	while(v[*it][*ft]) {
    	  ft++; if (ft == s.end()) {ft = s.begin(); bbbbb = 1;};
    	  if (*ft == *it) {bbb = 1;  break;}
    	}
    	if (bbb) {it++; continue;}
    	//cout << *it << "itft" << *ft << '\n';
    	b = check_road(*it, *ft);
    	//cout << *it << "it" << b << "ft" << *ft << '\n';
    	//cnt++; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    	if (b) {
    	  v[*it][*ft] = 1;
    	  v[*ft][*it] = -1;
    	  oc[*it]++;
    	  //cout << *it << "++\n";
    	  if (oc[*it]>1) {
    	    ft = it;
    	    //it++; //setmode
    	    //cout << *ft << '\n';
    	    s.erase(ft);
    	  } else {it++;}
    	} else {
    	  v[*it][*ft] = -1;
    	  v[*ft][*it] = 1;
    	  oc[*ft]++;
    	  //cout << *ft << "++\n";
    	  if (oc[*ft]>1) {
    	    s.erase(ft);
    	    //it++; //setmode
    	    if (!bbbbb) it++;
    	  } else {it++;}
    	}
    	//cout << *it << '\n';
    	//cout << (int)s.size() << '\n';
    	if (int(s.size()) <= 3) break;
    }
    //cout << -1 << '\n';
  }
  //ft = s.begin(); cout << *ft << " "; ft++; cout << *ft << " "; ft++; cout << *ft << "\n"; cout << cnt << '\n';
  ft = s.begin();
  //set<int>::iterator a = ft++, c, d; c = ft++; d = ft;
  vector<int>::iterator a = ft++, c, d; c = ft++; d = ft;
  //cout << oc[*c] << " " << *c << " " << *d << '\n';
  if (!v[*a][*c]) {
  	b = check_road(*a, *c);
  	if (b) {
    	  v[*a][*c] = 1;
    	  v[*c][*a] = -1;
    	  oc[*a]++;
    	} else {
    	  v[*a][*c] = -1;
    	  v[*c][*a] = 1;
    	  oc[*c]++;
    	}
  }
  if (!v[*c][*d]) {
  	b = check_road(*c, *d);
  	if (b) {
    	  v[*c][*d] = 1;
    	  v[*d][*c] = -1;
    	  oc[*c]++;
    	} else {
    	  v[*c][*d] = -1;
    	  v[*d][*c] = 1;
    	  oc[*d]++;
    	}
  }
  if (!v[*d][*a]) {
  	b = check_road(*d, *a);
  	if (b) {
    	  v[*d][*a] = 1;
    	  v[*a][*d] = -1;
    	  oc[*d]++;
    	} else {
    	  v[*d][*a] = -1;
    	  v[*a][*d] = 1;
    	  oc[*a]++;
    	}
  }
  bool br = 0;
    //cout << oc[*c] << " " << *c <<  '\n';
  if (oc[*a] == 1 && oc[*c] == 1 && oc[*d] == 1) {
  	//random_device rd;
  	vector<int> tw, sh; tw.push_back(*a); tw.push_back(*c); tw.push_back(*d);
  	random_shuffle(tw.begin(), tw.end(), rn);
  	for (int i = 0; i < N; i++) {sh.push_back(i);}
  	
  	//for (int i = 0; i < N; i++) {cout << sh[i] << " ";}
  	//cout << '\n';
  	//for (int i = 0; i < 3; i++) {cout << tw[i] << '\n';}
  	for (int j = 0; j <= 2; j++) {
  	random_shuffle(sh.begin(), sh.end(), rn);
  	for (int i = 0; i < N; i++) {
  		if (!v[tw[j]][sh[i]] && sh[i] != tw[j]) {
  			//cout << tw[j] << " " << sh[i] << '\n';
  			b = check_road(tw[j], sh[i]);
  			if (b) {br = 1; break;}
  		}
  	}
  	if (br) {br = 0;} else return tw[j];
  	}
  	/*for (int i = 0; i < N; i++) {
  		if (!v[*c][i] && i != *c) {
  			b = check_road(*c, i);
  			if (b) {br = 1; break;}
  		}
  	}
  	if (br) {br = 0;} else return *c;
  	for (int i = 0; i < N; i++) {
  		if (!v[*d][i] && i != *d) {
  			b = check_road(*d, i);
  			if (b) {br = 1; break;}
  		}
  	}
  	if (!br) return *d;*/
  } else {
  	if (oc[*a] > 1) {
  	  a = c; c = d;
  	} else if (oc[*c] > 1) {
  	  c = d;
  	}
  	if (!oc[*c]) {
  	d = a; a = c; c = d;
  	}
  	if (oc[*a] <= 1) {
  	for (int i = 0; i < N; i++) {
  		if (!v[*a][i] && i != *a) {
  			b = check_road(*a, i);
  			if (b) {
  			  oc[*a]++;
  			  if(oc[*a] > 1) {
  			    br = 1;
  			    break;
  			  }
  			}
  		}
  	}
  	if (br) {br = 0;} else return *a;
  	}
  	if (oc[*c] <= 1) {
  	for (int i = 0; i < N; i++) {
  		if (!v[*c][i] && i != *c) {
  			b = check_road(*c, i);
  			if (b) {br = 1; break;}
  		}
  	}
  	if (!br) return *c;
  	}
  }
  return -1;
}
