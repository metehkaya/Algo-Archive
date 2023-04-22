#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
typedef long long LL;

int T,n,a,b;
int ar[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

double f(int x , LL len , double alan) {
	int k = x/len;
	double res = k*alan;
	x %= len;
	for( int i = 0 ; i < n ; i++ )
		if(ar[i]) {
			if(x >= ar[i]) {
				x -= ar[i];
				res += (double) ar[i] * ar[i] / 2.0;
			}
			else {
				res += (double) x * x / 2.0;
				break;
			}
		}
	return res;
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d",&n,&a,&b);
		LL sum = 0;
		double total = 0;
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&ar[i]);
			sum += ar[i];
			total += (double) ar[i] * ar[i] / 2.0;
		}
		double ans = f(b,sum,total)-f(a,sum,total);
		ans /= (b-a);
		printf("Case #%d: %.7lf\n",tc,ans);
	}
	return 0;
}
