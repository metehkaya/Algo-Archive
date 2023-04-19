#include <bits/stdc++.h>
#define maxn 200003
#define pb push_back
using namespace std;

int n,m,ans,k;
int ar[maxn];
vector<int> v;

int main() {
	scanf("%d%d",&m,&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	if(n == 0) {
		puts("1");
		return 0;
	}
	if(n == m) {
		puts("0");
		return 0;
	}
	sort(ar+1,ar+n+1);
	for( int i = 2 ; i <= n ; i++ )
		if(ar[i] > ar[i-1]+1)
			v.pb(ar[i]-ar[i-1]-1);
	if(ar[1] > 1)
		v.pb(ar[1]-1);
	if(ar[n] < m)
		v.pb(m-ar[n]);
	k = v[0];
	int sz = v.size();
	for( int i = 1 ; i < sz ; i++ )
		k = min(k,v[i]);
	for( int i = 0 ; i < sz ; i++ )
		ans += (v[i]+k-1)/k;
	printf("%d\n",ans);
	return 0;
}
