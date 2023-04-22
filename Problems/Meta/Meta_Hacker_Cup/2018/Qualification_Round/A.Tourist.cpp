#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;

LL v;
int T,n,k;
string str[50];
vector<int> vec;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%lld",&n,&k,&v);
		for( int i = 0 ; i < n ; i++ )
			cin >> str[i];
		vec.clear();
		for( LL i = (v-1)*k ; i < v*k ; i++ )
			vec.pb(i%n);
		sort(vec.begin(),vec.end());
		printf("Case #%d:",tc);
		for( int i = 0 ; i < k ; i++ )
			cout << " " << str[vec[i]];
		puts("");
	}
	return 0;
}

