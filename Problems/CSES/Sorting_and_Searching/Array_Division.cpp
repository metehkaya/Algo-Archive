#include <bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long LL;

int n,k;
int ar[maxn];

bool check(LL limit) {
	LL sum = 0;
	int cnt = 0;
	for( int i = 0 , j = 0 ; i < n ; i = j , sum = 0 , cnt++ ) {
		while(j < n && sum + ar[j] <= limit)
			sum += ar[j++];
		if(i == j)
			return false;
	}
	return cnt <= k;
}

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	LL l = 1 , r = (1LL << 50) , ans;
	while(l <= r) {
		LL m = (l+r) >> 1;
		if(check(m))
			ans = m , r = m-1;
		else
			l = m+1;
	}
	printf("%lld\n",ans);
	return 0;
}