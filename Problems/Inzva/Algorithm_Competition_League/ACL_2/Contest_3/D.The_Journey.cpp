#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
typedef long long LL;

int n;
LL ans=1;
int cnt[26];
char s[maxn];

int main() {
	scanf("%s",s);
	n = strlen(s);
	for( int i = 0 ; i < n ; i++ ) {
		int c = s[i] - 'a';
		ans += i-cnt[c];
		cnt[c]++;
	}
	printf("%lld\n",ans);
	return 0;
}
