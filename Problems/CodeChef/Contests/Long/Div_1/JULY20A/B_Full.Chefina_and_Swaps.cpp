#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200000
#define pb push_back
using namespace std;
typedef long long LL;

int T,n;
int a[maxn];
int b[maxn];
map<int,int> cnt;
vector<int> v1,v2;

LL solve() {
	v1.clear();
	v2.clear();
	cnt.clear();
	for( int i = 0 ; i < n ; i++ )
		cnt[a[i]]++ , cnt[b[i]]--;
	int minVal = (*cnt.begin()).fi;
	map<int,int>::iterator it;
	for( it = cnt.begin() ; it != cnt.end() ; it++ ) {
		int val = it->fi;
		int diff = it->se;
		if(abs(diff) % 2)
			return -1;
		if(diff > 0)
			for( int j = 0 ; j < diff/2 ; j++ )
				v1.push_back(val);
		else if(diff < 0)
			for( int j = 0 ; j < -diff/2 ; j++ )
				v2.push_back(val);
	}
	LL ans = 0;
	int i = 0 , j = 0;
	int k = v1.size();
	while(i+j < k && min(v1[i],v2[j]) < 2*minVal) {
		if(v1[i] <= v2[j])
			ans += v1[i++];
		else
			ans += v2[j++];
	}
	ans += 2LL * minVal * (k-i-j);
	return ans;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&a[i]);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&b[i]);
		printf("%lld\n",solve());
	}
	return 0;
}
