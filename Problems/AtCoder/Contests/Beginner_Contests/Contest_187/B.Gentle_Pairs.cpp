#include <bits/stdc++.h>
#define maxn 1000
using namespace std;

int n,ans;
int x[maxn];
int y[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		cin >> x[i] >> y[i];
	for( int i = 0 ; i < n ; i++ )
		for( int j = i+1 ; j < n ; j++ ) {
			int dy = abs(y[j]-y[i]);
			int dx = abs(x[j]-x[i]);
			if(dy <= dx)
				ans++;
		}
	printf("%d\n",ans);
	return 0;
}
