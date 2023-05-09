#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int T,n;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 0 ; tc < T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&ar[i]);
		set<int> s;
		s.insert(++ar[n-1]);
		for( int i = n-2 ; i >= 0 ; i-- ) {
			if(ar[i]+1 < ar[i+1])
				ar[i]++;
			s.insert(ar[i]);
		}
		printf("%d\n",s.size());
	}
	return 0;
}
