#include <bits/stdc++.h>
#define maxn 100
#define maxk 100001
using namespace std;

int n,k;
int ar[maxn];
bool dp[maxk];

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 1 ; i <= k ; i++ )
		for( int j = 0 ; j < n && ar[j] <= i ; j++ )
			if( !dp[i-ar[j]] ) {
				dp[i] = true;
				break;
			}
	if(dp[k])
		puts("First");
	else
		puts("Second");
	return 0;
}
