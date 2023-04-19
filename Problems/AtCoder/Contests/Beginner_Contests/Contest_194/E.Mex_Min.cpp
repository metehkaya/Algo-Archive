#include <bits/stdc++.h>
#define maxn 1500000
using namespace std;

int n,m,ans;
int ar[maxn];
int cnt[maxn];
set<int> myset;

void add(int num) {
	if(num < m)
		if(++cnt[num] == 1)
			myset.erase(num);
}

void rem(int num) {
	if(num < m)
		if(--cnt[num] == 0)
			myset.insert(num);
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 0 ; i <= m ; i++ )
		myset.insert(i);
	for( int i = 0 ; i < m ; i++ )
		add(ar[i]);
	ans = *myset.begin();
	for( int i = m ; i < n ; i++ ) {
		add(ar[i]);
		rem(ar[i-m]);
		ans = min(ans,*myset.begin());
	}
	printf("%d\n",ans);
	return 0;
}
