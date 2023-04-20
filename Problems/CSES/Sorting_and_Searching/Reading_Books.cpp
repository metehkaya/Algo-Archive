#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
typedef long long LL;

int n;
int ar[maxn];
LL sum[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	sort(ar+1,ar+n+1);
	for( int i = 1 ; i <= n ; i++ )
		sum[i] = sum[i-1] + ar[i];
	int last = 0;
	for( int i = 1 ; i <= n && sum[i] <= sum[n]-sum[i] ; i++ )
		last = i;
	if(last == n-1)
		printf("%d\n",2*ar[n]);
	else
		printf("%lld\n",sum[n]);
	return 0;
}