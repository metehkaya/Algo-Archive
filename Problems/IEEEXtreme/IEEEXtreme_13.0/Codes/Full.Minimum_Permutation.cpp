#include <bits/stdc++.h>
#define maxn 100003
#define pb push_back
using namespace std;

int n,m;
int ar[maxn];
int rev[maxn];
vector<int> v[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		rev[ar[i]] = i;
	}
	for( int i=n+m , ind=n+1 ; i >= 1 ; i-- ) {
		if( rev[i] )
			ind = min( ind , rev[i] );
		else
			v[ind].pb(i);
	}
	for( int i = 1 ; i <= n ; i++ ) {
		for( int j = (int) v[i].size() - 1 ; j >= 0 ; j-- )
			printf("%d ", v[i][j]);
		printf("%d ", ar[i]);
	}
	for( int j = (int) v[n+1].size() - 1 ; j >= 0 ; j-- )
		printf("%d ", v[n+1][j]);
	return 0;
}
