#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200001
#define maxv 2000000
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int T,n,m;
int w,x,y,z;
int h[maxn];
int up[maxn];
int down[maxn];
vector<pi> v;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	v.clear();
	memset(up,-1,sizeof(up));
	memset(down,-1,sizeof(down));
}

bool check(int gap) {
	for( int i = 0 ; i < v.size() ; i++ ) {
		int head = v[i].first;
		int mn = max( h[head] - gap , 0 );
		int mx = min( h[head] + gap , maxv );
		for( int j = head+1 ; j <= v[i].second ; j++ ) {
			mn = max( mn - down[j-1] , 0 );
			mx = min( mx + up[j-1] , maxv );
			mn = max( mn , h[j] - gap );
			mx = min( mx , h[j] + gap );
			if(mn > mx)
				return false;
			mn = max( mn , 0 );
			mx = min( mx , maxv );
		}
	}
	return true;
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&m);
		scanf("%d%d%d%d%d%d",&h[1],&h[2],&w,&x,&y,&z);
		for( int i = 0 ; i < m ; i++ ) {
			int a,b,u,d;
			scanf("%d%d%d%d",&a,&b,&u,&d);
			if(a > b) {
				swap(a,b);
				swap(u,d);
			}
			u *= 2 , d *= 2;
			for( int j = a ; j < b ; j++ ) {
				if(up[j] == -1 || u < up[j])
					up[j] = u;
				if(down[j] == -1 || d < down[j])
					down[j] = d;
			}
		}
		for( int i = 3 ; i <= n ; i++ )
			h[i] = ( (LL) w * h[i-2] + (LL) x * h[i-1] + y ) % z;
		for( int i = 1 ; i <= n ; i++ )
			h[i] *= 2;
		for( int i = 1 , j = 1 ; i < n ; i = j+1 ) {
			j = i;
			while(j < n && up[j] != -1)
				j++;
			if(i != j)
				v.pb(pi(i,j));
		}
		int l = 0 , r = maxv , ans = -1;
		while(l <= r) {
			int mid = (l+r) >> 1;
			if(check(mid))
				ans = mid , r = mid-1;
			else
				l = mid+1;
		}
		printf("Case #%d: %lf\n",tc,ans/2.0);
	}
	return 0;
}
