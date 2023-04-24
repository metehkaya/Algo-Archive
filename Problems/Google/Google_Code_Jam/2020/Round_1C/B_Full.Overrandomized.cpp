#include <bits/stdc++.h>
#define pb push_back
#define se second
using namespace std;
typedef long long LL;

const int N = 10000;

int T,n;
bool var[256];
bool mark[256];
int cnt[256][17];
vector<string> words[17];

void reset() {
	memset(cnt, 0, sizeof(cnt));
	memset(var, false, sizeof(var));
	memset(mark, false, sizeof(mark));
	for( int i = 0 ; i < 17 ; i++ )
		words[i].clear();
}

int main() {
	cin >> T;
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		cin >> n;
		for( int i = 0 ; i < N ; i++ ) {
			LL m;
			string s;
			cin >> m >> s;
			int len = s.length();
			string pref = "";
			words[len].pb(s);
			for( int j = 0 ; j < len ; j++ )
				var[s[j]] = true;
		}
		for( int len = 1 ; len <= n ; len++ ) {
			int nw = words[len].size();
			for( int i = 0 ; i < nw ; i++ ) {
				string s = words[len][i];
				for( int j = 0 ; j < len ; j++ )
					cnt[s[j]][len-j]++;
			}
		}
		printf("Case #%d: ",tc);
		int total = 0;
		string ans = "";
		for( int k = n ; k >= 1 && total < 9 ; k-- ) {
			vector< pair<int,char> > v;
			for( int i = 'A' ; i <= 'Z' ; i++ )
				if( var[i] && !mark[i] && cnt[i][k] ) {
					mark[i] = true;
					v.pb( make_pair( cnt[i][k] , i ) );
				}
			int sz = v.size();
			total += sz;
			sort( v.begin() , v.end() );
			for( int i = sz-1 ; i >= 0 ; i-- )
				ans.pb( v[i].se );
		}
		for( int i = 'A' ; i <= 'Z' ; i++ )
			if( var[i] && !mark[i] ) {
				char c = i;
				string pref = "";
				pref.pb(c);
				ans = pref + ans;
				break;
			}
		cout << ans << endl;
	}
	return 0;	
}
