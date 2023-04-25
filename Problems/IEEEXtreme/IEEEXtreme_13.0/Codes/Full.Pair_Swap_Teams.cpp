#include <bits/stdc++.h>
#define maxn 100001
#define pb push_back
using namespace std;
typedef vector<int> vi;

int T,n,k;
int cnt[4];
int perm[4];
int hashh[4];
int key[maxn];
int ar[2*maxn];
int curr[4][4];
char str[maxn];

vector<vi> v[5];

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

int findCost() {
	int tot = 0;
	int tmp[k][k];
	for( int i = 0 ; i < k ; i++ )
		for( int j = i+1 ; j < k ; j++ ) {
			tmp[i][j] = curr[i][j];
			tmp[j][i] = curr[j][i];
		}
	for( int len = 2 ; len <= k ; len++ )
		for( int id = 0 ; id < (int) v[len].size() ; id++ ) {
			int mn = n;
			for( int i = 0 ; mn && i < len ; i++ )
				mn = min( mn , tmp[ v[len][id][i] ][ v[len][id][(i+1)%len] ] );
			if( mn ) {
				tot += mn * (len-1);
				for( int i = 0 ; i < len ; i++ )
					tmp[ v[len][id][i] ][ v[len][id][(i+1)%len] ] -= mn;
			}
		}
	return tot;
}

int solveOneCase() {
	memset(curr, 0, sizeof(curr));
	for( int i = 0 ; i < n ; i++ )
		curr[ar[i]][key[i]]++;
	int res = findCost();
	for( int i = 1 ; i < n ; i++ ) {
		curr[ar[i-1]][key[0]]--;
		curr[ar[i+n-1]][key[n-1]]++;
		int sum = 0;
		for( int j = 0 ; j < k-1 ; j++ ) {
			sum += cnt[perm[j]];
			curr[ar[i-1+sum]][perm[j+1]]--;
			curr[ar[i-1+sum]][perm[j]]++;
		}
		res = min(res, findCost());
	}
	return res;
}

void findCycles() {
	for( int i = 2 ; i <= k ; i++ )
		v[i].clear();
	for( int bmask = 3 ; bmask < (1<<k) ; bmask++ ) {
		vi tmp;
		for( int i = 0 ; i < k ; i++ )
			if( bmask & (1<<i) )
				tmp.pb(i);
		int cnt = (int) tmp.size();
		int arr[cnt];
		for( int i = 0 ; i < cnt ; i++ )
			arr[i] = tmp[i];
		do {
			vi temp;
			for( int i = 0 ; i < cnt ; i++ )
				temp.pb(arr[i]);
			v[cnt].pb(temp);
		} while(next_permutation(arr+1, arr+cnt));
	}
}

void solve() {
	if(k == 1) {
		puts("0");
		return;
	}
	findCycles();
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
	for( int tc=1 ; tc <= T ; tc++ ) {
		scanf("%s",str);
		convInput();
		solve();
	}
	return 0;
}
