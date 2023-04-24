#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int ar[101][101];

void f(int i , int j) {
	if(j == 1)
		ans += ar[i][j];
	else
		ans += max(0,ar[i][j]-ar[i][j-1]);
}

void g(int i , int j) {
	if(j == m)
		ans += ar[i][j];
	else
		ans += max(0,ar[i][j]-ar[i][j+1]);
}

void h(int i , int j) {
	if(i == 1)
		ans += ar[i][j];
	else
		ans += max(0,ar[i][j]-ar[i-1][j]);
}

void k(int i , int j) {
	if(i == n)
		ans += ar[i][j];
	else
		ans += max(0,ar[i][j]-ar[i+1][j]);
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ )
			scanf("%d",&ar[i][j]);
	ans = 2*n*m;
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ) {
			f(i,j);
			g(i,j);
			h(i,j);
			k(i,j);
		}
	printf("%d\n",ans);
	return 0;
}
