#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100000
using namespace std;
typedef long long LL;
typedef pair<LL,int> pLi;

LL ans;
int n,k;
int ar[maxn];
int cnt[maxn];
priority_queue<pLi> heap;

LL cost(int x , int y) {
	LL a = x/y;
	LL b = a+1;
	int cb = x%y;
	int ca = y-cb;
	return a*a*ca + b*b*cb;
}

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < n ; i++ ) {
		scanf("%d",&ar[i]);
		cnt[i] = 1;
		if(ar[i] > 1)
			heap.push( pLi( cost(ar[i],1)-cost(ar[i],2) , i ) );
	}
	while(k > n) {
		k--;
		pLi temp = heap.top();
		heap.pop();
		int idx = temp.se;
		if(++cnt[idx] < ar[idx])
			heap.push( pLi( cost(ar[idx],cnt[idx])-cost(ar[idx],cnt[idx]+1) , idx ) );
	}
	for( int i = 0 ; i < n ; i++ )
		ans += cost(ar[i],cnt[i]);
	printf("%lld\n",ans);
	return 0;
}
