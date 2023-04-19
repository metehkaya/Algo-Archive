#include <bits/stdc++.h>
#define maxn (1<<16)
using namespace std;

int n,N,mx,ans;
int ar[maxn];

int main() {
	scanf("%d",&n);
	N = (1<<n);
	bool secondHalf = false;
	for( int i = 0 ; i < N ; i++ ) {
		scanf("%d",&ar[i]);
		if(ar[i] > mx) {
			mx = ar[i];
			if(i >= N/2)
				secondHalf = true;
		}
	}
	mx = 0;
	int l = secondHalf ? 0 : N/2;
	int r = l + N/2;
	for( int i = l ; i < r ; i++ )
		if(ar[i] > mx) {
			mx = ar[i];
			ans = i;
		}
	printf("%d\n",ans+1);
	return 0;
}
