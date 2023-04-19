#include <bits/stdc++.h>
using namespace std;

int N,n,k,ans;
int ar[8][8];

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < n ; j++ )
			scanf("%d",&ar[i][j]);
	int perm[n];
	for( int i = 0 ; i < n ; i++ )
		perm[i] = i;
	do {
		if(perm[0] != 0)
			break;
		int t = 0;
		for( int i = 1 ; i < n ; i++ )
			t += ar[perm[i-1]][perm[i]];
		t += ar[perm[n-1]][0];
		if(t == k)
			ans++;
	}while(next_permutation(perm,perm+n));
	printf("%d\n",ans);
	return 0;
}
