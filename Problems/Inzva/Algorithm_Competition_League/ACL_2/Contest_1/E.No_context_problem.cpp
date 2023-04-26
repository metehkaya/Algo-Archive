#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

const LL MAXP = (LL) 3e3+1;

int n,p;
LL ar[maxn];
vector<LL> pr;
map<LL,pii> cnt;
bool isNotPrime[MAXP];

void sieve() {
	for( LL i = 2 ; i < MAXP ; i++ )
		if(!isNotPrime[i]) {
			p++;
			pr.push_back(i);
			for( LL j = i*i ; j < MAXP ; j += i )
				isNotPrime[j] = true;
		}
}

void input() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%lld",&ar[i]);
}

void factor() {
	for( int i = 0 ; i < n ; i++ ) {
		LL num = ar[i] , x = 1 , y = 1;
		for( int j = 0 ; j < p && pr[j] <= num ; j++ ) {
			int cnt = 0;
			while(num % pr[j] == 0) {
				cnt++;
				num /= pr[j];
			}
			cnt %= 3;
			if(cnt == 1)
				x *= pr[j] , y *= pr[j]*pr[j];
			else if(cnt == 2)
				x *= pr[j]*pr[j] , y *= pr[j];
		}
		x *= num;
		LL sq = sqrt(num);
		if(sq != 1) {
			if(sq*sq == num)
				y *= sq;
			else
				y *= num*num;
		}
		if(x <= y)
			cnt[x].first++;
		else
			cnt[y].second++;
	}
}

void solve() {
	int ans = 0;
	for( auto it = cnt.begin() ; it != cnt.end() ; it++ ) {
		if(it->first == 1)
			ans++;
		else
			ans += max( it->second.first , it->second.second );
	}
	printf("%d\n",ans);
}

int main() {
	sieve();
	input();
	factor();
	solve();
	return 0;
}