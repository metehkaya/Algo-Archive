#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
LL ans;
int cnt[20];

int main() {
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ) {
        int x;
        scanf("%d",&x);
        for( int k = 0 ; k < 20 ; k++ )
            if((x & (1 << k)) > 0)
                cnt[k]++;
    }
    for( int i = 0 ; i < 20 ; i++ )
        ans += (1LL << i) * cnt[i] * (n-cnt[i]);
    printf("%lld\n",ans);
    return 0;
}