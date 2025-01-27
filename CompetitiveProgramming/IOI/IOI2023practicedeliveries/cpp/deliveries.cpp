#include "deliveries.h"
#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
#define fi first
#define se second
using namespace std;

int n;
ll sfromrt=0, offtort = 0, totw=0;
vector<ll> distp, valfromrt; 
vector<vector<ll> > st_len, st_city, stid;
vector<vector<pair<ll, ll> > > st_fromrt;
vector<int> par, hp, pos, w,md;
vector<vector<pair<int, int> > > al;
vector<set<pair<ll, ll> > > subs;
vector<map<ll, ll> > subsinv;

int dfs1(int x) {
	int sts=1, mxs=0, mxid, sz;
	md[x]=0;
	int i=0;
	for (auto it : al[x]) { if(it.fi != par[x]) {
		par[it.fi]=x;
		distp[it.fi]=it.se;
		sz= dfs1(it.fi);
		sts+=sz;
		if (sz>mxs) {
			mxid = i;
			mxs = sz;
		}
		md[x] = max(md[x],md[it.fi]+1);
		}
		i++;
	}
	if (i>0) F(j,0,(int)al[x].size()) al[x][j].se = (j == mxid);
	return sts;
}
void dfs2(int x) {
	if (hp[x] == x) {
		st_len[x].assign(4*(md[x]+1),0), st_fromrt[x].assign(4*(md[x]+1),{0,0}), st_city[x].assign(4*(md[x]+1),0), stid[x].resize(md[x]+1); 
		stid[x][0]=x;
	} else {
		stid[hp[x]][pos[x]]=x;
	}
	for (auto it : al[x]) if (it.fi != par[x]){
		subs[x].insert({0,it.fi});
		subsinv[x][it.fi]=0;
		if (it.se) {
			pos[it.fi]=pos[x]+1;
			hp[it.fi]=hp[x];
		} else {
			pos[it.fi]=0;
			hp[it.fi]=it.fi;
		}
		dfs2(it.fi);
	}
}

void st_lenb (int l, int r, int x, int i) {
	if (l == r) return;
	if (r == l+1) {
		st_len[i][x] = distp[stid[i][r]];
		return;
	} int m = (l+r)/2;
	st_lenb(l,m,2*x+1,i);
	st_lenb(m,r,2*x+2,i);
	st_len[i][x] = st_len[i][2*x+1] + st_len[i][2*x+2];
}

ll st_lene(int l, int r, int dl, int dr, int x, int i) {
	if (l == r) return 0;
	if (l == dl && r == dr)  {
		return st_len[i][x];
	} int m = (l+r)/2;
	if (dr <= m) {return st_lene(l,m,dl,dr,2*x+1,i);}
	else if (dl >= m) {return st_lene(m,r,dl,dr,2*x+2,i);}
	else {
		ll x1 = st_lene(l,m,dl,m,2*x+1,i), x2 = st_lene(m,r,m,dr,2*x+2,i);
		return x1+x2;
	}
	return 0;
}

ll dist(int x) {
	if (x == 0) return 0;
	if (pos[x] == 0) {
		return distp[x] + dist(par[x]);
	}
	return st_lene(0,md[hp[x]],0,pos[x],0,hp[x]) + dist(hp[x]);
}

void st_fromrtu(int l, int r, int dl, int dr, int x, int i, ll v, int mode) {
	if (l == r) return;
	if (l == dl && r == dr) {
		if (mode) {st_fromrt[i][x].fi += v; return;}
		else {st_fromrt[i][x].se += v; return;}
	}
	int m = (l+r)/2;
	if (dr <= m) {st_fromrtu(l,m,dl,dr,2*x+1,i,v,mode);}
	else if (dl >= m) {st_fromrtu(m,r,dl,dr,2*x+2,i,v,mode);}
	else {
		st_fromrtu(l,m,dl,m,2*x+1,i,v,mode);
		st_fromrtu(m,r,m,dr,2*x+2,i,v,mode);
	}
}

ll st_fromrte(int l, int r, int d, int x, int i, int mode) {
	if (l == r) return 0;
	if (l == r-1) {
		if (mode) {return st_fromrt[i][x].fi;}
		else return st_fromrt[i][x].se;
	}
	int m = (l+r)/2;
	if (mode) {
		if (d <= m) {return st_fromrt[i][x].fi + st_fromrte(l,m,d,2*x+1,i,mode);}
		else if (d > m) {return st_fromrt[i][x].fi + st_fromrte(m,r,d,2*x+2,i,mode);}
	} else {
		if (d < m) {return st_fromrt[i][x].se + st_fromrte(l,m,d,2*x+1,i,mode);}
		else if (d >= m) {return st_fromrt[i][x].se + st_fromrte(m,r,d,2*x+2,i,mode);}
	}
	return 0;
}

ll up_fromrt(int x, ll v) {
	if (x == 0) return 0;
	if (pos[x] == 0) {
		valfromrt[x] += v*distp[x];
		return v*distp[x] + up_fromrt(par[x], v);
	}
	st_fromrtu(0,md[hp[x]],0,pos[par[x]],0,hp[x],v,1);
	st_fromrtu(0,md[hp[x]],pos[par[x]],md[hp[x]],0,hp[x],v*st_lene(0,md[hp[x]],0,pos[x],0,hp[x]),0);
	return up_fromrt(hp[x], v) + v*st_lene(0,md[hp[x]],0,pos[x],0,hp[x]);
}

ll ev_fromrt(int x) {
	if (x == 0) return 0;
	if (pos[x] == 0) return ev_fromrt(par[x]) + valfromrt[x];
	return ev_fromrt(hp[x])+ st_fromrte(0,md[hp[x]],pos[x],0,hp[x],1)*st_lene(0,md[hp[x]],0,pos[x],0,hp[x]) + st_fromrte(0,md[hp[x]],pos[par[x]],0,hp[x],0);
}

void st_cityu(int l, int r, int dl, int dr, int x, int i, ll v) {
	if (l == dl && r == dr) {
		st_city[i][x] += v;
		return;
	} int m = (l+r)/2;
	if (dr <= m) {st_cityu(l,m,dl,dr,2*x+1,i,v);}
	else if (dl >= m+1) {st_cityu(m+1,r,dl,dr,2*x+2,i,v);}
	else {
		st_cityu(l,m,dl,m,2*x+1,i,v);
		st_cityu(m+1,r,m+1,dr,2*x+2,i,v);
	}
}

void up_city(int x, int p, int s, ll dif, bool b) {
	if (x != s) {
		subs[x].erase({subsinv[x][p],p});
		subs[x].insert({subsinv[x][p]+dif,p});
		subsinv[x][p] += dif;
	}
	if (((int)al[x].size()>1 || x == 0) && !b) st_cityu(0,md[hp[x]],pos[x]+1,md[hp[x]],0,hp[x],dif);
	if (x == 0) {}
	else if (pos[x] == 0) {
		up_city(par[x],x,s,dif,0);
	} else {
		up_city(hp[x],stid[hp[x]][1],s,dif,1);
	}
}

ll st_citye(int l, int r, int d, int x, int i) {
	if (l == r) {
		return st_city[i][x];
	} int m = (l+r)/2;
	if (d <= m) {return st_city[i][x] + st_citye(l,m,d,2*x+1,i);}
	else return st_city[i][x] + st_citye(m+1,r,d,2*x+2,i);
}

int findz (int x, ll v) {
	if (subs[x].empty()) return x;
	auto it = subs[x].end(); it--;
	if (it->fi <= v) return x;
	else if (pos[it->se] == 0) return findz(it->se,v);
	else {
		int l = 1, r = md[x];
		while (r >l) {
			int m = (l+r+1)/2;
			ll d = st_citye(0,md[x],m,0,x);
			if (d <= v) {l = m;}
			else r = m-1;
		}
		if (subs[stid[x][l]].empty()) return stid[x][l];
		auto it = subs[stid[x][l]].end(); it--;
		if (it->fi <= v) return stid[x][l];
		else return findz(it->se,v);
	}
}

void init(int N, std::vector<int> U, std::vector<int> V, std::vector<int> T, std::vector<int> W) {
	W[0]++;
	n = N; w = W;
	al.resize(n); distp.resize(n);par.resize(n), hp.resize(n), pos.resize(n); par[0]=-1; hp[0]=0; pos[0]=0; 
	st_len.resize(n); st_fromrt.resize(n), st_city.resize(n); stid.resize(n);
	md.resize(n); subs.resize(n); subsinv.resize(n); valfromrt.resize(n);
	F(i,0,n-1) {
		al[U[i]].push_back({V[i],T[i]});
		al[V[i]].push_back({U[i],T[i]});
	}
	dfs1(0);
	dfs2(0);
	F(i,0,n) if (pos[i]== 0 && md[i] != 0) st_lenb(0,md[i],0,i);
	F(i,0,n) {
		if (W[i]!=0) {
			totw += W[i];
			up_city(i,i,i,W[i],0);
			offtort += w[i];
			sfromrt += up_fromrt(i,w[i]);
		}
	}
	return;
}

long long max_time(int S, int X) {
	ll dif = (ll)(X-w[S]) + (S == 0 ? 1 : 0);
	totw += dif;
	w[S] += dif;
	up_city(S,S,S,dif,0);
	int z = findz(0,totw/2);
	offtort += dif;
	sfromrt += up_fromrt(S,dif);
	return 2*(sfromrt - 2*ev_fromrt(z) + offtort*dist(z));
}
