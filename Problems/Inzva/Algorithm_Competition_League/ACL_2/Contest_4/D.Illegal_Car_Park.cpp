#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int n,k,ans;
int ar[maxn];
vector<int> v;

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	sort(ar,ar+n);
	for( int i = 1 ; i < n ; i++ )
		v.push_back(ar[i]-ar[i-1]-1);
	int ans = ar[n-1]+1 - ar[0];
	sort(v.begin(),v.end());
	for( int i = n-2 ; i >= n-k ; i-- )
		ans -= v[i];
	printf("%d\n",ans);
	return 0;
}
