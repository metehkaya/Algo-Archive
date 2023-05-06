#include <bits/stdc++.h>
#define fi first
#define se second
#define maxk 100000
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

const int LIMIT = 1024;
const int SUBMISSION = 2;

int k,w,h;
int ar[maxk][2];
vector<pi> divs;
vector<pi> facW,facH;
vector<int> divW,divH;

void f(int curr, int mult, vector<pi>& fac, vector<int>& div) {
	if(curr == (int) fac.size()) {
		div.pb(mult);
		return;
	}
	int val = fac[curr].fi;
	int cnt = fac[curr].se;
	f(curr+1, mult, fac, div);
	for( int i = 1 ; i <= cnt ; i++ ) {
		mult *= val;
		f(curr+1, mult, fac, div);
	}
}

void input() {
	scanf("%d%d%d",&w,&h,&k);
	for( int i = 0 ; i < k ; i++ )
		scanf("%d%d",&ar[i][0],&ar[i][1]);
}

void calc() {
	for( int i = 2 ; i <= w ; i++ )
		if( w%i == 0 ) {
			int cnt = 0;
			while( w%i == 0 )
				w/=i, cnt++;
			facW.pb(pi(i,cnt));
		}
	for( int i = 2 ; i <= h ; i++ )
		if( h%i == 0 ) {
			int cnt = 0;
			while( h%i == 0 )
				h/=i, cnt++;
			facH.pb(pi(i,cnt));
		}
	f(0, 1, facW, divW);
	f(0, 1, facH, divH);
	sort(divW.begin(), divW.end());
	sort(divH.begin(), divH.end());
	for( int i = 0 ; i < (int) divW.size() && divW[i] <= LIMIT ; i++ )
		for( int j = 0 ; j < (int) divH.size() && divH[j] <= LIMIT / divW[i] ; j++ )
			divs.pb( pi( divW[i] , divH[j] ) );
}

void output() {
	srand(time(NULL));
	for( int i = 0 ; i < LIMIT ; i++ )
		random_shuffle( divs.begin() , divs.end() );
	int d = (int) divs.size();
	int p = rand() % d;
	int n = divs[p].fi;
	int m = divs[p].se;
	int q = rand() % LIMIT + 1;
	printf("%d %d %d\n",n,m,q);
	for( int i = 0 ; i < q ; i++ ) {
		int o = rand() % 2;
		if(o == 1) {
			int id = rand() % m + 1;
			printf("1 %d\n",id);
		}
		else {
			int id = rand() % n + 1;
			printf("2 %d\n",id);
		}
	}
//	vector<pi> ops;
//	int upper = LIMIT / (n+m);
//	upper = 1;
//	for( int i = 1 ; i <= m ; i++ ) {
//		int t = rand() % (upper + 1);
//		for( int j = 0 ; j < t ; j++ )
//			ops.pb(pi(1,i));
//	}
//	for( int i = 1 ; i <= n ; i++ ) {
//		int t = rand() % (upper + 1);
//		for( int j = 0 ; j < t ; j++ )
//			ops.pb(pi(2,i));
//	}
//	int q = (int) ops.size();
//	printf("%d %d %d\n",n,m,q);
//	for( int i = 0 ; i < q ; i++ )
//		printf("%d %d\n",ops[i].fi,ops[i].se);
}

int main() {
	input();
	calc();
	output();
	return 0;
}
