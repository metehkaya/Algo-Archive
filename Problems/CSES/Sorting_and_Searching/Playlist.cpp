#include <bits/stdc++.h>
#define maxn 200000
using namespace std;

int n,ans;
int ar[maxn];
set<int> s;

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 0 , j = 0 ; i < n ; i++ ) {
		while(j < n && s.find(ar[j]) == s.end())
			s.insert(ar[j++]);
		ans = max(ans,j-i);
		s.erase(ar[i]);
	}
	printf("%d\n",ans);
	return 0;
}