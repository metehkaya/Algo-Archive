#include <bits/stdc++.h>
#define maxn 103
using namespace std;

int n;
int ar[maxn][2];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d%d",&ar[i][0],&ar[i][1]);
	for( int i = 2 ; i < n ; i++ )
		if(ar[i-1][0] == ar[i-1][1])
			if(ar[i][0] == ar[i][1])
				if(ar[i+1][0] == ar[i+1][1]) {
					puts("Yes");
					exit(0);
				}
	puts("No");
	return 0;
}
