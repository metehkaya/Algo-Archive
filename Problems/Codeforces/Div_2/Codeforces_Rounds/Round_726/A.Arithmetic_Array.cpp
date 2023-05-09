#include <bits/stdc++.h>
using namespace std;

int T,n;
int ar[50];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		int sum = 0;
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&ar[i]);
			sum += ar[i];
		}
		if(sum == n)
			puts("0");
		else if(sum < n)
			puts("1");
		else
			printf("%d\n",sum-n);
	}
	return 0;
}
