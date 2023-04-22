#include <bits/stdc++.h>
#define maxn 10000001
using namespace std;

int T,a,b,k;
int cnt[maxn];
vector<int> v[9];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void init() {
	for( int i = 2 ; i < maxn ; i++ ) {
		if(!cnt[i])
			for( int j = i ; j < maxn ; j += i )
				cnt[j]++;
		v[cnt[i]].push_back(i);
	}
}

int main() {
	io();
	init();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d",&a,&b,&k);
		int ans = 0;
		if(k <= 8)
			ans = upper_bound(v[k].begin(),v[k].end(),b) - lower_bound(v[k].begin(),v[k].end(),a);
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
