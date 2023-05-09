#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int T,n;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		vector<int> pos,neg;
		int sumP = 0 , sumN = 0 , cnt0 = 0;
		for( int i = 0 , x ; i < n ; i++ ) {
			scanf("%d",&x);
			if(x > 0) {
				pos.pb(x);
				sumP += x;
			}
			else if(x < 0) {
				neg.pb(x);
				sumN -= x;
			}
			else
				cnt0++;
		}
		if(sumP == sumN)
			puts("NO");
		else {
			puts("YES");
			if(sumP < sumN)
				swap(pos,neg);
			for( int i = 0 ; i < pos.size() ; i++ )
				printf("%d ",pos[i]);
			for( int i = 0 ; i < neg.size() ; i++ )
				printf("%d ",neg[i]);
			for( int i = 0 ; i < cnt0 ; i++ )
				printf("%d ",0);
			puts("");
		}
	}
	return 0;
}
