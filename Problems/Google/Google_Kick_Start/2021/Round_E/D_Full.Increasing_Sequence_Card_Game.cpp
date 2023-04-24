#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;
typedef long long LL;

LL n;
int T;
double res[maxn];

int main() {
	for( int i = 1 ; i < maxn ; i++ )
		res[i] = res[i-1] + 1.0 / i;
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n;
		double ans;
		if(n < maxn)
			ans = res[n];
		else
			ans = res[maxn-1] + log(n+1) - log(maxn);
		printf("Case #%d: %.7lf\n",tc,ans);
	}
	return 0;
}
