#include <bits/stdc++.h>
#define maxn 100003
using namespace std;

int n,ans;
int cnt[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i < n ; i++ )
		for( int j = i ; j < n ; j += i )
			ans++;
	printf("%d\n",ans);
	return 0;
}
