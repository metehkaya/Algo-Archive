#include <bits/stdc++.h>
#define maxn 200003
using namespace std;

int T,n;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		set<int> myset;
		for( int i = 1 ; i <= n ; i++ ) {
			scanf("%d",&ar[i]);
			myset.insert(ar[i]);
		}
		int sz = myset.size();
		sort(ar+1,ar+n+1);
		if(sz == 1 || n == 2) {
			for( int i = 1 ; i <= n ; i++ )
				printf("%d ",ar[i]);
			continue;
		}
		int minh = INT_MAX;
		int best = -1;
		for( int i = 1 ; i < n ; i++ ) {
			int l = ar[i];
			int r = ar[i+1];
			if(r-l < minh) {
				minh = r-l;
				best = i+1;
			}
		}
		for( int i = best ; i <= n ; i++ )
			printf("%d ",ar[i]);
		for( int i = 1 ; i < best ; i++ )
			printf("%d ",ar[i]);
		puts("");
	}
	return 0;
}
