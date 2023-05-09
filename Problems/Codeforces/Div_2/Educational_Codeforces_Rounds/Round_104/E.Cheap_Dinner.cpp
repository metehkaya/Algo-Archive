#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 150001
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;

struct datum {
	pi p;
	int cost;
};

datum getDatum(pi _p , int _cost) {
	datum d;
	d.p = _p;
	d.cost = _cost;
	return d;
}

bool operator<(const datum& a , const datum& b) {
	return a.cost > b.cost;
}

int n[4];
int m[3];
pi a[4][maxn];
set<pi> mark;
set<pi> forb[3];
vector<pi> v1,v2;
priority_queue<datum> heap;

int main() {
	for( int i = 0 ; i < 4 ; i++ )
		scanf("%d",&n[i]);
	for( int i = 0 ; i < 4 ; i++ ) {
		for( int j = 1 ; j <= n[i] ; j++ ) {
			scanf("%d",&a[i][j].fi);
			a[i][j].se = j;
		}
		sort(a[i]+1,a[i]+n[i]+1);
	}
	for( int i = 0 ; i < 3 ; i++ ) {
		scanf("%d",&m[i]);
		for( int j = 1 ; j <= m[i] ; j++ ) {
			int x,y;
			scanf("%d%d",&x,&y);
			forb[i].insert(pi(x,y));
		}
	}
	for( int i = 1 ; i <= n[1] ; i++ ) {
		int mycost = -1;
		for( int j = 1 ; j <= n[0] ; j++ ) {
			if(forb[0].find(pi(a[0][j].se,a[1][i].se)) == forb[0].end()) {
				mycost = a[0][j].fi + a[1][i].fi;
				break;
			}
		}
		if(mycost != -1) {
			v1.pb(pi(mycost,a[1][i].se));
		}
	}
	sort(v1.begin(),v1.end());
	for( int i = 1 ; i <= n[2] ; i++ ) {
		int mycost = -1;
		for( int j = 1 ; j <= n[3] ; j++ ) {
			if(forb[2].find(pi(a[2][i].se,a[3][j].se)) == forb[2].end()) {
				mycost = a[2][i].fi + a[3][j].fi;
				break;
			}
		}
		if(mycost != -1) {
			v2.pb(pi(mycost,a[2][i].se));
		}
	}
	sort(v2.begin(),v2.end());
	int A = v1.size();
	int B = v2.size();
	int ans = -1;
	if(A && B) {
		heap.push(getDatum(pi(0,0),v1[0].fi+v2[0].fi));
		mark.insert(pi(0,0));
		while(!heap.empty()) {
			datum d = heap.top();
			heap.pop();
			pi p = d.p;
			int cost = d.cost;
			int a = p.fi;
			int b = p.se;
			int a_id = v1[a].se;
			int b_id = v2[b].se;
			if(forb[1].find(pi(a_id,b_id)) == forb[1].end()) {
				ans = cost;
				break;
			}
			if(a+1 < A && mark.find(pi(a+1,b)) == mark.end()) {
				mark.insert(pi(a+1,b));
				heap.push(getDatum(pi(a+1,b),v1[a+1].fi+v2[b].fi));
			}
			if(b+1 < B && mark.find(pi(a,b+1)) == mark.end()) {
				mark.insert(pi(a,b+1));
				heap.push(getDatum(pi(a,b+1),v1[a].fi+v2[b+1].fi));
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
