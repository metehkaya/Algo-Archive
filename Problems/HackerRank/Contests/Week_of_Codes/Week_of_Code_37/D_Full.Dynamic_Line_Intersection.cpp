#include <bits/stdc++.h>
#define maxc 321
#define maxs 100001
using namespace std;

int n;
int res[maxs];
int cnt[maxc][maxc];

int main() {
	scanf("%d",&n);
	for( int i = 0 , k , b , q ; i < n ; i++ ) {
		char str[3];
		scanf("%s",str);
		if(str[0] == '+') {
			scanf("%d%d",&k,&b);
			b %= k;
			if(k < maxc)
				cnt[k][b]++;
			else
				for( int i = b ; i < maxs ; i += k )
					res[i]++;
		}
		else if(str[0] == '-') {
			scanf("%d%d",&k,&b);
			b %= k;
			if(k < maxc)
				cnt[k][b]--;
			else
				for( int i = b ; i < maxs ; i += k )
					res[i]--;
		}
		else {
			scanf("%d",&q);
			int ans = res[q];
			for( int i = 1 ; i < maxc ; i++ )
				ans += cnt[i][q%i];
			printf("%d\n",ans);
		}
	}
	return 0;
}
