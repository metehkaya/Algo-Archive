#include <bits/stdc++.h>
#define maxn 200000
using namespace std;

int n,x,ans;
int ar[maxn];

int main() {
	scanf("%d%d",&n,&x);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	sort(ar,ar+n);
	for( int i = n-1 , j = 0 ; i >= j ; i-- ) {
		ans++;
		if(j < i && ar[i]+ar[j] <= x)
			j++;
	}
	printf("%d\n",ans);
	return 0;
}