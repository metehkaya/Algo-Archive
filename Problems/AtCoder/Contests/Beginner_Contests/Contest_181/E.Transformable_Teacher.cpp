#include <bits/stdc++.h>
#define maxn 200003
using namespace std;
typedef long long LL;

int n,m;
LL ans;
LL ar[maxn];
LL sumPre[maxn];
LL sumSuf[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		cin >> ar[i];
	sort(ar+1,ar+n+1);
	for( int i = 1 ; 2*i <= n ; i++ ) {
		sumPre[i] = sumPre[i-1] + (ar[2*i] - ar[2*i-1]);
		sumSuf[i] = sumSuf[i-1] + (ar[n-2*i+2] - ar[n-2*i+1]);
	}
	ans = (1LL << 60);
	for( int q = 0 , x ; q < m ; q++ ) {
		scanf("%d",&x);
		int l = 1 , r = n , idx = 0;
		while(l <= r) {
			int mid = (l+r) >> 1;
			if(x >= ar[mid])
				idx = mid , l = mid+1;
			else
				r = mid-1;
		}
		int left = idx/2;
		int right = (n+1)/2 - left - 1;
		LL total = sumPre[left] + sumSuf[right];
		if(idx%2 == 0)
			total += ar[idx+1]-x;
		else
			total += x-ar[idx];
		ans = min(ans,total);
	}
	cout << ans << endl;
	return 0;
}
