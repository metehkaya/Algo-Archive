#include <bits/stdc++.h>
#include "ricehub.h"
using namespace std;

long long getCost(int l , int r , int x[], long long sum[]) {
	int m = (l+r) >> 1;
	long long cost = 0;
	if(l < m)
		cost += (m-l) * (long long) x[m-1] - (sum[m-1] - sum[l-1]);
	if(m < r)
		cost += (sum[r] - sum[m]) - (r-m) * (long long) x[m-1];
	return cost;
}

int besthub(int n, int xmax, int x[], long long budget) {
	int ans = 0;
	long long sum[n+1];
	sum[0] = 0;
	for( int i = 1 ; i <= n ; i++ )
		sum[i] = sum[i-1] + x[i-1];
	for( int l = 1 , r = 1 ; l <= n ; l++ ) {
		r = max(l,r);
		while(r < n && getCost(l,r+1,x,sum) <= budget)
			r++;
		ans = max(ans,r-l+1);
	}
	return ans;
}
