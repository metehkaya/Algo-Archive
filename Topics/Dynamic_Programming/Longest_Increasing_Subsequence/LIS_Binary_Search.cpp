#include <bits/stdc++.h>
#define maxn 100003
using namespace std;

int n,ans;
int ar[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	vector<int> last(n+1,INT_MAX);
	last[0] = INT_MIN;
	for( int i = 1 ; i <= n ; i++ ) {
		int idx = upper_bound(last.begin(),last.end(),ar[i]) - last.begin();
		if(last[idx-1] < ar[i] && ar[i] < last[idx]) {
			last[idx] = ar[i];
			ans = max(ans,idx);
		}
	}
	printf("LIS Length: %d\n",ans);
	return 0;
}
