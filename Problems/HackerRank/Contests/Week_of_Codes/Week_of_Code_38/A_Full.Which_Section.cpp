#include <bits/stdc++.h>
#define maxm 500
using namespace std;

int T,n,k,m;
int ar[maxm];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d",&n,&k,&m);
		for( int i = 0 ; i < m ; i++ )
			scanf("%d",&ar[i]);
		int sum = 0;
		for( int i = 0 ; i < m ; i++ ) {
			sum += ar[i];
			if(sum >= k) {
				printf("%d\n",i+1);
				break;
			}
		}
	}
	return 0;
}
