#include <bits/stdc++.h>
#define maxn 200000
#define mod 1000000007
using namespace std;
typedef long long LL;

struct data {
	int x,h;
}ar[maxn];

bool comp(const data &a , const data &b) {
	if(a.h != b.h)
		return a.h > b.h;
	return a.x < b.x;
}

int T,n;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d%d",&ar[i].x,&ar[i].h);
		LL ans = 0;
		set<int> s;
		set<int>::iterator it;
		sort(ar,ar+n,comp);
		for( int i = 0 , j = 0 ; i < n ; i = j ) {
			vector<int> v;
			while(j < n && ar[i].h == ar[j].h)
				v.push_back(ar[j++].x);
			int k = j-i;
			int last = -2 , cnt , sum , sqsum;
			for( int l = 0 ; l < k ; l++ ) {
				it = s.lower_bound(v[l]);
				int x = (it == s.end()) ? -1 : (*it);
				if(x != last) {
					last = x;
					cnt = 1;
					sum = v[l];
					sqsum = (LL) v[l] * v[l] % mod;
				}
				else {
					LL sq = (LL) v[l] * v[l] % mod;
					LL add = (cnt * sq) % mod;
					add = (add + sqsum) % mod;
					add -= 2LL * sum * v[l] % mod;
					if(add < 0)
						add = (add + 2LL * mod * mod) % mod;
					ans = (ans + add) % mod;
					cnt++;
					sum = (sum + v[l]) % mod;
					sqsum = (sqsum + sq) % mod;
				}
			}
			for( int l = 0 ; l < k ; l++ )
				s.insert(v[l]);
		}
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
