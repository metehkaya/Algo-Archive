#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T,n;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		LL sum = 0;
		bool ok = true;
		for( int i = 0 , x ; i < n ; i++ ) {
			scanf("%d",&x);
			sum += x;
			if(sum < i*(i+1)/2)
				ok = false;
		}
		if(ok)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
