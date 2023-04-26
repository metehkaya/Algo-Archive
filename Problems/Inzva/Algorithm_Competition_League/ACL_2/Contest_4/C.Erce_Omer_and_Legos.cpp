#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
typedef long long LL;

int n;
int ar[maxn];
LL sum,total;

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		scanf("%d",&ar[i]);
		sum += ar[i];
	}
	sort(ar,ar+n);
	int mx = 0;
	for( int i = 0 ; i < n ; i++ ) {
		mx = max(mx,ar[i]);
		total += mx++;
	}
	printf("%lld\n",total-sum);
	return 0;
}
