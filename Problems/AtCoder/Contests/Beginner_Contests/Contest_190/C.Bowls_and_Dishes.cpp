#include <bits/stdc++.h>
#define maxk 16
#define maxn 101
using namespace std;

int n,m,k,ans;
int a[maxn];
int b[maxn];
int c[maxk];
int d[maxk];
int cnt[maxn];

void f(int id) {
	if(id == k) {
		int val = 0;
		for( int i = 1 ; i <= m ; i++ )
			val += (cnt[a[i]] > 0) && (cnt[b[i]] > 0);
		ans = max(ans,val);
		return;
	}
	cnt[c[id]]++;
	f(id+1);
	cnt[c[id]]--;
	cnt[d[id]]++;
	f(id+1);
	cnt[d[id]]--;
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= m ; i++ )
		scanf("%d%d",&a[i],&b[i]);
	scanf("%d",&k);
	for( int i = 0 ; i < k ; i++ )
		scanf("%d%d",&c[i],&d[i]);
	f(0);
	printf("%d\n",ans);
	return 0;
}
