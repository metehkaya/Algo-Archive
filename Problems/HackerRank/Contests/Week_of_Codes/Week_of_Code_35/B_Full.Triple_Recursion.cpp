#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int a[100][100];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < n ; j++ ) {
			if(!i && !j)
				a[i][j] = m;
			else if(i == j)
				a[i][j] = a[i-1][j-1] + k;
			else if(i > j)
				a[i][j] = a[i-1][j] - 1;
			else
				a[i][j] = a[i][j-1] - 1;
		}
	for( int i = 0 ; i < n ; i++ , puts("") )
		for( int j = 0 ; j < n ; j++ )
			printf("%d ",a[i][j]);
	return 0;
}
