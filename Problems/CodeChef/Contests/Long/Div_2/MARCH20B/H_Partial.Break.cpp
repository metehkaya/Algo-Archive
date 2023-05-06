#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int T,S,n;
int a[maxn];
int b[maxn];

int main() {
	scanf("%d%d",&T,&S);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&a[i]);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&b[i]);
		sort(a, a+n);
		sort(b, b+n);
		bool ans = true;
		for( int i = 0 ; i < n && ans ; i++ )
			if( a[i] >= b[i] )
				ans = false;
		if(ans) {
			int indexA=0,indexB=0;
			while(a[indexA] == a[0])
				indexA++;
			while(indexA < n) {
				while(indexB < n && b[indexB] < a[indexA])
					indexB++;
				if(indexB == n || b[indexB] > a[indexA])
					break;
				indexA++;
			}
			ans = (indexA == n);
		}
		if(ans)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
