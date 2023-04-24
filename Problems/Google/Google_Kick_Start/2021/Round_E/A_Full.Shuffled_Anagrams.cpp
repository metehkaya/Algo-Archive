#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<char,int> pi;

int T,n;
string s,t;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> s;
		n = s.length();
		vector<pi> ss;
		for( int i = 0 ; i < n ; i++ )
			ss.pb(pi(s[i],i));
		sort(ss.begin(),ss.end());
		t = s;
		for( int i = 0 ; i < n ; i++ ) {
			int idx = ss[i].se;
			t[idx] = ss[(i+n/2)%n].fi;
		}
		bool ok = true;
		for( int i = 0 ; i < n ; i++ )
			if(s[i] == t[i])
				ok = false;
		if(ok)
			printf("Case #%d: %s\n",tc,t.c_str());
		else
			printf("Case #%d: IMPOSSIBLE\n",tc);
	}
	return 0;
}
