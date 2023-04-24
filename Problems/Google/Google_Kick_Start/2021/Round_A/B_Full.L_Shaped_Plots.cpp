#include <bits/stdc++.h>
#define maxn 1000
using namespace std;

int T,n,m,ans;
int l[maxn][maxn];
int r[maxn][maxn];
int u[maxn][maxn];
int d[maxn][maxn];
int ar[maxn][maxn];

void g(int x , int y) {
	if(x >= 4 && y >= 2)
		ans += min(y,x/2) - 1;
}

void f(int x , int y) {
	g(x,y);
	g(y,x);
}

void func1() {
	for( int i = 0 ; i < n ; i++ ) {
		for( int j1 = 0 , j2 = 0 ; j1 < m ; j1 = j2 ) {
			if(ar[i][j1] == 0) {
				l[i][j1] = r[i][j1] = 0;
				j2++;
			}
			else {
				while(j2 < m && ar[i][j2])
					j2++;
				int len = j2-j1;
				for( int k = 1 ; k <= len ; k++ ) {
					l[i][j1+k-1] = k;
					r[i][j2-k] = k;
				}
			}
		}
	}
}

void func2() {
	for( int j = 0 ; j < m ; j++ ) {
		for( int i1 = 0 , i2 = 0 ; i1 < n ; i1 = i2 ) {
			if(ar[i1][j] == 0) {
				u[i1][j] = d[i1][j] = 0;
				i2++;
			}
			else {
				while(i2 < n && ar[i2][j])
					i2++;
				int len = i2-i1;
				for( int k = 1 ; k <= len ; k++ ) {
					u[i1+k-1][j] = k;
					d[i2-k][j] = k;
				}
			}
		}
	}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&m);
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ )
				scanf("%d",&ar[i][j]);
		func1();
		func2();
		ans = 0;
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ )
				if(ar[i][j]) {
					f(u[i][j],l[i][j]);
					f(u[i][j],r[i][j]);
					f(d[i][j],l[i][j]);
					f(d[i][j],r[i][j]);
				}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
