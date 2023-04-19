#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
int mn[2];
int mx[2];

int main() {
	scanf("%d",&n);
	mn[0] = mn[1] = INT_MAX;
	mx[0] = mx[1] = INT_MIN;
	for( int i = 0 , x,y ; i < n ; i++ ) {
		scanf("%d%d",&x,&y);
		mn[0] = min(mn[0],x+y);
		mn[1] = min(mn[1],x-y);
		mx[0] = max(mx[0],x+y);
		mx[1] = max(mx[1],x-y);
	}
	LL diff1 = (LL) mx[0]-mn[0];
	LL diff2 = (LL) mx[1]-mn[1];
	printf("%lld\n",max(diff1,diff2));
	return 0;
}
