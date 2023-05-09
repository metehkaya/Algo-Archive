#include <bits/stdc++.h>
using namespace std;

int T,n;
int p[100][100];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		if(n%2) {
			int k = n/2;
			for( int i = 0 ; i < n ; i++ ) {
				for( int j = 1 ; j <= k ; j++ ) {
					int i2 = (i+j)%n;
					p[i][i2] = 1;
					p[i2][i] = -1;
				}
			}
		}
		else {
			int k = n/2-1;
			for( int i = 0 ; i < n ; i++ ) {
				for( int j = 1 ; j <= k ; j++ ) {
					int i2 = (i+j)%n;
					p[i][i2] = 1;
					p[i2][i] = -1;
				}
				int j = (i+k+1)%n;
				p[i][j] = p[j][i] = 0;
			}
		}
		for( int i = 0 ; i < n ; i++ )
			for( int j = i+1 ; j < n ; j++ )
				printf("%d ",p[i][j]);
		puts("");
	}
	return 0;
}
