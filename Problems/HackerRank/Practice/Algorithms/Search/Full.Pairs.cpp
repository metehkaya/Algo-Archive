#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int n,k,ans;
int ar[maxn];
set<int>s;

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	sort(ar, ar+n);
	for( int i = 0 ; i < n ; i++ ) {
		if(s.find(ar[i]-k) != s.end())
			ans++;
		s.insert(ar[i]);
	}
	printf("%d\n",ans);
	return 0;
}
