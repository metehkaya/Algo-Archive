#include <bits/stdc++.h>
#define mod 1000000007LL
using namespace std;
typedef long long LL;

int n,k;
int ar[51];
LL ans;
LL perm[51];

int h() {
	int mx = 0;
	for( int i = 2 ; i <= n ; i++ ) {
		int j = 0;
		while(i+j <= n && ar[i+j] == ar[j+1])
			j++;
		mx = max(mx,j);
	}
	return mx;
}

void g(int last) {
	LL add = h();
	add = (add*perm[last]);
	ans = (ans+add) % mod;
}

void f(int curr , int last) {
	if(curr == n+1) {
		g(last);
		return;
	}
	if(last == 0) {
		ar[curr] = last + 1;
		f(curr+1,last+1);
	}
	else {
		if(last < k) {
			ar[curr] = last+1;
			f(curr+1,last+1);
		}
		for( int i = 1 ; i <= last ; i++ ) {
			ar[curr] = i;
			f(curr+1,last);
		}
	}
}

int main() {
	scanf("%d%d",&n,&k);
	perm[0] = 1;
	for( int i = 1 ; i <= k ; i++ )
		perm[i] = (perm[i-1]*(k-i+1)) % mod;
	f(1,0);
	printf("%lld\n",ans);
	return 0;
}
