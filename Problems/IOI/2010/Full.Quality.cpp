#include <bits/stdc++.h>
#include "quality.h"
#include "grader.h"
#define maxn 3001
using namespace std;

int sum[maxn][maxn];

int rectangle(int n, int m, int h, int w, int ar[3001][3001]) {
	int N = n*m , ans = -1;
	int l = 1 , r = N;
	while(l <= r) {
		int mid = (l+r) >> 1;
		memset(sum,0,sizeof(sum));
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 1 ; j <= m ; j++ ) {
				int add = (ar[i-1][j-1] <= mid) ? +1 : -1;
				sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + add;
			}
		bool ok = false;
		for( int row = h ; row <= n ; row++ )
			for( int col = w ; col <= m ; col++ ) {
				int total = sum[row][col] - sum[row-h][col] - sum[row][col-w] + sum[row-h][col-w];
				if(total > 0)
					ok = true;
			}
		if(ok)
			ans = mid , r = mid-1;
		else
			l = mid+1;
	}
	return ans;
}
