#include <bits/stdc++.h>
using namespace std;

int n,ans;
int ar[100];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	sort(ar,ar+n);
	for( int i = 0 ; i < n ; i++ )
		for( int j = i+1 ; j < n ; j++ )
			for( int k = j+1 ; k < n ; k++ ) {
				if(ar[i] == ar[j] || ar[j] == ar[k])
					continue;
				if(ar[k] < ar[i]+ar[j])
					ans++;
			}
	printf("%d\n",ans);
	return 0;
}
