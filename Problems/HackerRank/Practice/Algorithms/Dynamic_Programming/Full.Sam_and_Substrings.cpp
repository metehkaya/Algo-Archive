#include <bits/stdc++.h>
#define maxn 200003
#define mod 1000000007
using namespace std;
typedef long long LL;

int n;
LL ans,last;
char str[maxn];

int main() {
	scanf("%s",str);
	n = strlen(str);
	ans = last = str[0]-'0';
	for( int i = 1 ; i < n ; i++ ) {
		int val = str[i]-'0';
		last = ( last*10 + (i+1)*val ) % mod;
		ans = (ans+last) % mod;
	}
	printf("%lld\n",ans);
	return 0;
}
