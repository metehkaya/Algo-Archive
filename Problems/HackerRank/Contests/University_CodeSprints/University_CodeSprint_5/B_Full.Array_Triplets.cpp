#include <bits/stdc++.h>
#define maxn 17
#define maxb (1<<17)
#define pb push_back
using namespace std;
typedef long long LL;

int n;
LL s,ans;
int ar[maxn];
LL sum[maxb];
int tot[maxb];
vector<int> v;

void f(int value , int initValue , int ind , int sz) {
	if(ind == sz) {
		if(value != initValue)
			tot[value]++;
		return;
	}
	int x = v[ind];
	f(value,initValue,ind+1,sz);
	f(value+(1<<x),initValue,ind+1,sz);
}

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		scanf("%d",&ar[i]);
		s += ar[i];
	}
	if(abs(s)%3 != 0) {
		puts("0");
		return 0;
	}
	for( int bmask = 1 ; bmask < (1<<n) ; bmask++ ) {
		v.clear();
		for( int i = 0 ; i < n ; i++ ) {
			if(bmask & (1<<i))
				sum[bmask] += ar[i];
			else
				v.pb(i);
		}
		if(sum[bmask] == s/3)
			f(bmask,bmask,0,v.size());
	}
	for( int i = 1 ; i < (1 << n) ; i++ )
		if(sum[i] == s/3)
			ans += tot[(1<<n)-i-1];
	printf("%lld\n",ans);
	return 0;
}
