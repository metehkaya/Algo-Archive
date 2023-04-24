#include <bits/stdc++.h>
#define maxc 26
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pi;
typedef pair<LL,pi> pii;

LL T;
LL cnt[maxc];

bool f(LL len) {
	vector<pii> v1;
	for( LL i = 0 , sum = 0 ; i < maxc && sum < len+1 ; i++ ) {
		LL mn = min(cnt[i],len+1-sum);
		if(!mn)
			continue;
		v1.pb(pii(i,pi(mn,0)));
		sum += mn;
	}
	vector<pii> v2;
	for( LL i = maxc-1 , sum = 0 ; i >= 0 && sum < len ; i-- ) {
		LL mn = min(cnt[i],len-sum);
		if(!mn)
			continue;
		v2.pb(pii(i,pi(mn,0)));
		sum += mn;
	}
	reverse(v2.begin(),v2.end());
	for( LL i = 0 , sum = 0 ; i < v1.size() ; i++ ) {
		sum += v1[i].se.fi;
		v1[i].se.se = sum;
	}
	for( LL i = 0 , sum = 0 ; i < v2.size() ; i++ ) {
		sum += v2[i].se.fi;
		v2[i].se.se = sum;
	}
	for( LL i = 0 , j = 0 ; i < v2.size() ; i++ ) {
		while(v1[j].se.se <= v2[i].se.se)
			j++;
		if(v2[i].fi <= v1[j].fi)
			return false;
	}
	return true;
}

int main() {
	scanf("%lld",&T);
	for( LL tc = 1 ; tc <= T ; tc++ ) {
		LL sum = 0;
		for( LL i = 0 ; i < maxc ; i++ ) {
			scanf("%lld",&cnt[i]);
			sum += cnt[i];
		}
		LL res = 0 , left = 1 , right = (sum - 1) / 2;
		while(left <= right) {
			LL mid = (left+right) >> 1;
			if(f(mid))
				res = mid , left = mid+1;
			else
				right = mid-1;
		}
		printf("%lld\n",res);
	}
	return 0;
}
