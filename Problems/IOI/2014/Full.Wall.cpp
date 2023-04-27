#include <bits/stdc++.h>
#include "wall.h"
#define fi first
#define se second
#define maxn 2000001
using namespace std;
typedef pair<int,int> pi;

int n,k;
int ids[maxn];
pi tree[4*maxn];
pi lazy[4*maxn];

void init(int x , int y , int id) {
	tree[id] = pi(0,0);
	lazy[id] = pi(-1,-1);
	if(x == y) {
		ids[x] = id;
		return;
	}
	int mid = (x+y) >> 1;
	init(x,mid,2*id);
	init(mid+1,y,2*id+1);
}

void pushLazy(pi& s , pi& t , int id , bool further) {
	if(s.fi != -1 && s.se != -1) {
		if(t.fi == -1 && t.se == -1)
			t = s;
		else if(t.fi != -1 && t.se == -1) {
			if(t.fi <= s.se)
				t = pi(s.se,s.se);
			else if(t.fi >= s.fi)
				t = s;
			else
				t.se = s.se;
		}
		else if(t.fi == -1 && t.se != -1) {
			if(t.se >= s.fi)
				t = pi(s.fi,s.fi);
			else if(t.se <= s.se)
				t = s;
			else
				t.fi = s.fi;
		}
		else {
			if(t.fi <= s.se)
				t = pi(s.se,s.se);
			else if(t.se >= s.fi)
				t = pi(s.fi,s.fi);
			else {
				t.se = max(t.se,s.se);
				t.fi = min(t.fi,s.fi);
			}
		}
	}
	else if(s.fi != -1) {
		if(t.fi == -1 && t.se == -1)
			t.fi = s.fi;
		else if(t.fi != -1 && t.se == -1)
			t.fi = min(t.fi,s.fi);
		else if(t.fi == -1 && t.se != -1) {
			if(s.fi <= t.se)
				t = pi(s.fi,s.fi);
			else
				t.fi = s.fi;
		}
		else {
			if(s.fi <= t.se)
				t = pi(s.fi,s.fi);
			else
				t.fi = min(t.fi,s.fi); 
		}
	}
	else if(s.se != -1) {
		if(t.fi == -1 && t.se == -1)
			t.se = s.se;
		else if(t.fi == -1 && t.se != -1)
			t.se = max(t.se,s.se);
		else if(t.fi != -1 && t.se == -1) {
			if(s.se >= t.fi)
				t = pi(s.se,s.se);
			else
				t.se = s.se;
		}
		else {
			if(s.se >= t.fi)
				t = pi(s.se,s.se);
			else
				t.se = max(t.se,s.se);
		}
	}
	if(further) {
		pushLazy(lazy[id],lazy[2*id],2*id,false);
		pushLazy(lazy[id],lazy[2*id+1],2*id+1,false);
	}
}

void updateMin(int cx , int cy , int qx , int qy , int val , int id) {
	pushLazy(lazy[id],tree[id],id,cx!=cy);
	lazy[id] = pi(-1,-1);
	if(qy < cx || cy < qx)
		return;
	if(qx <= cx && cy <= qy) {
		lazy[id].fi = val;
		pushLazy(lazy[id],tree[id],id,cx!=cy);
		lazy[id] = pi(-1,-1);
		return;
	}
	int mid = (cx + cy) >> 1;
	updateMin(cx,mid,qx,qy,val,2*id);
	updateMin(mid+1,cy,qx,qy,val,2*id+1);
	tree[id].fi = min(tree[2*id].fi,tree[2*id+1].fi);
	tree[id].se = max(tree[2*id].se,tree[2*id+1].se);
}

void updateMax(int cx , int cy , int qx , int qy , int val , int id) {
	pushLazy(lazy[id],tree[id],id,cx!=cy);
	lazy[id] = pi(-1,-1);
	if(qy < cx || cy < qx)
		return;
	if(qx <= cx && cy <= qy) {
		lazy[id].se = val;
		pushLazy(lazy[id],tree[id],id,cx!=cy);
		lazy[id] = pi(-1,-1);
		return;
	}
	int mid = (cx + cy) >> 1;
	updateMax(cx,mid,qx,qy,val,2*id);
	updateMax(mid+1,cy,qx,qy,val,2*id+1);
	tree[id].fi = min(tree[2*id].fi,tree[2*id+1].fi);
	tree[id].se = max(tree[2*id].se,tree[2*id+1].se);
}

void query(int x , int y , int id) {
	pushLazy(lazy[id],tree[id],id,x!=y);
	lazy[id] = pi(-1,-1);
	if(x == y)
		return;
	int mid = (x+y) >> 1;
	query(x,mid,2*id);
	query(mid+1,y,2*id+1);
}

void buildWall(int N, int K, int op[], int l[], int r[], int h[], int ans[]) {
	n = N , k = K;
	init(0,n-1,1);
	for( int i = 0 ; i < k ; i++ ) {
		if(op[i] == 1)
			updateMax(0,n-1,l[i],r[i],h[i],1);
		else
			updateMin(0,n-1,l[i],r[i],h[i],1);
	}
	query(0,n-1,1);
	for( int i = 0 ; i < n ; i++ )
		ans[i] = tree[ids[i]].se;
}
