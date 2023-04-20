#include <bits/stdc++.h>
#define maxn 200001
#define mod 1000000007
using namespace std;

struct data {
	int val,ord,id;
}ar[maxn];

bool comp1(const data& a , const data& b) {
	return a.val < b.val;
}

bool comp2(const data& a , const data& b) {
	return a.id < b.id;
}

int n,m,ans;
int tree[maxn];

int query(int x) {
	int res = 0;
	while(x) {
		res = (res + tree[x]) % mod;
		x -= (x & (-x));
	}
	return res;
}

void update(int x , int val) {
	while(x <= m) {
		tree[x] = (tree[x] + val) % mod;
		x += (x & (-x));
	}
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i].val);
		ar[i].id = i;
	}
	sort(ar+1 , ar+n+1 , comp1);
	for( int i = 1 , j = 1 , v = 1 ; i <= n ; i = j , v++ )
		while( j <= n && ar[i].val == ar[j].val )
			ar[j++].ord = v;
	m = ar[n].ord;
	sort(ar+1 , ar+n+1 , comp2);
	for( int i = 1 ; i <= n ; i++ ) {
		int add = ( query(ar[i].ord-1) + 1 ) % mod;
		update(ar[i].ord , add);
		ans = (ans + add) % mod;
	}
	printf("%d\n",ans);
	return 0;
}