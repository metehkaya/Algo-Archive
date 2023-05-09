#include <bits/stdc++.h>
#define maxn 200003
#define pb push_back
using namespace std;
typedef long long LL;

int n;
LL ans;
int cnt[256];
int idx[maxn];
int tree[maxn];
string s,t;
vector<int> v[maxn];

void update(int x) {
	while(x <= n) {
		tree[x]++;
		x += (x&(-x));
	}
}

int query(int x) {
	int sum = 0;
	while(x) {
		sum += tree[x];
		x -= (x&(-x));
	}
	return sum;
}

int main() {
	cin >> n >> s;
	t = s;
	reverse(t.begin(),t.end());
	for( int i = 0 ; i < n ; i++ )
		v[s[i]].pb(i);
	for( int i = 0 ; i < n ; i++ )
		idx[i] = v[t[i]][cnt[t[i]]++];
	for( int i = n-1 ; i >= 0 ; i-- ) {
		int pl = idx[i]+1 - query(idx[i]+1);
		ans += (i+1) - pl;
		update(idx[i]+1);
	}
	printf("%lld\n",ans);
	return 0;
}
