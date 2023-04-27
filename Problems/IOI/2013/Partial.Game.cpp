#include <bits/stdc++.h>
#include "game.h"
using namespace std;
typedef long long LL;

struct Quad {
	LL val;
	Quad* child[2][2];
	Quad() {
		val = 0;
		child[0][0] = NULL;
		child[0][1] = NULL;
		child[1][0] = NULL;
		child[1][1] = NULL;
	}
}*root;

LL gcd(LL x, LL y) {
    if(!y)
    	return x;
    return gcd(y,x%y);
}

int n,m;

void init(int xl , int xr , int yl , int yr , Quad* node) {
	if(xl == xr && yl == yr)
		return;
	int xm = (xl+xr)>>1;
	int ym = (yl+yr)>>1;
	if(xl == xr) {
		node->child[0][0] = new Quad();
		init(xl,xm,yl,ym,node->child[0][0]);
		node->child[0][1] = new Quad();
		init(xl,xm,ym+1,yr,node->child[0][1]);
	}
	else if(yl == yr) {
		node->child[0][0] = new Quad();
		init(xl,xm,yl,ym,node->child[0][0]);
		node->child[1][0] = new Quad();
		init(xm+1,xr,yl,ym,node->child[1][0]);
	}
	else {
		node->child[0][0] = new Quad();
		init(xl,xm,yl,ym,node->child[0][0]);
		node->child[0][1] = new Quad();
		init(xl,xm,ym+1,yr,node->child[0][1]);
		node->child[1][0] = new Quad();
		init(xm+1,xr,yl,ym,node->child[1][0]);
		node->child[1][1] = new Quad();
		init(xm+1,xr,ym+1,yr,node->child[1][1]);
	}
}

void init(int R, int C) {
	n = R;
	m = C;
	root = new Quad();
	init(0,n-1,0,m-1,root);
}

LL update(int xl , int xr , int yl , int yr , int X , int Y , LL VAL , Quad* node) {
	if(xr < X || X < xl)
		return node->val;
	if(yr < Y || Y < yl)
		return node->val;
	if(xl == xr && yl == yr)
		return node->val = VAL;
	LL GCD = 0;
	int xm = (xl+xr)>>1;
	int ym = (yl+yr)>>1;
	if(xl == xr) {
		GCD = gcd(GCD, update(xl,xm,yl,ym,X,Y,VAL,node->child[0][0]));
		GCD = gcd(GCD, update(xl,xm,ym+1,yr,X,Y,VAL,node->child[0][1]));
	}
	else if(yl == yr) {
		GCD = gcd(GCD, update(xl,xm,yl,ym,X,Y,VAL,node->child[0][0]));
		GCD = gcd(GCD, update(xm+1,xr,yl,ym,X,Y,VAL,node->child[1][0]));
	}
	else {
		GCD = gcd(GCD, update(xl,xm,yl,ym,X,Y,VAL,node->child[0][0]));
		GCD = gcd(GCD, update(xl,xm,ym+1,yr,X,Y,VAL,node->child[0][1]));
		GCD = gcd(GCD, update(xm+1,xr,yl,ym,X,Y,VAL,node->child[1][0]));
		GCD = gcd(GCD, update(xm+1,xr,ym+1,yr,X,Y,VAL,node->child[1][1]));
	}
	return node->val = GCD;
}

void update(int P, int Q, LL K) {
    update(0,n-1,0,m-1,P,Q,K,root);
}

LL query(int xl , int xr , int yl , int yr , int X1 , int Y1 , int X2 , int Y2 , Quad* node) {
	if(xr < X1 || X2 < xl)
		return 0;
	if(yr < Y1 || Y2 < yl)
		return 0;
	if(X1 <= xl && xr <= X2 && Y1 <= yl && yr <= Y2)
		return node->val;
	LL GCD = 0;
	int xm = (xl+xr)>>1;
	int ym = (yl+yr)>>1;
	if(xl == xr) {
		GCD = gcd(GCD, query(xl,xm,yl,ym,X1,Y1,X2,Y2,node->child[0][0]));
		GCD = gcd(GCD, query(xl,xm,ym+1,yr,X1,Y1,X2,Y2,node->child[0][1]));
	}
	else if(yl == yr) {
		GCD = gcd(GCD, query(xl,xm,yl,ym,X1,Y1,X2,Y2,node->child[0][0]));
		GCD = gcd(GCD, query(xm+1,xr,yl,ym,X1,Y1,X2,Y2,node->child[1][0]));
	}
	else {
		GCD = gcd(GCD, query(xl,xm,yl,ym,X1,Y1,X2,Y2,node->child[0][0]));
		GCD = gcd(GCD, query(xl,xm,ym+1,yr,X1,Y1,X2,Y2,node->child[0][1]));
		GCD = gcd(GCD, query(xm+1,xr,yl,ym,X1,Y1,X2,Y2,node->child[1][0]));
		GCD = gcd(GCD, query(xm+1,xr,ym+1,yr,X1,Y1,X2,Y2,node->child[1][1]));
	}
	return GCD;
}

LL calculate(int P, int Q, int U, int V) {
    return query(0,n-1,0,m-1,P,Q,U,V,root);
}
