#include <bits/stdc++.h>
#define maxn 100
using namespace std;

int n;
int x[maxn];
int y[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d%d",&x[i],&y[i]);
	for( int i = 0 ; i < n ; i++ )
		for( int j = i+1 ; j < n ; j++ )
			for( int k = j+1 ; k < n ; k++ )
				if( (x[k]-x[i]) * (y[j]-y[i]) == (x[j]-x[i]) * (y[k]-y[i]) ) {
					puts("Yes");
					return 0;
				}
	puts("No");
	return 0;
}
