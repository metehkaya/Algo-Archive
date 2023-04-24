#include <bits/stdc++.h>
#define maxn 10003
using namespace std;

int n,mn,mx;
int ar[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 1 ; i <= n ; i++ )
		if(ar[i] == 1) {
			mn++ , mx++;
			if(ar[i+1] == 1)
				mx++;
			ar[i] = ar[i+1] = 0;
		}
	printf("%d %d\n",mn,mx);
	return 0;
}
