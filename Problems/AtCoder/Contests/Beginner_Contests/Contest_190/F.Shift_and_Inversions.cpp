#include <bits/stdc++.h>
#define maxn 300001
using namespace std;
typedef long long LL;

int n;
LL ans;
int ar[maxn];
int tree[maxn];

void update(int x) {
	while(x <= n) {
		tree[x]++;
		x += (x&(-x));
	}
}

int query(int x) {
	int sum = 0;
	while(x) {
		sum += tree[x];
		x -= (x&(-x));
	}
	return sum;
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		update(++ar[i]);
		ans += i - query(ar[i]);
	}
	printf("%lld ",ans);
	for( int i = 1 ; i < n ; i++ ) {
		ans += n+1 - 2*ar[i];
		printf("%lld ",ans);
	}
	return 0;
}
