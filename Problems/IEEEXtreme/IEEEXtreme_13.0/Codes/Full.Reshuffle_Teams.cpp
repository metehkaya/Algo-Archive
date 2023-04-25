#include <bits/stdc++.h>
#define maxn 100001
#define pb push_back
using namespace std;

int T,n,k;
int cnt[4];
int perm[4];
int hashh[4];
int key[maxn];
int ar[2*maxn];
char str[maxn];

void convInput() {
	n = strlen(str);
	memset(cnt, 0, sizeof(cnt));
	for( int i = 0 ; i < n ; i++ )
		cnt[str[i]-'A']++;
	k = 0;
	for( int i = 0 ; i < 4 ; i++ ) {
		if( cnt[i] )
			hashh[i] = k++;
		else
			hashh[i] = -1;
	}
	for( int i = 0 ; i < 4 ; i++ )
		if( hashh[i] != -1 )
			cnt[hashh[i]] = cnt[i];
	for( int i = k ; i < 4 ; i++ )
		cnt[i] = 0;
	for( int i = 0 ; i < n ; i++ )
		str[i] = 'A' + hashh[str[i]-'A'];
	for( int i = 0 ; i < 2*n ; i++ )
		ar[i] = str[i%n] - 'A';
}

int solveOneCase() {
	int curr = 0;
	for( int i = 0 ; i < n ; i++ )
		curr += ar[i] != key[i];
	int res = curr;
	for( int i = 1 ; i < n ; i++ ) {
		curr -= ar[i-1] != key[0];
		curr += ar[i+n-1] != key[n-1];
		int sum = 0;
		for( int j = 0 ; j < k-1 ; j++ ) {
			sum += cnt[perm[j]];
			curr -= ar[i-1+sum] != perm[j+1];
			curr += ar[i-1+sum] != perm[j];
		}
		res = min(res,curr);
	}
	return res;
}

void solve() {
	if(k == 1) {
		puts("0");
		return;
	}
	int ans = n;
	for( int i = 0 ; i < k ; i++ )
		perm[i] = i;
	do {
		int sum = 0;
		for( int i = 0 ; i < k ; sum += cnt[perm[i++]] )
			for( int j = 0 ; j < cnt[perm[i]] ; j++ )
				key[j+sum] = perm[i];
		ans = min( ans , solveOneCase() );
	} while(next_permutation(perm+1, perm+k));
	printf("%d\n",ans);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%s",str);
		convInput();
		solve();
	}
	return 0;
}
