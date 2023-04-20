#include <bits/stdc++.h>
#define maxn 200000
using namespace std;

int n,x,ans;
int ar[maxn];

int main() {
	scanf("%d%d",&n,&x);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 0 , j = 0 , sum = 0 ; i < n ; i++ ) {
		while(j < n && sum < x)
			sum += ar[j++];
		if(sum == x)
			ans++;
		sum -= ar[i];
	}
	printf("%d\n",ans);
	return 0;
}