#include <bits/stdc++.h>
#define maxn 200003
using namespace std;
typedef long long LL;

int n;
LL ar[maxn];

int main() {
	scanf("%d",&n);
	LL mx = 0;
	LL sum1 = 0 , sum2 = 0;
	for( int i = 0 ; i < n ; i++ ) {
		scanf("%lld",&ar[i]);
		sum1 += max(ar[i],-ar[i]);
		sum2 += ar[i]*ar[i];
		mx = max(mx,max(ar[i],-ar[i]));
	}
	printf("%lld\n",sum1);
	printf("%.10lf\n",sqrt(sum2));
	printf("%lld\n",mx);
	return 0;
}
