#include <bits/stdc++.h>
#define maxn 25
using namespace std;
typedef long long LL;

int n,q;
LL ar[maxn][maxn];

void printStep(int r , int c) {
	printf("%d %d\n",r+1,c+1);
	fflush(stdout);
}

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		for( int j = 0 ; j < n ; j++ ) {
			LL val = (1LL << (i+j));
			ar[i][j] = (i % 2 == 0) ? val : 0LL;
			printf("%lld ",ar[i][j]);
		}
		printf("\n");
		fflush(stdout);
	}
	scanf("%d",&q);
	while(q--) {
		LL sum;
		scanf("%lld",&sum);
		int r = 0 , c = 0;
		printStep(r,c);
		while(r != n-1 || c != n-1) {
			LL val = (1LL << (r+c+1));
			val = (sum & val);
			if(c+1 < n && ar[r][c+1] == val)
				c++;
			else
				r++;
			printStep(r,c);
		}
	}
	return 0;
}
