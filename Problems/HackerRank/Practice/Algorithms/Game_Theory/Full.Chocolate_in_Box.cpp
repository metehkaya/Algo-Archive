#include <bits/stdc++.h>
#define maxn 1000000
using namespace std;

int n,ans,vxor;
int ar[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		scanf("%d",&ar[i]);
		vxor ^= ar[i];
	}
	for( int i = 0 ; i < n ; i++ ) {
		int tmp = vxor ^ ar[i];
		if(tmp < ar[i])
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
