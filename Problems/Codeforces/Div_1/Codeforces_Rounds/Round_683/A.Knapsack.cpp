#include <bits/stdc++.h>
#define maxn 200000
#define pb push_back
using namespace std;
typedef long long LL;

int T,n;
LL ar[maxn];
LL w,minw;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n >> w;
		minw = (w+1) / 2;
		for( int i = 0 ; i < n ; i++ )
			cin >> ar[i];
		LL sumw = 0;
		bool ok = false;
		vector<int> ans;
		for( int i = 0 ; i < n ; i++ )
			if(ar[i] >= minw && ar[i] <= w) {
				ok = true;
				ans.clear();
				ans.pb(i+1);
				break;
			}
			else if(ar[i] < minw) {
				sumw += ar[i];
				ans.pb(i+1);
				if(sumw >= minw) {
					ok = true;
					break;
				}
			}
		if(!ok)
			puts("-1");
		else {
			int sz = ans.size();
			printf("%d\n",sz);
			for( int i = 0 ; i < sz ; i++ )
				printf("%d ",ans[i]);
			puts("");
		}
	}
	return 0;
}
