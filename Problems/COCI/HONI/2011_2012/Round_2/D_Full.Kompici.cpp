#include <bits/stdc++.h>
#define maxs 1024
using namespace std;
typedef long long LL;

int n;
LL ans;
LL cnt[maxs];

int main() {
	scanf("%d",&n);
	while(n--) {
	    string s;
	    int bmask = 0;
	    cin >> s;
	    for(char c : s)
	        bmask |= (1 << (c - '0'));
        cnt[bmask]++;
	}
	for( int i = 0 ; i < maxs ; i++ )
	    for( int j = i ; j < maxs ; j++ )
	        if((i & j) > 0) {
	            if(i != j)
	                ans += cnt[i] * cnt[j];
                else
                    ans += cnt[i] * (cnt[i] - 1) / 2;
	        }
    printf("%lld\n",ans);
	return 0;
}