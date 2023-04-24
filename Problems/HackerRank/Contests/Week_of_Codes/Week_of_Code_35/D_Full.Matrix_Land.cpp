#include <bits/stdc++.h>
#define inf (1 << 30)
#define maxnm 4000003
using namespace std;

int n,m;
int ar[maxnm];
int lDp[maxnm];
int rDp[maxnm];
int lSum[maxnm];
int rSum[maxnm];
int lMin[maxnm];
int rMin[maxnm];

void read() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ )
			scanf("%d",&ar[m*(i-1)+j]);
}

void oneRow() {
	int ans = -inf;
	for( int i = 1 ; i <= m ; i++ ) {
		int val = lSum[m];
		if(i > 1)
			val -= lMin[i-1];
		if(i < m)
			val -= rMin[i+1];
		ans = max(ans,val);
	}
	printf("%d\n",ans);
	exit(0);
}

void preCalc() {
	for( int i = 1 , total ; i <= n ; i++ ) {
		total = ar[m*(i-1)+1];
		lSum[m*(i-1)+1] = total;
		lMin[m*(i-1)+1] = min(total,0);
		for( int j = 2 ; j <= m ; j++ ) {
			total += ar[m*(i-1)+j];
			lSum[m*(i-1)+j] = total;
			lMin[m*(i-1)+j] = min(lMin[m*(i-1)+j-1],total);
		}
		total = ar[m*i];
		rSum[m*i] = total;
		rMin[m*i] = min(total,0);
		for( int j = m - 1 ; j >= 1 ; j-- ) {
			total += ar[m*(i-1)+j];
			rSum[m*(i-1)+j] = total;
			rMin[m*(i-1)+j] = min(rMin[m*(i-1)+j+1],total);
		}
	}
}

void solve() {
	for( int i = 2 , best ; i <= n ; i++ ) {
		best = -inf;
		for( int j = 1 , val ; j <= m ; j++ ) {
			val = max(lDp[m*(i-2)+j],rDp[m*(i-2)+j]);
			if(j > 1)
				val -= lMin[m*(i-2)+j-1];
			best = max(best,val);
			lDp[m*(i-1)+j] = best;
			if(j < m)
				lDp[m*(i-1)+j] += rSum[m*(i-2)+j+1] - rMin[m*(i-2)+j+1];
			lDp[m*(i-1)+j] += lSum[m*(i-2)+j];
		}
		best = -inf;
		for( int j = m , val ; j >= 1 ; j-- ) {
			val = max(lDp[m*(i-2)+j],rDp[m*(i-2)+j]);
			if(j < m)
				val -= rMin[m*(i-2)+j+1];
			best = max(best,val);
			rDp[m*(i-1)+j] = best;
			if(j > 1)
				rDp[m*(i-1)+j] += lSum[m*(i-2)+j-1] - lMin[m*(i-2)+j-1];
			rDp[m*(i-1)+j] += rSum[m*(i-2)+j];
		}
	}
}

void print() {
	int ans = -inf;
	for( int i = 1 ; i <= m ; i++ ) {
		int val = max(lDp[m*(n-1)+i],rDp[m*(n-1)+i]);
		val += lSum[m*n];
		if(i > 1)
			val -= lMin[m*(n-1)+i-1];
		if(i < m)
			val -= rMin[m*(n-1)+i+1];
		ans = max(ans,val);
	}
	printf("%d\n",ans);
}

int main() {
	read();
	preCalc();
	if(n == 1)
		oneRow();
	solve();
	print();
	return 0;
}
