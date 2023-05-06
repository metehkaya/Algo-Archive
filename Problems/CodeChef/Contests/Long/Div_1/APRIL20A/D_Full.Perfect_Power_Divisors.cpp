#include <bits/stdc++.h>
#define mil 1000000
#define mod 1000000007
#define pb push_back
using namespace std;
typedef long long LL;

int T,p;
LL n,ans,rev6;
bool mark[mil+1];
vector<LL> perfects;

void addPerfect(int y, LL xy) {
	if(y%2)
		perfects.pb(xy);
	if(xy <= mil)
		mark[xy] = true;
}

int calcPow(int x, int y) {
	if(y == 0)
		return 1;
	int res = calcPow(x, y/2);
	res = (LL) res * res % mod;
	if(y & 1)
		res = (LL) res * x % mod;
	return res;
}

int calcRev(int x) {
	return calcPow(x, mod-2);
}

void precalc() {
	rev6 = calcRev(6);
	LL upper = (LL) mil*mil*mil;
	for( int i = 2 ; i <= mil ; i++ )
		if(!mark[i]) {
			LL xy = (LL) i*i;
			int y = 2;
			while(xy <= upper/i) {
				addPerfect(y, xy);
				y++;
				xy *= i;
			}
			addPerfect(y, xy);
		}
	p = perfects.size();
}

int bs(int left, int right, int mult) {
	int last = -1;
	while(left <= right) {
		int mid = (left + right) / 2;
		LL sq = (LL) mid*mid;
		if(sq <= n/mult)
			last = mid , left = mid+1;
		else
			right = mid-1;
	}
	return last;
}

void addInterval(int head, int tail, int mult) {
	LL sum = 0;
	int len = tail - head + 1;
	LL sq = (LL) head*head % mod;
	sum = sq * len % mod;
	LL add = (LL) len * (len-1) % mod;
	sum = ( sum + add * head % mod ) % mod;
	LL x = (len - 1);
	add = (x * (x+1)) % mod;
	add = (add * (2*x+1)) % mod;
	add = (add * rev6) % mod;
	sum = (sum + add) % mod;
	sum = (sum * mult) % mod;
	ans = (ans + sum) % mod;
}

int main() {
	precalc();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		ans = 0;
		scanf("%lld",&n);
		for( int i = 0 ; i < p ; i++ )
			ans = ( ans + (n - n % perfects[i]) ) % mod;
		LL minN = min(n, (LL) mil*mil);
		for( LL i = 1 ; i*i <= minN ; i++ )
			ans = ( ans + (n - n % (i*i)) ) % mod;
		if(n >= (mil+1LL)*(mil+1LL)) {
			int upper = n / ( (mil+1LL)*(mil+1LL) );
			int head = mil + 1LL;
			int root = mod-7;
			for( int i = upper ; i >= 1 ; i-- ) {
				int tail = bs(head, root, i);
				if(tail != -1) {
					addInterval(head, tail, i);
					head = tail+1;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
