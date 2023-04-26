#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;

int n,lis;
int len[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 , val ; i <= n ; i++ ) {
		scanf("%d",&val);
		len[val] = len[val-1]+1;
		lis = max(lis,len[val]);
	}
	printf("%d\n",n-lis);
	return 0;
}