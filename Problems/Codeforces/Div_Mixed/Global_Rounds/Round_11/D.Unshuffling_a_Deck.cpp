#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 1003
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n;
int l[maxn];
int r[maxn];
int ar[maxn];
int cpy[maxn];
int pos[maxn];
vector< vector<int> > ans;

bool check() {
	int idx = 0;
	for( int i = 1 ; i <= n ; i++ )
		if(ar[i] != i) {
			idx = i;
			break;
		}
	if(idx == 0)
		return false;
	for( int i = 1 ; i <= n ; i++ )
		pos[ar[i]] = i;
	for( int i = 1 , j = 1 ; i <= n ; i = j ) {
		while(j <= n && ar[j]-ar[i] == j-i)
			j++;
		for( int k = i ; k < j ; k++ )
			l[k] = i , r[k] = j-1;
	}
	vector<pi> v;
	if(idx != 1)
		v.pb(pi(1,idx-1));
	v.pb(pi(idx,r[idx]));
	int idx2 = pos[ar[idx]-1];
	v.pb(pi(r[idx]+1,idx2));
	if(idx2 != n)
		v.pb(pi(idx2+1,n));
	vector<int> add;
	int sz = v.size();
	for( int i = 0 ; i < sz ; i++ )
		add.pb(v[i].se-v[i].fi+1);
	ans.pb(add);
	for( int i = sz-1 , id = 0 ; i >= 0 ; i-- )
		for( int j = v[i].fi ; j <= v[i].se ; j++ )
			cpy[++id] = ar[j];
	for( int i = 1 ; i <= n ; i++ )
		ar[i] = cpy[i];
	return true;
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	while(check());
	int sz = ans.size();
	printf("%d\n",sz);
	for( int i = 0 ; i < sz ; i++ ) {
		int sz2 = ans[i].size();
		printf("%d",sz2);
		for( int j = 0 ; j < sz2 ; j++ )
			printf(" %d",ans[i][j]);
		puts("");
	}
	return 0;
}
