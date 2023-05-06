#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int T,n,x;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&x);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&ar[i]);
		sort(ar,ar+n);
		int ans = 0 , rem = n , i = 0;
		while(i < n) {
			if(ar[i] <= x/2)
				i++;
			else if(ar[i] <= x) {
				rem--;
				ans++;
				x = 2*ar[i++];
			}
			else if(2*x < ar[n-1]) {
				ans++;
				x *= 2;
			}
			else {
				if(ar[n-1] % 2 == 0)
					x = 2*ar[n-1];
				else
					x = 2*(ar[n-1]-1);
				rem--;
				ans += 2;
				ar[n-1] = 0;
			}
		}
		printf("%d\n",ans+rem);
	}
	return 0;
}
