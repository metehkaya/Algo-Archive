#include <bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long LL;

int n;
LL ans,sum;
int ar[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	sort(ar,ar+n);
	for( int i = 0 ; i < n ; i++ ) {
		ans += (LL)ar[i]*i - sum;
		sum += ar[i];
	}
	cout << ans << endl;
	return 0;
}
