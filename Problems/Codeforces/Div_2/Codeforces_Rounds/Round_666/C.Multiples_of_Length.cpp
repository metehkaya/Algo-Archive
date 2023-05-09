#include <bits/stdc++.h>
#define maxn 100003
using namespace std;
typedef long long LL;

int n;
LL ar[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%I64d",&ar[i]);
	if(n <= 3) {
		for( int i = 1 ; i <= n ; i++ ) {
			printf("%d %d\n",i,i);
			printf("%I64d\n",-ar[i]);
		}
		for( int i = 0 ; i < 3-n ; i++ ) {
			puts("1 1");
			puts("0");
		}
		return 0;
	}
	printf("%d %d\n",n,n);
	printf("%I64d\n",-ar[n]);
	ar[n] = 0;
	printf("1 %d\n",n-1);
	for( int i = 1 ; i < n ; i++ ) {
		LL val = max(ar[i],-ar[i])%n;
		if(ar[i] < 0)
			val = n-val;
		printf("%I64d ",val*(n-1));
		ar[i] += val*(n-1);
	}
	puts("");
	printf("1 %d\n",n);
	for( int i = 1 ; i <= n ; i++ )
		printf("%I64d ",-ar[i]);
	puts("");
	return 0;
}
