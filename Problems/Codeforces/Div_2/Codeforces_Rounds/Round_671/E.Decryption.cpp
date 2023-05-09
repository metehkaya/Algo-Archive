#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int T,N,n;
vector<pi> pr;

void f(int root , int mult , int last , int id , int k) {
	if(id == k) {
		if(mult != root && mult != last)
			printf("%d ",mult);
		return;
	}
	f(root,mult,last,id+1,k);
	for( int i = 1 ; i <= pr[id].se ; i++ ) {
		mult *= pr[id].fi;
		f(root,mult,last,id+1,k);
	}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		pr.clear();
		scanf("%d",&n);
		N = n;
		for( int i = 2 ; i*i <= n ; i++ )
			if(n%i == 0) {
				if(N%i == 0) {
					int cnt = 0;
					while(N%i == 0)
						N /= i , cnt++;
					pr.pb(pi(i,cnt));
				}
			}
		if(N > 1)
			pr.pb(pi(N,1));
		int sz = pr.size();
		int score = 0;
		if(pr.size() == 2 && pr[0].se == 1 && pr[1].se == 1)
			score = 1;
		int p = pr[0].fi;
		int cnt = pr[0].se;
		int mult = 1;
		for( int i = 0 ; i < cnt ; i++ ) {
			mult *= p;
			printf("%d ",mult);
		}
		if(sz > 1) {
			int last = pr[0].fi*pr[sz-1].fi;
			for( int k = 1 ; k < sz ; k++ ) {
				p = pr[k].fi;
				cnt = pr[k].se;
				mult = 1;
				for( int i = 0 ; i < cnt ; i++ ) {
					mult *= p;
					f(mult,mult,last,0,k);
				}
				mult = 1;
				for( int i = 0 ; i < cnt ; i++ ) {
					mult *= p;
					printf("%d ",mult);
				}
			}
			printf("%d ",last);
		}
		puts("");
		printf("%d\n",score);
	}
	return 0;
}
