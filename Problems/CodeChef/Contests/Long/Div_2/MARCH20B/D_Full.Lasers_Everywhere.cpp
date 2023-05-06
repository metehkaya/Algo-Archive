#include <bits/stdc++.h>
#define maxn 200003
#define pb push_back
using namespace std;

struct data {
	int id,y;
	bool start;
};

int T,n,m;
int ar[maxn];
int ans[maxn];
int q[maxn][3];
int tree[maxn];
vector<int> nums;
map<int,int> hashh;
vector<data> queries[maxn];

void reset() {
	nums.clear();
	hashh.clear();
	for( int i = 1 ; i <= n ; i++ )
		queries[i].clear();
	for( int i = 1 ; i <= n+m ; i++ )
		tree[i] = 0;
}

int query(int id) {
	int res = 0;
	while(id) {
		res += tree[id];
		id -= (id & (-id));
	}
	return res;
}

void update(int id, int val) {
	while(id <= n+m) {
		tree[id] += val;
		id += (id & (-id));
	}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&m);
		for( int i = 1 ; i <= n ; i++ ) {
			scanf("%d",&ar[i]);
			nums.pb(ar[i]);
		}
		for( int i = 1 ; i <= m ; i++ ) {
			scanf("%d%d%d",&q[i][0],&q[i][1],&q[i][2]);
			nums.pb(q[i][2]);
		}
		sort(nums.begin(), nums.end());
		hashh[nums[0]] = 1;
		for( int i=1 , ord=1 ; i < n+m ; i++ )
			if( nums[i] != nums[i-1] )
				hashh[nums[i]] = ++ord;
		for( int i = 1 ; i <= n ; i++ )
			ar[i] = hashh[ar[i]];
		for( int i = 1 ; i <= m ; i++ ) {
			q[i][2] = hashh[q[i][2]];
			data q1;
			q1.id = i;
			q1.y = q[i][2];
			q1.start = true;
			queries[q[i][0]].pb(q1);
			data q2;
			q2.id = i;
			q2.y = q[i][2];
			q2.start = false;
			queries[q[i][1]].pb(q2);
		}
		for( int i = 1 ; i <= n ; i++ ) {
			for( int j = 0 ; j < (int) queries[i].size() ; j++ )
				if( queries[i][j].start )
					ans[ queries[i][j].id ] = -query( queries[i][j].y );
				else
					ans[ queries[i][j].id ] += query( queries[i][j].y );
			if(i < n) {
				int mn = min(ar[i], ar[i+1]);
				int mx = max(ar[i], ar[i+1]);
				update(mn, +1);
				update(mx+1, -1);
			}
		}
		for( int i = 1 ; i <= m ; i++ )
			printf("%d\n",ans[i]);
	}
	return 0;
}
