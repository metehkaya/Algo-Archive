#include <bits/stdc++.h>
#define maxn 1000
using namespace std;
typedef pair<int,int> pi;

int T,n,m;
int ar[maxn];
int cnt[maxn];

void output(bool flag) {
	if(!flag)
		puts("NO");
	else {
		printf("YES");
		for( int i = 0 ; i < n ; i++ )
			printf(" %d",cnt[i]);
		puts("");
	}
}

pi getIndices() {
	for( int i = 0 ; i < n ; i++ )
		if( ar[i] > 1 && ar[i] < m )
			for( int j = i+1 ; j < n ; j++ )
				if( ar[j] < m && ar[j] % ar[i] != 0 )
					return pi(i,j);
	return pi(-1,-1);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		memset(cnt, 0, sizeof(cnt));
		int notDiv=-1;
		scanf("%d%d",&n,&m);
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&ar[i]);
			if( m % ar[i] != 0 )
				notDiv = i;
		}
		if(notDiv != -1) {
			cnt[notDiv] = m/ar[notDiv] + 1;
			output(true);
		}
		else {
			pi p = getIndices();
			int index1 = p.first;
			int index2 = p.second;
			if(index1 == -1)
				output(false);
			else {
				cnt[index2] = m / ar[index2] - 1;
				cnt[index1] = ar[index2] / ar[index1] + 1;
				output(true);
			}
		}
	}
	return 0;
}
